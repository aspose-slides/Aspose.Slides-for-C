#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void ApplyProtection()
{

	// ExStart:ApplyProtection
	// The path to the documents directory.
	const String templatePath = u"../templates/RectPicFrame.pptx";
	const String outPath = u"../out/ProtectedSample.pptx";

	//Instatiate Presentation class that represents a PPTX
	SharedPtr<Presentation> pres = MakeObject<Presentation>(templatePath);

	//ISlide object for accessing the slides in the presentation
	SharedPtr<ISlide> slide = pres->get_Slides()->idx_get(0);

	//IShape object for holding temporary shapes
	SharedPtr<IShape> shape;

	//Traversing through all the slides in the presentation
	for (int slideCount = 0; slideCount < pres->get_Slides()->get_Count(); slideCount++)
	{
		slide = pres->get_Slides()->idx_get(slideCount);

		//Travesing through all the shapes in the slides
		for (int count = 0; count < slide->get_Shapes()->get_Count(); count++)
		{
			shape = slide->get_Shapes()->idx_get(count);  

			if (ObjectExt::Is<IAutoShape>(shape)) {

				//Type casting to Auto shape and  getting auto shape lock
				SharedPtr<IAutoShape> aShp = DynamicCast<IAutoShape>(shape);
				SharedPtr<IAutoShapeLock> autoShapeLock = DynamicCast<IAutoShapeLock>(aShp->get_ShapeLock());

				//Applying shapes locks
				autoShapeLock->set_PositionLocked(true);
				autoShapeLock->set_SelectLocked(true);
				autoShapeLock->set_SizeLocked(true);
			}
			//if shape is group shape
			else if (ObjectExt::Is<IGroupShape>(shape)) {

				//Type casting to group shape and  getting group shape lock
				SharedPtr<IGroupShape> group = DynamicCast<IGroupShape>(shape);
				SharedPtr<IGroupShapeLock> groupShapeLock = DynamicCast<IGroupShapeLock>(group->get_ShapeLock());

				//Applying shapes locks
				groupShapeLock->set_GroupingLocked(true);
				groupShapeLock->set_PositionLocked(true);
				groupShapeLock->set_SelectLocked(true);
				groupShapeLock->set_SizeLocked(true);
			}
			//if shape is a connector
			else if (ObjectExt::Is<IConnector>(shape)) {

				//Type casting to connector shape and  getting connector shape lock
				SharedPtr<IConnector> conn = DynamicCast<IConnector>(shape);
				SharedPtr<IConnectorLock> connLock = DynamicCast<IConnectorLock>(conn->get_ShapeLock());

				//Applying shapes locks				
				connLock->set_PositionMove(true);
				connLock->set_SelectLocked(true);
				connLock->set_SizeLocked(true);
			}
			//if shape is picture frame
			else if (ObjectExt::Is<IPictureFrame>(shape)) {

				//Type casting to pitcture frame shape and  getting picture frame shape lock
				SharedPtr<IPictureFrame> pic = DynamicCast<IPictureFrame>(shape);
				SharedPtr<IPictureFrameLock> picLock = DynamicCast<IPictureFrameLock>(pic->get_ShapeLock());

				//Applying shapes locks				
				picLock->set_PositionLocked(true);
				picLock->set_SelectLocked(true);
				picLock->set_SizeLocked(true);
			}			
		}
	}

	//Saving the presentation file
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:ApplyProtection
}