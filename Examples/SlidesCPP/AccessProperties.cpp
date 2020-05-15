#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;

void AccessProperties()
{
	//ExStart:AccessProperties
	const String templatePath = u"../templates/AccessProperties.pptx";

	SharedPtr<LoadOptions> loadOptions = System::MakeObject<LoadOptions>();
	loadOptions->set_Password(u"pass");
	loadOptions->set_OnlyLoadDocumentProperties ( true);

	SharedPtr<Presentation> presentation = System::MakeObject<Presentation>(templatePath, loadOptions);

	SharedPtr<IDocumentProperties> docProps = presentation->get_DocumentProperties();

	Console::WriteLine(u"Name of Application : {0}", docProps->get_NameOfApplication());

	//ExEnd:AccessProperties
}
