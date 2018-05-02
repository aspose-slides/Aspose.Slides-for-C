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
#include <DOM/LoadOptions.h>
#include <LoadFormat.h>


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


void DefaultFonts()
{

	// ExStart:DefaultFonts
	// The path to the documents directory.
	const String outPath = u"../out/DefaultFonts_out.pptx";
	const String tempplatePath = u"../templates/DefaultFonts.pptx";

	// Use load options to define the default regualr and asian fonts// Use load options to define the default regualr and asian fonts
	SharedPtr<LoadOptions> loadOptions = MakeObject< LoadOptions>(LoadFormat::Auto);
	loadOptions->set_DefaultRegularFont(u"Wingdings");
	loadOptions->set_DefaultAsianFont(u"Wingdings");


	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(tempplatePath,loadOptions);

	// Generate slide thumbnail
	pres->get_Slides()->idx_get(0)->GetThumbnail(1, 1)->Save(u"../out/DefaultFonts_out.png", System::Drawing::Imaging::ImageFormat::get_Png());

	// Generate PDF
	pres->Save(u"../out/DefaultFonts_out.pdf", Aspose::Slides::Export::SaveFormat::Pdf);

	// Generate XPS
	pres->Save(u"../out/DefaultFonts_out.xps", Aspose::Slides::Export::SaveFormat::Xps);

	// ExEnd:DefaultFonts
}
