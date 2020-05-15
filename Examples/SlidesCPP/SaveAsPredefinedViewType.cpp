#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;

void SaveAsPredefinedViewType()
{
	//ExStart:SaveAsPredefinedViewType

	const String outPath = u"../out/SaveAsPredefinedViewType_out.ppt";

	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	pres->get_ViewProperties()->set_LastView(ViewType::SlideMasterView);

	pres->Save(outPath, SaveFormat::Pptx);

	//ExEnd:SaveAsPredefinedViewType
}
