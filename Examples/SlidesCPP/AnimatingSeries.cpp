#include <system/object_ext.h>

#include <DOM/Presentation.h>
#include <DOM/ISlide.h>
#include <DOM/IChart.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IShapeCollection.h>
#include <DOM/Chart/ChartType.h>
#include <DOM/NullableBool.h>
#include <DOM/Chart/ChartTitle.h>
#include <DOM/Chart/IChartData.h>
#include <DOM/ITextFrame.h>
#include <DOM/ITextFrameFormat.h>
#include <DOM/Chart/Chart.h>
#include <DOM/Chart/IAxis.h>
#include <DOM/Chart/IAxesManager.h>
#include <DOM/Chart/IChartCategoryCollection.h>
#include <DOM/Chart/IChartDataWorkbook.h>
#include <DOM/Chart/IChartSeriesCollection.h>
#include <DOM/Chart/IDataLabelCollection.h>
#include <DOM/Chart/DisplayUnitType.h>
#include <DOM/Chart/IChartDataPointCollection.h>
#include <DOM/Chart/ErrorBarValueType.h>
#include <DOM/Chart/IErrorBarsFormat.h>
#include <DOM/Chart/DataSourceType.h>
#include <DOM/Chart/DataSourceTypeForErrorBarsCustomValues.h>
#include <DOM/Chart/ErrorBarsCustomValues.h>
#include <DOM/Chart/IDoubleChartValue.h>
#include <DOM/Chart/ErrorBarType.h>
#include <DOM/Chart/IDoubleChartValue.h>
#include <DOM/Chart/IFormat.h>
#include <DOM/ILineFormat.h>
#include <DOM/Chart/IDataLabelFormat.h>

#include <DOM/Animation/ISequence.h>
#include <DOM/Animation/EffectType.h>
#include <DOM/Animation/EffectSubtype.h>
#include <DOM/Animation/EffectTriggerType.h>
#include <DOM/Animation/EffectChartMinorGroupingType.h>
#include <DOM/Animation/EffectChartMajorGroupingType.h>

#include <DOM/Animation/AnimationTimeLine.h>
#include <DOM/Animation/Sequence.h>
//#include <DOM/Animation/EffectChartMinorGroupingType.h>
//#include <DOM/Animation/EffectChartMinorGroupingType.h>



#include <Export/SaveFormat.h>


#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Charts;
using namespace Aspose::Slides::Animation;

using namespace System;

void AnimatingSeries()
{
	//ExStart:AnimatingSeries

	// The path to the documents directory.
	const String templatePath = u"../templates/ExistingChart.pptx";
	const String outPath = u"../out/AnimatingSeries.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	//Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Add chart with default data
	auto chart = DynamicCast<Aspose::Slides::Charts::Chart>(slide->get_Shapes()->idx_get(0));

	// Animate series
	slide->get_Timeline()->get_MainSequence()->AddEffect(chart, EffectType::Fade, EffectSubtype::None, EffectTriggerType::AfterPrevious);

	auto sequence = DynamicCast<Aspose::Slides::Animation::Sequence>(slide->get_Timeline()->get_MainSequence());

	sequence->AddEffect(chart,EffectChartMajorGroupingType::BySeries, 0,EffectType::Appear, EffectSubtype::None, EffectTriggerType::AfterPrevious);

	sequence->AddEffect(chart,EffectChartMajorGroupingType::BySeries, 1,EffectType::Appear, EffectSubtype::None, EffectTriggerType::AfterPrevious);

	sequence->AddEffect(chart,EffectChartMajorGroupingType::BySeries, 2,EffectType::Appear, EffectSubtype::None, EffectTriggerType::AfterPrevious);

	sequence->AddEffect(chart,EffectChartMajorGroupingType::BySeries, 3,EffectType::Appear, EffectSubtype::None, EffectTriggerType::AfterPrevious);

	// Write the presentation file to disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

//ExEnd:AnimatingSeries


}
