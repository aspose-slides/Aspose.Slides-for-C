#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace IO;

void ExtractVideo()
{
	// ExStart:ExtractVideo
	// The path to the documents directory.
	const String templatePath = Path::Combine(GetDataPath(), u"Video.pptx");
	const String outPath = Path::Combine(GetOutPath(), u"Video_out");
	
	// Instantiate a Presentation object that represents a presentation file 
	SharedPtr<Presentation> presentation = System::MakeObject<Presentation>(templatePath);

	for (auto slide : presentation->get_Slides())
	{
		for (auto shape: slide->get_Shapes())
		{
			if (ObjectExt::Is<VideoFrame>(shape))
			{
				SharedPtr<VideoFrame> vf = System::DynamicCast_noexcept<VideoFrame>(shape);
				String type = vf->get_EmbeddedVideo()->get_ContentType();
				type = type.Remove(0, type.LastIndexOf(L'/') + 1);
				ArrayPtr<uint8_t> buffer = vf->get_EmbeddedVideo()->get_BinaryData();
				
				auto stream = System::MakeObject<FileStream>(outPath + type, FileMode::Create, FileAccess::Write, FileShare::Read);
				stream->Write(buffer, 0, buffer->get_Length());
			}
		}
	}

	//ExEnd:ExtractVideo
}
