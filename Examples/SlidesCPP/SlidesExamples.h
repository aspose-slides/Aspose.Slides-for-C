#pragma once
#include <DOM/NullableBool.h>
#include <DOM/DocumentProperties.h>
#include <system/io/directory.h>

inline void Copy(const System::String& from, const System::String& to)
{
    if (System::IO::File::Exists(to))
    {
        System::IO::File::Delete(to);
    }
    System::IO::File::Copy(from, to);
}

inline System::String GetDataPath()
{
    return System::IO::Path::Combine(System::IO::Directory::GetCurrentDirectory(), u"../templates/");
}

inline System::String GetOutPath()
{
    return System::IO::Path::Combine(System::IO::Directory::GetCurrentDirectory(), u"../out/");
}

//Developer Guide > Loading, Saving and Converting

#pragma region Working with ActiveX Controls
void LinkingVideoActiveXControl();
void ManageActiveXControl();
#pragma endregion

#pragma region Working with Presentation Decks
#pragma region Presentation Conversions to different formats

void ConversionToTIFFNotes();
void ConvertNotesSlideViewToPDF();
void ConvertPresentationToPasswordProtectedPDF();
void ConvertPresentationToResponsiveHTML();
void ConvertIndividualSlideToHTML();
void ConvertToPDF();
void ConvertToPDFWithHiddenSlides();
void ConvertToSWF();
void ConvertWholePresentationToHTML();
void ConvertWithoutXpsOptions();
void ConvertWithXpsOptions();
void CustomOptionsPDFConversion();
void PPTtoPPTX();
void PresentationToTIFFWithCustomImagePixelFormat();
void PresentationToTIFFWithDefaultSize();
void EmbedFontsInHtml();
void ConvertingPresentationToHtmlWithEmbedAllFontsHtmlController();
void BestImagesCompressionRatioforPDF();
void SetPDFPageSize();
void ExportToHTMLWithResponsiveLayout();
void ExportToHtmlWithImageLinks();
void CovertToPDFWithProgressUpdate();
void SaveToStream();
void ConvertToFodp();
void ConvertToPdfConformancePdf1A_PdfUa();
void ExportMathParagraphToMathML();
void SvgFormattingController();
void PdfImport();
void ConvertToXaml();
void ConvertToGif();
void ConvertToHtml5();

#pragma endregion

#pragma region Opening presentation decks

void OpenPasswordPresentation();
void OpenPresentation();
void VerifyingPresentationWithoutloading();
void OpenVeryLargePresentation();
void CloneSlideIntoSpecifiedSection();
void SetAccessPermissionsToPDF();

#pragma endregion

#pragma region Loading Options
void MeteredLicencing();
void SpecifyFontsUsedWithPresentation();
void AddingEMZImagesToImageCollection();
void AddBlobToPresentation();
void LoadFormatEnumeration();
void GetFileFormat();
#pragma endregion
#pragma region Working with Presentation Document properties

void AccessBuiltinProperties();
void AccessModifyingProperties();
void AccessOpenDoc();
void AccessProperties();
void UpdatePresentationProperties();
void UpdatePresentationPropertiesUsingNewTemplate();
void UpdateByTemplate(System::String path, System::SharedPtr<Aspose::Slides::DocumentProperties> templateprop);
void UpdatePresentationPropertiesUsingPropertiesOfAnotherPresentationAsATemplate();
void ReadOnlyRecommendedProperties();
void CheckPresentationProtection();
void CheckPasswordExample();
void RootDirectoryClsId();

#pragma endregion

#pragma region Saving Presentation decks

void RemoveWriteProtection();
void CreateNewPresentation();
void SaveAsPredefinedViewType();
void SaveAsReadOnly();
void SaveProperties();
void SaveToFile();
void SaveWithPassword();
void ExportBlobFromPresentation();
void ApplyingExternalThemeToDependingSlides();
void SettingInterruptionToken();
void AddBlobImageToPresentation();

