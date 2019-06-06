

#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IMasterSlideCollection.h>
#include <DOM/ISlide.h>
#include <DOM/ILayoutSlide.h>
#include <DOM/IGlobalLayoutSlideCollection.h>
#include <DOM/SplitterBarStateType.h>
#include <DOM/IViewProperties.h>
#include <DOM/INormalViewProperties.h>
#include <DOM/INormalViewRestoredProperties.h>
#include "SlidesExamples.h"
using namespace Aspose::Slides;

using namespace System;

void ManagePresenetationNormalViewState()
{
	//ExStart:ManagePresenetationNormalViewState

	System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

	pres->get_ViewProperties()->get_NormalViewProperties()->set_HorizontalBarState(Aspose::Slides::SplitterBarStateType::Restored);
	pres->get_ViewProperties()->get_NormalViewProperties()->set_VerticalBarState(Aspose::Slides::SplitterBarStateType::Maximized);

	pres->get_ViewProperties()->get_NormalViewProperties()->get_RestoredTop()->set_AutoAdjust(true);
	pres->get_ViewProperties()->get_NormalViewProperties()->get_RestoredTop()->set_DimensionSize(80.0f);
	pres->get_ViewProperties()->get_NormalViewProperties()->set_ShowOutlineIcons(true);

	pres->Save(u"../out/presentation.pptx", Aspose::Slides::Export::SaveFormat::Pptx);
	//ExEnd:ManagePresenetationNormalViewState

}