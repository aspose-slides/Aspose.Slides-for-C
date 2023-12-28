#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;

using namespace System::IO;

void DeletePictureCroppedAreasExample()
{
    //ExStart:DeletePictureCroppedAreasExample

	// Path to source presentation
    const System::String presentationName = Path::Combine(GetDataPath(), u"CroppedImage.pptx");
    // Path to output document
    const System::String outFilePath = Path::Combine(GetOutPath(), u"CroppedImage-out.pptx");

    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(presentationName);

    // Gets the first slide
    System::SharedPtr<ISlide> slide = pres->get_Slide(0);

    // Gets the PictureFrame
    System::SharedPtr<IPictureFrame> picFrame = System::AsCast<IPictureFrame>(slide->get_Shape(0));

    // Deletes cropped areas of the PictureFrame image
    System::SharedPtr<IPPImage> croppedImage = picFrame->get_PictureFormat()->DeletePictureCroppedAreas();

    // Save result
    pres->Save(outFilePath, SaveFormat::Pptx);

    // Check size
    System::Console::WriteLine(u"Source presentation length\t = {0}", System::MakeObject<FileInfo>(presentationName)->get_Length());
    System::Console::WriteLine(u"Resulting presentation length\t = {0}", System::MakeObject<FileInfo>(outFilePath)->get_Length());

    //ExEnd:DeletePictureCroppedAreasExample
}
