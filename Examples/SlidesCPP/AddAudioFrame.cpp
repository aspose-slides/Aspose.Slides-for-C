#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void AddAudioFrame()
{
	// ExStart:AddAudioFrame
	// The path to the documents directory.
	const String outPath = u"../out/AudioFrameEmbed_out.pptx";
	const String filePath = u"../templates/sampleaudio.wav";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Load the wav sound file to stream
	SharedPtr<IO::FileStream> stream = System::MakeObject<IO::FileStream>(filePath, IO::FileMode::Open, IO::FileAccess::Read);

	// Add Audio Frame
	SharedPtr<IAudioFrame> af = slide->get_Shapes()->AddAudioFrameEmbedded(50, 150, 100, 100, stream);

	// Set Play Mode and Volume of the Audio
	af->set_PlayMode(AudioPlayModePreset::Auto);
	af->set_Volume (AudioVolumeMode::Loud);

	//Write the PPTX file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:AddAudioFrame
}
