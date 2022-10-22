#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;

void SvgConvertionOptions()
{
    // ExStart:SvgConvertionOptions

    const System::String presentationName = System::IO::Path::Combine(GetDataPath(), u"SvgShapesConvertion.pptx");
    const System::String outPath = System::IO::Path::Combine(GetOutPath(), u"SvgShapesConvertion.svg");

    auto presentation = System::MakeObject<Presentation>(presentationName);

    // Create new SVG option
    System::SharedPtr<Export::SVGOptions> svgOptions = System::MakeObject<Export::SVGOptions>();

    // Set UseFrameSize property to include frame in a rendering area.
    svgOptions->set_UseFrameSize(true);

    // Set UseFrameRotation property to exclude rotation of the shape when rendering.
    svgOptions->set_UseFrameRotation(false);

    // Save a shape to svg using SvgOptions
    System::SharedPtr<System::IO::FileStream> stream = System::MakeObject<System::IO::FileStream>(outPath, System::IO::FileMode::Create);
    presentation->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0)->WriteAsSvg(stream, svgOptions);

    // ExEnd:SvgConvertionOptions
}
