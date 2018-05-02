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
#include <DOM/Vba/VbaProject.h>
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


void AddVBAMacros()
{

	// ExStart:AddVBAMacros
	// The path to the documents directory.
	const String outPath = u"../out/AddVBAMacros_out.pptm";

	// Load the desired the presentation
	SharedPtr<Presentation> presentation = MakeObject<Presentation>();
	// Create new VBA Project
	presentation->set_VbaProject(MakeObject<VbaProject>());

	// Add empty module to the VBA project
	SharedPtr<IVbaModule> module = presentation->get_VbaProject()->get_Modules()->AddEmptyModule(u"Module");

	// Set module source code
	module->set_SourceCode(u"Sub Test(oShape As Shape) MsgBox \"Test\" End Sub");

	// Create reference to <stdole>
	SharedPtr<VbaReferenceOleTypeLib> stdoleReference =
		MakeObject<VbaReferenceOleTypeLib>(u"stdole", u"*\\G{00020430-0000-0000-C000-000000000046}#2.0#0#C:\\Windows\\system32\\stdole2.tlb#OLE Automation");

	// Create reference to Office
	SharedPtr<VbaReferenceOleTypeLib> officeReference =
		MakeObject<VbaReferenceOleTypeLib>(u"Office", u"*\\G{2DF8D04C-5BFA-101B-BDE5-00AA0044DE52}#2.0#0#C:\\Program Files\\Common Files\\Microsoft Shared\\OFFICE14\\MSO.DLL#Microsoft Office 14.0 Object Library");

	// Add references to the VBA project
	presentation->get_VbaProject()->get_References()->Add(stdoleReference);
	presentation->get_VbaProject()->get_References()->Add(officeReference);

	// Save PPTX to Disk
	presentation->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptm);


	// ExEnd:AddVBAMacros
}
