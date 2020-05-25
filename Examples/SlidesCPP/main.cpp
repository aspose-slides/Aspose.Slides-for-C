#include "stdafx.h"
#include <Util/License.h>
#include <BuildVersionInfo.h>
#include "SlidesExamples.h"

using namespace System;
using namespace Aspose::Slides;

void ShowSlidesVersion()
{
	Console::WriteLine(u"API version details : " + BuildVersionInfo::Product() + u" " + BuildVersionInfo::AssemblyVersion());
}

int main(int argc, const char argv[])
{
	try
	{
        Directory::CreateDirectory_(GetOutPath());

	    #pragma region Showing API Version	
	    ShowSlidesVersion();
	    #pragma endregion
        
	    #pragma region Load License
	    // The path to the License file.
	    const String LicPath = u"../license/Aspose.Total.NET.lic";
	    try
        {
            //System::MakeObject<Aspose::Slides::License>()->SetLicense(LicPath);
		    SharedPtr<License> lic = MakeObject<License>();
		    lic->SetLicense(LicPath);

		    //Check if License is applied
		    if (lic->IsLicensed())
		    {
			    Console::WriteLine(u"License properly applied");
		    }
		    else
		    {
			    Console::WriteLine(u"Warning: License is not properly applied or is expired");
		    }
	    }
	    catch (Exception e)
	    {
		    Console::WriteLine(e->get_Message());
	    }
	    #pragma endregion 
        
	    #pragma region Working with Presentation Decks
	    ExtractTextFromSlide();
        
	    #pragma region Presentation Conversions to different formats
	    ConversionToTIFFNotes();
	    ConvertNotesSlideViewToPDF();
	    ConvertPresentationToPasswordProtectedPDF();
	    ConvertPresentationToResponsiveHTML();
	    ConvertToPDF();
	    ConvertToPDFWithHiddenSlides();
	    ConvertToSWF();
	    ConvertWholePresentationToHTML();
	    ConvertWithoutXpsOptions();
	    ConvertWithXpsOptions();
	    CustomOptionsPDFConversion();
	    PPTtoPPTX();
	    PresentationToTIFFWithCustomImagePixelFormat();
	    PresentationToTIFFWithDefaultSize();
	    ConvertIndividualSlideToHTML();
	    EmbedFontsInHtml();
        ConvertingPresentationToHtmlWithEmbedAllFontsHtmlController();
	    BestImagesCompressionRatioforPDF();
	    ExportToHTMLWithResponsiveLayout();
	    CovertToPDFWithProgressUpdate();
	    SaveToStream();
        ConvertToFodp();
        ConvertToPdfConformancePdf1A_PdfUa();

	    #pragma endregion

	    #pragma region Opening presentation decks

	    OpenPasswordPresentation();
	    OpenPresentation();
	    VerifyingPresentationWithoutloading();
	    OpenVeryLargePresentation();
	    CloneSlideIntoSpecifiedSection();
	    SetAccessPermissionsToPDF();                   

	    #pragma endregion
        
	    #pragma region Loading Options

	    SpecifyFontsUsedWithPresentation();
	    AddingEMZImagesToImageCollection();
	    AddBlobToPresentation();

	    #pragma endregion
        
	    #pragma region Working with Presentation Document properties

	    AccessBuiltinProperties();
	    AccessModifyingProperties();
	    AccessOpenDoc();
	    AccessProperties();
	    UpdatePresentationProperties();
	    UpdatePresentationPropertiesUsingNewTemplate();
	    UpdatePresentationPropertiesUsingPropertiesOfAnotherPresentationAsATemplate();
        ReadOnlyRecommendedProperties();
        CheckPresentationProtection();

	    #pragma endregion

	    #pragma region Saving Presentation decks

	    RemoveWriteProtection();
	    CreateNewPresentation();
	    SaveAsPredefinedViewType();
	    SaveAsReadOnly();
	    SaveProperties();
	    SaveToFile();
	    SaveWithPassword();
	    ExportBlobFromPresentation();
	    SavingHTMLAndCSSFileWhenExportingIntoHTML();
	    RenderingNotesWhileConvertingToHTML();
	    ConvertingPresentationToHTMLWithPreservingOriginalFonts();
	    ApplyingExternalThemeToDependingSlides();
	    SettingInterruptionToken();
	    AddBlobImageToPresentation();
        AddImageFromSVGObjectFromExternalResource();
        ConvertSvgImageObjectIntoGroupOfShapes();
        AddImageFromSVGObject();
	    #pragma endregion

	    #pragma region Presentation Rendering-Printing
        // This doesn't work.
	    //DefaultPrinterPrinting();
        //SpecificPrinterPrinting();
	    SetSlideNumber();
	    SetZoom();
        SupportOfDigitalSignature();
	    #pragma endregion
	    
	    #pragma region Managing VBA Macros
	    System::Console::WriteLine(u"Managing VBA Macros");

	    AddVBAMacros();
	    RemoveVBAMacros();
	    ExtractingVBAMacros();
	    #pragma endregion
	    
	    #pragma endregion

	    #pragma region Working with Slides

	    #pragma region Slide CRUD operations
	    System::Console::WriteLine(u"Working with slide CRUD");
        
	    AddSlides();
	    AddLayoutSlides();
	    AccessSlides();
	    AccessSlidebyID();
	    AccessSlidebyIndex();
	    RemoveSlideUsingIndex();
	    RemoveSlideUsingReference();
	    ChangePosition();
	    CloneWithInSamePresentation();
	    CloneAtEndOfAnotherPresentation();
	    CloneInAnotherPresentationAtSpecifiedPosition();
	    CloneAtEndOfAnotherSpecificPosition();
	    CloneToAnotherPresentationWithMaster();
	    CloneToAnotherPresentationWithSetSizeAndType();
	    ManageSlidesSections();
	    AddNotesSlideWithNotesStyle();

	    #pragma endregion 

	    #pragma region Setting slides backgrounds
	    System::Console::WriteLine(u"Setting slide backgrounds");

	    SetBackgroundToGradient();
	    SetImageAsBackground();
	    SetSlideBackgroundMaster();
	    SetSlideBackgroundNormal();
        GetBackgroundEffectiveValues();
	    #pragma endregion 

	    #pragma region working with SlidesComments
	    System::Console::WriteLine(u"Working with slide comments");

	    AddSlideComments();
	    AccessSlideComments();
        AddParentComments();
	    #pragma endregion

	    #pragma region Working with hyperlinks
	    System::Console::WriteLine(u"Working with slide hyperlinks");

	    RemoveHyperlinks();
        SetHyperlinkColor();
	    MutableHyperlink();
        AddHyperlink();
	    #pragma endregion

	    #pragma region Managing slide layouts
	    System::Console::WriteLine(u"Setting slide size for PDF");

	    SetPDFPageSize();
	    #pragma endregion

	    #pragma region Extract Data from Presentation
	    System::Console::WriteLine(u"Extracting video from presentation");

	    ExtractVideo();
	    #pragma endregion
		    
	    #pragma region Managing slide Notes
	    System::Console::WriteLine(u"Manaing Slide Notes");

	    RemoveNotesAtSpecificSlide();
	    RemoveNotesFromAllSlides();
	    #pragma endregion

	    #pragma region Rendering Slides
	    System::Console::WriteLine(u"Rendering Slides");

	    CreateSlidesSVGImage();
	    ThumbnailFromSlide();
	    ThumbnailFromSlideInNotes();
	    ThumbnailWithUserDefinedDimensions();
        GeneratingSVGWithCustomShapeIDS();
        RenderComments();

	    #pragma endregion

	    #pragma region Managing Slide Transitions
	    System::Console::WriteLine(u"Managing Slide Transitions");

	    ManageSimpleSlideTransitions();
	    ManagingBetterSlideTransitions();
	    SetTransitionEffects();
	    SimpleSlideTransitions();
        SupportOfMorphTransition();
        SetTransitionMorphType();
	    CheckSlidesComparison();
	    HeaderFooterManager();
	    HandoutHeaderFooterManager();
	    MasterNotesSlideHeaderFooterManager();
	    SetChildFooter();
	    SetSizeAndType();
        SetSlideSizeScale();
	    #pragma endregion

	    #pragma region Working with Shapes

        GetCameraEffectiveData();
        GetLightRigEffectiveData();
        GetShapeBevelEffectiveData();
        SubstitutePictureTitleOfOLEObjectFrame();
        AddMathematicalShape();
        ShapesAlignment();

	    #pragma region Working with Charts
	    System::Console::WriteLine(u"Working with Charts");

	    AddCustomError();
	    AddErrorBars();
	    AnimatingCategoriesElements();
	    AnimatingSeries();
	    AnimatingSeriesElements();
	    AutomaticChartSeriescolor();
	    ChangeChartCategoryAxis();
	    ChartEntities();
	    ChartTrendLines();
	    DisplayChartLabels();
	    DisplayPercentageAsLabels();
	    DoughnutChartHole();
	    ExistingChart();
	    ManagePropertiesCharts();
	    NormalCharts();
	    NumberFormat();
	    PieChart();
	    ScatteredChart();
	    SecondPlotOptionsforCharts();
	    SetAutomaticSeriesFillColor();
	    SetCategoryAxisLabelDistance();
	    SetChartSeriesOverlap();
	    SetDataLabelsPercentageSign();
	    SetDataRange();
	    SetGapWidth();
	    MultiCategoryChart();
        // This doesn't work.
	    //SwitchChartRowColumns();
	    SettingAutomicPieChartSliceColors();
	    AddBoxAndWhiskerChart();
	    AddFunnelChart();
	    AddHistogramChart();
	    AddHistogramParetoChart();
	    AddSunburstChart();
	    AddTreemapChart();
	    AddWaterfallChart();
	    SettingPrecisionOfDataLabel();
	    DateFormatForCategoryAxis();
	    VerticalAxisRotationAngle();
	    SettingPositionAxis();
	    ShowDisplayUnitLabelOnChartValueAxis();
	    SettingBubbleChartScaling();
	    SetMarkerOptionsonSeries();
	    GetChartImage();
	    ChangingSeriesColor();
	    SettingChartAreaRoundedBorders();
	    ChangeColorOfCategoriesInSeries();
	    SettingFontPropertiesForChartDataTable();
	    SettingFontSizeOfLegend();
	    SettingFontSizeOfIndividualLegend();
	    SettingInvertIfNegativePropertyForIndividualSeries();
	    AddStockChart();
	    AddDoughnutCallout();
	    HideInformationFromChart();
	    AddingCustomLines();
	    FontPropertiesForChart();
	    ClearSpecificChartSeriesDataPointsData();
	    DefaultMarkersInChart();
	    SetExternalWorkbookWithUpdateChartData();
	    SetLayoutMode();
        try
        {
            EditChartDatainExternalWorkbook();
        }
        catch (const InvalidOperationException& e)
        {
            Console::WriteLine(e);
        }
        SetExternalWorkbook();
        CreateExternalWorkbook();
        SupportOfBubbleSizeRepresentation();
        AddRadarChart();
        SetChartDataCellFormulas();
        SpreadsheetFormulasOptions();
	    #pragma endregion

	    #pragma region ManageAutoShapes	
	    System::Console::WriteLine(u"Working with AutoShapes");

	    AccessingAltTextinGroupshapes();
	    AddArrowShapedLine();
	    AddArrowShapedLineToSlide();
	    AddPlainLineToSlide();
	    ChangeShapeOrder();
	    ConnectorLineAngle();
	    ConnectShapesUsingConnectors();
	    ConnectShapeUsingConnectionSite();
	    FormatJoinStyles();
	    FormatLines();
	    FormattedEllipse();
	    FormattedRectangle();
	    SimpleEllipse();
	    SimpleRectangle();
	    GetCameraEffectiveData();
	    GetLightRigEffectiveData();
	    GetShapeBevelEffectiveData();
	    AddColorToDataPoints();
	    #pragma endregion
        
	    #pragma region ManageFrameObjects	
	    System::Console::WriteLine(u"Working with OLE Objects");

	    AccessOLEObjectFrame();
	    AddAudioFrame();
	    AddOLEObjectFrame();
	    AddRelativeScaleHeightPictureFrame();
	    AddSimplePictureFrames();
	    AddVideoFrame();
	    AddVideoFrameFromWebSource();
	    ChangeOLEObjectData();
	    EmbeddedVideoFrame();
	    PictureFrameFormatting();
	    StretchOffsetLeftForPictureFrame();
	    SetFileTypeForAnEmbeddingObject();
	    ExtractEmbeddedFileDataFromOLEObject();
	    #pragma endregion

	    #pragma region ShapeEffects	
	    System::Console::WriteLine(u"Managing Shape Effects");

	    AnimationsOnShapes();
	    Apply3DRotationEffectOnShape();
	    ApplyBevelEffects();
	    CloneShapes();
	    CreateBoundsShapeThumbnail();
	    CreateGroupShape();
	    CreateScalingFactorThumbnail();
	    CreateShapeThumbnail();
	    CreateSmartArtChildNoteThumbnail();
	    FillShapesGradient();
	    FillShapesPattern();
	    FillShapesPicture();
	    FillShapeswithSolidColor();
	    FindShapeInSlide();
	    Hidingshapes();
	    InterlopShapeID();
	    RemoveShape();
	    RotatingShapes();
	    SetAlternativeText();
	    InsertSvgIntoPresentation();
	    AnimationsOnOLEObject();
	    CreateShapeSVGImage();

	    #pragma endregion

	    #pragma region SmartArt	
	    System::Console::WriteLine(u"Working with SmartArt Shapes");

	    AccessChildNodes();
	    AccessChildNodeSpecificPosition();
	    AccessSmartArt();
	    AccessSmartArtParticularLayout();
	    AccessSmartArtShape();
	    AddNodes();
	    AddNodesSpecificPosition();
	    AssistantNode();
	    ChangeSmartArtLayout();
	    ChangeSmartArtShapeColorStyle();
	    ChangeSmartArtState();
	    ChangeTextOnSmartArtNode();
	    ChangSmartArtShapeStyle();
	    CheckSmartArtHiddenProperty();
	    CreateSmartArtShape();
	    FillFormatSmartArtShapeNode();
	    OrganizeChartLayoutType();
	    RemoveNode();
	    RemoveNodeSpecificPosition();
	    SmartArtNodeLevel();
	    GetTextFromSmartArtNode();
	    ShowPictureOrganizationChart();
	    CustomChildNodesInSmartArt();

	    #pragma endregion

	    #pragma region Working with Tables	
	    System::Console::WriteLine(u"Working with Tables");

	    AddImageinsideTableCell();
	    CellSplit();
	    CloningInTable();
	    MergeCell();
	    MergeCells();
	    RemovingRowColumn();
	    StandardTables();
	    TableFromScratch();
	    TableWithCellBorders();
	    UpdateExistingTable();
	    VerticallyAlignText();
	    LockAspectRatio();
	    GetEffectiveValuesOfTable();
	    #pragma endregion
        
	    #pragma region Formatting Text	
	    Console::WriteLine(u"Formatting Text");

	    ApplyInnerShadow();
	    ApplyOuterShadow();
	    CustomRotationAngleTextframe();
	    DefaultFonts();
	    ExportingHTMLText();
	    FontFamilySetting();
	    FontProperties();
	    ImportingHTMLText();
	    LineSpacing();
	    ManageEmbeddedFonts();
	    ManageParagraphFontProperties();
	    ManageParagraphPictureBulletsInPPT();
	    MultipleParagraphs();
	    ParagraphBullets();
	    ParagraphIndent();
	    ParagraphsAlignment();
	    ReplaceFontsExplicitly();
	    ReplacingText();
	    RotatingText();
	    RuleBasedFontsReplacement();
	    SetAnchorOfTextFrame();
	    SetAutofitOftextframe();
	    SetTextFontProperties();
	    ShadowEffects();
	    TextBoxHyperlink();
	    TextBoxOnSlideProgram();
	    UseCustomFonts();
	    AddEmbeddedFonts();
	    AddColumnInTexBoxes();
	    GetFontsFolders();
	    AddingSuperscriptAndSubscriptTextInTextFrame();
	    EndParaGraphProperties();
	    GetEffectsByTextParagraph();
	    MutilevelBullets();
	    HighlightText();
	    HighlightTextUsingRegx();
	    SetTransparencyOfTextInShadow();
	    AddColumnsinTextFrame();
	    AnimationEffectinParagraph();
	    GetEffectiveValues();
	    SetLocalFontHeightValues();
	    GetTextFrameFormatEffectiveData();
	    GetTextStyleEffectiveData();
	    SetCustomBulletsNumber();
	    SetFontFallBack();
	    FallBackRulesCollection();
	    RenderingWithFallBackFont();
	    SetDefaultFont();
        AddCustomPromptText();
        PortionGetRect();

	    #pragma endregion		

        #pragma region Views
        Console::WriteLine(u"Views");
        ManagePresenetationNormalViewState();
        #pragma endregion

	    #pragma endregion

	    #pragma endregion

	    Console::WriteLine(u"Examples processed successfully...");
    }
    catch (const Exception& error)
    {
        Console::WriteLine(u"Error: {0}", error);
        return 1;
    }
    catch (const std::exception& error)
    {
        std::cerr << "Error: " << error.what() << std::endl;
        return 1;
    }

    return 0;
}
