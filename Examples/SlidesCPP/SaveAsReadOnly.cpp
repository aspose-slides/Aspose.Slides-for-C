#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;

void SaveAsReadOnly()
{
	//ExStart:SaveAsReadOnly

	const String outPath = u"../out/SaveAsReadOnly_out.ppt";
	
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	pres->get_ProtectionManager()->SetWriteProtection(u"test");

	pres->Save(outPath, SaveFormat::Pptx);

	//ExEnd:SaveAsReadOnly
}