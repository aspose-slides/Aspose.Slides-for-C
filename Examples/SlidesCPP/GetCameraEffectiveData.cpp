#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IMasterSlideCollection.h>
#include <DOM/IMasterSlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/ShapeType.h>
#include <DOM/ITextFrameFormat.h>
#include <DOM/AutoShape.h>
#include <DOM/ITextFrame.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IThreeDFormat.h>
#include <DOM/IThreeDFormatEffectiveData.h>
#include <DOM/ICameraEffectiveData.h>

#include <system/string.h>
#include <system/console.h>

#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void GetCameraEffectiveData()
{

    //ExStart:GetCameraEffectiveData

	// The path to the documents directory.
	const String templatePath = u"../templates/Presentation1.pptx";

	System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

	System::SharedPtr<IThreeDFormatEffectiveData> threeDEffectiveData = pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0)->get_ThreeDFormat()->GetEffective();

	System::Console::WriteLine(u"= Effective camera properties =");
	System::Console::WriteLine(System::String(u"Type: ") + System::ObjectExt::ToString(threeDEffectiveData->get_Camera()->get_CameraType()));
	System::Console::WriteLine(System::String(u"Field of view: ") + threeDEffectiveData->get_Camera()->get_FieldOfViewAngle());
	System::Console::WriteLine(System::String(u"Zoom: ") + threeDEffectiveData->get_Camera()->get_Zoom());

	
	//ExEnd:GetCameraEffectiveData



}