void SavingHTMLAndCSSFileWhenExportingIntoHTML();
void AddImageFromSVGObjectFromExternalResource();
void ConvertSvgImageObjectIntoGroupOfShapes();
void AddImageFromSVGObject();

void RenderingNotesWhileConvertingToHTML();
void ConvertingPresentationToHTMLWithPreservingOriginalFonts();

#pragma endregion

#pragma region Presentation Rendering-Printing

void SetSlideNumber();
void SetZoom();
void SupportOfDigitalSignature();

#pragma endregion

#pragma region Managing VBA Macros
void AddVBAMacros();
void RemoveVBAMacros();
void ExtractingVBAMacros();
#pragma endregion
#pragma endregion

#pragma region Working with Slides

#pragma region Managing Slides
void AddSlides();
void AddLayoutSlides();
void AccessSlides();
void AccessSlidebyID();
void AccessSlidebyIndex();
void RemoveSlideUsingIndex();
void RemoveSlideUsingReference();
void ChangePosition();
void CloneWithInSamePresentation();
void CloneWithinSamePresentationToEnd();
void CloneAtEndOfAnotherPresentation();
void CloneInAnotherPresentationAtSpecifiedPosition();
void CloneAtEndOfAnotherSpecificPosition();
void CloneToAnotherPresentationWithMaster();
void CloneToAnotherPresentationWithSetSizeAndType();
void CheckSlidesComparison();
void HeaderFooterManager();
void SetChildFooter();
void SetSizeAndType();
void SetSlideSizeScale();
void ManageSlidesSections();
void AddNotesSlideWithNotesStyle();
void HandoutHeaderFooterManager();
void MasterNotesSlideHeaderFooterManager();

#pragma endregion

#pragma region Working with hyperlinks
void RemoveHyperlinks();
void SetHyperlinkColor();
void MutableHyperlink();
void AddHyperlink();
void MacroHyperlink();
#pragma endregion

#pragma region Slide Background
void SetBackgroundToGradient();
void SetImageAsBackground();
void SetSlideBackgroundMaster();
void SetSlideBackgroundNormal();
void GetBackgroundEffectiveValues();
#pragma endregion

#pragma region Slide Comments
void AccessSlideComments();
void AddSlideComments();
void AddParentComments();
#pragma endregion

#pragma region Managing slide layouts
void SetPDFPageSize();
#pragma endregion

#pragma region Extract Data from Presentation
void ExtractVideo();
#pragma endregion

#pragma region Managing slide Notes
void RemoveNotesAtSpecificSlide();
void RemoveNotesFromAllSlides();
#pragma endregion

#pragma region Rendering Slides
void CreateSlidesSVGImage();
void ThumbnailFromSlide();
void ThumbnailFromSlideInNotes();
void ThumbnailWithUserDefinedDimensions();
void RenderComments();
void GeneratingSVGWithCustomShapeIDS();
void RenderOptions();
void Rendering3D();

#pragma endregion

#pragma region Managing Slide Transitions
void ManageSimpleSlideTransitions();
void ManagingBetterSlideTransitions();
void SetTransitionEffects();
void SimpleSlideTransitions();
void SupportOfMorphTransition();
void SetTransitionMorphType();
#pragma endregion

#pragma region Working with Shapes

void GetCameraEffectiveData();
void GetLightRigEffectiveData();
void GetShapeBevelEffectiveData();
void SubstitutePictureTitleOfOLEObjectFrame();
void AddMathematicalShape();
void ShapesAlignment();
void SketchedShapes();
void GeometryShapeAddSegment();
void GeometryShapeCompositeObjects();
void GeometryShapeCreatesCustomGeometry();
void GeometryShapeRemoveSegment();
void GeometryShapeUsingShapeUtil();
void CreateSummaryZoom();
void CreateZoomFrame();
void AnimationTargetShapes();

