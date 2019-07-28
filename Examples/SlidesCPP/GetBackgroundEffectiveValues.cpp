#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IBackgroundEffectiveData.h>
#include <DOM/IFillFormatEffectiveData.h>
#include <DOM/FillType.h>

#include <system/console.h>
#include <system/string.h>
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;
using namespace System;


void GetBackgroundEffectiveValues()
{

	//ExStart:GetBackgroundEffectiveValues

	const String templatePath = u"../templates/SamplePresentation.pptx";
	

	auto pres = System::MakeObject<Presentation>(templatePath);
	System::SharedPtr<IBackgroundEffectiveData> effBackground = pres->get_Slides()->idx_get(0)->CreateBackgroundEffective();
	if (effBackground->get_FillFormat()->get_FillType() == Aspose::Slides::FillType::Solid)
	{
		System::Console::WriteLine(System::String(u"Fill color: ") + effBackground->get_FillFormat()->get_SolidFillColor());
	}
	else
	{
		System::Console::WriteLine(System::String(u"Fill type: ") + System::ObjectExt::ToString(effBackground->get_FillFormat()->get_FillType()));
	}
	//ExEnd:GetBackgroundEffectiveValues


}