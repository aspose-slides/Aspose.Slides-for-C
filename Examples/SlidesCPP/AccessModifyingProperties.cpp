#include<DOM/DocumentProperties.h>
#include<DOM/IDocumentProperties.h>

#include<Dom/CommonSlideViewProperties.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/console.h>
#include <cstdint>
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

void AccessModifyingProperties() {



	//ExStart:AccessModifyingProperties
	const String templatePath = u"../templates/AccessModifyingProperties.pptx";

	System::SharedPtr<Presentation> presentation = System::MakeObject<Presentation>(templatePath);

	// Create a reference to DocumentProperties object associated with Prsentation
	System::SharedPtr<IDocumentProperties> documentProperties = presentation->get_DocumentProperties();


	for (int32_t i = 0; i < documentProperties->get_CountOfCustomProperties(); i++)
	{
		System::Console::WriteLine(u"Custom Property Name : {0}", documentProperties->GetCustomPropertyName(i));
		System::Console::WriteLine(u"Custom Property Vlaue : {0}", documentProperties->idx_get(documentProperties->GetCustomPropertyName(i)));
	}

	//ExEnd:AccessModifyingProperties
}