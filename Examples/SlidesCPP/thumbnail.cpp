#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IShapeCollection.h>

#include <drawing/imaging/image_format.h>
#include <system/string.h>

#include "thumbnail.h"

using namespace Aspose::Slides;

using namespace System;
using namespace System::Drawing::Imaging;

const String templatePath = L"../templates/TestDeck_050.pptx";

void Thumbnail::SampleThumbnail()
{
    auto pres = MakeObject<Presentation>(templatePath);

    auto bitmap = pres->get_Slides()->idx_get(0)->GetThumbnail(1, 1);

    bitmap->Save(L"../out/TestDeck_050.png", ImageFormat::get_Png());
	pres->Save(L"../out/SampleAddText.pdf", Export::SaveFormat::Pdf);
}
