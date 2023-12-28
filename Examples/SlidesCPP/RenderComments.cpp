#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;

using namespace System::IO;
using namespace System::Drawing::Imaging;
using namespace System::Drawing;

void RenderComments()
{
    //ExStart:RenderComments

    // The path to the documents directory.
    const System::String templatePath = u"../templates/comments.pptx";
    const System::String outPath = u"../out/OutPresBitmap_Comments.png";

    // Instantiate Presentation class
    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

    //Create bitmap object
    auto bmp = System::MakeObject<Bitmap>(740, 960);
    System::SharedPtr<Graphics> graphics = Graphics::FromImage(bmp);

    // Access the first slide
    System::SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

    System::SharedPtr<IRenderingOptions> renderOptions = System::MakeObject<RenderingOptions>();
    System::SharedPtr<INotesCommentsLayoutingOptions> options = System::MakeObject<NotesCommentsLayoutingOptions>();
    options->set_CommentsAreaColor(Color::get_Red());
    options->set_CommentsAreaWidth(200);
    options->set_CommentsPosition(CommentsPositions::Right);
    options->set_NotesPosition(NotesPositions::BottomTruncated);
    renderOptions->set_SlidesLayoutOptions(options);

    // Access and render the first slide
    pres->get_Slides()->idx_get(0)->RenderToGraphics(renderOptions, graphics);
    try
    {
        bmp->Save(outPath, ImageFormat::get_Png());
    }
    catch (const System::Exception& e)
    {
        System::Console::WriteLine(u"Exception " + e->get_Message());
    }
    //ExEnd:RenderComments
}
