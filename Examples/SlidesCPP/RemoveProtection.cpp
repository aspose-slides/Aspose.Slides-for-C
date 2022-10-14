#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void RemoveProtection()
{
	// ExStart:RemoveProtection
	// The path to the documents directory.
	const String templatePath = u"../templates/ProtectedSample.pptx";
	const String outPath = u"../out/RemoveProtectionSample.pptx";

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
				SharedPtr<IAutoShape> aShp = ExplicitCast<IAutoShape>(shape);
				SharedPtr<IAutoShapeLock> autoShapeLock = ExplicitCast<IAutoShapeLock>(aShp->get_ShapeLock());

				//Applying shapes locks
				autoShapeLock->set_PositionLocked(false);
				autoShapeLock->set_SelectLocked(false);
				autoShapeLock->set_SizeLocked(false);
			}
			//if shape is group shape
			else if (ObjectExt::Is<IGroupShape>(shape)) {

				//Type casting to group shape and  getting group shape lock
				SharedPtr<IGroupShape> group = ExplicitCast<IGroupShape>(shape);
				SharedPtr<IGroupShapeLock> groupShapeLock = ExplicitCast<IGroupShapeLock>(group->get_ShapeLock());

				//Applying shapes locks
				groupShapeLock->set_GroupingLocked(false);
				groupShapeLock->set_PositionLocked(false);
				groupShapeLock->set_SelectLocked(false);
				groupShapeLock->set_SizeLocked(false);
			}
			//if shape is a connector
			else if (ObjectExt::Is<IConnector>(shape)) {

				//Type casting to connector shape and  getting connector shape lock
				SharedPtr<IConnector> conn = ExplicitCast<IConnector>(shape);
				SharedPtr<IConnectorLock> connLock = ExplicitCast<IConnectorLock>(conn->get_ShapeLock());

				//Applying shapes locks				
				connLock->set_PositionMove(false);
				connLock->set_SelectLocked(false);
				connLock->set_SizeLocked(false);
			}
			//if shape is picture frame
			else if (ObjectExt::Is<IPictureFrame>(shape)) {

				//Type casting to pitcture frame shape and  getting picture frame shape lock
				SharedPtr<IPictureFrame> pic = ExplicitCast<IPictureFrame>(shape);
				SharedPtr<IPictureFrameLock> picLock = ExplicitCast<IPictureFrameLock>(pic->get_ShapeLock());

				//Applying shapes locks				
				picLock->set_PositionLocked(false);
				picLock->set_SelectLocked(false);
				picLock->set_SizeLocked(false);
			}
		}
	}

	//Saving the presentation file
	pres->Save(outPath, Export::SaveFormat::Pptx);

	// ExEnd:RemoveProtection
}
