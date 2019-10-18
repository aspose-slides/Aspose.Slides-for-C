#include <system/object_ext.h>
#include<Dom/ProtectionManager.h>
#include <DOM/Presentation.h>
#include<Dom/IProtectionManager.h>
#include <Export/SaveFormat.h>
#include<Dom/CommonSlideViewProperties.h>
#include "SlidesExamples.h"
#include <DOM/IAutoShape.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IShapeCollection.h>
#include <DOM/ShapeType.h>

#include <system/io/file_stream.h>
#include <system/io/file_share.h>
#include <system/io/file_mode.h>
#include <system/io/file_access.h>

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;

using namespace System;
using namespace System::IO;

void SaveToStream() {

	//ExStart:SaveToStream

	const String outPath = u"../out/Save_As_Stream_out.pptx";

	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	SharedPtr<IAutoShape> shape = pres->get_Slides()->idx_get(0)->get_Shapes()->AddAutoShape(Aspose::Slides::ShapeType::Rectangle, 200, 200, 200, 200);
	/// Load the video file to stream
	System::SharedPtr<System::IO::Stream> stream = System::MakeObject<System::IO::FileStream>(outPath, System::IO::FileMode::Create);

	pres->Save(stream, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:SaveToStream

}