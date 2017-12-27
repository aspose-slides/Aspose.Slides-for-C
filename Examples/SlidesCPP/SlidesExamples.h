#pragma once
#include <DOM/NullableBool.h>
using namespace std;


//Developer Guide > Loading, Saving and Converting

#pragma region Working with ActiveX Controls
void LinkingVideoActiveXControl();
void ManageActiveXControl();
#pragma endregion

#pragma region Working with Presentation Decks
#pragma region Managing VBA Macros
void AddVBAMacros();
void RemoveVBAMacros();
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
#pragma endregion

#pragma region Working with hyperlinks
void RemoveHyperlinks();
#pragma endregion

#pragma region Slide Background
void SetBackgroundToGradient();
void SetImageAsBackground();
void SetSlideBackgroundMaster();
void SetSlideBackgroundNormal();
#pragma endregion

#pragma region Slide Comments
void AccessSlideComments();
void AddSlideComments();
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
#pragma endregion

#pragma region Managing Slide Transitions
void ManageSimpleSlideTransitions();
void ManagingBetterSlideTransitions();
void SetTransitionEffects();
void SimpleSlideTransitions();
#pragma endregion

#pragma region Working with Shapes

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
#pragma endregion

#pragma region ShapeEffects	

void AnimationsOnShapes();
void Apply3DRotationEffectOnShape();
void ApplyBevelEffects();
void CloneShapes();
void CreateBoundsShapeThumbnail();
void CreateGroupShape();
void CreateScalingFactorThumbnail();
void CreateShapeThumbnail();
void CreateSmartArtChildNoteThumbnail();
void FillShapesGradient();
void FillShapesPattern();
void FillShapesPicture();
void FillShapeswithSolidColor();
void FindShapeInSlide();
void Hidingshapes();
void InterlopShapeID();
void RemoveShape();
void RotatingShapes();
void SetAlternativeText();
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
#pragma endregion

#pragma region Formatting Text	

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
#pragma endregion		


#pragma endregion

#pragma endregion