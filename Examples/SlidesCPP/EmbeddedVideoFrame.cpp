#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace System::Drawing;

void EmbeddedVideoFrame()
{
	// ExStart:EmbeddedVideoFrame
	// The path to the documents directory.
	const String outPath = u"../out/EmbeddedVideoFrame_out.pptx";
	const String filePath = u"../templates/Wildlife.mp4";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Load the video file to stream
	SharedPtr<IO::Stream> stream = System::MakeObject<IO::FileStream>(filePath, IO::FileMode::Open, IO::FileAccess::Read);
	
	// Embedd vide inside presentation
	SharedPtr<IVideo> vid = pres->get_Videos()->AddVideo(stream);

	// Add Video Frame
	SharedPtr<IVideoFrame> vf = slide->get_Shapes()->AddVideoFrame(50, 150, 300, 150, vid);

	// Set video to Video Frame
	vf->set_EmbeddedVideo(vid);

	// Set Play Mode and Volume of the Video
	vf->set_PlayMode(VideoPlayModePreset::Auto);
	vf->set_Volume(AudioVolumeMode::Loud);

	//Write the PPTX file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:EmbeddedVideoFrame
}
