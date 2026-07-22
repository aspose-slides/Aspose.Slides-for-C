#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void Html5PicturesCompressionExample()
{
    //ExStart:Html5PicturesCompressionExample

    // The path to the presentation.
    const String pptxFileName = Path::Combine(GetDataPath(), u"PresentationPic.pptx");
    // The path to output files
    const String html5OutFile = Path::Combine(GetOutPath(), u"PresentationPic150.html");

    SharedPtr<Presentation> pres = MakeObject<Presentation>(pptxFileName);
    SharedPtr<Html5Options> options = MakeObject<Html5Options>();
    options->set_PicturesCompression(PicturesCompression::Dpi150);

    // Save result
    pres->Save(html5OutFile, SaveFormat::Html5, options);

    //ExEnd:Html5PicturesCompressionExample
}
