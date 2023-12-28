#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;

using namespace System::IO;

void ShapeIsDecorativeExample()
{
    //ExStart:ShapeIsDecorativeExample

	// Path to output document
    const System::String outFilePath = Path::Combine(GetOutPath(), u"DecorativeDemo.pptx");

    System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    // Create new shape
    System::SharedPtr<IShape> shape1 = pres->get_Slide(0)->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 10.0f, 10.0f, 100.0f, 100.0f);

    // Set shape as “decorative” object
    shape1->set_IsDecorative(true);

    // Save result
    pres->Save(outFilePath, SaveFormat::Pptx);

    //ExEnd:ShapeIsDecorativeExample
}
