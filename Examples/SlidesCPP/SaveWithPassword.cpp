#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;

void SaveWithPassword()
{
	//ExStart:SaveWithPassword

	const String outPath = u"../out/SaveWithPassword_out.pptx";

	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//...do some work here..

	pres->get_ProtectionManager()->Encrypt(u"pass");
	
	pres->Save(outPath, SaveFormat::Pptx);

	//ExEnd:SaveWithPassword
}
