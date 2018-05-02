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
void SaveAsReadOnly() {

	//ExStart:SaveAsReadOnly

	const String outPath = u"../out/SaveAsReadOnly_out.ppt";
	
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	pres->get_ProtectionManager()->SetWriteProtection(u"test");

	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:SaveAsReadOnly

}