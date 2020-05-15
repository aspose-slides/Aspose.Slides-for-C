#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;
using namespace System;

void OpenVeryLargePresentation()
{
	//ExStart:OpenVeryLargePresentation
	// The path to the documents directory.

	const String templatePath = u"../templates/Video.pptx";
	const String outPath = u"../out/veryLargePresentation-copy.pptx";

	SharedPtr<LoadOptions> loadOptions = MakeObject<LoadOptions>();

	SharedPtr<BlobManagementOptions> blobOptions = MakeObject<BlobManagementOptions>();
	blobOptions->set_PresentationLockingBehavior(PresentationLockingBehavior::KeepLocked);

	loadOptions->set_BlobManagementOptions(blobOptions);

    //Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath, loadOptions);

	pres->get_Slides()->idx_get(0)->set_Name(u"Very large presentation");

	// presentation will be saved to the other file, the memory consumptions still low during saving.
	pres->Save(outPath, SaveFormat::Pptx);

	//ExEnd:OpenVeryLargePresentation
}
