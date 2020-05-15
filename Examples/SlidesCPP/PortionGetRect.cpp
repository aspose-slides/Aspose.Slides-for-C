#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void PortionGetRect()
{
    //ExStart:PortionGetRect

    String outPath = GetOutPath();

    SharedPtr<Presentation> pres = System::MakeObject<Presentation>();

    // Create table
    SharedPtr<ITable> tbl = pres->get_Slides()->idx_get(0)->get_Shapes()->AddTable(50.0f, 50.0f, System::MakeArray<double>({ 50, 70 }), System::MakeArray<double>({ 50, 50, 50 }));

    // Create paragraths
    SharedPtr<IParagraph> paragraph0 = System::MakeObject<Paragraph>();
    paragraph0->get_Portions()->Add(System::MakeObject<Portion>(u"Text "));
    paragraph0->get_Portions()->Add(System::MakeObject<Portion>(u"in0"));
    paragraph0->get_Portions()->Add(System::MakeObject<Portion>(u" Cell"));

    SharedPtr<IParagraph> paragraph1 = System::MakeObject<Paragraph>();
    paragraph1->set_Text(u"On0");

    SharedPtr<IParagraph> paragraph2 = System::MakeObject<Paragraph>();
    paragraph2->get_Portions()->Add(System::MakeObject<Portion>(u"Hi there "));
    paragraph2->get_Portions()->Add(System::MakeObject<Portion>(u"col0"));

    SharedPtr<ICell> cell = tbl->get_Rows()->idx_get(1)->idx_get(1);

    // Add text into the table cell
    cell->get_TextFrame()->get_Paragraphs()->Clear();
    cell->get_TextFrame()->get_Paragraphs()->Add(paragraph0);
    cell->get_TextFrame()->get_Paragraphs()->Add(paragraph1);
    cell->get_TextFrame()->get_Paragraphs()->Add(paragraph2);

    // Add TextFrame
    SharedPtr<IAutoShape> autoShape = pres->get_Slides()->idx_get(0)->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 400.0f, 100.0f, 60.0f, 120.0f);
    autoShape->get_TextFrame()->set_Text(u"Text in shape");
    autoShape->get_TextFrame()->get_Paragraphs()->idx_get(0)->get_ParagraphFormat()->set_Alignment(TextAlignment::Left);

    // Getting coordinates of the left top corner of the table cell.
    double x = tbl->get_X() + cell->get_OffsetX();
    double y = tbl->get_Y() + cell->get_OffsetY();

    // Using IParagrap.GetRect() and IPortion.GetRect() methods in order to add frame to portions and paragraphs.
    for(int i = 0; i < cell->get_TextFrame()->get_Paragraphs()->get_Count(); ++i)
    {
        SharedPtr<IParagraph> para = cell->get_TextFrame()->get_Paragraphs()->idx_get(i);
        if (para->get_Text() == u"")
        {
            continue;
        }

        System::Drawing::RectangleF rect = para->GetRect();
        SharedPtr<IAutoShape> shape = pres->get_Slides()->idx_get(0)->get_Shapes()->AddAutoShape(ShapeType::Rectangle, rect.get_X() + (float)x, rect.get_Y() + (float)y, rect.get_Width(), rect.get_Height());

        shape->get_FillFormat()->set_FillType(FillType::NoFill);
        shape->get_LineFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_Yellow());
        shape->get_LineFormat()->get_FillFormat()->set_FillType(FillType::Solid);

        for (int j = 0; j < para->get_Portions()->get_Count(); ++j)
        {
            SharedPtr<IPortion> portion = para->get_Portions()->idx_get(j);
            if (portion->get_Text().Contains(u"0"))
            {
                rect = portion->GetRect();
                shape = pres->get_Slides()->idx_get(0)->get_Shapes()->AddAutoShape(ShapeType::Rectangle, rect.get_X() + (float)x, rect.get_Y() + (float)y, rect.get_Width(), rect.get_Height());

                shape->get_FillFormat()->set_FillType(FillType::NoFill);
            }
        }
    }

    // Add frame to AutoShape paragraphs.    
    for (int i = 0; i < cell->get_TextFrame()->get_Paragraphs()->get_Count(); ++i)
    {
        SharedPtr<IParagraph> para = cell->get_TextFrame()->get_Paragraphs()->idx_get(i);
        System::Drawing::RectangleF rect = para->GetRect();
        SharedPtr<IAutoShape> shape = pres->get_Slides()->idx_get(0)->get_Shapes()->AddAutoShape(ShapeType::Rectangle, rect.get_X() + autoShape->get_X(), rect.get_Y() + autoShape->get_Y(), rect.get_Width(), rect.get_Height());

        shape->get_FillFormat()->set_FillType(FillType::NoFill);
        shape->get_LineFormat()->get_FillFormat()->get_SolidFillColor()->set_Color(System::Drawing::Color::get_Yellow());
        shape->get_LineFormat()->get_FillFormat()->set_FillType(FillType::Solid);
    }

    pres->Save(outPath + u"GetRect_Out.pptx", Export::SaveFormat::Pptx);

    //ExEnd:PortionGetRect
}
