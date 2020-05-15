#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void ExtractVideo()
{
	// ExStart:ExtractVideo
	// The path to the documents directory.
	const String templatePath = u"../templates/Video.pptx";
	const String outPath = u"../out/Video_out";
	// The path to the documents directory.
	String dataDir = u"replace_with_the_correct_path";

	// Instantiate a Presentation object that represents a presentation file 
	SharedPtr<Presentation> presentation = System::MakeObject<Presentation>(templatePath);

	{
		auto slide_enumerator = (presentation->get_Slides())->GetEnumerator();
		decltype(slide_enumerator->get_Current()) slide;
		while (slide_enumerator->MoveNext() && (slide = slide_enumerator->get_Current(), true))
		{
			auto shape_enumerator = (presentation->get_Slides()->idx_get(0)->get_Shapes())->GetEnumerator();
			decltype(shape_enumerator->get_Current()) shape;
			while (shape_enumerator->MoveNext() && (shape = shape_enumerator->get_Current(), true))
			{
				if (ObjectExt::Is<VideoFrame>(shape))
				{
					SharedPtr<VideoFrame> vf = System::DynamicCast_noexcept<VideoFrame>(shape);
					String type = vf->get_EmbeddedVideo()->get_ContentType();
					int32_t ss = type.LastIndexOf(L'/');
					type = type.Remove(0, type.LastIndexOf(L'/') + 1);
					ArrayPtr<uint8_t> buffer = vf->get_EmbeddedVideo()->get_BinaryData();
					{
						SharedPtr<IO::FileStream> stream = System::MakeObject<IO::FileStream>(outPath + type, IO::FileMode::Create, IO::FileAccess::Write, IO::FileShare::Read);

						// Clearing resources under 'using' statement
						//System::Details::DisposeGuard __dispose_guard_0{ stream, ASPOSE_CURRENT_FUNCTION };
						// ------------------------------------------
						stream->Write(buffer, 0, buffer->get_Length());
					}
				}
			}
		}
	}

	//ExEnd:ExtractVideo
}
