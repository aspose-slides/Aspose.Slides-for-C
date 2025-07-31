#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

void InkEffectsExample()
{
    //ExStart:InkEffectsExample

    // The path to the presentation
    const String pptxPath = Path::Combine(GetDataPath(), u"InkEffects.pptx");
    const String effectImagePath = Path::Combine(GetDataPath(), u"Effect.png");

    // The path to output file
    const String outFilePath = Path::Combine(GetOutPath(), u"InkEffects.png");

    SharedPtr<Presentation> pres = MakeObject<Presentation>(pptxPath);

    // Get Ink object
    SharedPtr<Ink::Ink> ink = AsCast<Ink::Ink>(pres->get_Slide(0)->get_Shape(0));
    SharedPtr<Ink::IInkBrush> brush = ink->get_Traces()[0]->get_Brush();

    // Show InkEffects of the brush
    Console::WriteLine(u"InkEffects = {0}", brush->get_InkEffect());

    // Set image for InkEffects
    SharedPtr<IImage> image = Images::FromFile(effectImagePath);
    Ink::Ink::get_InkEffectImages()->Add(brush->get_InkEffect(), image);

    // Save result
    pres->get_Slide(0)->GetImage(2.0f, 2.0f)->Save(outFilePath, ImageFormat::Png);

    //ExEnd:InkEffectsExample
}
