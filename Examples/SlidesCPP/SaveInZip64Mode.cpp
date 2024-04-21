#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System::IO;

void SaveInZip64Mode()
{
    //ExStart:SaveInZip64Mode
    const System::String outFilePath = Path::Combine(GetOutPath(), u"PresentationZip64.pptx");

    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    System::SharedPtr<PptxOptions> pptxOptions = System::MakeObject<PptxOptions>();
    pptxOptions->set_Zip64Mode(Zip64Mode::Always);

    pres->Save(outFilePath, SaveFormat::Pptx, pptxOptions);
    //ExEnd:SaveInZip64Mode
}
