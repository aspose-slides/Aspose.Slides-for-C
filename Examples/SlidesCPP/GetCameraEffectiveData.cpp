#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void GetCameraEffectiveData()
{
    //ExStart:GetCameraEffectiveData

	// The path to the documents directory.
	const String templatePath = u"../templates/Presentation1.pptx";

	SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

	SharedPtr<IThreeDFormatEffectiveData> threeDEffectiveData = pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0)->get_ThreeDFormat()->GetEffective();

	Console::WriteLine(u"= Effective camera properties =");
	Console::WriteLine(String(u"Type: ") + ObjectExt::ToString((int)threeDEffectiveData->get_Camera()->get_CameraType()));
	Console::WriteLine(String(u"Field of view: ") + threeDEffectiveData->get_Camera()->get_FieldOfViewAngle());
	Console::WriteLine(String(u"Zoom: ") + threeDEffectiveData->get_Camera()->get_Zoom());

	//ExEnd:GetCameraEffectiveData
}
