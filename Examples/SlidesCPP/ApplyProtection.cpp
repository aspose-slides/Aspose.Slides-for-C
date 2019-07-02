#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IShapeCollection.h>
#include <DOM/Shape.h>
#include <DOM/IAutoShape.h>
#include <DOM/IAutoShapeLock.h>
#include <DOM/IGroupShape.h>
#include <DOM/IGroupShapeLock.h>
#include <DOM/IConnector.h>
#include <DOM/IConnectorLock.h>
#include <DOM/IPictureFrame.h>
#include <DOM/IPictureFrameLock.h>
#include <DOM/ISlide.h>
#include <system/object.h>
#include <Export/SaveFormat.h>

#include "SlidesExamples.h"
using namespace Aspose;
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

			if (System::ObjectExt::Is<IAutoShape>(shape)) {

				//Type casting to Auto shape and  getting auto shape lock
				SharedPtr<IAutoShape> aShp = DynamicCast<Aspose::Slides::IAutoShape>(shape);
				SharedPtr<IAutoShapeLock> autoShapeLock = DynamicCast<Aspose::Slides::IAutoShapeLock>(aShp->get_ShapeLock());

				//Applying shapes locks
				autoShapeLock->set_PositionLocked(true);
				autoShapeLock->set_SelectLocked(true);
				autoShapeLock->set_SizeLocked(true);
			}
			//if shape is group shape
			else if (System::ObjectExt::Is<IGroupShape>(shape)) {

				//Type casting to group shape and  getting group shape lock
				SharedPtr<IGroupShape> group = DynamicCast<Aspose::Slides::IGroupShape>(shape);
				SharedPtr<IGroupShapeLock> groupShapeLock = DynamicCast<Aspose::Slides::IGroupShapeLock>(group->get_ShapeLock());

				//Applying shapes locks
				groupShapeLock->set_GroupingLocked(true);
				groupShapeLock->set_PositionLocked(true);
				groupShapeLock->set_SelectLocked(true);
				groupShapeLock->set_SizeLocked(true);
			}
			//if shape is a connector
			else if (System::ObjectExt::Is<IConnector>(shape)) {

				//Type casting to connector shape and  getting connector shape lock
				SharedPtr<IConnector> conn = DynamicCast<Aspose::Slides::IConnector>(shape);
				SharedPtr<IConnectorLock> connLock = DynamicCast<Aspose::Slides::IConnectorLock>(conn->get_ShapeLock());

				//Applying shapes locks				
				connLock->set_PositionMove(true);
				connLock->set_SelectLocked(true);
				connLock->set_SizeLocked(true);
			}
			//if shape is picture frame
			else if (System::ObjectExt::Is<IPictureFrame>(shape)) {

				//Type casting to pitcture frame shape and  getting picture frame shape lock
				SharedPtr<IPictureFrame> pic = DynamicCast<Aspose::Slides::IPictureFrame>(shape);
				SharedPtr<IPictureFrameLock> picLock = DynamicCast<Aspose::Slides::IPictureFrameLock>(pic->get_ShapeLock());

				//Applying shapes locks				
				picLock->set_PositionLocked(true);
				picLock->set_SelectLocked(true);
				picLock->set_SizeLocked(true);
			}			
		}
	}

	//Saving the presentation file
	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);

	// ExEnd:ApplyProtection
}