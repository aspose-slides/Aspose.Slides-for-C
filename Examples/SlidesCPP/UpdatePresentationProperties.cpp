#include <system/object_ext.h>
#include<Dom/ProtectionManager.h>
#include<Dom/IDocumentProperties.h>
#include <DOM/Presentation.h>
#include<DOM/PresentationFactory.h>
#include<DOM/IPresentationInfo.h>
#include<Dom/IPresentationFactory.h>
#include<Dom/IProtectionManager.h>
#include <Export/SaveFormat.h>

#include<Dom/CommonSlideViewProperties.h>

#include "SlidesExamples.h"
using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;
using namespace System;

void UpdatePresentationProperties() {


	//ExStart:UpdatePresentationProperties

	const String templatePath = u"../templates/ModifyBuiltinProperties.pptx";
	const String outPath = u"../out/ModifyBuiltinProperties1.pptx";

//	SharedPtr<PresentationFactory> factory = MakeObject<PresentationFactory>();

	// read the info of presentation 
	System::SharedPtr<IPresentationInfo> info = PresentationFactory::get_Instance()->GetPresentationInfo(templatePath);

	// obtain the current properties 
	System::SharedPtr<IDocumentProperties> props = info->ReadDocumentProperties();

	// set the new values of Author and Title fields 
	props->set_Author ( u"New Author");
	props->set_Title (u"New Title");

	// update the presentation with a new values 
	info->UpdateDocumentProperties(props);
	
	info->WriteBindedPresentation(outPath);

	//ExEnd:UpdatePresentationProperties
}