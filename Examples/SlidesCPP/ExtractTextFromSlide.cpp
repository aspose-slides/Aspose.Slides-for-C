#include <DOM/ITextFrame.h>
#include <Util/SlideUtil.h>
#include <DOM/ISlideCollection.h>
#include <DOM/ISlide.h>
#include <DOM/Presentation.h>
#include <DOM/IParagraphCollection.h>
#include <DOM/IParagraph.h>


#include "SlidesExamples.h"
using namespace Aspose;
using namespace Aspose::Slides;

using namespace System;

//void ExtractTextFromSlide() {
//
//	//ExStart:ExtractTextFromSlide
//	// The path to the documents directory.
//	const String inputFile = u"../templates/AccessSlides.pptx";
//
//	//Instatiate PresentationEx class that represents a PPTX file
//	SharedPtr<Presentation> pres = MakeObject<Presentation>(inputFile);
//
//	//Get an Array of TextFrameEx objects from the first slide
//	ArrayPtr<SharedPtr<ITextFrame>> textFramesSlideOne = Aspose::Slides::Util::SlideUtil::GetAllTextBoxes(pres->get_Slides()->idx_get(0));
//
//	//Loop through the Array of TextFrames
//	for (int i = 0; i < textFramesSlideOne->get_Length(); i++) {
//	
//		//Loop through paragraphs in current TextFrame
//		/*for(SharedPtr<Paragraph> para : textFramesSlideOne->idx_get(i)->get_Paragraphs()) {
//		
//		}*/
//		for(ArrayPtr<SharedPtr<IParagraph>> para : textFramesSlideOne->idx_get(i)->get_Paragraphs()) {
//
//		}
//	}
//	
//		
//		
//
//	//ExEnd:ExtractTextFromSlide
//
//}