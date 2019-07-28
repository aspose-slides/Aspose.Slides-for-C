#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IMasterSlideCollection.h>
#include <DOM/IMasterSlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/ShapeType.h>
#include <DOM/IGroupShapeLock.h>
#include <DOM/AutoShapeLock.h>
#include <DOM/IGraphicalObjectLock.h>
#include <DOM/IGraphicalObject.h>
#include <DOM/IShape.h>
#include <DOM/IBaseShapeLock.h>
#include <DOM/GraphicalObjectLock.h>
#include <DOM/IAutoShape.h>
#include <DOM/AutoShape.h>
#include <DOM/Table/ITable.h>

#include <Export/SaveFormat.h>
#include <iostream>
#include <system/console.h>

#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;


void LockAspectRatio() {

	//ExStart:LockAspectRatio


	const String templatePath = u"../templates/pres.pptx";
	const String outPath = u"../out/LockAspectRatio_out.pptx";
	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	
	
	SharedPtr<ITable> table = DynamicCast<ITable>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0)) ;

	
	System::Console::WriteLine(u"Lock aspect ratio set: " + table->get_GraphicalObjectLock()->get_AspectRatioLocked());

	table->get_GraphicalObjectLock()->set_AspectRatioLocked(!table->get_GraphicalObjectLock()->get_AspectRatioLocked()); // invert


	//Write the PPTX to Disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);
	//ExEnd:LockAspectRatio
}