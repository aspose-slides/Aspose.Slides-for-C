#include <QtWidgets/QApplication>
#include <QtWidgets/QtWidgets>

#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/ISlide.h>

#include <drawing/imaging/image_format.h>
#include <system/string.h>
#include <drawing/bitmap.h>
#include <system/io/directory.h>

#include "../../Source/QtHelpers/qtcorehelpers.h"

using namespace Aspose::Slides;

using Aspose::QtHelpers::Convert;
using System::Drawing::Imaging::ImageFormat;
using System::IO::Path;

void ConvertPresentation(const QString& fileName, const QString& outputFileName, const QString& outputType)
{
    auto pres = System::MakeObject<Presentation>(Convert(fileName));

    System::String output = Convert(outputFileName);

    if (outputType == "Pdf")
    {
        pres->Save(output, Export::SaveFormat::Pdf);
    }
    else if (outputType == "Xps")
    {
        pres->Save(output, Export::SaveFormat::Xps);
    }
    else if (outputType == "Swf")
    {
        pres->Save(output, Export::SaveFormat::Swf);
    }
    else if (outputType == "Html")
    {
        pres->Save(output, Export::SaveFormat::Html);
    }
    else if (outputType == "Png")
    {
        for(int i = 0; i < pres->get_Slides()->get_Count(); ++i)
        {
            System::String outputSlideName = Path::GetFileNameWithoutExtension(output) + u"_" + System::ObjectExt::ToString(i) + Path::GetExtension(output);
            System::String outputSlidePath = Path::Combine(Path::GetDirectoryName(output), outputSlideName);
            pres->get_Slides()->idx_get(i)->GetThumbnail(2.0f, 2.0f)->Save(outputSlidePath, ImageFormat::get_Png());
        }
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *ui = new QWidget();

    QLineEdit *txtFileName = new QLineEdit();
    QPushButton *loadButton = new QPushButton("...");
    QObject::connect(loadButton, &QPushButton::clicked, [txtFileName]() {
        txtFileName->setText(QFileDialog::getOpenFileName());
    });

    QComboBox *formatCombo = new QComboBox();
    formatCombo->addItems({
        "Pdf",
        "Xps",
        "Swf",
        "Html",
        "Png"
        });
    QPushButton *convertButton = new QPushButton("Convert");
    QObject::connect(convertButton, &QPushButton::clicked, [txtFileName, formatCombo]() {
        QString fileName = txtFileName->text();
        QString outputType = formatCombo->currentText();
        QFileInfo info(fileName);
        QString outputFile = info.path() + "/" + info.completeBaseName() + "." + outputType;
        if (outputFile == fileName)
            return;
        outputFile = QFileDialog::getSaveFileName(nullptr, "Select converted file name", outputFile);
        ConvertPresentation(txtFileName->text(), outputFile, outputType);
        QMessageBox::information(nullptr, "Information", QString("File %1 Converted into %2").arg(fileName, outputFile));
    });

    QLabel* saveAsLabel = new QLabel("Save As");
    saveAsLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QLabel* selectedFileLabel = new QLabel("Selected file");

    QGridLayout *grid = new QGridLayout(ui);
    grid->setVerticalSpacing(15);

    grid->addWidget(selectedFileLabel, 0, 0, 1, 1);
    grid->addWidget(txtFileName, 0, 1, 1, 2);
    grid->setColumnStretch(1, 2);
    grid->addWidget(loadButton, 0, 3);
    grid->addWidget(saveAsLabel, 1, 1);
    grid->addWidget(formatCombo, 1, 2);
    grid->addWidget(convertButton, 1, 3);
    ui->setLayout(grid);

    ui->setWindowTitle("Aspose.Slides for C++ sample Qt application");
    ui->show();
     
    return a.exec();
}
