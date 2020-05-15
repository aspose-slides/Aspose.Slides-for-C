#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;
using namespace IO;

// ExStart:AddingEMZImagesToImageCollection

void AddingEMZImagesToImageCollection()
{
	// The path to the documents directory.
	const String outPath = u"../out/AddingEMZImagesToImageCollection_out.pptx";
	const String filePath = u"../templates/2.emz";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	auto data = GetFileByteData(filePath);
	
	SharedPtr<IPPImage> imgx = pres->get_Images()->AddImage(data);

	//Adding picture frame with EMZ image	
	auto m = slide->get_Shapes()->AddPictureFrame(ShapeType::Rectangle, 0, 0, pres->get_SlideSize()->get_Size().get_Width(), pres->get_SlideSize()->get_Size().get_Height(), imgx);

	//Write the PPTX file to disk
	pres->Save(outPath, Export::SaveFormat::Pptx);
}

ArrayPtr<uint8_t> GetFileByteData(String fileNameZip)
{
	 SharedPtr<FileStream> fs = File::OpenRead(fileNameZip);
	 ArrayPtr<uint8_t> buffer = System::MakeArray<uint8_t>(fs->get_Length(), 0);
	 fs->Read(buffer, 0, buffer->get_Length());
	 return buffer;
}
//ExEnd:AddingEMZImagesToImageCollection