#pragma region Working with Charts
void AddCustomError();
void AddErrorBars();
void AnimatingCategoriesElements();
void AnimatingSeries();
void AnimatingSeriesElements();
void AutomaticChartSeriescolor();
void ChangeChartCategoryAxis();
void ChartEntities();
void ChartTrendLines();
void DisplayChartLabels();
void DisplayPercentageAsLabels();
void DoughnutChartHole();
void ExistingChart();
void ManagePropertiesCharts();
void NormalCharts();
void NumberFormat();
void PieChart();
void ScatteredChart();
void SecondPlotOptionsforCharts();
void SetAutomaticSeriesFillColor();
void SetCategoryAxisLabelDistance();
void SetChartSeriesOverlap();
void SetDataLabelsPercentageSign();
void SetDataRange();
void SetGapWidth();
void MultiCategoryChart();
void SwitchChartRowColumns();
void SettingAutomicPieChartSliceColors();
void AddBoxAndWhiskerChart();
void AddFunnelChart();
void AddHistogramChart();
void AddHistogramParetoChart();
void AddSunburstChart();
void AddTreemapChart();
void AddWaterfallChart();
void SettingPrecisionOfDataLabel();
void DateFormatForCategoryAxis();
void VerticalAxisRotationAngle();
void SettingPositionAxis();
void ShowDisplayUnitLabelOnChartValueAxis();
void SettingBubbleChartScaling();
void SetMarkerOptionsonSeries();
void GetChartImage();
void ChangingSeriesColor();
void SettingChartAreaRoundedBorders();
void ChangeColorOfCategoriesInSeries();
void SettingFontPropertiesForChartDataTable();
void SettingFontSizeOfLegend();
void SettingFontSizeOfIndividualLegend();
void SettingInvertIfNegativePropertyForIndividualSeries();
void AddStockChart();
void AddDoughnutCallout();
void EditChartDatainExternalWorkbook();
void SetExternalWorkbook();
void CreateExternalWorkbook();
void HideInformationFromChart();
void AddingCustomLines();
void FontPropertiesForChart();
void ClearSpecificChartSeriesDataPointsData();
void DefaultMarkersInChart();
void SetExternalWorkbookWithUpdateChartData();
void SetLayoutMode();
void AddColorToDataPoints();
void SupportOfBubbleSizeRepresentation();
void AddRadarChart();
void SetChartDataCellFormulas();
void SpreadsheetFormulasOptions();
void RecoverWorkbook();
void ChartGetRange();
void MapChart();
void CalculateFormulas();
void WorksheetsExample();
#pragma endregion

#pragma region ManageAutoShapes	

void AccessingAltTextinGroupshapes();
void AddArrowShapedLine();
void AddArrowShapedLineToSlide();
void AddPlainLineToSlide();
void ChangeShapeOrder();
void ConnectorLineAngle();
static double getDirection(float w, float h, Aspose::Slides:: NullableBool flipH, Aspose::Slides::NullableBool flipV);
void ConnectShapesUsingConnectors();
void ConnectShapeUsingConnectionSite();
void FormatJoinStyles();
void FormatLines();
void FormattedEllipse();
void FormattedRectangle();
void SimpleEllipse();
void SimpleRectangle();
void RemoveHyperlinks();
#pragma endregion

#pragma region ManageFrameObjects	

void AccessOLEObjectFrame();
void AddAudioFrame();
void AddOLEObjectFrame();
void AddRelativeScaleHeightPictureFrame();
void AddSimplePictureFrames();
void AddVideoFrame();
void AddVideoFrameFromWebSource();
void ChangeOLEObjectData();
void EmbeddedVideoFrame();
void PictureFrameFormatting();
System::ArrayPtr<uint8_t> GetFileByteData(System::String fileNameZip);
void StretchOffsetLeftForPictureFrame();
void SetFileTypeForAnEmbeddingObject();
void ExtractEmbeddedFileDataFromOLEObject();

#pragma endregion

#pragma region ShapeEffects	

