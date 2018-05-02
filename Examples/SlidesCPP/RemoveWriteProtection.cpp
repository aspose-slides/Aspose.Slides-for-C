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
void RemoveWriteProtection () {

	//ExStart:RemoveWriteProtection

	const String outPath = u"../out/RemoveWriteProtection_out.ppt";
	const String templatePath = u"../templates/RemoveWriteProtection.pptx";
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	if (pres->get_ProtectionManager()->get_IsWriteProtected()) {

		pres->get_ProtectionManager()->RemoveWriteProtection();
	}
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);
	
	//ExEnd:RemoveWriteProtection

}