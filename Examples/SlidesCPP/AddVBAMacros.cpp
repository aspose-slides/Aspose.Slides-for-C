#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Vba;
using namespace System;
using namespace System::Drawing;

void AddVBAMacros()
{
	// ExStart:AddVBAMacros
	// The path to the documents directory.
	const String outPath = u"../out/AddVBAMacros_out.pptm";

	// Load the desired the presentation
	SharedPtr<Presentation> presentation = MakeObject<Presentation>();
	// Create new VBA Project
	presentation->set_VbaProject(MakeObject<VbaProject>());

	// Add empty module to the VBA project
	SharedPtr<IVbaModule> module = presentation->get_VbaProject()->get_Modules()->AddEmptyModule(u"Module");

	// Set module source code
	module->set_SourceCode(u"Sub Test(oShape As Shape) MsgBox \"Test\" End Sub");

	// Create reference to <stdole>
	SharedPtr<VbaReferenceOleTypeLib> stdoleReference =
		MakeObject<VbaReferenceOleTypeLib>(u"stdole", u"*\\G{00020430-0000-0000-C000-000000000046}#2.0#0#C:\\Windows\\system32\\stdole2.tlb#OLE Automation");

	// Create reference to Office
	SharedPtr<VbaReferenceOleTypeLib> officeReference =
		MakeObject<VbaReferenceOleTypeLib>(u"Office", u"*\\G{2DF8D04C-5BFA-101B-BDE5-00AA0044DE52}#2.0#0#C:\\Program Files\\Common Files\\Microsoft Shared\\OFFICE14\\MSO.DLL#Microsoft Office 14.0 Object Library");

	// Add references to the VBA project
	presentation->get_VbaProject()->get_References()->Add(stdoleReference);
	presentation->get_VbaProject()->get_References()->Add(officeReference);

	// Save PPTX to Disk
	presentation->Save(outPath, Export::SaveFormat::Pptm);

	// ExEnd:AddVBAMacros
}
