#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;

using namespace System;
using namespace System::IO;
using namespace System::Drawing::Imaging;

void RenderOptions()
{
    // ExStart:RenderOptions
    // The path to the documents directory.
    String outPath = GetOutPath();
    String presPath = Path::Combine(GetDataPath(), u"RenderingOptions.pptx");

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>(presPath);
        
    SharedPtr<IRenderingOptions> renderingOpts = System::MakeObject<RenderingOptions>();
    renderingOpts->get_NotesCommentsLayouting()->set_NotesPosition(NotesPositions::BottomTruncated);

    auto image = pres->get_Slides()->idx_get(0)->GetThumbnail(renderingOpts, 4 / 3.f, 4 / 3.f);
    image->Save(Path::Combine(outPath, u"RenderingOptions-Slide1-Original.png"), ImageFormat::get_Png());

    renderingOpts->get_NotesCommentsLayouting()->set_NotesPosition(NotesPositions::None);
    renderingOpts->set_DefaultRegularFont(u"Arial Black");
    auto arialbImage = pres->get_Slides()->idx_get(0)->GetThumbnail(renderingOpts, 4 / 3.f, 4 / 3.f);
    arialbImage->Save(Path::Combine(outPath, u"RenderingOptions-Slide1-ArialBlackDefault.png"), ImageFormat::get_Png());

    renderingOpts->set_DefaultRegularFont(u"Arial Narrow");
    auto arialnImage = pres->get_Slides()->idx_get(0)->GetThumbnail(renderingOpts, 4 / 3.f, 4 / 3.f);
    arialnImage->Save(Path::Combine(outPath, u"RenderingOptions-Slide1-ArialNarrowDefault.png"), ImageFormat::get_Png());
    // ExEnd:RenderOptions
}
