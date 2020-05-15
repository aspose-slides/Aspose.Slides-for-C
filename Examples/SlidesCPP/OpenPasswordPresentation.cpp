#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void OpenPasswordPresentation()
{
	//ExStart:OpenPasswordPresentation
	// The path to the documents directory.
	const String templatePath = u"../templates/PasswordPres.pptx";
	
	SharedPtr<LoadOptions> loadOptions = MakeObject<LoadOptions>();
	loadOptions->set_Password(u"pass");

    //Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath, loadOptions);

	printf("Total slides inside presentation are : %d\n", pres->get_Slides()->get_Count());
	
	//ExEnd:OpenPasswordPresentation
}
