#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IShapeCollection.h>
#include <DOM/INotesSlideManager.h>
#include <DOM/INotesSlide.h>
#include <DOM/SlideSize.h>
#include <export/NotesCommentsLayoutingOptions.h>
#include <Export/CommentsPositions.h>
#include <Export/NotesPositions.h>


#include <drawing/imaging/image_format.h>
#include <system/string.h>
#include <system/IO/file.h>
#include <system/diagnostics/process.h>

#include <system/object.h>
#include <system/object_ext.h>
#include <system/special_casts.h>
#include <system/io/path.h>

#include <iostream>
#include <system/console.h>

#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;

using namespace System;
using namespace System::IO;
using namespace System::Drawing::Imaging;
using namespace System::Drawing;
using namespace System::Diagnostics;


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
	try {
 		bmp->Save(outPath, ImageFormat::get_Png());
	}
	catch (Exception e)
	{
		System::Console::WriteLine(u"Exception " + e.get_Message());

	}
	//ExEnd:RenderComments
}
