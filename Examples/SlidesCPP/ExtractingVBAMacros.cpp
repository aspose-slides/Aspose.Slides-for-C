#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IMasterSlideCollection.h>
#include <DOM/IMasterSlide.h>
#include <system/string.h>

#include <DOM/Vba/IVbaProject.h>
#include <DOM/Vba/VbaProject.h>
#include <DOM/Vba/IVbaModule.h>
#include <DOM/Vba/VbaModule.h>
#include <DOM/Vba/IVbaModuleCollection.h>
#include <DOM/Vba/VbaReferenceOleTypeLib.h>
#include <DOM/Vba/IVbaReferenceCollection.h>


#include <iostream>
#include <system/console.h>
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Vba;

void ExtractingVBAMacros() {

	//ExStart:ExtractingVBAMacros

	// The path to the documents directory.
	const String templatePath = u"../templates/VBA.pptm";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);


	if (pres->get_VbaProject() != NULL) // check if Presentation contains VBA Project
	{
		
		//for (SharedPtr<IVbaModule> module : pres->get_VbaProject()->get_Modules())
		for (int i = 0; i < pres->get_VbaProject()->get_Modules()->get_Count(); i++)
		{
			SharedPtr<IVbaModule> module = pres->get_VbaProject()->get_Modules()->idx_get(i);

			System::Console::WriteLine(module->get_Name());
			System::Console::WriteLine(module->get_SourceCode());
		}
	}
	//ExEnd:ExtractingVBAMacros

}