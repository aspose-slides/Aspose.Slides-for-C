#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <DOM/IPresentation.h>
#include <memory>
#include "presentation_model.h"
#include <DOM/ILegacyDiagram.h>
#include <DOM/ITextFrame.h>
#include <DOM/IGeometryShape.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// The main window of the PresentationExplorer demo.
//
// PresentationExplorer allows to open presentation using Aspose.Slides.
// Once a presentation is opened, you can explore its object model in the tree.
// You can also save the presentation into PPT, PPTX, ODP, FODP, PDF, TIFF, GIF, XPS, HTML formats
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();
    void on_actionSaveAs_triggered();
    void on_actionPreview_triggered();
    void on_actionExit_triggered();
    void on_actionExpandAll_triggered();
    void on_actionCollapseAll_triggered();
    void on_actionAbout_triggered();
    void on_actionLoadLicense_triggered();

    void treeView_currentChanged(const QModelIndex &current, const QModelIndex &previous);

private:
    Ui::MainWindow *ui;

    // The currently opened presentation.
    System::SharedPtr<Aspose::Slides::IPresentation> m_presentation;

    // Hierarchical model of the opened presentation.
    std::unique_ptr<PresentationModel> m_presentationModel;

    // Last selected directory in the open and save dialogs.
    QString m_initialDirectory;
    // Last selected presentation path.
    QString m_fileName;
    // Indicates if the library is licensed.
    bool m_isLicensed;

    void openPresentation();
    void savePresentation();
    void loadLicense();
    bool isCanDraw(Aspose::Slides::IPresentationComponent* node);
    void draw(Aspose::Slides::IPresentationComponent* node);
    void expandAllNodes();
    void collapseAllNodes();
    void collapseNodesRecursively(const QModelIndex& parent);
    QString getNodeText(const QModelIndex& index) const;
    QString selectOpenFileName();
    QString selectSaveFileName();
    void showNodeInfo(const QModelIndex &current);
    void showErrorMessage(const QString& message);

    void setMainWindowTitle();
    void ResetApplicationState();

    bool licenseAsposeSlides(const QString& licenseFile);
    static QString getDescription(const QString& presentationFileName, Aspose::Slides::IPresentation* presentation);
    static QString getDescription(Aspose::Slides::IPresentation* presentation, Aspose::Slides::ISlide* slide);
    static QString getDescription(Aspose::Slides::ITextFrame* textFrame);
    static QString getDescription(Aspose::Slides::IShape* shape);
    static QString getDescription(Aspose::Slides::IGeometryShape* geometryShape);
    static QString getDescription(Aspose::Slides::IAudioFrame* audioFrame);
    static QString getDescription(Aspose::Slides::IVideoFrame* videoFrame);
    static QString getDescription(Aspose::Slides::Charts::IChart* chart);
    static QString getDescription(Aspose::Slides::IOleObjectFrame* oleObjectFrame);
    static QString getDescription(Aspose::Slides::ITable* table);
    static QString getDescription(Aspose::Slides::IZoomFrame* zoomFrame);
    static QString getDescription(Aspose::Slides::IGroupShape* groupShape);
    static QString getDescription(Aspose::Slides::SmartArt::ISmartArt* smartArt);
};
#endif // MAINWINDOW_H
