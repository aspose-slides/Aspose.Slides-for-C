#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;

using namespace System::IO;
using namespace System::Drawing::Imaging;

void RenderOptions()
{
    // ExStart:RenderOptions
    // The path to the documents directory.
    const System::String outPath = GetOutPath();
    const System::String presPath = Path::Combine(GetDataPath(), u"RenderingOptions.pptx");

    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(presPath);
        
    System::SharedPtr<IRenderingOptions> renderingOpts = System::MakeObject<RenderingOptions>();
    System::SharedPtr<INotesCommentsLayoutingOptions> notesCommentsOpts = System::MakeObject<NotesCommentsLayoutingOptions>();
    notesCommentsOpts->set_NotesPosition(NotesPositions::BottomTruncated);
    renderingOpts->set_SlidesLayoutOptions(notesCommentsOpts);

    auto image = pres->get_Slides()->idx_get(0)->GetThumbnail(renderingOpts, 4 / 3.f, 4 / 3.f);
    image->Save(Path::Combine(outPath, u"RenderingOptions-Slide1-Original.png"), ImageFormat::get_Png());

    notesCommentsOpts->set_NotesPosition(NotesPositions::None);
    renderingOpts->set_DefaultRegularFont(u"Arial Black");
    auto arialbImage = pres->get_Slides()->idx_get(0)->GetThumbnail(renderingOpts, 4 / 3.f, 4 / 3.f);
    arialbImage->Save(Path::Combine(outPath, u"RenderingOptions-Slide1-ArialBlackDefault.png"), ImageFormat::get_Png());

    renderingOpts->set_DefaultRegularFont(u"Arial Narrow");
    auto arialnImage = pres->get_Slides()->idx_get(0)->GetThumbnail(renderingOpts, 4 / 3.f, 4 / 3.f);
    arialnImage->Save(Path::Combine(outPath, u"RenderingOptions-Slide1-ArialNarrowDefault.png"), ImageFormat::get_Png());
    // ExEnd:RenderOptions
}
