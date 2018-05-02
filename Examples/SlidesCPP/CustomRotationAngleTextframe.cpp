#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IMasterSlideCollection.h>
#include <DOM/IMasterSlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/ShapeType.h>
#include <DOM/Background.h>
#include <DOM/BackgroundType.h>
#include <DOM/GradientFormat.h>
#include <DOM/FillFormat.h>
#include <DOM/ILineFormat.h>
#include <DOM/ILineFillFormat.h>
#include <DOM/PictureFillFormat.h>
#include <DOM/PictureFillMode.h>
#include <DOM/IPPImage.h>
#include <DOM/IImageCollection.h>
#include <DOM/ISlidesPicture.h>
#include <DOM/IColorFormat.h>
#include <DOM/IAutoShape.h>
#include <DOM/AutoShape.h>
#include <DOM/IEffectFormat.h>
#include <DOM/Effects/IOuterShadow.h>
#include <DOM/SchemeColor.h>
#include <DOM/ColorType.h>
#include <DOM/Chart/Chart.h>
#include <DOM/Chart/ChartType.h>
#include <DOM/Chart/IChartSeriesCollection.h>
#include <DOM/Chart/IChartSeries.h>
#include <DOM/Chart/IChartData.h>
#include <DOM/Chart/IDataLabelCollection.h>
#include <DOM/Chart/IDataLabelFormat.h>
#include <DOM/Chart/IChartTextFormat.h>
#include <DOM/Chart/IChartTextBlockFormat.h>
#include <DOM/Chart/IChartTitle.h>


#include <DOM/FillType.h>
#include <DOM/TileFlip.h>
#include <drawing/imaging/image_format.h>
#include <DOM/Shape.h>
#include <DOM/Presentation.h>
#include <DOM/ITextFrame.h>
#include <DOM/ISlideCollection.h>
#include <DOM/ISlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/IShape.h>
#include <DOM/TextVerticalType.h>
#include <DOM/TextAnchorType.h>
#include <DOM/IPortionCollection.h>
#include <DOM/IPortion.h>
#include <DOM/IPortionFormat.h>
#include <DOM/IParagraphCollection.h>
#include <DOM/IParagraph.h>
#include <DOM/ITextFrameFormat.h>


#include <system/object.h>
#include <system/object_ext.h>
#include <system/special_casts.h>
#include <system/io/path.h>
#include <drawing/imaging/image_format.h>
#include <system/string.h>

#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Aspose::Slides::Charts;
using namespace System;
using namespace System::Drawing;

const int NodesCount = 5;

void CustomRotationAngleTextframe()
{

	// ExStart:CustomRotationAngleTextframe
	// The path to the documents directory.
	const String outPath = u"../out/CustomRotationAngleTextframe_out.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> sld = pres->get_Slides()->idx_get(0);

	// Add an AutoShape of Rectangle type
	SharedPtr<IChart>  chart = sld->get_Shapes()->AddChart(ChartType::ClusteredColumn, 50, 50, 500, 300);

	SharedPtr<IChartSeries> series = chart->get_ChartData()->get_Series()->idx_get(0);

	series->get_Labels()->get_DefaultDataLabelFormat()->set_ShowValue(true);
	series->get_Labels()->get_DefaultDataLabelFormat()->get_TextFormat()->get_TextBlockFormat()->set_RotationAngle(65);

	chart->set_HasTitle (true);
	chart->get_ChartTitle()->AddTextFrameForOverriding(u"Custom title")->get_TextFrameFormat()->set_RotationAngle ( -30);

	// Save PPTX to Disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);


	// ExEnd:CustomRotationAngleTextframe
}
