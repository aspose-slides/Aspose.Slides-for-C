#include <presentation_model.h>
#include <DOM/IAutoShape.h>
#include <DOM/IChart.h>
#include <DOM/IPictureFrame.h>
#include <DOM/IAudioFrame.h>
#include <DOM/IVideoFrame.h>
#include <DOM/IGroupShape.h>
#include <DOM/IConnector.h>
#include <DOM/IGraphicalObject.h>
#include <DOM/Ink/IInk.h>
#include <DOM/ILegacyDiagram.h>
#include <DOM/IOleObjectFrame.h>
#include <DOM/SmartArt/ISmartArt.h>
#include <DOM/SmartArt/SmartArtShape.h>
#include <DOM/Table/ITable.h>
#include <DOM/Zoom/IZoomFrame.h>
#include <DOM/ITextFrame.h>
#include <DOM/SmartArt/ISmartArtNodeCollection.h>

#include <QFile>

#include "hidpisupport.h"
#include "qtcorehelpers.h"

PresentationModel::PresentationModel(System::SharedPtr<Aspose::Slides::IPresentation> presentation, QObject *parent)
    : QAbstractItemModel(parent),
      m_presentationNodes(presentation)
{
}

QModelIndex PresentationModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!parent.isValid())
    {
        if (row == 0)
        {
            return createIndex(row, column, m_presentationNodes.getRoot());
        }
        return QModelIndex();
    }

    auto parentNode = getNodePointer(parent);
    auto node = m_presentationNodes.getNode(parentNode, row);
    if(node != nullptr)
    {
        return createIndex(row, column, node);
    }

    return QModelIndex();
}

QModelIndex PresentationModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
    {
        return QModelIndex();
    }

    auto childNode = getNodePointer(index);
    auto parentNode = m_presentationNodes.getParent(childNode);
    if (parentNode == nullptr)
        return QModelIndex();

    int parentNodeIndex = (parentNode == m_presentationNodes.getRoot()) ? 0 : m_presentationNodes.getIndex(m_presentationNodes.getParent(parentNode));
    return createIndex(parentNodeIndex, 0, parentNode);
}

int PresentationModel::rowCount(const QModelIndex &parent) const
{
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        return 1;

    auto parentNode = getNodePointer(parent);
    auto presentation = dynamic_cast<Aspose::Slides::IPresentation*>(parentNode);
    if(presentation)
    {
        return presentation->get_Slides()->get_Count();
    }

    auto slide = dynamic_cast<Aspose::Slides::ISlide*>(parentNode);
    if(slide)
    {
        return slide->get_Shapes()->get_Count();
    }

    auto autoShape = dynamic_cast<Aspose::Slides::IAutoShape*>(parentNode);
    if(autoShape != nullptr && autoShape->get_TextFrame() != nullptr &&
       autoShape->get_TextFrame()->get_Text().get_Length() != 0)
    {
        return 1;
    }

    auto smartArtShape = dynamic_cast<Aspose::Slides::SmartArt::ISmartArtShape*>(parentNode);
    if(smartArtShape != nullptr && smartArtShape->get_TextFrame() != nullptr &&
       smartArtShape->get_TextFrame()->get_Text().get_Length() != 0)
    {
        return 1;
    }

    auto groupShape = dynamic_cast<Aspose::Slides::IGroupShape*>(parentNode);
    if(groupShape)
    {
        return groupShape->get_Shapes()->get_Count();
    }

    auto smartArt = dynamic_cast<Aspose::Slides::SmartArt::ISmartArt*>(parentNode);
    if(smartArt)
    {
        return smartArt->get_AllNodes()->get_Count();
    }

    return 0;
}

int PresentationModel::columnCount(const QModelIndex &/*parent*/) const
{
    return 1;
}

QVariant PresentationModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    auto node = getNodePointer(index);

    if (role == Qt::DisplayRole)
        return getNodeName(node);

    if (role == Qt::DecorationRole)
        return getNodeIcon(node);

    return QVariant();
}

Qt::ItemFlags PresentationModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index);
}

