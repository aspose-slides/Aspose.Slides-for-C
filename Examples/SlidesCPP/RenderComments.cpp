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
	const String templatePath = u"../templates/TestDeck_050.pptx";
	const String outPath = u"../out/RenderComments_out.png";

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	//Create bitmap object
	auto bmp = MakeObject<Bitmap>(740, 960);
	SharedPtr<Graphics> graphics = Graphics::FromImage(bmp);

	// Access the first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	SharedPtr<NotesCommentsLayoutingOptions>opts = MakeObject<NotesCommentsLayoutingOptions>();
	opts->set_CommentsAreaColor ( Color::get_Red());

	opts->set_CommentsAreaWidth ( 200);
	opts->set_CommentsPosition(CommentsPositions::Right);
	opts->set_NotesPosition(NotesPositions::BottomTruncated);

	// Access and render the first slide
	pres->get_Slides()->idx_get(0)->RenderToGraphics(opts, graphics);
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
