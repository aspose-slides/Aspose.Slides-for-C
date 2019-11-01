#include <DOM/Presentation.h>
#include <DOM/ISlide.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IGlobalLayoutSlideCollection.h>
#include <DOM/IFillFormat.h>
#include <DOM/IShapeCollection.h>
#include <iostream>
#include <system/console.h>

#include "SlidesExamples.h"
#include <Export/SaveFormat.h>

using namespace Aspose;
using namespace Aspose::Slides;

void AccessLayoutFormats() {

	//ExStart:AccessLayoutFormats

	// The path to the documents directory.
	const String outPath = u"../templates/pres.pptx";

	//Instantiate Presentation class that represents PPTX file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	
	for (int x = 0; x < pres->get_LayoutSlides()->get_Count(); x++) 
	{

			SharedPtr<IShapeCollection> shapeCollection = pres->get_LayoutSlides()->idx_get(x)->get_Shapes();
			
					

			for (int i = 0; i < shapeCollection->get_Count(); i++) {
			
				SharedPtr<IShape> shape = shapeCollection->idx_get(i);

				System::Console::WriteLine(shape->get_FillFormat());
			
			}


			for (int j = 0; j < shapeCollection->get_Count(); j++) {

				SharedPtr<IShape> shape = shapeCollection->idx_get(j);
				
				System::Console::WriteLine(shape->get_LineFormat());
			}

	}

	//ExEnd:AccessLayoutFormats
}