Aspose::Slides::IPresentationComponent* PresentationModel::getNodePointer(const QModelIndex &index) const
{
    return static_cast<Aspose::Slides::IPresentationComponent*>(index.internalPointer());
}

// Get icon to display in the QTreeView control.
QIcon PresentationModel::getNodeIcon(Aspose::Slides::IPresentationComponent* node) const
{
    const QString iconName = getNodeIconName(node);
    auto it = mIconCache.find(iconName);
    if (it == mIconCache.end())
    {
        QIcon icon;
        if(!QFile::exists(":/resources/images/nodes/" + iconName + ".png"))
        {
            icon.addFile((":/resources/images/nodes/Unknown.png"));
        }
        else
        {
            icon.addFile((":/resources/images/nodes/" + iconName + ".png"));
        }

        const auto iconSize = icon.availableSizes().at(0);
        icon = QIcon(HiDpiSupport::scaleImage(icon.pixmap(iconSize)));

        mIconCache.insert({ iconName, icon });
        return icon;
    }
    return it->second;
}

// Get display name for the specified presentation node.
QString PresentationModel::getNodeName(Aspose::Slides::IPresentationComponent* node) const
{
    using Aspose::QtHelpers::Convert;

    auto nodeType = m_presentationNodes.getType(node);

    switch(nodeType)
    {
        case NodeType::presentation:
        {
            return "Presentation";
        }
        case NodeType::slide:
        {
            auto slide = dynamic_cast<Aspose::Slides::ISlide*>(node);
            return "Slide " + QString::number(slide->get_SlideNumber());
        }
        case NodeType::textBody:
        {
            auto textFrame = dynamic_cast<Aspose::Slides::ITextFrame*>(node);
            if(textFrame != nullptr &&
                    textFrame->get_Text().get_Length() != 0)
            {
                return "Text Body";
            }
        }
        case NodeType::groupShape:
        {
            auto groupShape = dynamic_cast<Aspose::Slides::IGroupShape*>(node);
            if(groupShape)
            {
                return "Group Shape";
            }
        }
        case NodeType::shape:
        {
            auto shape = dynamic_cast<Aspose::Slides::IShape*>(node);
            if(shape)
            {
                if(dynamic_cast<Aspose::Slides::IAutoShape*>(shape))
                {
                    return "Shape";
                }
                else if (dynamic_cast<Aspose::Slides::Charts::IChart*>(shape))
                {
                    return "Chart";
                }
                else if (dynamic_cast<Aspose::Slides::IAudioFrame*>(shape))
                {
                    return "Audio from File";
                }
                else if (dynamic_cast<Aspose::Slides::IVideoFrame*>(shape))
                {
                    return "Video from File";
                }
                else if (dynamic_cast<Aspose::Slides::Ink::IInk*>(shape))
                {
                    return "Ink Object";
                }
                else if (dynamic_cast<Aspose::Slides::IPictureFrame*>(shape))
                {
                    return "Picture";
                }
                else if (dynamic_cast<Aspose::Slides::IConnector*>(shape))
                {
                    return "Connection Shape";
                }
                else if (dynamic_cast<Aspose::Slides::ILegacyDiagram*>(shape))
                {
                    return "Legacy Drawing Object";
                }
                else if (dynamic_cast<Aspose::Slides::IOleObjectFrame*>(shape))
                {
                    return "OLE Object";
                }
                else if (dynamic_cast<Aspose::Slides::SmartArt::ISmartArtShape*>(shape))
                {
                    return "Shape";
                }
                if(dynamic_cast<Aspose::Slides::SmartArt::ISmartArt*>(shape))
                {
                    return "Smart Art Diagram";
                }
                else if (dynamic_cast<Aspose::Slides::ITable*>(shape))
                {
                    return "Table";
                }
                else if (dynamic_cast<Aspose::Slides::IZoomFrame*>(shape))
                {
                    return "Slide Zoom Object";
                }

                return "Unknown shape";
            }
            return "Unknown item";
        }
    }

    return "Unknown";
}

// Get icon name for the specified presentation node.
// The name represents name of .ico file without extension located in the resources.qrc file.
QString PresentationModel::getNodeIconName(Aspose::Slides::IPresentationComponent *node) const
{
    return getNodeName(node);
}
