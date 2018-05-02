#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IShapeCollection.h>
#include <DOM/ShapeType.h>
#include <DOM/IAutoShape.h>
//#include <DOM/IVideoCollection.h>
//#include <DOM/IVideo.h>
#include <DOM/VideoCollection.h>
#include <DOM/Video.h>

#include <DOM/FillType.h>
#include <DOM/TileFlip.h>
#include <drawing/imaging/image_format.h>
#include <DOM/Shape.h>
#include <DOM/Presentation.h>
#include <DOM/ITextFrame.h>
#include <DOM/ISlideCollection.h>
#include <DOM/ISlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/IShape.h>
#include <DOM/NullableBool.h>
#include <DOM/IVideoFrame.h>
#include <LoadingStreamBehavior.h>

#include <system/io/file_stream.h>
#include <system/io/file_share.h>
#include <system/io/file_mode.h>
#include <system/io/file_access.h>

#include <system/object.h>
#include <system/object_ext.h>
#include <system/special_casts.h>
#include <system/io/path.h>
#include <drawing/imaging/image_format.h>
#include <system/string.h>

#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;
using namespace System::IO;

// ExStart:AddBlobToPresentation

void AddBlobToPresentation()
{
	// ExStart:AddBlobToPresentation

	// The path to the documents directory.
	const String outPath = u"../out/AddBlobToPresentation_out.pptx";
	const String filePath = u"../templates/Wildlife.mp4";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	//Loading very large video
	auto data = GetFileByteData(filePath);

	// Load the video file to stream
	System::SharedPtr<System::IO::Stream> stream = System::MakeObject<System::IO::FileStream>(filePath, System::IO::FileMode::Open, System::IO::FileAccess::Read);

	// Embedd vide inside presentation
	System::SharedPtr<IVideo> video = pres->get_Videos()->AddVideo(stream,  LoadingStreamBehavior::KeepLocked);

	//Adding video	
	slide->get_Shapes()->AddVideoFrame(0, 0, 480, 270, video);

	//Write the PPTX file to disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:AddBlobToPresentation

}

