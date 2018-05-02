#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/io/file_stream.h>
#include <system/io/file_share.h>
#include <system/io/file_mode.h>
#include <system/io/file_access.h>
#include <system/exceptions.h>
#include <system/enum_helpers.h>
#include <system/details/dispose_guard.h>
#include <system/collections/ienumerator.h>
#include <system/array.h>
#include <DOM/VideoFrame.h>
#include <DOM/Presentation.h>
#include <DOM/IVideoFrame.h>
#include <DOM/IVideo.h>
#include <DOM/ISlideCollection.h>
#include <DOM/ISlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/IShape.h>
#include <cstdint>
#include <system/string.h>
#include <system/IO/file.h>
#include <system/special_casts.h>
#include <system/io/path.h>
#include "SlidesExamples.h"
//#include "ExtractVideo.h"
#include <system/object.h>

using namespace Aspose::Slides;

using namespace System;


void ExtractVideo()
{
	
	// ExStart:ExtractVideo
	// The path to the documents directory.
	const String templatePath = u"../templates/Video.pptx";
	const String outPath = u"../out/Video_out";
	// The path to the documents directory.
	System::String dataDir = u"replace_with_the_correct_path";

	// Instantiate a Presentation object that represents a presentation file 
	System::SharedPtr<Presentation> presentation = System::MakeObject<Presentation>(templatePath);

	{
		auto slide_enumerator = (presentation->get_Slides())->GetEnumerator();
		decltype(slide_enumerator->get_Current()) slide;
		while (slide_enumerator->MoveNext() && (slide = slide_enumerator->get_Current(), true))
		{
			auto shape_enumerator = (presentation->get_Slides()->idx_get(0)->get_Shapes())->GetEnumerator();
			decltype(shape_enumerator->get_Current()) shape;
			while (shape_enumerator->MoveNext() && (shape = shape_enumerator->get_Current(), true))
			{
				if (System::ObjectExt::Is<VideoFrame>(shape))
				{
					System::SharedPtr<VideoFrame> vf = System::DynamicCast_noexcept<Aspose::Slides::VideoFrame>(shape);
					System::String type = vf->get_EmbeddedVideo()->get_ContentType();
					int32_t ss = type.LastIndexOf(L'/');
					type = type.Remove(0, type.LastIndexOf(L'/') + 1);
					System::ArrayPtr<uint8_t> buffer = vf->get_EmbeddedVideo()->get_BinaryData();
					{
						System::SharedPtr<System::IO::FileStream> stream = System::MakeObject<System::IO::FileStream>(outPath + type, System::IO::FileMode::Create, System::IO::FileAccess::Write, System::IO::FileShare::Read);

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
