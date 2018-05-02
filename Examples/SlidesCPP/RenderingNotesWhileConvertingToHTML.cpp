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
void RenderingNotesWhileConvertingToHTML() {

	//ExStart:RenderingNotesWhileConvertingToHTML

	const String outPath = u"../out/HTML_Notes_out.hmtl";
	const String templatePath = u"../templates/AccessSlides.pptx";

	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	//pres->get_ProtectionManager()->Encrypt(u"pass");
	//...do some work here..

	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::HtmlNotes);

	//ExEnd:RenderingNotesWhileConvertingToHTML

}