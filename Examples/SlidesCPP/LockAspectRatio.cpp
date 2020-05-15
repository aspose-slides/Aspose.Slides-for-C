#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Slides;

void LockAspectRatio()
{
	//ExStart:LockAspectRatio

	const String templatePath = u"../templates/pres.pptx";
	const String outPath = u"../out/LockAspectRatio_out.pptx";
	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	SharedPtr<ITable> table = DynamicCast<ITable>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0)) ;

	Console::WriteLine(u"Lock aspect ratio set: " + table->get_GraphicalObjectLock()->get_AspectRatioLocked());

	table->get_GraphicalObjectLock()->set_AspectRatioLocked(!table->get_GraphicalObjectLock()->get_AspectRatioLocked()); // invert

	//Write the PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);
	//ExEnd:LockAspectRatio
}
