#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void GetLightRigEffectiveData() 
{
	//ExStart:GetLightRigEffectiveData

	// The path to the documents directory.
	const String templatePath = u"../templates/Presentation1.pptx";

	SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

	SharedPtr<IThreeDFormatEffectiveData> threeDEffectiveData = pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0)->get_ThreeDFormat()->GetEffective();

	Console::WriteLine(u"= Effective light rig properties =");
	Console::WriteLine(String(u"Type: ") + ObjectExt::ToString((int)threeDEffectiveData->get_LightRig()->get_LightType()));
	Console::WriteLine(String(u"Direction: ") + ObjectExt::ToString((int)threeDEffectiveData->get_LightRig()->get_Direction()));

	//ExEnd:GetLightRigEffectiveData
}
