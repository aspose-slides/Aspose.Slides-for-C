#include <iostream>
#include <system/console.h>

#include <Export/SaveFormat.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IMasterSlideCollection.h>
#include <DOM/ISlide.h>
#include <DOM/ILayoutSlide.h>
#include <DOM/SlideLayoutType.h>
#include <DOM/IGlobalLayoutSlideCollection.h>
#include <DOM/IMasterLayoutSlideCollection.h>
#include <DOM/ICommentAuthorCollection.h>
#include <DOM/ISlideSize.h>
#include <DOM/SlideSizeType.h>




//#include <drawing/PointF.h>
#include <drawing/imaging/image_format.h>
#include <system/string.h>
//#include <system/datetime.h>
#include "ManageSlides.h"

using namespace Aspose::Slides;

using namespace System;

void::ManageSlides::AddSlides()
{
	//ExStart:AddSlides
	
	// The path to the documents directory.
	const String outPath = L"../templates/AddSlides.pptx";

	// Instantiate Presentation class that represents the presentation file
	SharedPtr<Presentation> pres = MakeObject<Presentation>();
	
	// Instantiate SlideCollection calss
	SharedPtr<ISlideCollection> slds = pres->get_Slides();

	for (int i = 0; i < pres->get_LayoutSlides()->get_Count(); i++)
	{
		// Add an empty slide to the Slides collection
		slds->AddEmptySlide(pres->get_LayoutSlides()->idx_get(i));

	}

	// Save the PPTX file to the Disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);
	
	//ExEnd:AddSlides
}

void::ManageSlides::AddLayoutSlides()
{
	//ExStart:AddLayoutSlides

	// The path to the documents directory.
	const String templatePath = L"../templates/AddSlides.pptx";
	const String outPath = L"../out/AddLayoutSlides.pptx";

	// Instantiate Presentation class that represents the presentation file
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	
	// Try to search by layout slide type
	SharedPtr<IMasterLayoutSlideCollection> layoutSlides = pres->get_Masters()->idx_get(0)->get_LayoutSlides();
	
	
	SharedPtr<ILayoutSlide> layoutSlide;
	if (layoutSlides->GetByType(SlideLayoutType::TitleAndObject) != NULL)
	{
		layoutSlide = layoutSlides->GetByType(SlideLayoutType::TitleAndObject);
	}
	else if(layoutSlides->GetByType(SlideLayoutType::Title) != NULL)
	{
		layoutSlide = layoutSlides->GetByType(SlideLayoutType::Title);
	}

	if (layoutSlide ==  NULL)
	{
		// The situation when a presentation doesn't contain some type of layouts.
		// presentation File only contains Blank and Custom layout types.
		// But layout slides with Custom types has different slide names,
		// like "Title", "Title and Content", etc. And it is possible to use these
		// names for layout slide selection.
		// Also it is possible to use the set of placeholder shape types. For example,
		// Title slide should have only Title pleceholder type, etc.
		
		for (int i=0;i<layoutSlides->get_Count();i++) 
		{
			SharedPtr<ILayoutSlide> titleAndObjectLayoutSlide = layoutSlides->idx_get(i);
			
			if (titleAndObjectLayoutSlide->get_Name().Equals(L"Title and Object"))
			{
				layoutSlide = titleAndObjectLayoutSlide;
				break;
			}
		}

		if (layoutSlide == NULL)
		{
			for (int i = 0; i < layoutSlides->get_Count(); i++)
			{
				SharedPtr<ILayoutSlide> titleLayoutSlide = layoutSlides->idx_get(i);

				if (titleLayoutSlide->get_Name().Equals(L"Title"))
				{
					layoutSlide = titleLayoutSlide;
					break;
				}
			}

			if (layoutSlide == NULL)
			{
				layoutSlide = layoutSlides->GetByType(SlideLayoutType::Blank);
				if (layoutSlide == NULL)
				{
					layoutSlide = layoutSlides->Add(SlideLayoutType::TitleAndObject, L"Title and Object");
				}
			}
		}
	}

	// Adding empty slide with added layout slide 
	pres->get_Slides()->InsertEmptySlide(0, layoutSlide);

	// Save the PPTX file to the Disk
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:AddLayoutSlides
}


