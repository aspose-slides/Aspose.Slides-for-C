#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void RefreshThumbnailPresentation()
{
    //ExStart:RefreshThumbnailPresentation

    // Path for source presentation
    const String pptxFile = Path::Combine(GetDataPath(), u"Image.pptx");
    // Out path
    const String resultPath = Path::Combine(GetOutPath(), u"result_with_old_thumbnail.pptx");

    SharedPtr<Presentation> pres = MakeObject<Presentation>(pptxFile);
    // Remove all shapes from the slide
    pres->get_Slide(0)->get_Shapes()->Clear();

    SharedPtr<PptxOptions> pptxOptions = MakeObject<PptxOptions>();
    pptxOptions->set_RefreshThumbnail(false);
    // Save presentation
    pres->Save(resultPath, SaveFormat::Pptx, pptxOptions);

    //ExEnd:RefreshThumbnailPresentation
}
