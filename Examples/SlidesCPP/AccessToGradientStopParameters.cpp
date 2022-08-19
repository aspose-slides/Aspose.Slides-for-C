#include "stdafx.h"
#include "SlidesExamples.h"
#include <cmath>
#include <cassert>

using namespace Aspose::Slides;
using namespace System;
using namespace System::IO;


float ColorTransformToBrightness(SharedPtr<IColorOperationCollection> colorOperations)
{
    float addLuminanceValue = std::numeric_limits<float>::quiet_NaN();
    float multiplyLuminanceValue = std::numeric_limits<float>::quiet_NaN();

    for (auto op : colorOperations)
    {
        switch (op->get_OperationType())
        {
        case ColorTransformOperation::AddLuminance:
            addLuminanceValue = op->get_Parameter();
            break;

        case ColorTransformOperation::MultiplyLuminance:
            multiplyLuminanceValue = op->get_Parameter();
            break;
        }
    }

    if (std::isnan(multiplyLuminanceValue))
        return 1.f;

    if (std::isnan(addLuminanceValue))
        return multiplyLuminanceValue - 1.f;

    assert(System::Math::Abs(addLuminanceValue + multiplyLuminanceValue - 1.f) < 0.0001f);

    return addLuminanceValue;
}

float ColorTransformToTransparency(SharedPtr<IColorOperationCollection> colorOperations)
{
    for (auto op : colorOperations)
    {
        if (op->get_OperationType() == ColorTransformOperation::SetAlpha)
            return 1.f - op->get_Parameter();
    }
    return 0.f;
}


void AccessToGradientStopParameters()
{
    auto pres = MakeObject<Presentation>(Path::Combine(GetDataPath(), u"GradientBackground.pptx"));

    for (auto slide : pres->get_Slides())
    {
        auto background = slide->get_Background();
        if (background->get_FillFormat()->get_FillType() == FillType::Gradient)
        {
            auto backgroundGradientFormat = background->get_FillFormat()->get_GradientFormat();
            if (backgroundGradientFormat->get_GradientShape() == GradientShape::Linear)
            {
                auto gradientStops = backgroundGradientFormat->get_GradientStops();
                for (auto gradientStop : gradientStops)
                {
                    Console::WriteLine(u"Gradient Stop Position = {0}", gradientStop->get_Position() * 100.f);
                    SharedPtr<IColorFormat> gradientColorFormat = gradientStop->get_Color();
                    if (gradientColorFormat != nullptr)
                    {
                        float transparencyFromColor = (255 - gradientColorFormat->get_Color().get_A()) / 255.f;
                        
                        Console::WriteLine(u"Transparency from color = {0:F2} %", transparencyFromColor * 100.f);
                        
                        float brightness = ColorTransformToBrightness(gradientColorFormat->get_ColorTransform());
                        float transparency = ColorTransformToTransparency(gradientColorFormat->get_ColorTransform());

                        Console::WriteLine(u"Transparency = {0} %, Brightness = {1} %", transparency * 100.f, brightness * 100.f);
                        Console::WriteLine(u"-----------------------------------------------");
                    }
                }
            }
        }
    }
}
