#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;

void GetBackgroundEffectiveValues()
{
	//ExStart:GetBackgroundEffectiveValues

	const String templatePath = u"../templates/SamplePresentation.pptx";

	auto pres = System::MakeObject<Presentation>(templatePath);
	SharedPtr<IBackgroundEffectiveData> effBackground = pres->get_Slides()->idx_get(0)->CreateBackgroundEffective();
	if (effBackground->get_FillFormat()->get_FillType() == FillType::Solid)
	{
		Console::WriteLine(String(u"Fill color: ") + effBackground->get_FillFormat()->get_SolidFillColor());
	}
	else
	{
		Console::WriteLine(String(u"Fill type: ") + ObjectExt::ToString(effBackground->get_FillFormat()->get_FillType()));
	}
	//ExEnd:GetBackgroundEffectiveValues
}
