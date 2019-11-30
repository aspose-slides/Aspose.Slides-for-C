#include <iostream>
#include <Util/License.h>
#include <BuildVersionInfo.h>
//#include "AssemblyConstants.h"
#include <system/console.h>
#include <system/exception.h>
#include "SlidesExamples.h"

using namespace System;
using namespace Aspose::Slides;


void ShowSlidesVersion()
{
	System::Console::WriteLine(u"API version details : " + BuildVersionInfo::Product() + u" " + BuildVersionInfo::AssemblyVersion());

}

int main(int argc, const char argv[])
{
	try 
	{

		
		#pragma region Showing API Version	
		//ShowSlidesVersion();
		#pragma endregion

		#pragma region Load License
		// The path to the License file.
		const String LicPath = u"../license/Aspose.Total.NET.lic";
		try {
//			System::MakeObject<Aspose::Slides::License>()->SetLicense(LicPath);
			SharedPtr<Aspose::Slides::License> lic = MakeObject<Aspose::Slides::License>();
			lic->SetLicense(LicPath);

			//Check if License is applied
			if (lic->IsLicensed())
		//	if (System::MakeObject<Aspose::Slides::License>()->IsLicensed())
			{
				System::Console::WriteLine(u"License properly applied");
			}
			else
			{
				System::Console::WriteLine(u"Warning: License is not properly applied or is expired");
			}
		}
		catch (Exception e)
		{
			System::Console::WriteLine(e.get_StackTrace());
		}
			#pragma endregion 

		#pragma region Working with Presentation Decks
		//  ExtractTextFromSlide();
		#pragma region Presentation Conversions to different formats
				//TIFF support not available in 17.12
				//ConversionToTIFFNotes();
				//ConvertNotesSlideViewToPDF();
				//ConvertPresentationToPasswordProtectedPDF();
				//ConvertPresentationToResponsiveHTML();
				//ConvertToPDF();
				//ConvertToPDFWithHiddenSlides();
				//ConvertToSWF();
				//ConvertWholePresentationToHTML();
				//ConvertWithoutXpsOptions();
				//ConvertWithXpsOptions();
				//CustomOptionsPDFConversion();
				//PPTtoPPTX();
				//TIFF support not available in 17.12
				//PresentationToTIFFWithCustomImagePixelFormat();
				//PresentationToTIFFWithDefaultSize();
				//LinkAllFontsHtmlController();
				//ConvertIndividualSlideToHTML();
				//EmbedFontsInHtml();
				//ConvertingPresentationToHtmlWithEmbedAllFontsHtmlController();
				//BestImagesCompressionRatioforPDF();
		        //ExportToHTMLWithResponsiveLayout();
		        //CovertToPDFWithProgressUpdate();
		         //SaveToStream();

		#pragma endregion

		#pragma region Opening presentation decks

				//OpenPasswordPresentation();
				//OpenPresentation();
				//VerifyingPresentationWithoutloading();
				//OpenVeryLargePresentation();
                                

		#pragma endregion

		#pragma region Loading Options
				//SpecifyFontsUsedWithPresentation();
				//AddingEMZImagesToImageCollection();
				//AddBlobToPresentation();

		#pragma endregion

		#pragma region Working with Presentation Document properties

				//AccessBuiltinProperties();
				//AccessModifyingProperties();
				//AccessOpenDoc();
				//AccessProperties();
				//UpdatePresentationProperties();
				//UpdatePresentationPropertiesUsingNewTemplate();
				//UpdatePresentationPropertiesUsingPropertiesOfAnotherPresentationAsATemplate();

		#pragma endregion

		#pragma region Saving Presentation decks

				//RemoveWriteProtection();
				//CreateNewPresentation();
				//SaveAsPredefinedViewType();
				//SaveAsReadOnly();
				//This is not working
				//SaveProperties();
				//SaveToFile();
				//This is not working
				//SaveWithPassword();
				//ExportBlobFromPresentation();
				//SavingHTMLAndCSSFileWhenExportingIntoHTML();
				//RenderingNotesWhileConvertingToHTML();
				//ConvertingPresentationToHTMLWithPreservingOriginalFonts();
				//ApplyingExternalThemeToDependingSlides();
				//SettingInterruptionToken();
		        // AddBlobImageToPresentation();

		#pragma endregion

		#pragma region Presentation Rendering-Printing
				//DefaultPrinterPrinting();
				//SetSlideNumber();
				//SetZoom();
				//SpecificPrinterPrinting();
		#pragma endregion
		
		#pragma region Managing VBA Macros
			//System::Console::WriteLine(u"Managing VBA Macros");
			//AddVBAMacros();
			//RemoveVBAMacros();
		    //ExtractingVBAMacros();
			#pragma endregion
		
		#pragma endregion

		#pragma region Working with Slides
	
		#pragma region Slide CRUD operations
		//System::Console::WriteLine(u"Working with slide CRUD");
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
		//ManageSlidesSections();
		//AddNotesSlideWithNotesStyle();


		#pragma endregion 

		#pragma region Setting slides backgrounds
		//System::Console::WriteLine(u"Setting slide backgrounds");
		//SetBackgroundToGradient();
		//SetImageAsBackground();
		//SetSlideBackgroundMaster();
		//SetSlideBackgroundNormal();
        //GetBackgroundEffectiveValues();
		#pragma endregion 

		#pragma region working with SlidesComments
		//System::Console::WriteLine(u"Working with slide comments");
		//AddSlideComments();
		//AccessSlideComments();
		#pragma endregion

		#pragma region Working with hyperlinks
		//System::Console::WriteLine(u"Working with slide hyperlinks");
		//RemoveHyperlinks();
        // SetHyperlinkColor();
		 //MutableHyperlink();
        //AddHyperlink();
		#pragma endregion

		#pragma region Managing slide layouts
			//System::Console::WriteLine(u"Setting slide size for PDF");
			//SetPDFPageSize();
		#pragma endregion

		#pragma region Extract Data from Presentation
			//System::Console::WriteLine(u"Extracting video from presentation");
			//ExtractVideo();
		#pragma endregion
			
		#pragma region Managing slide Notes
		//System::Console::WriteLine(u"Manaing Slide Notes");
		//RemoveNotesAtSpecificSlide();
		//RemoveNotesFromAllSlides();
		#pragma endregion

		#pragma region Rendering Slides
		//System::Console::WriteLine(u"Rendering Slides");
		//CreateSlidesSVGImage();
		//ThumbnailFromSlide();
		//ThumbnailFromSlideInNotes();
		//ThumbnailWithUserDefinedDimensions();
	//	GeneratingSVGWithCustomShapeIDS();
//		RenderComments();

		#pragma endregion

		#pragma region Managing Slide Transitions
		//System::Console::WriteLine(u"Managing Slide Transitions");
		//ManageSimpleSlideTransitions();
		//ManagingBetterSlideTransitions();
		//SetTransitionEffects();
		//SimpleSlideTransitions();
        //SupportOfMorphTransition();
        //SetTransitionMorphType();

		//This is not working
		//CheckSlidesComparison();
		//HeaderFooterManager();
		//HandoutHeaderFooterManager();
		//MasterNotesSlideHeaderFooterManager();
		//SetChildFooter();
		//SetSizeAndType();
		#pragma endregion

		#pragma region Working with Shapes

		#pragma region Working with Charts
			//System::Console::WriteLine(u"Working with Charts");
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
			//MultiCategoryChart();
			//SwitchChartRowColumns();
			//SettingAutomicPieChartSliceColors();
			//AddBoxAndWhiskerChart();
			//AddFunnelChart();
			//AddHistogramChart();
			//AddHistogramParetoChart();
			//AddSunburstChart();
			//AddTreemapChart();
			//AddWaterfallChart();
			//SettingPrecisionOfDataLabel();
			//DateFormatForCategoryAxis();
			//VerticalAxisRotationAngle();
			//SettingPositionAxis();
			//ShowDisplayUnitLabelOnChartValueAxis();
			//SettingBubbleChartScaling();
			//SetMarkerOptionsonSeries();
			//GetChartImage();
			//ChangingSeriesColor();
			//SettingChartAreaRoundedBorders();
			//ChangeColorOfCategoriesInSeries();
			//SettingFontPropertiesForChartDataTable();
			//SettingFontSizeOfLegend();
			//SettingFontSizeOfIndividualLegend();
			//SettingInvertIfNegativePropertyForIndividualSeries();
			//AddStockChart();
			//AddDoughnutCallout();
			//HideInformationFromChart();
			//AddingCustomLines();
		//FontPropertiesForChart();
			//ClearSpecificChartSeriesDataPointsData();
			//DefaultMarkersInChart();
		   // SetExternalWorkbookWithUpdateChartData();
		   //SetLayoutMode();
		#pragma endregion

		#pragma region ManageAutoShapes	
		//System::Console::WriteLine(u"Working with AutoShapes");
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
		//GetCameraEffectiveData();
		//GetLightRigEffectiveData();
	        //GetShapeBevelEffectiveData();
		#pragma endregion

		#pragma region ManageFrameObjects	
		//System::Console::WriteLine(u"Working with OLE Objects");
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
		//StretchOffsetLeftForPictureFrame();
		//SetFileTypeForAnEmbeddingObject();
		//ExtractEmbeddedFileDataFromOLEObject();
		#pragma endregion

		#pragma region ShapeEffects	
		//System::Console::WriteLine(u"Managing Shape Effects");
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
		//InterlopShapeID();
//		InsertSvgIntoPresentation();
		//AnimationsOnOLEObject();
		//CreateShapeSVGImage();

		#pragma endregion

		#pragma region SmartArt	
		//System::Console::WriteLine(u"Working with SmartArt Shapes");
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
		//GetTextFromSmartArtNode();
		//ShowPictureOrganizationChart();
		//CustomChildNodesInSmartArt();
		//EditChartDatainExternalWorkbook();
		//SetExternalWorkbook();
		//CreateExternalWorkbook();

		#pragma endregion

		#pragma region Working with Tables	
		//System::Console::WriteLine(u"Working with Tables");

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
		//LockAspectRatio();
		//GetEffectiveValuesOfTable();
		#pragma endregion

		#pragma region Formatting Text	
		System::Console::WriteLine(u"Formatting Text");

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
		//AddEmbeddedFonts();
		//AddColumnInTexBoxes();
		//GetFontsFolders();
		//AddingSuperscriptAndSubscriptTextInTextFrame();
		//EndParaGraphProperties();
		//GetEffectsByTextParagraph();
		//MutilevelBullets();
		//HighlightText();
		//HighlightTextUsingRegx();
		//SetTransparencyOfTextInShadow();
		//AddColumnsinTextFrame();
		//AnimationEffectinParagraph();
		//GetEffectiveValues();
		//SetLocalFontHeightValues();
	        //GetTextFrameFormatEffectiveData();
		//GetTextStyleEffectiveData();
		//SetCustomBulletsNumber();
		//SetFontFallBack();
		//FallBackRulesCollection();
		//RenderingWithFallBackFont();
		//AccessPromptText();
		#pragma endregion		

		#pragma endregion

		#pragma endregion

		System::Console::WriteLine(u"Examples processed successfully...");

		//ChangeOLEObjectData
		//SmartArtNodeLevel

	}//end Try
	catch (const System::Exception& error)
	{
		System::Console::WriteLine(u"Error: {0}", error);
	}
	catch (const std::exception& error)
	{
		std::cerr << "Error: " << error.what() << std::endl;
	}
	
}
