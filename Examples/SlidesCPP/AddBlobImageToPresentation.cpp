#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/PictureFillMode.h>
#include <DOM/IImageCollection.h>
#include <LoadingStreamBehavior.h>
#include <DOM/IShapeCollection.h>
#include <DOM/ShapeType.h>
#include <system/io/file_mode.h>
#include <system/io/file_stream.h>

#include <system/string.h>
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;
using namespace System;






void AddBlobImageToPresentation()
{
	//ExStart:AddBlobImageToPresentation

	// supposed we have the large image file we want to include into the presentation
	 System::String pathToLargeImage = u"../templates/largeImage.jpg";

	// create a new presentation which will contain this image
	auto pres = System::MakeObject<Presentation>();

	auto fileStream = System::MakeObject<System::IO::FileStream>(pathToLargeImage, System::IO::FileMode::Open);

	// let's add the image to the presentation - we choose KeepLocked behavior, because we not
	// have an intent to access the "largeImage.png" file.
	auto img = pres->get_Images()->AddImage(fileStream, LoadingStreamBehavior::KeepLocked);
	
	pres->get_Slides()->idx_get(0)->get_Shapes()->AddPictureFrame(Aspose::Slides::ShapeType::Rectangle, 0.0f, 0.0f, 300.0f, 200.0f, img);
	// save the presentation. Despite that the output presentation will be
	// large, the memory consumption will be low the whole lifetime of the pres object
	pres->Save(u"../out/presentationWithLargeImage.pptx", Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:AddBlobImageToPresentation
}