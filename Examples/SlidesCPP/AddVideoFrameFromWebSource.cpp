#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void AddVideoFrameFromWebSource()
{
	// ExStart:AddVideoFrameFromWebSource
	// The path to the documents directory.
	const String outPath = u"../out/AddVideoFrameFromWebSource_out.pptx";
	const String filePath = u"../templates/video1.avi";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add Video Frame from web source
	SharedPtr<IVideoFrame> vf = slide->get_Shapes()->AddVideoFrame(10, 10, 427, 240,u"https://www.youtube.com/embed/Tj75Arhq5ho");

	// Set Play Mode and Volume of the Video
	vf->set_PlayMode(VideoPlayModePreset::Auto);

	//Write the PPTX file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:AddVideoFrameFromWebSource
}
