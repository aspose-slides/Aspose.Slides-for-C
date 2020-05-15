#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void ConnectShapeUsingConnectionSite()
{
	// ExStart:ConnectShapeUsingConnectionSite

	// The path to the documents directory.
	const String outPath = u"../out/ConnectShapeUsingConnectionSite_out.pptx";
	const String templatePath = u"../templates/ConnectorLineAngle.pptx";

	// Load the desired the presentation
	SharedPtr<Presentation> pres = MakeObject<Presentation>();

	// Access first slide
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	// Accessing shapes collection for selected slide
	SharedPtr<IShapeCollection> shapes = slide->get_Shapes();

	// Add an autoshape of type Ellipse
	SharedPtr<IAutoShape> ellipse = slide->get_Shapes()->AddAutoShape(ShapeType::Ellipse, 0, 100, 100, 100);

	// Add an autoshape of type rectangle
	SharedPtr<IAutoShape> rect = slide->get_Shapes()->AddAutoShape(ShapeType::Rectangle, 100, 200, 100, 100);

	// Adding connector shape to slide shape collection
	SharedPtr<IConnector> connector = shapes->AddConnector(ShapeType::BentConnector3, 0, 0, 10, 10);

	// Joining Shapes to connectors
	connector->set_StartShapeConnectedTo(ellipse);
	connector->set_EndShapeConnectedTo(rect);

	// Setting the desired connection site index of Ellipse shape for connector to get connected
	int wantedIndex = 6;

	// Checking if desired index is less than maximum site index count
	if (ellipse->get_ConnectionSiteCount() > wantedIndex)
	{
		// Setting the desired connection site for connector on Ellipse
		connector->set_StartShapeConnectionSiteIndex ( wantedIndex);
	}

	//Write the PPTX to Disk
	pres->Save(outPath, Export::SaveFormat::Pptx);

	//ExEnd:ConnectShapeUsingConnectionSite
}
