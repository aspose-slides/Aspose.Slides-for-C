#include "stdafx.h"
#include <Util/License.h>
#include <BuildVersionInfo.h>
#include "SlidesExamples.h"

using namespace System;
using namespace Aspose::Slides::Export;
using namespace System::Drawing;
using namespace System::IO;
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
            SharedPtr<License> lic = MakeObject<License>();
            lic->SetLicense(LicPath);

            // Check if License is applied
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
        ConvertToPdfCompliance();
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
        // EmbedFontsInHtml();
        // ConvertingPresentationToHtmlWithEmbedAllFontsHtmlController();
        BestImagesCompressionRatioforPDF();
        ExportToHTMLWithResponsiveLayout();
        CovertToPDFWithProgressUpdate();
        SaveToStream();
        ConvertToFodp();
        ConvertToPdfConformancePdf1A_PdfUa();
        ExportMathParagraphToMathML();
        SvgFormattingController();
        ImportFromPdf();
        ExportToHtmlWithImageLinks();
        ConvertToXaml();
        ConvertToGif();
        ConvertToHtml5();
        SvgConvertionOptions();
        ConvertToAnimation();
        ConvertToMarkdown();
        // ConvertHTMLEmbeddingImages();
        ConvertToBlackWhiteTiff();
        ConvertToHandout();
        ExportInkExample();
        PdfImportTableExample();
        ExportMathParagraphToLatex();
        ConvertToHtml5NotesComments();
        ConvertToPdfUnsupportedFontStyles();
        ConvertToXml();
        ExportOleExample();

#pragma endregion

#pragma region Opening presentation decks

        OpenPasswordPresentation();
        OpenPresentation();
        VerifyingPresentationWithoutloading();
        OpenVeryLargePresentation();
        CloneSlideIntoSpecifiedSection();
        SetAccessPermissionsToPDF();
        DeleteEmbeddedBinaryObjects();

#pragma endregion

#pragma region Loading Options

        SpecifyFontsUsedWithPresentation();
        SpecifyDefaultTextLanguage();
        AddingEMZImagesToImageCollection();
        AddBlobToPresentation();

#pragma endregion

#pragma region LowCode

        ForEachPortion();

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
        CheckPasswordExample();
        RootDirectoryClsId();
        PresentationSlideShowSetup();
        SlideShowMediaControls();

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
        //ConvertingPresentationToHTMLWithPreservingOriginalFonts();
        ApplyingExternalThemeToDependingSlides();
        SettingInterruptionToken();
        AddBlobImageToPresentation();
        SaveInZip64Mode();
        AddImageFromSVGObjectFromExternalResource();
        ConvertSvgImageObjectIntoGroupOfShapes();
        AddImageFromSVGObject();
#pragma endregion

#pragma region Presentation Rendering-Printing
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
        AccessToGradientStopParameters();

#pragma endregion 

#pragma region working with SlidesComments
        System::Console::WriteLine(u"Working with slide comments");

        AddSlideComments();
        AccessSlideComments();
        AddParentComments();
        ModernComments();
#pragma endregion

#pragma region Working with hyperlinks
        System::Console::WriteLine(u"Working with slide hyperlinks");

        RemoveHyperlinks();
        SetHyperlinkColor();
        MutableHyperlink();
        AddHyperlink();
        MacroHyperlink();
        ExternalUrlOriginal();
#pragma endregion

#pragma region Managing slide layouts
        System::Console::WriteLine(u"Setting slide size for PDF");

        SetPDFPageSize();
        RemoveUnusedLayoutMaster();
        GetBasePlaceholderExample();
        LayoutPlaceholderManagerExample();
#pragma endregion

#pragma region Extract Data from Presentation
        System::Console::WriteLine(u"Extracting video from presentation");

        ExtractVideo();
        ExtractAudio();
        ExtractAudioFromTimeline();
        ExtractAudioFromHyperLink();
        StopPreviousSoundExample();
#pragma endregion

#pragma region Managing slide Notes
        System::Console::WriteLine(u"Managing Slide Notes");

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
        RenderOptions();
        Rendering3D();

#pragma endregion

#pragma region Managing Slide Transitions
        System::Console::WriteLine(u"Managing Slide Transitions");

        ManageSimpleSlideTransitions();
        ManageBetterSlideTransitions();
        SetTransitionEffects();
        SimpleSlideTransitions();
        SupportOfMorphTransition();
        SetTransitionMorphType();
        AnimationRepeatOnSlide();
        AnimationRewind();
        AfterAnimationTypeExample();
        CheckSlidesComparison();
        ManageHeaderFooter();
        ManageHandoutHeaderFooter();
        ManageMasterNotesSlideHeaderFooter();
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
        MathShape_GetChildren();
        ShapesAlignment();
        SketchedShapes();
        GeometryShapeAddSegment();
        GeometryShapeCompositeObjects();
        GeometryShapeCreatesCustomGeometry();
        GeometryShapeRemoveSegment();
        GeometryShapeUsingShapeUtil();
        CreateSummaryZoom();
        CreateZoomFrame();
        CreateSectionZoom();

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
        SwitchChartRowColumns();
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
        RecoverWorkbook();
        ChartGetRange();
        MapChart();
        CalculateFormulas();
        WorksheetsExample();
        TimeUnitTypeEnum();
        LeaderLineColor();
        ChartPointDataIndex();
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
        AnimationTargetShapes();
        DuotoneEffectsPVI();
        IsTextShape();
        SetVideoTrimFromEnd();
        InkManagementExample();
        DeletePictureCroppedAreasExample();
        ShapeIsDecorativeExample();
        TilePictureFillFormatExample();

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
        TableTransparency();
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
        GetFontsSubstitution();
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
        BulletFillFormatEffective();
        WordArt();
        KeepTextFlat();
        EmbeddedFontCompression();
        FindAndReplaceText();
        AnimateTextTypeExample();
        NumberLinesInParagraph();
        FindAndReplaceTextResult();
        FontBinaryDataExample();
        FontEmbeddingLevelExample();

#pragma endregion

#pragma region Views
        Console::WriteLine(u"Views");
        ManagePresenetationNormalViewState();
        GradientStyleRendering();

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
