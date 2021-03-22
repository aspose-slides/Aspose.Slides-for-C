#include <QCoreApplication>
#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>

using namespace Aspose::Slides;
using namespace Export;
using namespace System;

int main(int argc, char *argv[])
{
    String outPath = u"Presentation.pptx";

    SharedPtr<Presentation> pres = MakeObject<Presentation>();
    pres->Save(outPath, SaveFormat::Pptx);

    QCoreApplication::exit(0);
}
