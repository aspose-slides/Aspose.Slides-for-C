#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void ManagePresenetationNormalViewState()
{
	//ExStart:ManagePresenetationNormalViewState

	SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

	pres->get_ViewProperties()->get_NormalViewProperties()->set_HorizontalBarState(SplitterBarStateType::Restored);
	pres->get_ViewProperties()->get_NormalViewProperties()->set_VerticalBarState(SplitterBarStateType::Maximized);

	pres->get_ViewProperties()->get_NormalViewProperties()->get_RestoredTop()->set_AutoAdjust(true);
	pres->get_ViewProperties()->get_NormalViewProperties()->get_RestoredTop()->set_DimensionSize(80.0f);
	pres->get_ViewProperties()->get_NormalViewProperties()->set_ShowOutlineIcons(true);

	pres->Save(u"../out/presentation.pptx", Export::SaveFormat::Pptx);
	//ExEnd:ManagePresenetationNormalViewState
}
