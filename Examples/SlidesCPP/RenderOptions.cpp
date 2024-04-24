#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System::IO;

void RenderOptions()
{
    // ExStart:RenderOptions
    // The path to the documents directory.
    const System::String outPath = GetOutPath();
    const System::String presPath = Path::Combine(GetDataPath(), u"RenderingOptions.pptx");

    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(presPath);
    System::SharedPtr<ISlide> slide = pres->get_Slide(0);
        
    System::SharedPtr<IRenderingOptions> renderingOpts = System::MakeObject<RenderingOptions>();
    System::SharedPtr<INotesCommentsLayoutingOptions> notesCommentsOpts = System::MakeObject<NotesCommentsLayoutingOptions>();
    notesCommentsOpts->set_NotesPosition(NotesPositions::BottomTruncated);
    renderingOpts->set_SlidesLayoutOptions(notesCommentsOpts);

    float scale = 4 / 3.f;

    auto image = slide->GetImage(renderingOpts, scale, scale);
    image->Save(Path::Combine(outPath, u"RenderingOptions-Slide1-Original.png"), ImageFormat::Png);

    notesCommentsOpts->set_NotesPosition(NotesPositions::None);
    renderingOpts->set_DefaultRegularFont(u"Arial Black");
    auto arialbImage = slide->GetImage(renderingOpts, scale, scale);
    arialbImage->Save(Path::Combine(outPath, u"RenderingOptions-Slide1-ArialBlackDefault.png"), ImageFormat::Png);

    renderingOpts->set_DefaultRegularFont(u"Arial Narrow");
    auto arialnImage = slide->GetImage(renderingOpts, scale, scale);
    arialnImage->Save(Path::Combine(outPath, u"RenderingOptions-Slide1-ArialNarrowDefault.png"), ImageFormat::Png);
    // ExEnd:RenderOptions
}
