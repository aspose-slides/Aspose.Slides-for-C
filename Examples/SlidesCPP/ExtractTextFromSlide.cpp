#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void ExtractTextFromSlide()
{
	//ExStart:ExtractTextFromSlide
	// The path to the documents directory.
	const String inputFile = u"../templates/text.pptx";

	//Instatiate PresentationEx class that represents a PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(inputFile);

	//Get an Array of TextFrameEx objects from the first slide
	ArrayPtr<SharedPtr<ITextFrame>> textFramesSlideOne = Util::SlideUtil::GetAllTextBoxes(pres->get_Slides()->idx_get(0));

	//Loop through the Array of TextFrames
	for (int i = 0; i < textFramesSlideOne->get_Length(); i++)
    {
        SharedPtr<ITextFrame> textFrame = textFramesSlideOne->idx_get(i);
		//Loop through paragraphs in current TextFrame
		for (int paragraph_index = 0; paragraph_index < textFrame->get_Paragraphs()->get_Count(); ++paragraph_index)
        {
            SharedPtr<IParagraph> paragraph = textFrame->get_Paragraphs()->idx_get(paragraph_index);
            //Loop through portions in the current Paragraph
		    for (int portion_index = 0; portion_index < paragraph->get_Portions()->get_Count(); ++portion_index)
            {
                SharedPtr<IPortion> portion = paragraph->get_Portions()->idx_get(portion_index);

		        //Display text in the current portion
                Console::WriteLine(portion->get_Text());

                //Display font height of the text
                Console::WriteLine(portion->get_PortionFormat()->get_FontHeight());

                //Display font name of the text
                Console::WriteLine(portion->get_PortionFormat()->get_LatinFont()->get_FontName());
            }
		}
	}
	
	//ExEnd:ExtractTextFromSlide
}
