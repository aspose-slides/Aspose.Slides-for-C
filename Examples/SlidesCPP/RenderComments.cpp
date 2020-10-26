#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;

using namespace System;
using namespace IO;
using namespace System::Drawing::Imaging;
using namespace System::Drawing;

void RenderComments()
{
    //ExStart:RenderComments

    // The path to the documents directory.
    const String templatePath = u"../templates/comments.pptx";
    const String outPath = u"../out/OutPresBitmap_Comments.png";

    // Instantiate Presentation class
    SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

    //Create bitmap object
    auto bmp = MakeObject<Bitmap>(740, 960);
    SharedPtr<Graphics> graphics = Graphics::FromImage(bmp);

    // Access the first slide
    SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

    SharedPtr<IRenderingOptions> renderOptions = System::MakeObject<RenderingOptions>();
    renderOptions->get_NotesCommentsLayouting()->set_CommentsAreaColor(Color::get_Red());
    renderOptions->get_NotesCommentsLayouting()->set_CommentsAreaWidth(200);
    renderOptions->get_NotesCommentsLayouting()->set_CommentsPosition(CommentsPositions::Right);
    renderOptions->get_NotesCommentsLayouting()->set_NotesPosition(NotesPositions::BottomTruncated);

    // Access and render the first slide
    pres->get_Slides()->idx_get(0)->RenderToGraphics(renderOptions, graphics);
    try
    {
        bmp->Save(outPath, ImageFormat::get_Png());
    }
    catch (Exception e)
    {
        Console::WriteLine(u"Exception " + e->get_Message());
    }
    //ExEnd:RenderComments
}
