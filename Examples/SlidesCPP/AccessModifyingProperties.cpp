#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;

void AccessModifyingProperties()
{
	//ExStart:AccessModifyingProperties
	const String templatePath = u"../templates/AccessModifyingProperties.pptx";

	SharedPtr<Presentation> presentation = System::MakeObject<Presentation>(templatePath);

	// Create a reference to DocumentProperties object associated with Prsentation
	SharedPtr<IDocumentProperties> documentProperties = presentation->get_DocumentProperties();

	for (int32_t i = 0; i < documentProperties->get_CountOfCustomProperties(); i++)
	{
		Console::WriteLine(u"Custom Property Name : {0}", documentProperties->GetCustomPropertyName(i));
		Console::WriteLine(u"Custom Property Vlaue : {0}", documentProperties->idx_get(documentProperties->GetCustomPropertyName(i)));
	}

	//ExEnd:AccessModifyingProperties
}
