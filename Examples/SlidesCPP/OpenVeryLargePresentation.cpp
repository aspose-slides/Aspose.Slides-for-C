#include <system/object_ext.h>
#include<Dom/LoadOptions.h>
#include <DOM/Presentation.h>
#include<ILoadOptions.h>
#include<DOM/LoadOptions.h>
#include<DOM/ISlideCollection.h>
#include<DOM/BlobManagementOptions.h>
#include<PresentationLockingBehavior.h>


#include <Export/SaveFormat.h>
#include<System/console.h>
#include <iostream>
#include<System/convert.h>
#include <system/console.h>
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;

using namespace System;

void OpenVeryLargePresentation()
{

	//ExStart:OpenVeryLargePresentation
	// The path to the documents directory.

	const String templatePath = u"../templates/Video.pptx";
	const String outPath = u"../out/veryLargePresentation-copy.pptx";
	//Instantiate Presentation class that represents PPTX file

	SharedPtr < Aspose::Slides::LoadOptions > loadOptions = MakeObject <Aspose::Slides::LoadOptions>();

	SharedPtr<BlobManagementOptions>blobOptions = MakeObject<BlobManagementOptions>();
	blobOptions->set_PresentationLockingBehavior(PresentationLockingBehavior::KeepLocked);

	loadOptions->set_BlobManagementOptions(blobOptions);

	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath, loadOptions);

	pres->get_Slides()->idx_get(0)->set_Name(u"Very large presentation");

	// presentation will be saved to the other file, the memory consumptions still low during saving.
	pres->Save(outPath, SaveFormat::Pptx);

	//ExEnd:OpenVeryLargePresentation

}