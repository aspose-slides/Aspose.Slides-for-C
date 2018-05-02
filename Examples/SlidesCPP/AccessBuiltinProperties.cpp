
#include<Dom/ProtectionManager.h>
#include <DOM/Presentation.h>
#include<DOM/PresentationFactory.h>
#include<Dom/IPresentationFactory.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/console.h>
#include <Export/SaveFormat.h>
#include<DOM/DocumentProperties.h>
#include<DOM/IDocumentProperties.h>
#include<Dom/CommonSlideViewProperties.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/console.h>
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;
using namespace System;
void AccessBuiltinProperties()
{


	//ExStart:AccessBuiltinProperties

	const String templatePath = u"../templates/AccessSlides.pptx";
	System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);


	System::SharedPtr<IDocumentProperties> documentProperties = pres->get_DocumentProperties();
	
	System::Console::WriteLine(u"Category : {0}" , documentProperties->get_Category());
	System::Console::WriteLine(u"Current Status : {0}", documentProperties->get_ContentStatus());
	System::Console::WriteLine(u"Creation Date : {0}", documentProperties->get_CreatedTime().ToString());
	System::Console::WriteLine(u"Author : {0}", documentProperties->get_Author());
	System::Console::WriteLine(u"Description : {0}", documentProperties->get_Comments());
	System::Console::WriteLine(u"KeyWords : {0}", documentProperties->get_Keywords());
	System::Console::WriteLine(u"Last Modified By : {0}", documentProperties->get_LastSavedBy());
	System::Console::WriteLine(u"Supervisor : {0}", documentProperties->get_Manager());
	System::Console::WriteLine(u"Modified Date : {0}", documentProperties->get_LastSavedTime().ToString());
	System::Console::WriteLine(u"Presentation Format : {0}", documentProperties->get_PresentationFormat());
	System::Console::WriteLine(u"Last Print Date : {0}",documentProperties->get_LastPrinted().ToString());
	System::Console::WriteLine(u"Is Shared between producers : {0}", documentProperties->get_SharedDoc());
	System::Console::WriteLine(u"Subject : {0}", documentProperties->get_Subject());
	System::Console::WriteLine(u"Title : {0}", documentProperties->get_Title());
	//ExEnd:AccessBuiltinProperties            


}