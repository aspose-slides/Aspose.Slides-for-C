#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;

void AccessBuiltinProperties()
{
	//ExStart:AccessBuiltinProperties

	const String templatePath = u"../templates/AccessSlides.pptx";
	SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);

	SharedPtr<IDocumentProperties> documentProperties = pres->get_DocumentProperties();
	
	Console::WriteLine(u"Category : {0}" , documentProperties->get_Category());
	Console::WriteLine(u"Current Status : {0}", documentProperties->get_ContentStatus());
	Console::WriteLine(u"Creation Date : {0}", documentProperties->get_CreatedTime().ToString());
	Console::WriteLine(u"Author : {0}", documentProperties->get_Author());
	Console::WriteLine(u"Description : {0}", documentProperties->get_Comments());
	Console::WriteLine(u"KeyWords : {0}", documentProperties->get_Keywords());
	Console::WriteLine(u"Last Modified By : {0}", documentProperties->get_LastSavedBy());
	Console::WriteLine(u"Supervisor : {0}", documentProperties->get_Manager());
	Console::WriteLine(u"Modified Date : {0}", documentProperties->get_LastSavedTime().ToString());
	Console::WriteLine(u"Presentation Format : {0}", documentProperties->get_PresentationFormat());
	Console::WriteLine(u"Last Print Date : {0}",documentProperties->get_LastPrinted().ToString());
	Console::WriteLine(u"Is Shared between producers : {0}", documentProperties->get_SharedDoc());
	Console::WriteLine(u"Subject : {0}", documentProperties->get_Subject());
	Console::WriteLine(u"Title : {0}", documentProperties->get_Title());
	//ExEnd:AccessBuiltinProperties            
}
