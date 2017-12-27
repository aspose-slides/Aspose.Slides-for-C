#include <iostream>
#include <system/console.h>

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
#include <DOM/Effects/IInnerShadow.h>
#include <DOM/SchemeColor.h>
#include <DOM/ColorType.h>
#include <DOM/IShapeFrame.h>

#include <DOM/FillType.h>
#include <DOM/TileFlip.h>
#include <drawing/imaging/image_format.h>
#include <DOM/Shape.h>
#include <DOM/Presentation.h>
#include <DOM/ITextFrame.h>
#include <DOM/ISlideCollection.h>
#include <DOM/ISlide.h>
#include <DOM/IMasterSlide.h>
#include <DOM/IMasterSlideCollection.h>
#include <DOM/IMasterLayoutSlideCollection.h>
#include <DOM/ILayoutSlide.h>
#include <DOM/SlideLayoutType.h>

#include <DOM/IShapeCollection.h>
#include <DOM/IShape.h>
#include <DOM/TextVerticalType.h>
#include <DOM/TextAnchorType.h>
#include <DOM/IPortionCollection.h>
#include <DOM/IPortion.h>
#include <DOM/IPortionFormat.h>
#include <DOM/IParagraphCollection.h>
#include <DOM/IParagraph.h>
#include <DOM/IFontData.h>
#include <DOM/Fonts/FontData.h>
#include <DOM/NullableBool.h>
#include <DOM/TextUnderlineType.h>
#include <DOM/TextAutofitType.h>
#include <DOM/ITextFrameFormat.h>
#include <DOM/Effects/IOuterShadow.h>
#include <DOM/SchemeColor.h>
#include <DOM/ColorType.h>
#include <DOM/IGroupShape.h>
#include <DOM/GroupShape.h>
#include <DOM/LineStyle.h>
#include <DOM/LineDashStyle.h>
#include <DOM/LineArrowheadLength.h>
#include <DOM/LineArrowheadStyle.h>
#include <DOM/LineStyle.h>
#include <DOM/IThreeDFormat.h>
#include <DOM/ICamera.h>
#include <DOM/LightRigPresetType.h>
#include <DOM/CameraPresetType.h>
#include <DOM/ILightRig.h>
#include <DOM/ITextFrameFormat.h>
#include <DOM/Effects/IOuterShadow.h>
#include <DOM/SchemeColor.h>
#include <DOM/ColorType.h>
#include <DOM/IGroupShape.h>
#include <DOM/GroupShape.h>
#include <DOM/LineStyle.h>
#include <DOM/LineDashStyle.h>
#include <DOM/LineArrowheadLength.h>
#include <DOM/LineArrowheadStyle.h>
#include <DOM/LineStyle.h>
#include <DOM/IThreeDFormat.h>
#include <DOM/ICamera.h>
#include <DOM/LightRigPresetType.h>
#include <DOM/LightingDirection.h>

#include <DOM/CameraPresetType.h>
#include <DOM/IShapeBevel.h>
#include <DOM/BevelPresetType.h>

#include <system/io/file_stream.h>
#include <system/io/file_share.h>
#include <system/io/file_mode.h>
#include <system/io/file_access.h>

#include <system/object.h>
#include <system/object_ext.h>
#include <system/special_casts.h>
#include <system/io/path.h>
#include <drawing/imaging/image_format.h>
#include <system/string.h>


#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Aspose::Slides::Animation;
using namespace System;
using namespace System::Drawing;


void CloneShapes()
{
	// ExStart:CloneShapes

	// The path to the documents directory.
	const String outPath = L"../out/CloneShapes_out.pptx";
	const String templatePath = L"../templates/Source Frame.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Accessing shapes collection for selected slide
	SharedPtr<IShapeCollection> sourceShapes = slide->get_Shapes();

	SharedPtr<ILayoutSlide> blankLayout = pres->get_Masters()->idx_get(0)->get_LayoutSlides()->GetByType(SlideLayoutType::Blank);
	SharedPtr<ISlide> destSlide = pres->get_Slides()->AddEmptySlide(blankLayout);
	SharedPtr<IShapeCollection> destShapes = destSlide->get_Shapes();
	destShapes->AddClone(sourceShapes->idx_get(1), 50, 150 + sourceShapes->idx_get(0)->get_Height());
	destShapes->AddClone(sourceShapes->idx_get(2));
	destShapes->InsertClone(0, sourceShapes->idx_get(0), 50, 150);

	//Write the PPTX to Disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:CloneShapes

}


