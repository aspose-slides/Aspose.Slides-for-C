#include <system/object_ext.h>
#include<Dom/ProtectionManager.h>
#include <DOM/Presentation.h>
#include<Dom/IViewProperties.h>
#include<ViewType.h>

#include <Export/SaveFormat.h>
#include<Dom/CommonSlideViewProperties.h>
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;

using namespace System;
void SaveAsPredefinedViewType() {

	//ExStart:SaveAsPredefinedViewType

	const String outPath = u"../out/SaveAsPredefinedViewType_out.ppt";

	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	pres->get_ViewProperties()->set_LastView(Aspose::Slides::ViewType::SlideMasterView);

	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:SaveAsPredefinedViewType

}