#pragma once

#include <system/io/path.h>
#include <system/io/file_stream.h>
#include <system/io/memory_stream.h>
#include <drawing/imaging/image_format.h>
#include <drawing/bitmap.h>
#include <drawing/graphics.h>

#include <LoadingStreamBehavior.h>
#include <ViewType.h>
#include <LoadFormat.h>
#include <IResourceLoadingCallback.h>
#include <PresentationLockingBehavior.h>

#include <DOM/Presentation.h>
#include <DOM/VideoCollection.h>
#include <DOM/Video.h>
#include <DOM/AudioCollection.h>
#include <DOM/PresentationFactory.h>
#include <DOM/PresentationInfo.h>
#include <DOM/SlideCollection.h>
#include <DOM/Slide.h>
#include <DOM/LoadOptions.h>
#include <DOM/BlobManagementOptions.h>
#include <DOM/InterruptionToken.h>
#include <DOM/SpreadsheetOptions.h>
#include <DOM/InterruptionTokenSource.h>
#include <DOM/GlobalLayoutSlideCollection.h>
#include <DOM/MasterLayoutSlideCollection.h>
#include <DOM/LayoutSlide.h>
#include <DOM/Placeholder.h>
#include <DOM/PlaceholderSize.h>
#include <DOM/PlaceholderType.h>
#include <DOM/IAnimationTimeLine.h>

#include <DOM/CommentAuthorCollection.h>
#include <DOM/CommentAuthor.h>
#include <DOM/CommentCollection.h>
#include <DOM/Comment.h>

#include <DOM/AutoShapeLock.h>
#include <DOM/GroupShapeLock.h>
#include <DOM/ConnectorLock.h>
#include <DOM/PictureFrameLock.h>

#include <DOM/ProtectionManager.h>

#include <DOM/PPImage.h>
#include <DOM/SvgImage.h>

#include <DOM/ShapeCollection.h>
#include <DOM/Shape.h>
#include <DOM/AutoShape.h>
#include <DOM/GroupShape.h>

#include <DOM/NullableBool.h>
#include <DOM/DocumentProperties.h>
#include <DOM/FillType.h>
#include <DOM/ShapeType.h>
#include <DOM/PathFillModeType.h>
#include <DOM/LineSketchType.h>
#include <DOM/ShapesAlignmentType.h>
#include <DOM/BackgroundType.h>
#include <DOM/SlideSizeType.h>
#include <DOM/SlideSizeScaleType.h>
#include <DOM/BulletType.h>
#include <DOM/PictureFillMode.h>
#include <DOM/TileFlip.h>

#include <DOM/SlideLayoutType.h>
#include <DOM/ZoomImageType.h>
#include <DOM/LineStyle.h>
#include <DOM/LineDashStyle.h>
#include <DOM/TextAutofitType.h>
#include <DOM/LineArrowheadStyle.h>
#include <DOM/LineArrowheadLength.h>
#include <DOM/LineArrowheadWidth.h>
#include <DOM/LineJoinStyle.h>
#include <DOM/AudioPlayModePreset.h>
#include <DOM/AudioVolumeMode.h>
#include <DOM/VideoPlayModePreset.h>
#include <DOM/GradientShape.h>
#include <DOM/ColorType.h>
#include <DOM/SchemeColor.h>
#include <DOM/PatternStyle.h>
#include <DOM/ColorTransformOperation.h>
#include <DOM/ColorOperationCollection.h>
#include <DOM/ShapeThumbnailBounds.h>
#include <DOM/TextShapeType.h>
#include <DOM/TextAnchorType.h>
#include <DOM/RectangleAlignment.h>
#include <DOM/TextAlignment.h>
#include <DOM/GradientDirection.h>
#include <DOM/PresetColor.h>
#include <DOM/TextVerticalType.h>
#include <DOM/TextUnderlineType.h>
#include <DOM/NumberedBulletStyle.h>
#include <DOM/SplitterBarStateType.h>
#include <DOM/FontAlignment.h>

#include <DOM/LineFillFormat.h>
#include <DOM/ColorFormat.h>
#include <DOM/FillFormat.h>
#include <DOM/SketchFormat.h>
#include <DOM/PictureFillFormat.h>
#include <DOM/ParagraphFormat.h>
#include <DOM/BulletFormat.h>
#include <DOM/GradientFormat.h>
#include <DOM/TextFrameFormat.h>
#include <DOM/PatternFormat.h>

#include <DOM/ShapeFrame.h>
#include <DOM/TextFrame.h>
#include <DOM/PictureFrame.h>
#include <DOM/AudioFrame.h>
#include <DOM/VideoFrame.h>
#include <DOM/ZoomFrame.h>

