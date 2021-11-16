#pragma once
#include "presentation_node_list.h"
#include <QAbstractItemModel>
#include <QIcon>

#include <DOM/IPresentation.h>
#include <DOM/IPresentationComponent.h>

// Custom model that provides GUI representation for the presentation nodes.
class PresentationModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    PresentationModel(System::SharedPtr<Aspose::Slides::IPresentation> presentation, QObject *parent = nullptr);

    QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex& index) const override;
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;

    Aspose::Slides::IPresentationComponent* getNodePointer(const QModelIndex& index) const;
    QIcon getNodeIcon(Aspose::Slides::IPresentationComponent* node) const;

    QString getNodeName(Aspose::Slides::IPresentationComponent* node) const;
    QString getNodeIconName(Aspose::Slides::IPresentationComponent* node) const;

private:
    PresentationNodeList m_presentationNodes;
    mutable std::map<QString, QIcon> mIconCache;
};

