#ifndef ASPOSE_QTGUIHELPERS_H
#define ASPOSE_QTGUIHELPERS_H

#include <QColor>
#include <QPoint>
#include <QPointF>
#include <QRect>
#include <QRectF>
#include <QSize>
#include <QSizeF>

#include <drawing/color.h>
#include <drawing/point.h>
#include <drawing/point_f.h>
#include <drawing/rectangle.h>
#include <drawing/rectangle_f.h>
#include <drawing/size.h>
#include <drawing/size_f.h>

namespace Aspose { namespace QtHelpers {

/// Convert System::Drawing::Color to QColor.
inline QColor Convert(const System::Drawing::Color& color)
{
    return QColor(color.get_R(), color.get_G(), color.get_B(), color.get_A());
}

/// Convert QColor to System::Drawing::Color.
inline System::Drawing::Color Convert(const QColor& color)
{
    return System::Drawing::Color::FromArgb(color.alpha(), color.red(), color.green(), color.blue());
}

/// Convert System::Drawing::Point to QPoint.
inline QPoint Convert(const System::Drawing::Point& point)
{
    return QPoint(point.get_X(), point.get_Y());
}

/// Convert QPoint to System::Drawing::Point.
inline System::Drawing::Point Convert(const QPoint& point)
{
    return System::Drawing::Point(point.x(), point.y());
}

/// Convert System::Drawing::PointF to QPointF.
inline QPointF Convert(const System::Drawing::PointF& point)
{
    return QPointF(point.get_X(), point.get_Y());
}

/// Convert QPointF to System::Drawing::PointF.
inline System::Drawing::PointF Convert(const QPointF& point)
{
    return System::Drawing::PointF(point.x(), point.y());
}

/// Convert System::Drawing::Size to QSize.
inline QSize Convert(const System::Drawing::Size& size)
{
    return QSize(size.get_Width(), size.get_Height());
}

/// Convert QSize to System::Drawing::Size.
inline System::Drawing::Size Convert(const QSize& size)
{
    return System::Drawing::Size(size.width(), size.height());
}

/// Convert System::Drawing::SizeF to QSizeF.
inline QSizeF Convert(const System::Drawing::SizeF& size)
{
    return QSizeF(size.get_Width(), size.get_Height());
}

/// Convert QSizeF to System::Drawing::SizeF.
inline System::Drawing::SizeF Convert(const QSizeF& size)
{
    return System::Drawing::SizeF(size.width(), size.height());
}

/// Convert System::Drawing::Rectangle to QRect.
inline QRect Convert(const System::Drawing::Rectangle& rect)
{
    return QRect(rect.get_X(), rect.get_Y(), rect.get_Width(), rect.get_Height());
}

/// Convert QRect to System::Drawing::Rectangle.
inline System::Drawing::Rectangle Convert(const QRect& rect)
{
    return System::Drawing::Rectangle(rect.x(), rect.y(), rect.width(), rect.height());
}

/// Convert System::Drawing::RectangleF to QRectF.
inline QRectF Convert(const System::Drawing::RectangleF& rect)
{
    return QRectF(rect.get_X(), rect.get_Y(), rect.get_Width(), rect.get_Height());
}

/// Convert QRectF to System::Drawing::RectangleF.
inline System::Drawing::RectangleF Convert(const QRectF& rect)
{
    return System::Drawing::RectangleF(rect.x(), rect.y(), rect.width(), rect.height());
}

}} // namespace Aspose::QtHelpers

#endif // ASPOSE_QTGUIHELPERS_H
