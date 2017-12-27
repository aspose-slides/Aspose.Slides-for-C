#include <iostream>
#include <Util/License.h>
#include "AssemblyInfo.h"

#include <system/console.h>
#include <system/exception.h>
#include "SlidesExamples.h"

using namespace System;
using namespace Aspose::Slides;


void ShowSlidesVersion()
{
	System::Console::WriteLine(L"API version details : " + BuildVersionInfo::Product() + L" " + BuildVersionInfo::AssemblyVersion());

}

int main(int argc, const char argv[])
{
	try 
	{

		
		#pragma region Showing API Version	
		ShowSlidesVersion();
		#pragma endregion

		#pragma region Load License
		// The path to the License file.
		const String LicPath = L"../license/Aspose.Slides.lic";
		System::MakeObject<Aspose::Slides::License>()->SetLicense(LicPath);
		SharedPtr<Aspose::Slides::License> lic = MakeObject<Aspose::Slides::License>();
		lic->SetLicense(LicPath);

		//Check if License is applied
		if (lic->IsLicensed())
		{
			System::Console::WriteLine(L"License properly applied");
		}
		else
		{
			System::Console::WriteLine(L"Warning: License is not properly applied or is expired");
		}
		#pragma endregion 

		#pragma region Working with Presentation Decks
	
		#pragma region Managing VBA Macros
			//System::Console::WriteLine(L"Managing VBA Macros");
			//AddVBAMacros();
			//RemoveVBAMacros();
			#pragma endregion
		
		#pragma endregion

		#pragma region Working with Slides
	
		#pragma region Slide CRUD operations
		//System::Console::WriteLine(L"Working with slide CRUD");
		//AddSlides();
		//AddLayoutSlides();
		//AccessSlides();
		//AccessSlidebyID();
		//AccessSlidebyIndex();
		//RemoveSlideUsingIndex();
		//RemoveSlideUsingReference();
		//ChangePosition();
		//CloneWithInSamePresentation();
		//CloneAtEndOfAnotherPresentation();
		//CloneInAnotherPresentationAtSpecifiedPosition();
		//CloneAtEndOfAnotherSpecificPosition();
		//CloneToAnotherPresentationWithMaster();
		//CloneToAnotherPresentationWithSetSizeAndType();
		#pragma endregion 

		#pragma region Setting slides backgrounds
		//System::Console::WriteLine(L"Setting slide backgrounds");
		//SetBackgroundToGradient();
		//SetImageAsBackground();
		//SetSlideBackgroundMaster();
		//SetSlideBackgroundNormal();
		#pragma endregion 

		#pragma region working with SlidesComments
		//System::Console::WriteLine(L"Working with slide comments");
		//AddSlideComments();
		//AccessSlideComments();
		#pragma endregion

		#pragma region Working with hyperlinks
		//System::Console::WriteLine(L"Working with slide hyperlinks");
		//RemoveHyperlinks();
		#pragma endregion

		#pragma region Managing slide layouts
			//System::Console::WriteLine(L"Setting slide size for PDF");
			//SetPDFPageSize();
		#pragma endregion

		#pragma region Extract Data from Presentation
			//System::Console::WriteLine(L"Extracting video from presentation");
			//ExtractVideo();
		#pragma endregion
			
		#pragma region Managing slide Notes
		//System::Console::WriteLine(L"Manaing Slide Notes");
		//RemoveNotesAtSpecificSlide();
		//RemoveNotesFromAllSlides();
		#pragma endregion

		#pragma region Rendering Slides
		//System::Console::WriteLine(L"Rendering Slides");
		//CreateSlidesSVGImage();
		//ThumbnailFromSlide();
		//ThumbnailFromSlideInNotes();
		//ThumbnailWithUserDefinedDimensions();
		#pragma endregion

		#pragma region Managing Slide Transitions
		//System::Console::WriteLine(L"Managing Slide Transitions");
		//ManageSimpleSlideTransitions();
		//ManagingBetterSlideTransitions();
		//SetTransitionEffects();
		//SimpleSlideTransitions();
		#pragma endregion

		#pragma region Working with Shapes

		#pragma region Working with Charts
			//System::Console::WriteLine(L"Working with Charts");
			//AddCustomError();
			//AddErrorBars();
			//AnimatingCategoriesElements();
			//AnimatingSeries();
			//AnimatingSeriesElements();
			//AutomaticChartSeriescolor();
			//ChangeChartCategoryAxis();
			//ChartEntities();
			//ChartTrendLines();
			//DisplayChartLabels();
			//DisplayPercentageAsLabels();
			//DoughnutChartHole();
			//ExistingChart();
			//ManagePropertiesCharts();
			//NormalCharts();
			//NumberFormat();
			//PieChart();
			//ScatteredChart();
			//SecondPlotOptionsforCharts();
			//SetAutomaticSeriesFillColor();
			//SetCategoryAxisLabelDistance();
			//SetChartSeriesOverlap();
			//SetDataLabelsPercentageSign();
			//SetDataRange();
			//SetGapWidth();

		#pragma endregion

		#pragma region ManageAutoShapes	
		//System::Console::WriteLine(L"Working with AutoShapes");
		//AccessingAltTextinGroupshapes();
		//AddArrowShapedLine();
		//AddArrowShapedLineToSlide();
		//AddPlainLineToSlide();
		//ChangeShapeOrder();
		//ConnectorLineAngle();
		//ConnectShapesUsingConnectors();
		//ConnectShapeUsingConnectionSite();
		//FormatJoinStyles();
		//FormatLines();
		//FormattedEllipse();
		//FormattedRectangle();
		//SimpleEllipse();
		//SimpleRectangle();
		#pragma endregion

		#pragma region ManageFrameObjects	
		//System::Console::WriteLine(L"Working with OLE Objects");
		//AccessOLEObjectFrame();
		//AddAudioFrame();
		//AddOLEObjectFrame();
		//AddRelativeScaleHeightPictureFrame();
		//AddSimplePictureFrames();
		//AddVideoFrame();
		//AddVideoFrameFromWebSource();
		//ChangeOLEObjectData();
		//EmbeddedVideoFrame();
		//PictureFrameFormatting();
		#pragma endregion

		#pragma region ShapeEffects	
		//System::Console::WriteLine(L"Managing Shape Effects");
		//AnimationsOnShapes();
		//Apply3DRotationEffectOnShape();
		//ApplyBevelEffects();
		//CloneShapes();
		//CreateBoundsShapeThumbnail();
		//CreateGroupShape();
		//CreateScalingFactorThumbnail();
		//CreateShapeThumbnail();
		//CreateSmartArtChildNoteThumbnail();
		//FillShapesGradient();
		//FillShapesPattern();
		//FillShapesPicture();
		//FillShapeswithSolidColor();
		//FindShapeInSlide();
		//Hidingshapes();
		//InterlopShapeID();
		//RemoveShape();
		//RotatingShapes();
		//SetAlternativeText();
		#pragma endregion

		#pragma region SmartArt	
		//System::Console::WriteLine(L"Working with SmartArt Shapes");
		//AccessChildNodes();
		//AccessChildNodeSpecificPosition();
		//AccessSmartArt();
		//AccessSmartArtParticularLayout();
		//AccessSmartArtShape();
		//AddNodes();
		//AddNodesSpecificPosition();
		//AssistantNode();
		//ChangeSmartArtLayout();
		//ChangeSmartArtShapeColorStyle();
		//ChangeSmartArtState();
		//ChangeTextOnSmartArtNode();
		//ChangSmartArtShapeStyle();
		//CheckSmartArtHiddenProperty();
		//CreateSmartArtShape();
		//FillFormatSmartArtShapeNode();
		//OrganizeChartLayoutType();
		//RemoveNode();
		//RemoveNodeSpecificPosition();
		//SmartArtNodeLevel();
		#pragma endregion

		#pragma region Working with Tables	
		//System::Console::WriteLine(L"Working with Tables");

		//AddImageinsideTableCell();
		//CellSplit();
		//CloningInTable();
		//MergeCell();
		//MergeCells();
		//RemovingRowColumn();
		//StandardTables();
		//TableFromScratch();
		//TableWithCellBorders();
		//UpdateExistingTable();
		//VerticallyAlignText();
		#pragma endregion

		#pragma region Formatting Text	
		System::Console::WriteLine(L"Formatting Text");

		//ApplyInnerShadow();
		//ApplyOuterShadow();
		//CustomRotationAngleTextframe();
		//DefaultFonts();
		//ExportingHTMLText();
		//FontFamilySetting();
		//FontProperties();
		//ImportingHTMLText();
		//LineSpacing();
		//ManageEmbeddedFonts();
		//ManageParagraphFontProperties();
		//ManageParagraphPictureBulletsInPPT();
		//MultipleParagraphs();
		//ParagraphBullets();
		//ParagraphIndent();
		//ParagraphsAlignment();
		//ReplaceFontsExplicitly();
		//ReplacingText();
		//RotatingText();
		//RuleBasedFontsReplacement();
		//SetAnchorOfTextFrame();
		//SetAutofitOftextframe();
		//SetTextFontProperties();
		//ShadowEffects();
		//TextBoxHyperlink();
		//TextBoxOnSlideProgram();
		//UseCustomFonts();
		#pragma endregion		

		#pragma endregion

		#pragma endregion

		System::Console::WriteLine(L"Examples processed successfully...");

		//ChangeOLEObjectData
		//SmartArtNodeLevel

	}//end Try
	catch (const System::Exception& error)
	{
		System::Console::WriteLine(L"Error: {0}", error);
	}
	catch (const std::exception& error)
	{
		std::cerr << "Error: " << error.what() << std::endl;
	}
	
}