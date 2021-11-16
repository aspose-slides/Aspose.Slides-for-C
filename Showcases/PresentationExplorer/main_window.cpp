#include "main_window.h"
#include "./ui_main_window.h"

#include "about_dialog.h"

#include "hidpisupport.h"
#include "qtcorehelpers.h"

#include <DOM/Presentation.h>
#include <DOM/Slide.h>
#include <DOM/SlideSize.h>
#include <DOM/SlideCollection.h>
#include <Export/RenderingOptions.h>
#include <DOM/PresentationFactory.h>
#include <DOM/DocumentProperties.h>
#include <DOM/PresentationInfo.h>
#include <DOM/Shape.h>
#include <DOM/ShapeThumbnailBounds.h>
#include <DOM/ICommentAuthorCollection.h>
#include <DOM/ICommentAuthor.h>
#include <DOM/IComment.h>
#include <DOM/SlideOrienation.h>
#include <DOM/ISlideSize.h>
#include <DOM/IAutoShape.h>
#include <DOM/ITextFrame.h>
#include <DOM/IAudioFrame.h>
#include <DOM/IAudio.h>
#include <DOM/IVideoFrame.h>
#include <DOM/IVideo.h>
#include <DOM/AudioVolumeMode.h>
#include <DOM/AudioPlayModePreset.h>
#include <DOM/VideoPlayModePreset.h>
#include <DOM/IChart.h>
#include <DOM/Chart/ChartType.h>
#include <DOM/IConnector.h>
#include <DOM/ShapeType.h>
#include <DOM/IOleObjectFrame.h>
#include <DOM/Table/ITable.h>
#include <DOM/Table/IRowCollection.h>
#include <DOM/Table/IColumnCollection.h>
#include <DOM/IZoomFrame.h>
#include <DOM/ZoomImageType.h>
#include <DOM/IControlCollection.h>
#include <DOM/IGroupShape.h>
#include <DOM/SmartArt/ISmartArt.h>
#include <DOM/SmartArt/ISmartArtNodeCollection.h>
#include <DOM/ISlideShowTransition.h>
#include <DOM/SlideShowTransition/TransitionType.h>
#include <DOM/ILayoutSlide.h>
#include <DOM/SlideLayoutType.h>
#include <DOM/IShapeStyle.h>
#include <DOM/IColorFormat.h>
#include <DOM/IImageCollection.h>
#include <DOM/IAudioCollection.h>
#include <DOM/IVideoCollection.h>
#include <DOM/IProtectionManager.h>
#include <DOM/IDigitalSignatureCollection.h>
#include <DOM/IFillFormat.h>
#include <DOM/IColorFormat.h>
#include <DOM/FillType.h>
#include <Export/SaveFormat.h>
#include <Util/License.h>

#include <drawing/bitmap.h>
#include <drawing/image.h>
#include <drawing/graphics.h>
#include <drawing/imaging/image_format.h>
#include <system/io/memory_stream.h>

#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QShortcut>
#include <QScreen>
#include <QTextStream>

#include <map>

using Aspose::QtHelpers::Convert;

namespace {

void scaleActionIcon(QAction* action)
{
    QPixmap pixmap = action->icon().pixmap(16, 16);
    action->setIcon(HiDpiSupport::scaleImage(pixmap));
}

QString BoolToQString(bool test)
{
    return test ? "true" : "false";
}

Aspose::Slides::Export::SaveFormat getFormatByFileName(const QString& fileName)
{
    using Aspose::Slides::Export::SaveFormat;

    if(fileName.endsWith(".ppt"))
    {
        return SaveFormat::Ppt;
    }
    else if(fileName.endsWith(".pptx"))
    {
        return SaveFormat::Pptx;
    }
    else if(fileName.endsWith(".fodp"))
    {
        return SaveFormat::Fodp;
    }
    if(fileName.endsWith(".odp"))
    {
        return SaveFormat::Odp;
    }
    else if(fileName.endsWith(".pdf"))
    {
        return SaveFormat::Pdf;
    }
    else if(fileName.endsWith("tif"))
    {
        return SaveFormat::Tiff;
    }
    else if(fileName.endsWith(".gif"))
    {
        return SaveFormat::Gif;
    }
    else if(fileName.endsWith(".html"))
    {
        return SaveFormat::Html;
    }
    else if(fileName.endsWith(".xps"))
    {
        return SaveFormat::Xps;
    }

    return SaveFormat::Ppt;
};

} // unnamed namespace

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      m_isLicensed(false)
{
    ui->setupUi(this);

    scaleActionIcon(ui->actionOpen);
    scaleActionIcon(ui->actionSaveAs);
    scaleActionIcon(ui->actionPreview);
    scaleActionIcon(ui->actionExpandAll);
    scaleActionIcon(ui->actionCollapseAll);
    ui->toolBar->setIconSize(ui->toolBar->iconSize() * HiDpiSupport::getImageScaleFactor());
    ui->canvas->setStyleSheet("QLabel { background-color : gray; }");

    resize(QGuiApplication::primaryScreen()->availableSize() * 3 / 5);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    openPresentation();
}