void AnimationsOnShapes();
void AnimationsOnOLEObject();
void Apply3DRotationEffectOnShape();
void ApplyBevelEffects();
void CloneShapes();
void CreateBoundsShapeThumbnail();
void CreateGroupShape();
void CreateScalingFactorThumbnail();
void CreateShapeThumbnail();
void CreateShapeSVGImage();
void CreateSmartArtChildNoteThumbnail();
void FillShapesGradient();
void FillShapesPattern();
void FillShapesPicture();
void FillShapeswithSolidColor();
void FindShapeInSlide();
void Hidingshapes();
void RemoveShape();
void RotatingShapes();
void SetAlternativeText();
void InterlopShapeID();
void InsertSvgIntoPresentation();
void DuotoneEffectsPVI();

#pragma endregion

#pragma region SmartArt	

void AccessChildNodes();
void AccessChildNodeSpecificPosition();
void AccessSmartArt();
void AccessSmartArtParticularLayout();
void AccessSmartArtShape();
void AddNodes();
void AddNodesSpecificPosition();
void AssistantNode();
void ChangeSmartArtLayout();
void ChangeSmartArtShapeColorStyle();
void ChangeSmartArtState();
void ChangeTextOnSmartArtNode();
void ChangSmartArtShapeStyle();
void CheckSmartArtHiddenProperty();
void CreateSmartArtShape();
void FillFormatSmartArtShapeNode();
void OrganizeChartLayoutType();
void RemoveNode();
void RemoveNodeSpecificPosition();
void SmartArtNodeLevel();
void GetTextFromSmartArtNode();
void ShowPictureOrganizationChart();
void CustomChildNodesInSmartArt();
void GetEffectsByTextParagraph();
void MutilevelBullets();

#pragma endregion

#pragma region Working with Tables	

void AddImageinsideTableCell();
void CellSplit();
void CloningInTable();
void MergeCell();
void MergeCells();
void RemovingRowColumn();
void StandardTables();
void TableFromScratch();
void TableWithCellBorders();
void UpdateExistingTable();
void VerticallyAlignText();
void LockAspectRatio();
void GetEffectiveValuesOfTable();
#pragma endregion

#pragma region Formatting Text	

void ExtractTextFromSlide();
void ApplyInnerShadow();
void ApplyOuterShadow();
void CustomRotationAngleTextframe();
void DefaultFonts();
void ExportingHTMLText();
void FontFamilySetting();
void FontProperties();
void ImportingHTMLText();
void LineSpacing();
void ManageEmbeddedFonts();
void ManageParagraphFontProperties();
void ManageParagraphPictureBulletsInPPT();
void MultipleParagraphs();
void ParagraphBullets();
void ParagraphIndent();
void ParagraphsAlignment();
void ReplaceFontsExplicitly();
void ReplacingText();
void RotatingText();
void RuleBasedFontsReplacement();
void SetAnchorOfTextFrame();
void SetAutofitOftextframe();
void SetTextFontProperties();
void ShadowEffects();
void TextBoxHyperlink();
void TextBoxOnSlideProgram();
void UseCustomFonts();
void AddEmbeddedFonts();
void AddColumnInTexBoxes();
void GetFontsFolders();
void AddingSuperscriptAndSubscriptTextInTextFrame();
void EndParaGraphProperties();
void HighlightText();
void HighlightTextUsingRegx();
void SetTransparencyOfTextInShadow();
void AddColumnsinTextFrame();
void AnimationEffectinParagraph();
void GetEffectiveValues();
void SetLocalFontHeightValues();
void GetTextFrameFormatEffectiveData();
void GetTextStyleEffectiveData();
void SetCustomBulletsNumber();
void SetFontFallBack();
void FallBackRulesCollection();
void RenderingWithFallBackFont();
void SetDefaultFont();
void AddCustomPromptText();
void PortionGetRect();
void BulletFillFormatEffective();
void WordArt();
void KeepTextFlat();

#pragma endregion		

#pragma region Views
void ManagePresenetationNormalViewState();
#pragma endregion

#pragma endregion

#pragma endregion