void::ManageSlides::AccessSlides()
{
	//ExStart:AccessSlides
	// The path to the documents directory.
	const String templatePath = L"../templates/AddSlides.pptx";

	// Instantiate Presentation class that represents the presentation file
	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Instantiate SlideCollection calss
	SharedPtr<ISlideCollection> slds = pres->get_Slides();

	// Accessing a slide using its slide index
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	System::Console::WriteLine(L"Slide Number from: " + slide->get_SlideNumber());

	//ExEnd:AccessSlides
}

void::ManageSlides::AccessSlidebyID()
{
	//ExStart:AccessSlidebyID

	// The path to the documents directory.
	const String templatePath = L"../templates/AddSlides.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Getting Slide ID
	uint id = pres->get_Slides()->idx_get(0)->get_SlideId();

	// Accessing Slide by ID
	SharedPtr<IBaseSlide> slide = pres->GetSlideById(id);

	//ExEnd:AccessSlidebyID

}

void::ManageSlides::AccessSlidebyIndex()
{
	//ExStart:AccessSlidebyIndex

	// The path to the documents directory.
	const String templatePath = L"../templates/AddSlides.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Accessing Slide by ID
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	//ExEnd:AccessSlidebyIndex

}

void::ManageSlides::RemoveSlideUsingIndex()
{
	//ExStart:RemoveSlideUsingIndex

	// The path to the documents directory.
	const String templatePath = L"../templates/AddSlides.pptx";
	const String outPath = L"../out/RemoveSlidesByID.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Removing a slide using its slide index
	pres->get_Slides()->RemoveAt(0);

	// Writing the presentation file
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:RemoveSlideUsingIndex
}

void::ManageSlides::RemoveSlideUsingReference()
{
	//ExStart:RemoveSlideUsingReference

	// The path to the documents directory.
	const String templatePath = L"../templates/AddSlides.pptx";
	const String outPath = L"../out/RemoveSlidesByReference.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Accessing Slide by ID from collection
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Removing a slide using its reference
	pres->get_Slides()->Remove(slide);

	// Writing the presentation file
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:RemoveSlideUsingReference
}

void::ManageSlides::ChangePosition()
{
	//ExStart:ChangePosition

	// The path to the documents directory.
	const String templatePath = L"../templates/AddSlides.pptx";
	const String outPath = L"../out/ChangeSlidePosition.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Accessing Slide by ID from collection
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Set the new position for the slide
	slide->set_SlideNumber(2);

	// Writing the presentation file
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:ChangePosition
}

void::ManageSlides::CloneWithInSamePresentation()
{
	//ExStart:CloneWithInSamePresentation

	// The path to the documents directory.
	const String templatePath = L"../templates/AddSlides.pptx";
	const String outPath = L"../out/CloneWithInSamePresentation.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Accessing Slide by ID from collection
	SharedPtr<ISlideCollection> slides = pres->get_Slides();

	// Clone the desired slide to the specified index in the same presentation
	slides->InsertClone(2, pres->get_Slides()->idx_get(0));

	// Writing the presentation file
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:CloneWithInSamePresentation
}

void::ManageSlides::CloneWithinSamePresentationToEnd()
{
	//ExStart:CloneWithinSamePresentationToEnd

	// The path to the documents directory.
	const String templatePath = L"../templates/AddSlides.pptx";
	const String outPath = L"../out/CloneWithinSamePresentationToEnd.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	// Accessing Slide by ID from collection
	SharedPtr<ISlideCollection> slides = pres->get_Slides();

	// Clone the desired slide at end of same presentation
	slides->AddClone(pres->get_Slides()->idx_get(0));

	// Writing the presentation file
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:CloneWithinSamePresentationToEnd
}

void::ManageSlides::CloneAtEndOfAnotherPresentation()
{
	//ExStart:CloneAtEndOfAnotherPresentation

	// The path to the documents directory.
	const String templatePath = L"../templates/AddSlides.pptx";
	const String outPath = L"../out/CloneAtEndOfAnotherPresentation.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	//Instantiate target presentation object
	SharedPtr<Presentation> destPres = MakeObject<Presentation>();

	// Accessing Slide by ID from collection
	SharedPtr<ISlideCollection> slideCollection = destPres->get_Slides();

	// Clone the desired slide at end of other presentation
	slideCollection->AddClone(pres->get_Slides()->idx_get(0));

	// Writing the presentation file
	destPres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:CloneAtEndOfAnotherPresentation
}
void::ManageSlides::CloneInAnotherPresentationAtSpecifiedPosition()
{
	//ExStart:CloneInAnotherPresentationAtSpecifiedPosition

	// The path to the documents directory.
	const String templatePath = L"../templates/AddSlides.pptx";
	const String outPath = L"../out/CloneAnotherPresentationAtSpecifiedPosition.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);
	
	//Instantiate target presentation object
	SharedPtr<Presentation> destPres = MakeObject<Presentation>();

	// Accessing Slide by ID from collection
	SharedPtr<ISlideCollection> slideCollection = destPres->get_Slides();

	// Clone the desired slide at end of other presentation
	slideCollection->InsertClone(1,pres->get_Slides()->idx_get(0));

	// Writing the presentation file
	destPres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:CloneInAnotherPresentationAtSpecifiedPosition
}

