#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;

using namespace System::IO;

void ConvertToHandout()
{
    //ExStart:ConvertToHandout

    // The path to the documents directory.
    const System::String templateFilePath = Path::Combine(GetDataPath(), u"HandoutExample.pptx");
    const System::String outFilePath = Path::Combine(GetOutPath(), u"HandoutExample.pdf");

    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templateFilePath);

    // Set convertion options
    System::SharedPtr<PdfOptions> options = System::MakeObject<PdfOptions>();
    options->set_ShowHiddenSlides(true);

    // Set Handout Layouting
    System::SharedPtr<HandoutLayoutingOptions> handoutLayoutingOptions = System::MakeObject<HandoutLayoutingOptions>();
    handoutLayoutingOptions->set_Handout(HandoutType::Handouts4Horizontal);
    options->set_SlidesLayoutOptions(handoutLayoutingOptions);

    // Save result
    pres->Save(outFilePath, SaveFormat::Pdf, options);

    //ExEnd:ConvertToHandout
}