void MainWindow::on_actionSaveAs_triggered()
{
    savePresentation();
}

void MainWindow::on_actionPreview_triggered()
{
    showNodeInfo(ui->treeView->currentIndex());
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionExpandAll_triggered()
{
    expandAllNodes();
}

void MainWindow::on_actionCollapseAll_triggered()
{
    collapseAllNodes();
}

void MainWindow::on_actionAbout_triggered()
{
    AboutDialog aboutDialog(QString(APP_VERSION), this);
    aboutDialog.setWindowTitle("About PresentationExplorer");
    aboutDialog.setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    aboutDialog.window()->layout()->setSizeConstraint(QLayout::SetFixedSize);
    aboutDialog.exec();
}

void MainWindow::on_actionLoadLicense_triggered()
{
    loadLicense();
}

void MainWindow::treeView_currentChanged(const QModelIndex &current, const QModelIndex &/*previous*/)
{
    // Enable/disable 'Expand All' and 'Collapse All' actions.
    const bool hasChildren = m_presentationModel->hasChildren(current);
    ui->actionExpandAll->setEnabled(hasChildren);
    ui->actionCollapseAll->setEnabled(hasChildren);

    showNodeInfo(current);
}

// This code activates Aspose.Slides license.
// If you don't specify a license, Aspose.Slides will work in evaluation mode.
bool MainWindow::licenseAsposeSlides(const QString& licenseFile)
{
    auto lic = System::MakeObject<Aspose::Slides::License>();

    try
    {
        lic->SetLicense(Convert(licenseFile));
    }
    catch (const System::Exception& ex)
    {
        showErrorMessage(Convert(ex->get_Message()));
        return false;
    }

    return lic->IsLicensed();
}

// Shows the open file dialog box and opens a presentation.
void MainWindow::openPresentation()
{
    const QString fileName = selectOpenFileName();
    if (fileName.isNull())
        return;

    // This operation can take some time so we set the Cursor to WaitCursor.
    setCursor(Qt::WaitCursor);
    QApplication::processEvents();

    // Load presentation is put in a try-catch block to handle situations when it fails for some reason.
    try
    {
        // Loads the presentation into Aspose.Slides object model.
        m_presentation = System::MakeObject<Aspose::Slides::Presentation>(Convert(fileName));
    }
    catch (System::Exception& ex)
    {
        unsetCursor();
        showErrorMessage(Convert(ex->get_Message()));
        ResetApplicationState();
        return;
    }

    m_fileName = fileName;

    // Detach old model
    ui->treeView->setModel(nullptr);

    // Create new model (and delete old)
    m_presentationModel = std::make_unique<PresentationModel>(m_presentation);

    // Attach new model
    ui->treeView->setModel(m_presentationModel.get());

    // Update UI
    setMainWindowTitle();

    ui->actionSaveAs->setEnabled(true);
    ui->actionPreview->setEnabled(true);
    ui->actionPreview->setChecked(true);
    ui->actionExpandAll->setEnabled(true);
    ui->actionCollapseAll->setEnabled(true);

    connect(ui->treeView->selectionModel(), &QItemSelectionModel::currentChanged, this, &MainWindow::treeView_currentChanged);

    // Shows the immediate children of the document node.
    ui->treeView->expandToDepth(0);

    // Selects root node of the tree.
    ui->treeView->setCurrentIndex(m_presentationModel->index(0, 0));

    unsetCursor();
}

// Saves the presentation with the name and format provided in standard Save As dialog.
void MainWindow::savePresentation()
{
    using Aspose::Slides::Export::SaveFormat;

    if (m_presentation == nullptr)
    {
        return;
    }

    const QString fileName = selectSaveFileName();
    if (fileName.isNull())
        return;

    // This operation can take some time so we set the Cursor to WaitCursor.
    setCursor(Qt::WaitCursor);
    QApplication::processEvents();

    // This operation is put in try-catch block to handle situations when operation fails for some reason.
    try
    {
        // For most of the save formats it is enough to just invoke Aspose.Slides save.
        m_presentation->Save(Convert(fileName), getFormatByFileName(fileName));
    }
    catch (...)
    {
    }

    unsetCursor();
}

void MainWindow::loadLicense()
{
    const QString filter =
        "Licence file (*.lic);;"
        "All Files (*.*)";
    const QString licenseFileName = QFileDialog::getOpenFileName(this, "Load License", m_initialDirectory, filter);
    if (licenseFileName.isNull())
        return;

    if(licenseAsposeSlides(licenseFileName))
    {
        if(m_presentation.get() != nullptr)
        {
            showNodeInfo(ui->treeView->currentIndex());
        }
        m_isLicensed = true;
    }

    setMainWindowTitle();
}

bool MainWindow::isCanDraw(Aspose::Slides::IPresentationComponent *node)
{
    if(dynamic_cast<Aspose::Slides::ISlide*>(node) != nullptr ||
       dynamic_cast<Aspose::Slides::IShape*>(node) != nullptr)
    {
        return true;
    }
    return false;
}

// Draws a node on a separate widget.
void MainWindow::draw(Aspose::Slides::IPresentationComponent* node)
{
    if (node == nullptr || !isCanDraw(node))
    {
        return;
    }

    setCursor(Qt::WaitCursor);
    QApplication::processEvents();

    float scale = 1.0f;

    System::SmartPtr<System::Drawing::Bitmap> img;
    auto slide = dynamic_cast<Aspose::Slides::ISlide*>(node);
    if(slide != nullptr)
    {
        try
        {
            img = slide->GetThumbnail(scale, scale);
        }
        catch (...)
        {
            unsetCursor();
            return;
        }
    }

    auto shape = dynamic_cast<Aspose::Slides::IShape*>(node);
    if(shape != nullptr)
    {
        if(shape->get_Width() == 0 || shape->get_Height() == 0)
        {
            ui->canvas->clear();
            return;
        }

        try
        {
            img = shape->GetThumbnail(Aspose::Slides::ShapeThumbnailBounds::Shape, scale, scale);
        }
        catch (...)
        {
            unsetCursor();
            return;
        }
    }

    QPixmap pixmap;
    {
        // Copy data from System::Drawing::Bitmap to QPixmap.
        const auto stream = System::MakeObject<System::IO::MemoryStream>();
        img->Save(stream, System::Drawing::Imaging::ImageFormat::get_Png());

        stream->set_Position(0);

        const auto buffer = stream->GetBuffer();
        pixmap.loadFromData(buffer->data_ptr(), buffer->get_Length());
    }

    QPixmap scaledPixmap = pixmap.scaled(ui->canvas->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->canvas->setPixmap(scaledPixmap);

    unsetCursor();
}

// Expands all nodes under currently selected node.
void MainWindow::expandAllNodes()
{
    // This operation can take some time so we set the Cursor to WaitCursor.
    setCursor(Qt::WaitCursor);
    QApplication::processEvents();

    auto index = ui->treeView->currentIndex();
    if (index.isValid())
        ui->treeView->expandRecursively(index);

    unsetCursor();
}

// Collapses all nodes under currently selected node.
void MainWindow::collapseAllNodes()
{
    // This operation can take some time so we set the Cursor to WaitCursor.
    setCursor(Qt::WaitCursor);
    QApplication::processEvents();

    auto index = ui->treeView->currentIndex();
    if (index.isValid())
        collapseNodesRecursively(index);

    unsetCursor();
}

void MainWindow::collapseNodesRecursively(const QModelIndex& parent)
{
    int count = m_presentationModel->rowCount(parent);
    if (count > 0)
    {
        for (int i = 0; i < count; ++i)
            collapseNodesRecursively(m_presentationModel->index(i, 0, parent));

        ui->treeView->collapse(parent);
    }
}

// Get text contained by the corresponding presentation node.
QString MainWindow::getNodeText(const QModelIndex& index) const
{
    auto node = m_presentationModel->getNodePointer(index);
    if (node == nullptr)
    {
        return QString();
    }

    auto presentation = dynamic_cast<Aspose::Slides::IPresentation*>(node);
    if(presentation)
    {
        return getDescription(m_fileName, m_presentation.get());
    }

    auto slide = dynamic_cast<Aspose::Slides::ISlide*>(node);
    if(slide)
    {
        return getDescription(m_presentation.get(), slide);
    }

    auto textFrame = dynamic_cast<Aspose::Slides::ITextFrame*>(node);
    if(textFrame)
    {
        return getDescription(textFrame);
    }

    auto shape = dynamic_cast<Aspose::Slides::IShape*>(node);
    if(shape == nullptr)
    {
        return QString();
    }

    QString shapeDescription = getDescription(shape);

    auto geometryShape = dynamic_cast<Aspose::Slides::IGeometryShape*>(node);
    if(geometryShape)
    {
        shapeDescription += getDescription(geometryShape);
    }

    Aspose::Slides::IAudioFrame* audioFrame = dynamic_cast<Aspose::Slides::IAudioFrame*>(shape);
    if (audioFrame != nullptr)
    {
        return shapeDescription + getDescription(audioFrame);
    }

    Aspose::Slides::IVideoFrame* videoFrame = dynamic_cast<Aspose::Slides::IVideoFrame*>(shape);
    if (videoFrame != nullptr)
    {
        return shapeDescription + getDescription(videoFrame);
    }

    Aspose::Slides::Charts::IChart* chart = dynamic_cast<Aspose::Slides::Charts::IChart*>(shape);
    if (chart != nullptr)
    {
        return shapeDescription + getDescription(chart);
    }

    Aspose::Slides::IOleObjectFrame* oleObjectFrame = dynamic_cast<Aspose::Slides::IOleObjectFrame*>(shape);
    if (oleObjectFrame != nullptr)
    {
        return shapeDescription + getDescription(oleObjectFrame);
    }

    Aspose::Slides::ITable* table = dynamic_cast<Aspose::Slides::ITable*>(shape);
    if (table != nullptr)
    {
        return shapeDescription + getDescription(table);
    }

    Aspose::Slides::IZoomFrame* zoomFrame = dynamic_cast<Aspose::Slides::IZoomFrame*>(shape);
    if (zoomFrame != nullptr)
    {
        return shapeDescription + getDescription(zoomFrame);
    }

    Aspose::Slides::IGroupShape* groupShape = dynamic_cast<Aspose::Slides::IGroupShape*>(shape);
    if (groupShape != nullptr)
    {
        return shapeDescription + getDescription(groupShape);
    }

    Aspose::Slides::SmartArt::ISmartArt* smartArt = dynamic_cast<Aspose::Slides::SmartArt::ISmartArt*>(shape);
    if (smartArt != nullptr)
    {
        return shapeDescription + getDescription(smartArt);
    }

    return shapeDescription;
}

// Selects file name for a presentation to open or null.
QString MainWindow::selectOpenFileName()
{
    const QString filter =
        "All Supported Formats (*.ppt *.pptx *.odp *.fodp);;"
        "PowerPoint 97-2003 (*.ppt);;"
        "PowerPoint 2007 OOXML Documents (*.pptx);;"
        "OpenDocument (*.odp *.fodp);;"
        "All Files (*.*)";
    const QString fileName = QFileDialog::getOpenFileName(this, "Open Presentation", m_initialDirectory, filter);
    if (!fileName.isNull())
    {
        const QFileInfo fileInfo(fileName);
        m_initialDirectory = fileInfo.dir().path();
    }
    return fileName;
}

// Selects file name for saving currently opened presentation or null.
QString MainWindow::selectSaveFileName()
{
    const QString filter =
        "PowerPoint 97-2003 (*.ppt);;"
        "PowerPoint 2007 OOXML Documents (*.pptx);;"
        "OpenDocument (*.odp *.fodp);;"
        "PDF (*.pdf);;"
        "TIFF (*.tiff *.tif);;"
        "GIF (*.gif);;"
        "XPS Document (*.xps);;"
        "Web Page (*.html);;";
    const QFileInfo originalFileInfo(m_fileName);
    const QString templateFileName = m_initialDirectory + QDir::separator() + originalFileInfo.baseName() + ".pptx";
    const QString fileName = QFileDialog::getSaveFileName(this, "Save Presentation As", templateFileName, filter);
    if (!fileName.isNull())
    {
        const QFileInfo fileInfo(fileName);
        m_initialDirectory = fileInfo.dir().path();
    }
    return fileName;
}

void MainWindow::showNodeInfo(const QModelIndex &current)
{
    Aspose::Slides::IPresentationComponent* node = m_presentationModel->getNodePointer(current);
    if(isCanDraw(node))
    {
        if(ui->canvas->isHidden())
        {
            ui->canvas->clear();
            ui->canvas->show();

            QApplication::processEvents();
        }
        else
        {
            ui->canvas->clear();
        }

        if(ui->actionPreview->isChecked())
        {
            draw(node);
        }
    }
    else
    {
        ui->canvas->hide();
    }

    // Show the text contained by selected presentation node.
    ui->textEdit->setText(getNodeText(current));
}

void MainWindow::showErrorMessage(const QString &message)
{
    QMessageBox messageBox(QMessageBox::Critical,
                           "Presentation Explorer - unexpected error occured",
                           message, QMessageBox::Ok, this);
    messageBox.setTextInteractionFlags(Qt::TextSelectableByMouse);
    messageBox.exec();
}

void MainWindow::setMainWindowTitle()
{
    QString title = "Presentation Explorer";
    if(!m_fileName.isEmpty())
    {
        title += " - " + m_fileName;
    }

    if(m_isLicensed)
    {
        title += " (Licensed)";
    }
    else
    {
        title += " (Evaluation mode)";
    }

    setWindowTitle(title);
}

void MainWindow::ResetApplicationState()
{
    ui->canvas->clear();
    ui->canvas->show();
    ui->textEdit->clear();
    ui->treeView->reset();
    m_presentation = nullptr;
    m_presentationModel = nullptr;
    m_fileName = "";
    m_initialDirectory = "";
    setMainWindowTitle();
}

QString MainWindow::getDescription(const QString& presentationFileName, Aspose::Slides::IPresentation* presentation)
{
    if(presentationFileName.isEmpty())
    {
        return QString();
    }

    auto presentationInfo = Aspose::Slides::PresentationFactory::get_Instance()->GetPresentationInfo(Convert(presentationFileName));
    auto props = presentationInfo->ReadDocumentProperties();

    QString result;
    QTextStream description(&result);
    if(!props->get_Author().IsEmpty())
    {
        description << "Author: " << Convert(props->get_Author()) << Qt::endl;
    }
    if(!props->get_Title().IsEmpty())
    {
        description << "Title: " << Convert(props->get_Title()) << Qt::endl;
    }
    if(!props->get_PresentationFormat().IsEmpty())
    {
        description << "Format: " << Convert(props->get_PresentationFormat()) << Qt::endl;
    }
    if(!props->get_Subject().IsEmpty())
    {
        description << "Subject: " << Convert(props->get_Subject()) << Qt::endl;
    }

    description << "Slides count: " << presentation->get_Slides()->get_Count() << Qt::endl;
    description << "Images count: " << presentation->get_Images()->get_Count() << Qt::endl;
    description << "Audios count: " << presentation->get_Audios()->get_Count() << Qt::endl;
    description << "Videos count: " << presentation->get_Videos()->get_Count() << Qt::endl;

    System::SharedPtr<Aspose::Slides::ISlideSize> slideSize = presentation->get_SlideSize();

    description << Qt::endl;
    description << "Slide info: " << Qt::endl;
    description << "Width: " << slideSize->get_Size().get_Width() << Qt::endl;
    description << "Height: " << slideSize->get_Size().get_Height() << Qt::endl;
    description << "Orientation: " << Convert(System::ObjectExt::ToString(slideSize->get_Orientation())) << Qt::endl;

    description << Qt::endl;
    description << "Security info: " << Qt::endl;
    description << "Encrypted: " << BoolToQString(presentation->get_ProtectionManager()->get_IsEncrypted()) << Qt::endl;
    description << "Write protected: " << BoolToQString(presentation->get_ProtectionManager()->get_IsWriteProtected()) << Qt::endl;
    description << "Read only recommended: " << BoolToQString(presentation->get_ProtectionManager()->get_ReadOnlyRecommended()) << Qt::endl;
    description << "Have digital signatures: " << BoolToQString(presentation->get_DigitalSignatures()->get_Count() > 0) << Qt::endl;

    return result;
}

QString MainWindow::getDescription(Aspose::Slides::IShape *shape)
{
    if(shape == nullptr)
    {
        return QString();
    }

    QString result;
    QTextStream description(&result);
    description << "X: " << shape->get_X() << " Y: " << shape->get_Y() << Qt::endl;
    description << "Width: " << shape->get_Width() << " Height: " << shape->get_Height() << Qt::endl << Qt::endl;

    if(shape->get_Hidden())
    {
        description << "The shape is hidden." << Qt::endl;
    }

    description << "Fill type: " << Convert(System::ObjectExt::ToString(shape->get_FillFormat()->get_FillType())) << Qt::endl;
    description << "Solid fill color: " << Convert(System::ObjectExt::ToString(shape->get_FillFormat()->get_SolidFillColor()->get_Color())) << Qt::endl;


    return result;
}

QString MainWindow::getDescription(Aspose::Slides::IGeometryShape *geometryShape)
{
    if(geometryShape == nullptr)
    {
        return QString();
    }

    QString result;
    QTextStream description(&result);

    description << "Shape type: " << Convert(System::ObjectExt::ToString(geometryShape->get_ShapeType())) << Qt::endl;
    if(geometryShape->get_ShapeStyle())
    {
        description << "Shape style: " << Convert(System::ObjectExt::ToString(geometryShape->get_ShapeStyle()->get_FillColor()->get_Color())) << Qt::endl;
    }

    return result;
}

QString MainWindow::getDescription(Aspose::Slides::IAudioFrame* audioFrame)
{
    if(audioFrame == nullptr)
    {
        return QString();
    }

    QString result;
    QTextStream description(&result);
    description << "Content type: " << Convert(audioFrame->get_EmbeddedAudio()->get_ContentType())
                << Qt::endl;
    description << "Binary data size: " << audioFrame->get_EmbeddedAudio()->get_BinaryData()->get_Count()
                << " bytes" << Qt::endl;
    description << "Volume: " << Convert(System::ObjectExt::ToString(audioFrame->get_Volume()))
                << Qt::endl;
    description << "Play mode: " << Convert(System::ObjectExt::ToString(audioFrame->get_PlayMode()))
                << Qt::endl << Qt::endl;

    return result;
}

QString MainWindow::getDescription(Aspose::Slides::IVideoFrame *videoFrame)
{
    if(videoFrame == nullptr)
    {
        return QString();
    }

    QString result;
    QTextStream description(&result);
    description << "Content type: " << Convert(videoFrame->get_EmbeddedVideo()->get_ContentType())
                << Qt::endl;
    description << "Binary data size: " << videoFrame->get_EmbeddedVideo()->get_BinaryData()->get_Count()
                << " bytes" << Qt::endl;
    description << "Volume: " << Convert(System::ObjectExt::ToString(videoFrame->get_Volume()))
                << Qt::endl;
    description << "Play mode: " << Convert(System::ObjectExt::ToString(videoFrame->get_PlayMode()))
                << Qt::endl << Qt::endl;

    return result;
}

QString MainWindow::getDescription(Aspose::Slides::Charts::IChart *chart)
{
    if(chart == nullptr)
    {
        return QString();
    }

    QString result;
    QTextStream description(&result);
    description << "Chart type: " << Convert(System::ObjectExt::ToString(chart->get_Type()))
                << Qt::endl;
    description << "Has title: " << Convert(System::ObjectExt::ToString(chart->get_HasTitle()))
                << Qt::endl;
    description << "Has legend: " << Convert(System::ObjectExt::ToString(chart->get_HasLegend()))
                << Qt::endl;
    description << "Has data table: " << Convert(System::ObjectExt::ToString(chart->get_HasDataTable()))
                << Qt::endl;

    return result;
}

QString MainWindow::getDescription(Aspose::Slides::IOleObjectFrame *oleObjectFrame)
{
    if(oleObjectFrame == nullptr)
    {
        return QString();
    }

    QString result;
    QTextStream description(&result);
    description << "ProgID: " << Convert(oleObjectFrame->get_ObjectProgId())
                << Qt::endl;
    if(oleObjectFrame->get_IsObjectLink())
    {
        description << "Link path: " << Convert(oleObjectFrame->get_LinkPathLong())
                    << Qt::endl;
    }
    else
    {
        description << "Embedded file: " << Convert(oleObjectFrame->get_EmbeddedFileName())
                    << Qt::endl;
        description << "Embedded file label: " << Convert(oleObjectFrame->get_EmbeddedFileLabel())
                        << Qt::endl;
        description << "Embedded data size: " << oleObjectFrame->get_EmbeddedFileData()->get_Count()
                        << " bytes" << Qt::endl;
    }

    return result;
}

QString MainWindow::getDescription(Aspose::Slides::ITable *table)
{
    if(table == nullptr)
    {
        return QString();
    }

    QString result;
    QTextStream description(&result);
    description << "Rows count: " << table->get_Rows()->get_Count()
                << Qt::endl;
    description << "Columns count: " << table->get_Columns()->get_Count()
                << Qt::endl;

    return result;
}

QString MainWindow::getDescription(Aspose::Slides::IZoomFrame *zoomFrame)
{
    if(zoomFrame == nullptr)
    {
        return QString();
    }

    QString result;
    QTextStream description(&result);
    description << "Image type: " << Convert(System::ObjectExt::ToString(zoomFrame->get_ImageType()))
                << Qt::endl;
    description << "Target slide number: " << zoomFrame->get_TargetSlide()->get_SlideNumber()
                << Qt::endl;

    return result;
}

QString MainWindow::getDescription(Aspose::Slides::IGroupShape *groupShape)
{
    if(groupShape == nullptr)
    {
        return QString();
    }

    QString result;
    QTextStream description(&result);
    description << "Shapes count: " << groupShape->get_Shapes()->get_Count()
                << Qt::endl;

    return result;
}

QString MainWindow::getDescription(Aspose::Slides::SmartArt::ISmartArt *smartArt)
{
    if(smartArt == nullptr)
    {
        return QString();
    }

    QString result;
    QTextStream description(&result);
    description << "Nodes count: " << smartArt->get_AllNodes()->get_Count()
                << Qt::endl;

    return result;
}

QString MainWindow::getDescription(Aspose::Slides::IPresentation* presentation, Aspose::Slides::ISlide *slide)
{
    if(slide == nullptr)
    {
        return QString();
    }

    QString result;
    QTextStream description(&result);

    if(!slide->get_Name().IsEmpty())
    {
        description << "Name:" << Convert(slide->get_Name()) << Qt::endl;
    }

    description << "Slide number: " << slide->get_SlideNumber() << Qt::endl;
    description << "Slide id: " << slide->get_SlideId() << Qt::endl;
    description << "Shapes count: " << slide->get_Shapes()->get_Count() << Qt::endl;

    if(slide->get_Controls()->get_Count() != 0)
    {
        description << "ActiveX controls count: " << slide->get_Controls()->get_Count() << Qt::endl;
    }

    description << "Slide show transition type: " << Convert(System::ObjectExt::ToString(slide->get_SlideShowTransition()->get_Type())) << Qt::endl;

    if(slide->get_LayoutSlide())
    {
        description << "Layout type: " << Convert(System::ObjectExt::ToString(slide->get_LayoutSlide()->get_LayoutType())) << Qt::endl;
    }

    if(slide->GetSlideComments(nullptr)->get_Count() == 0)
    {
        return result;
    }

    description << Qt::endl << "Comments:" << Qt::endl << Qt::endl;
    for(const auto& commentAuthor : presentation->get_CommentAuthors())
    {
        for (const auto& comment : slide->GetSlideComments(commentAuthor) )
        {
            description << Convert(comment->get_Author()->get_Name());
            description << " :" << Qt::endl;
            description << Convert(comment->get_Text()) << Qt::endl;
        }
    }

    return result;
}

QString MainWindow::getDescription(Aspose::Slides::ITextFrame *textFrame)
{
    if(textFrame == nullptr)
    {
        return QString();
    }

    QString result;
    QTextStream description(&result);

    if(textFrame->get_Text().get_Length() != 0)
    {
        description << "Text:" << Qt::endl;
        description << Convert(textFrame->get_Text());
    }

    return result;
}

