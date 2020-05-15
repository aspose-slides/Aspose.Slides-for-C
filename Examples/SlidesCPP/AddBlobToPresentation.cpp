#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace IO;

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
	SharedPtr<Stream> stream = System::MakeObject<FileStream>(filePath, FileMode::Open, FileAccess::Read);

	// Embedd vide inside presentation
	SharedPtr<IVideo> video = pres->get_Videos()->AddVideo(stream,  LoadingStreamBehavior::KeepLocked);

	//Adding video	
	slide->get_Shapes()->AddVideoFrame(0, 0, 480, 270, video);

	//Write the PPTX file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:AddBlobToPresentation
}
