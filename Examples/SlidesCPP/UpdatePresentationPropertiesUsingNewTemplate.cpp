#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Slides;
using namespace Export;
using namespace System;
using namespace IO;

//ExStart:UpdatePresentationPropertiesUsingNewTemplate
void UpdateByTemplates(String path, SharedPtr<DocumentProperties> templateprop)
{
	SharedPtr<IPresentationInfo> toUpdate = PresentationFactory::get_Instance()->GetPresentationInfo(path);
	toUpdate->UpdateDocumentProperties(templateprop);
	toUpdate->WriteBindedPresentation(path);
}
void UpdatePresentationPropertiesUsingNewTemplate()
{
	// The path to the documents directory.
	const String templatePath1 = u"../templates/doc1.pptx";
	const String templatePath2 = u"../templates/doc2.odp";
	const String templatePath3 = u"../templates/doc3.ppt";

    const String outPath1 = u"../out/doc1.pptx";
    const String outPath2 = u"../out/doc2.odp";
    const String outPath3 = u"../out/doc3.ppt";

    Copy(templatePath1, outPath1);
    Copy(templatePath2, outPath2);
    Copy(templatePath3, outPath3);

	SharedPtr<DocumentProperties> templateProp = System::MakeObject<DocumentProperties>();
	templateProp->set_Author(u"Template Author");
	templateProp->set_Title(u"Template Title");
	templateProp->set_Category(u"Template Category");
	templateProp->set_Keywords(u"Keyword1, Keyword2, Keyword3");
	templateProp->set_Company(u"Our Company");
	templateProp->set_Comments(u"Created from template");
	templateProp->set_ContentType(u"Template Content");
	templateProp->set_Subject(u"Template Subject");

	UpdateByTemplates(outPath1, templateProp);
	UpdateByTemplates(outPath2, templateProp);
	UpdateByTemplates(outPath3, templateProp);
}
//ExEnd:UpdatePresentationPropertiesUsingNewTemplate
