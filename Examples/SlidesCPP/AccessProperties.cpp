#include<DOM/DocumentProperties.h>
#include<Dom/CommonSlideViewProperties.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/console.h>
#include <cstdint>

#include <DOM/LoadOptions.h>
#include <system/object_ext.h>
#include <DOM/Presentation.h>
#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include<DOM/PresentationFactory.h>
#include<Dom/IPresentationFactory.h>
#include "SlidesExamples.h"


using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;
using namespace System;

void AccessProperties() {



	//ExStart:AccessProperties
	const String templatePath = u"../templates/AccessProperties.pptx";


	System::SharedPtr<LoadOptions> loadOptions = System::MakeObject<LoadOptions>();

	loadOptions->set_Password(u"pass");

	loadOptions->set_OnlyLoadDocumentProperties ( true);

	System::SharedPtr<Presentation> presentation = System::MakeObject<Presentation>(templatePath, loadOptions);


	System::SharedPtr<IDocumentProperties> docProps = presentation->get_DocumentProperties();

	System::Console::WriteLine(u"Name of Application : {0}", docProps->get_NameOfApplication());

	//ExEnd:AccessProperties
}