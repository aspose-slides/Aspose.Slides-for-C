#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IShapeCollection.h>
#include <DOM/IAutoShape.h>
#include <DOM/Hyperlink.h>
#include <DOM/FillType.h>
#include <DOM/IFillFormat.h>
#include <DOM/Hyperlink.h>
#include <DOM/HyperlinkColorSource.h>
#include <DOM/HyperlinkActionType.h>
#include <DOM/IHyperlinkQueries.h>
#include <DOM/ShapeType.h>
#include <DOM/Paragraph.h>
#include <DOM/IParagraphCollection.h>
#include <DOM/Portion.h>
#include <DOM/IPortionFormat.h>
#include <DOM/IPortionCollection.h>
#include <DOM/ITextFrame.h>
#include <DOM/IColorFormat.h>


#include "SlidesExamples.h"
using namespace Aspose::Slides;
using namespace System;

void MutableHyperlink()
{
	//ExStart:MutableHyperlink
System::SharedPtr <Presentation> presentation = System::MakeObject <Presentation>();
System::SharedPtr <IAutoShape> shape1 = presentation->get_Slides()->idx_get(0)->get_Shapes()->AddAutoShape(Aspose::Slides::ShapeType::Rectangle, 100, 100, 600, 50, false);
shape1->AddTextFrame(u"Aspose: File Format APIs");
shape1->get_TextFrame()->get_Paragraphs()->idx_get(0)->get_Portions()->idx_get(0)->get_PortionFormat()->set_HyperlinkClick(System::MakeObject < Hyperlink >(u"https://www.aspose.com/"));
shape1->get_TextFrame()->get_Paragraphs()->idx_get(0)->get_Portions()->idx_get(0)->get_PortionFormat()->get_HyperlinkClick()->set_Tooltip(u"More than 70% Fortune 100 companies trust Aspose APIs");

shape1->get_TextFrame()->get_Paragraphs()->idx_get(0)->get_Portions()->idx_get(0)->get_PortionFormat()->set_FontHeight(32);
presentation->Save(u"../out/presentation-out.pptx", Aspose::Slides::Export::SaveFormat::Pptx);
//ExEnd:MutableHyperlink
}