#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void GetShapeBevelEffectiveData()
{
	//ExStart:GetShapeBevelEffectiveData

	// The path to the documents directory.
	const String templatePath = u"../templates/Presentation1.pptx";

	SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

	SharedPtr<IThreeDFormatEffectiveData> threeDEffectiveData = pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0)->get_ThreeDFormat()->GetEffective();

	Console::WriteLine(u"= Effective shape's top face relief properties =");
	Console::WriteLine(String(u"Type: ") + ObjectExt::ToString((int)threeDEffectiveData->get_BevelTop()->get_BevelType()));
	Console::WriteLine(String(u"Width: ") + threeDEffectiveData->get_BevelTop()->get_Width());
	Console::WriteLine(String(u"Height: ") + threeDEffectiveData->get_BevelTop()->get_Height());

	//ExEnd:GetShapeBevelEffectiveData
}
