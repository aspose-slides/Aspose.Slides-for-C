#include "SlidesExamples.h"

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <DOM/PresentationFactory.h>
#include <DOM/IPresentationInfo.h>
#include <DOM/IDocumentProperties.h>
#include <DOM/DocumentProperties.h>
#include <Export/SaveFormat.h>
#include<Export/IPptxOptions.h>

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;
using namespace System;

//ExStart:UpdatePresentationPropertiesUsingPropertiesOfAnotherPresentationAsATemplate
void UpdateByTemplate(System::String path, System::SharedPtr<DocumentProperties> templateprop)
{
	System::SharedPtr<IPresentationInfo> toUpdate = PresentationFactory::get_Instance()->GetPresentationInfo(path);
	toUpdate->UpdateDocumentProperties(templateprop);
	toUpdate->WriteBindedPresentation(path);
}
void UpdatePresentationPropertiesUsingPropertiesOfAnotherPresentationAsATemplate()
{

	// The path to the documents directory.
	const String templatePath1 = u"../templates/doc1.pptx";
	const String templatePath2 = u"../templates/doc2.odp";
	const String templatePath3 = u"../templates/doc3.ppt";
	const String templatePath = u"../templates/template.pptx";

	// The path to the documents directory.
	const String dataDir = u"../templates/Sample.pptx";
	//System::SharedPtr<DocumentProperties> template1;
	System::SharedPtr<IPresentationInfo> info = PresentationFactory::get_Instance()->GetPresentationInfo(templatePath);

	System::SharedPtr<DocumentProperties> templateprop = System::DynamicCast<Aspose::Slides::DocumentProperties>(info->ReadDocumentProperties());


	templateprop->set_Author(u"Template Author");
	templateprop->set_Title(u"Template Title");
	templateprop->set_Category(u"Template Category");
	templateprop->set_Keywords(u"Keyword1, Keyword2, Keyword3");
	templateprop->set_Company(u"Our Company");
	templateprop->set_Comments(u"Created from template");
	templateprop->set_ContentType(u"Template Content");
	templateprop->set_Subject(u"Template Subject");

	UpdateByTemplate(templatePath1, templateprop);
	UpdateByTemplate(templatePath2, templateprop);
	UpdateByTemplate(templatePath3, templateprop);
}

//ExEnd:UpdatePresentationPropertiesUsingPropertiesOfAnotherPresentationAsATemplate