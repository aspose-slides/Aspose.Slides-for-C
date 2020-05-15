#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;

//ExStart:UpdatePresentationPropertiesUsingPropertiesOfAnotherPresentationAsATemplate
void UpdateByTemplate(String path, SharedPtr<DocumentProperties> templateprop)
{
	SharedPtr<IPresentationInfo> toUpdate = PresentationFactory::get_Instance()->GetPresentationInfo(path);
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

    const String outPath1 = u"../out/doc1.pptx";
    const String outPath2 = u"../out/doc2.odp";
    const String outPath3 = u"../out/doc3.ppt";

    Copy(templatePath1, outPath1);
    Copy(templatePath2, outPath2);
    Copy(templatePath3, outPath3);

	SharedPtr<IPresentationInfo> info = PresentationFactory::get_Instance()->GetPresentationInfo(templatePath);

	SharedPtr<DocumentProperties> templateprop = System::DynamicCast<DocumentProperties>(info->ReadDocumentProperties());
	
	templateprop->set_Author(u"Template Author");
	templateprop->set_Title(u"Template Title");
	templateprop->set_Category(u"Template Category");
	templateprop->set_Keywords(u"Keyword1, Keyword2, Keyword3");
	templateprop->set_Company(u"Our Company");
	templateprop->set_Comments(u"Created from template");
	templateprop->set_ContentType(u"Template Content");
	templateprop->set_Subject(u"Template Subject");

	UpdateByTemplate(outPath1, templateprop);
	UpdateByTemplate(outPath2, templateprop);
	UpdateByTemplate(outPath3, templateprop);
}
//ExEnd:UpdatePresentationPropertiesUsingPropertiesOfAnotherPresentationAsATemplate