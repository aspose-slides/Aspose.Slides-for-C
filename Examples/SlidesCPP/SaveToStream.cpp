#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;

using namespace System;
using namespace IO;

void SaveToStream()
{
	//ExStart:SaveToStream

	const String outPath = u"../out/Save_As_Stream_out.pptx";

	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	SharedPtr<IAutoShape> shape = pres->get_Slides()->idx_get(0)->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 200, 200, 200, 200);
	
	SharedPtr<Stream> stream = System::MakeObject<FileStream>(outPath, FileMode::Create);
	pres->Save(stream, SaveFormat::Pptx);

	//ExEnd:SaveToStream
}