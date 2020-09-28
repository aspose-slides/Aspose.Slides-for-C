#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Slides;
using namespace Export;
using namespace System;

//ExStart:SvgFormattingController
class MySvgShapeFormattingController : public ISvgShapeAndTextFormattingController
{
public:
    MySvgShapeFormattingController::MySvgShapeFormattingController(int32_t shapeStartIndex = 0)
        : m_shapeIndex(0), m_portionIndex(0), m_tspanIndex(0)
    {
        m_shapeIndex = shapeStartIndex;
        m_portionIndex = 0;
    }

    void FormatShape(SharedPtr<ISvgShape> svgShape, SharedPtr<IShape> shape)
    {
        svgShape->set_Id(String::Format(u"shape-{0}", m_shapeIndex++));
        m_portionIndex = m_tspanIndex = 0;
    }

    void FormatText(SharedPtr<ISvgTSpan> svgTSpan, SharedPtr<IPortion> portion, SharedPtr<ITextFrame> textFrame)
    {
        int32_t paragraphIndex = 0;
        int32_t portionIndex = 0;
        for (int32_t i = 0; i < textFrame->get_Paragraphs()->get_Count(); ++i)
        {
            portionIndex = textFrame->get_Paragraphs()->idx_get(i)->get_Portions()->IndexOf(portion);
            if (portionIndex > -1)
            {
                paragraphIndex = i;
                break;
            }
        }

        if (m_portionIndex != portionIndex)
        {
            m_tspanIndex = 0;
            m_portionIndex = portionIndex;
        }

        svgTSpan->set_Id(String::Format(u"paragraph-{0}_portion-{1}_{2}", paragraphIndex, m_portionIndex, m_tspanIndex++));
    }

private:
    int32_t m_shapeIndex, m_portionIndex, m_tspanIndex;
};

void SvgFormattingController()
{    
    String pptxFileName = Path::Combine(GetDataPath(), u"Convert_Svg_Custom.pptx");
    String outSvgFileName = Path::Combine(GetOutPath(), u"Convert_Svg_Custom.svg");

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>(pptxFileName);

    SharedPtr<SVGOptions> svgOptions = System::MakeObject<SVGOptions>();
    svgOptions->set_ShapeFormattingController(System::MakeObject<MySvgShapeFormattingController>());

    SharedPtr<FileStream> stream = System::MakeObject<FileStream>(outSvgFileName, FileMode::Create);
    pres->get_Slides()->idx_get(0)->WriteAsSvg(stream, svgOptions);
}
//ExEnd:SvgFormattingController