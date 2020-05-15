#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Slides;
using namespace Vba;

void ExtractingVBAMacros()
{
	//ExStart:ExtractingVBAMacros

	// The path to the documents directory.
	const String templatePath = u"../templates/VBA.pptm";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	if (pres->get_VbaProject() != nullptr) // check if Presentation contains VBA Project
	{
		//for (SharedPtr<IVbaModule> module : pres->get_VbaProject()->get_Modules())
		for (int i = 0; i < pres->get_VbaProject()->get_Modules()->get_Count(); i++)
		{
			SharedPtr<IVbaModule> module = pres->get_VbaProject()->get_Modules()->idx_get(i);

			Console::WriteLine(module->get_Name());
			Console::WriteLine(module->get_SourceCode());
		}
	}
	//ExEnd:ExtractingVBAMacros
}
