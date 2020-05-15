#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace IO;

//ExStart:GeneratingSVGWithCustomShapeIDS
class CustomSvgShapeFormattingController : public ISvgShapeFormattingController
{
public:
    CustomSvgShapeFormattingController(int32_t shapeStartIndex = 0)
        : m_shapeIndex(0)
    {
        m_shapeIndex = shapeStartIndex;
    }

    void FormatShape(SharedPtr<ISvgShape> svgShape, SharedPtr<IShape> shape)
    {
        svgShape->set_Id(System::String::Format(u"shape-{0}", m_shapeIndex++));
    }

private:
    int32_t m_shapeIndex;
};

void GeneratingSVGWithCustomShapeIDS()
{
    // The path to the documents directory.
    const String templatePath = u"../templates/TestDeck_050.pptx";
    const String outPath = u"../out/GeneratingSVGWithCustomShapeIDS_out.svg";

    SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

    SharedPtr<FileStream> stream = System::MakeObject<FileStream>(outPath, FileMode::Create);

    SharedPtr<SVGOptions> svgOptions = System::MakeObject<SVGOptions>();
    svgOptions->set_ShapeFormattingController(System::MakeObject<CustomSvgShapeFormattingController>(0));

    pres->get_Slides()->idx_get(0)->WriteAsSvg(stream, svgOptions);
}
//ExEnd:GeneratingSVGWithCustomShapeIDS