void::ManageSlides::CloneAtEndOfAnotherSpecificPosition()
{
	//ExStart:CloneAtEndOfAnotherSpecificPosition

	// The path to the documents directory.
	const String templatePath = L"../templates/AddSlides.pptx";
	const String outPath = L"../out/CloneAtEndOfAnotherSpecificPosition.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	//Instantiate target presentation object
	SharedPtr<Presentation> destPres = MakeObject<Presentation>();

	// Accessing Slide by ID from collection
	SharedPtr<ISlideCollection> slideCollection = destPres->get_Slides();

	// Clone the desired slide at end of other presentation
	slideCollection->InsertClone(1, pres->get_Slides()->idx_get(0));

	// Writing the presentation file
	destPres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:CloneAtEndOfAnotherSpecificPosition
}

void::ManageSlides::CloneToAnotherPresentationWithMaster()
{
	//ExStart:CloneToAnotherPresentationWithMaster

	// The path to the documents directory.
	const String templatePath = L"../templates/AddSlides.pptx";
	const String outPath = L"../out/CloneToAnotherPresentationWithMaster.pptx";

	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	//Instantiate target presentation object
	SharedPtr<Presentation> destPres = MakeObject<Presentation>();

	// Accessing Slide by ID from collection
	SharedPtr<ISlideCollection> slideCollection = destPres->get_Slides();

	
	// Instantiate ISlide from the collection of slides in source presentation along with
	// Master slide
	SharedPtr<ISlide> SourceSlide = pres->get_Slides()->idx_get(0);
	SharedPtr<IMasterSlide> SourceMaster = SourceSlide->get_LayoutSlide()->get_MasterSlide();

	// Clone the desired master slide from the source presentation to the collection of masters in the
	// Destination presentation
	SharedPtr<IMasterSlideCollection> masters = destPres->get_Masters();
	SharedPtr<IMasterSlide> DestMaster = SourceSlide->get_LayoutSlide()->get_MasterSlide();

	// Clone the desired master slide from the source presentation to the collection of masters in the
	// Destination presentation
	SharedPtr<IMasterSlide> iSlide = masters->AddClone(SourceMaster);

	// Clone the desired slide from the source presentation with the desired master to the end of the
	// Collection of slides in the destination presentation
	slideCollection->AddClone(SourceSlide, iSlide, true);

	
	// Clone the desired slide at end of other presentation
	slideCollection->InsertClone(1, pres->get_Slides()->idx_get(0));

	// Writing the presentation file
	destPres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:CloneToAnotherPresentationWithMaster
}

void::ManageSlides:: CloneToAnotherPresentationWithSetSizeAndType()
{
	//ExStart:CloneToAnotherPresentationWithSetSizeAndType

	// The path to the documents directory.
	const String templatePath = L"../templates/AddSlides.pptx";
	const String outPath = L"../out/CloneToAnotherPresentationWithSetSizeAndType.pptx";
	// Instantiate Presentation class
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	//Instantiate target presentation object
	SharedPtr<Presentation> destPres = MakeObject<Presentation>();

	// Accessing Slide by ID from collection
	SharedPtr<ISlideCollection> slideCollection = destPres->get_Slides();

	// Set the slide size of generated presentations to that of source
	destPres->get_SlideSize()->set_Type( pres->get_SlideSize()->get_Type());
	destPres->get_SlideSize()->set_Size(pres->get_SlideSize()->get_Size());

//	destPres->get_SlideSize()->set_Size(Size(pres->get_SlideSize()->get_Type(),);


	// Clone the desired slide at desired position of other presentation
	slideCollection->InsertClone(1, pres->get_Slides()->idx_get(0));

	// Writing the presentation file
	destPres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	//ExEnd:CloneToAnotherPresentationWithSetSizeAndType
}