#pragma once
#include <system/object_ext.h>

#include <DOM/Presentation.h>
#include <DOM/IPresentation.h>
#include <Export/SaveFormat.h>
#include <Export/HtmlOptions.h>
#include<Export/ResponsiveHtmlController.h>
#include <Export/HtmlFormatter.h>
#include <DOM/ISlideCollection.h>
#include <Export/IHtmlFormattingController.h>
#include <Export/IHtmlGenerator.h>

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;

 class CustomFormattingController :: IHtmlFormattingController
{
	 void IHtmlFormattingController.WriteDocumentStart(IHtmlGenerator generator, IPresentation presentation);

	void IHtmlFormattingController.WriteDocumentEnd(IHtmlGenerator generator, IPresentation presentation);

	void IHtmlFormattingController.WriteSlideStart(IHtmlGenerator generator, ISlide slide);

	void IHtmlFormattingController.WriteSlideEnd(IHtmlGenerator generator, ISlide slide);

	void IHtmlFormattingController.WriteShapeStart(IHtmlGenerator generator, IShape shape);

	void IHtmlFormattingController.WriteShapeEnd(IHtmlGenerator generator, IShape shape);

	private const string SlideHeader = "<div class=\"slide\" name=\"slide\" id=\"slide{0}\">";
	private const string SlideFooter = "</div>";
 };