#include <DOM/ImageCollection.h>

#include <DOM/ParagraphCollection.h>
#include <DOM/Paragraph.h>
#include <DOM/Portion.h>
#include <DOM/PortionCollection.h>
#include <DOM/PortionFormat.h>
#include <DOM/Hyperlink.h>
#include <DOM/HyperlinkManager.h>
#include <DOM/SectionCollection.h>
#include <DOM/Section.h>
#include <DOM/HyperlinkColorSource.h>
#include <DOM/SlideSize.h>

#include <DOM/ISlidesPicture.h>

#include <DOM/Connector.h>

#include <DOM/GeometryPath.h>
#include <DOM/ThreeDFormat.h>

#include <DOM/Background.h>

#include <DOM/TextStyle.h>

#include <DOM/MasterSlideCollection.h>
#include <DOM/MasterSlideHeaderFooterManager.h>
#include <DOM/MasterSlide.h>
#include <DOM/MasterNotesSlide.h>
#include <DOM/IMasterNotesSlideManager.h>
#include <DOM/MasterNotesSlideHeaderFooterManager.h>
#include <DOM/MasterHandoutSlide.h>
#include <DOM/MasterHandoutSlideHeaderFooterManager.h>
#include <DOM/IMasterHandoutSlideManager.h>
#include <DOM/NotesSlideHeaderFooterManager.h>

#include <DOM/GradientStopCollection.h>
#include <DOM/GraphicalObjectLock.h>
#include <DOM/HyperlinkQueries.h>
#include <DOM/TextHighlightingOptions.h>

#include <DOM/NotesSlideManager.h>
#include <DOM/NotesSlide.h>
#include <DOM/NotesSize.h>

#include <DOM/ViewProperties.h>
#include <DOM/CommonSlideViewProperties.h>
#include <DOM/INormalViewProperties.h>
#include <DOM/NormalViewRestoredProperties.h>

#include <DOM/DigitalSignature.h>
#include <DOM/DigitalSignatureCollection.h>

// 3D
#include <DOM/CameraPresetType.h>
#include <DOM/ThreeDFormat.h>
#include <DOM/Camera.h>
#include <DOM/LightRig.h>
#include <DOM/LightRigPresetType.h>
#include <DOM/LightingDirection.h>
#include <DOM/MaterialPresetType.h>
#include <DOM/ShapeBevel.h>
#include <DOM/BevelPresetType.h>

// Fonts
#include <DOM/Fonts/FontData.h>
#include <DOM/Fonts/FontFallBackRule.h>
#include <DOM/Fonts/FontFallBackRulesCollection.h>
#include <DOM/Fonts/FontDataFactory.h>
#include <DOM/Fonts/FontsManager.h>
#include <DOM/Fonts/FontsLoader.h>
#include <DOM/Fonts/FontSubstRule.h>
#include <DOM/Fonts/FontSubstRuleCollection.h>
#include <DOM/FontSubstCondition.h>
#include <DOM/FontCollectionIndex.h>
#include <DOM/FontSources.h>

// EffectiveData
#include <DOM/GradientStopCollectionEffectiveData.h>
#include <DOM/GradientStopEffectiveData.h>
#include <DOM/IBackgroundEffectiveData.h>
#include <DOM/IBasePortionFormatEffectiveData.h>
#include <DOM/IBulletFormatEffectiveData.h>
#include <DOM/ICameraEffectiveData.h>
#include <DOM/IEffectFormatEffectiveData.h>
#include <DOM/IFillFormatEffectiveData.h>
#include <DOM/IFontsEffectiveData.h>
#include <DOM/IGradientFormatEffectiveData.h>
#include <DOM/IGradientStopCollectionEffectiveData.h>
#include <DOM/IGradientStopEffectiveData.h>
#include <DOM/ILightRigEffectiveData.h>
#include <DOM/ILineFillFormatEffectiveData.h>
#include <DOM/ILineFormatEffectiveData.h>
#include <DOM/IParagraphFormatEffectiveData.h>
#include <DOM/IPatternFormatEffectiveData.h>
#include <DOM/IPictureEffectiveData.h>
#include <DOM/IPictureFillFormatEffectiveData.h>
#include <DOM/IPortionFormatEffectiveData.h>
#include <DOM/IShapeBevelEffectiveData.h>
#include <DOM/ISketchFormatEffectiveData.h>
#include <DOM/ITabEffectiveData.h>
#include <DOM/ITextFrameFormatEffectiveData.h>
#include <DOM/ITextStyleEffectiveData.h>
#include <DOM/IThreeDFormatEffectiveData.h>
