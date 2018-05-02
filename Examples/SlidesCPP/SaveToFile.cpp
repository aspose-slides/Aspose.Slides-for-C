#include <system/object_ext.h>
#include<Dom/ProtectionManager.h>
#include <DOM/Presentation.h>
#include<Dom/IProtectionManager.h>
#include <Export/SaveFormat.h>
#include<Dom/CommonSlideViewProperties.h>
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;

using namespace System;
void SaveToFile() {

	//ExStart:SaveToFile

	const String outPath = u"../out/SaveToFile_out.ppt";
	
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	//pres->get_ProtectionManager()->Encrypt(u"pass");
	//...do some work here..

	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:SaveToFile

}