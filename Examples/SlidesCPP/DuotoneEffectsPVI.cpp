#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Effects;
using namespace Export;
using namespace System;
using namespace System::Drawing;
using namespace IO;

void DuotoneEffectsPVI()
{
    SharedPtr<Presentation> presentation = System::MakeObject<Presentation>();
   
    String imagePath = GetDataPath() + u"aspose-logo.jpg";

    // Add image to presentation
    SharedPtr<IPPImage> backgroundImage = presentation->get_Images()->AddImage(Image::FromFile(imagePath));

    // Set background in first slide
    SharedPtr<IBackground> background = presentation->get_Slides()->idx_get(0)->get_Background();
    background->set_Type(BackgroundType::OwnBackground);
    background->get_FillFormat()->set_FillType(FillType::Picture);
    background->get_FillFormat()->get_PictureFillFormat()->get_Picture()->set_Image(backgroundImage);

    // Add Duotone effect to background
    auto ImageTransformOperationCollection = background->get_FillFormat()->get_PictureFillFormat()->get_Picture()->get_ImageTransform();
    SharedPtr<IDuotone> duotone = ImageTransformOperationCollection->AddDuotoneEffect();

    // Set Doutone properties
    duotone->get_Color1()->set_ColorType(ColorType::Scheme);
    duotone->get_Color1()->set_SchemeColor(SchemeColor::Accent1);
    duotone->get_Color2()->set_ColorType(ColorType::Scheme);
    duotone->get_Color2()->set_SchemeColor(SchemeColor::Dark2);

    // Get Effective values of the Duotone effect
    SharedPtr<IDuotoneEffectiveData> duotoneEffective = duotone->GetEffective();

    // Show effective values
    Console::WriteLine(String(u"Duotone effective color1: ") + duotoneEffective->get_Color1());
    Console::WriteLine(String(u"Duotone effective color2: ") + duotoneEffective->get_Color2());
}
