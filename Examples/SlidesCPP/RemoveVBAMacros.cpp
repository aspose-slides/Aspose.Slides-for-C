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
#include <DOM/Table/ITable.h>
#include <DOM/Table/ICell.h>
#include <DOM/Table/ICellCollection.h>
#include <DOM/Table/IRow.h>
#include <DOM/Table/IRowCollection.h>
#include <DOM/Table/IColumn.h>
#include <DOM/Table/IColumnCollection.h>

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
#include <DOM/Vba/IVbaProject.h>
#include <DOM/Vba/IVbaModule.h>
#include <DOM/Vba/IVbaModuleCollection.h>
#include <DOM/Vba/VbaReferenceOleTypeLib.h>
#include <DOM/Vba/IVbaReferenceCollection.h>


#include <system/object.h>
#include <system/object_ext.h>
#include <system/special_casts.h>
#include <system/io/path.h>
#include <drawing/imaging/image_format.h>
#include <system/string.h>
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Aspose::Slides::Vba;
using namespace System;
using namespace System::Drawing;


void RemoveVBAMacros()
{

	// ExStart:RemoveVBAMacros
	// The path to the documents directory.
	const String outPath = u"../out/RemoveVBAMacros_out.pptm";
	const String templatePath = u"../templates/vba.pptm";

	// Load the desired the presentation
	SharedPtr<Presentation> presentation = MakeObject<Presentation>(templatePath);

	// Access the Vba module and remove 
	presentation->get_VbaProject()->get_Modules()->Remove(presentation->get_VbaProject()->get_Modules()->idx_get(0));

	// Save PPTX to Disk
	presentation->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptm);


	// ExEnd:RemoveVBAMacros
}
