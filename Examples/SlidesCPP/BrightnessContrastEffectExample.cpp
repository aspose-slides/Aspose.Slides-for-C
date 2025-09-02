#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Effects;
using namespace Export;
using namespace System;
using namespace IO;

void BrightnessContrastEffectExample()
{
    //ExStart:BrightnessContrastEffectExample

    // Path to source presentation
    const String presentationName = Path::Combine(GetDataPath(), u"BrightnessContrast.pptx");

    auto presentation = MakeObject<Presentation>(presentationName);

    // Get slide
    SharedPtr<ISlide> slide = presentation->get_Slide(0);

    // Get picture frame
    SharedPtr<IPictureFrame> pictureFrame = ExplicitCast<IPictureFrame>(slide->get_Shape(0));

    // Get image transform operations
    SharedPtr<IImageTransformOperationCollection> imageTransform = pictureFrame->get_PictureFormat()->get_Picture()->get_ImageTransform();

    for (auto&& effect : imageTransform)
    {
        if (ObjectExt::Is<IBrightnessContrast>(effect))
        {
            // Get brightness and contrast values
            SharedPtr<IBrightnessContrast> brightnessContrast = ExplicitCast<IBrightnessContrast>(effect);
            SharedPtr<IBrightnessContrastEffectiveData> brightnessContrastEffectiveData = brightnessContrast->GetEffective();

            Console::WriteLine(u"Brightness value = {0}", brightnessContrastEffectiveData->get_Brightness());
            Console::WriteLine(u"Contrast value = {0}", brightnessContrastEffectiveData->get_Contrast());
        }
    }

    //ExEnd:BrightnessContrastEffectExample
}
