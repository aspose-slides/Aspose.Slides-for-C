#include "about_dialog.h"
#include "ui_about_dialog.h"

#include "hidpisupport.h"

AboutDialog::AboutDialog(const QString& version, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);

    ui->labelLogo->setMaximumSize(ui->labelLogo->maximumSize() * HiDpiSupport::getImageScaleFactor());
    ui->versionLabel->setText("Version " + version);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
