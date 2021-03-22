#ifndef ASPOSE_QTCOREHELPERS_H
#define ASPOSE_QTCOREHELPERS_H

#include <QByteArray>
#include <QDate>
#include <QDateTime>
#include <QFileDevice>
#include <QIODevice>
#include <QString>
#include <QTime>
#include <QUrl>
#include <QUuid>

#include <system/array.h>
#include <system/date_time.h>
#include <system/date_time_offset.h>
#include <system/exceptions.h>
#include <system/guid.h>
#include <system/string.h>
#include <system/timespan.h>
#include <system/uri.h>
#include <system/io/stream.h>

#include <cstdint>
#include <stdexcept>

namespace Aspose { namespace QtHelpers {

/// Convert System::String to QString.
inline QString Convert(const System::String& str)
{
    if (str.IsNull())
        return QString();

    const QChar* data = reinterpret_cast<const QChar*>(str.begin());
    const int length = str.get_Length();

    return QString(data, length);
}

/// Convert QString to System::String.
inline System::String Convert(const QString& str)
{
    if (str.isNull())
        return System::String();

    const char16_t* data = reinterpret_cast<const char16_t*>(str.data());
    const int length = str.length();

    return System::String(data, length);
}

/// Convert System::Array<uint8_t> to QByteArray.
inline QByteArray Convert(const System::ByteArrayPtr& array)
{
    if (array == nullptr)
        return QByteArray();

    const char* data = reinterpret_cast<const char*>(array->data_ptr());
    const int length = array->get_Length();

    return QByteArray(data, length);
}

/// Convert QByteArray to System::Array<uint8_t>.
inline System::ByteArrayPtr Convert(const QByteArray& array)
{
    if (array.isNull())
        return nullptr;

    const uint8_t* data = reinterpret_cast<const uint8_t*>(array.data());
    const int length = array.length();

    return System::MakeArray<uint8_t>(length, data);
}

/// Convert System::DateTime to QDateTime.
inline QDateTime Convert(const System::DateTime& dateTime)
{
    const auto elapsed = dateTime - System::DateTime::UnixEpoch;
    const auto elapsedMsecs = elapsed.get_Ticks() / System::DateTime::TicksPerMillisecond;

    auto result = QDateTime::fromMSecsSinceEpoch(elapsedMsecs, Qt::TimeSpec::UTC);
    if (dateTime.get_Kind() != System::DateTimeKind::Utc)
        result.setTimeSpec(Qt::TimeSpec::LocalTime);

    return result;
}

/// Convert System::DateTimeOffset to QDateTime.
inline QDateTime Convert(const System::DateTimeOffset& dateTimeOffset)
{
    const auto elapsed = dateTimeOffset.get_DateTime() - System::DateTime::UnixEpoch;
    const auto elapsedMsecs = elapsed.get_Ticks() / System::DateTime::TicksPerMillisecond;
    const auto offsetFromUtc = dateTimeOffset.get_Offset().get_Ticks() / System::TimeSpan::TicksPerSecond;

    return QDateTime::fromMSecsSinceEpoch(elapsedMsecs - offsetFromUtc * 1000, Qt::TimeSpec::OffsetFromUTC, offsetFromUtc);
}

/// Convert QDateTime to System::DateTime.
inline System::DateTime Convert(const QDateTime& dateTime)
{
    if (!dateTime.isValid())
        throw std::invalid_argument("invalid datetime");

    try
    {
        const System::TimeSpan timeSinceUnixEpoch(dateTime.toMSecsSinceEpoch() * System::TimeSpan::TicksPerMillisecond);

        System::TimeSpan offsetFromUtc;
        if (dateTime.timeSpec() == Qt::TimeSpec::LocalTime)
            offsetFromUtc = System::TimeSpan::FromTicks(dateTime.offsetFromUtc() * System::TimeSpan::TicksPerSecond);

        auto result = System::DateTime::UnixEpoch + (timeSinceUnixEpoch + offsetFromUtc);

        if (dateTime.timeSpec() == Qt::TimeSpec::LocalTime)
            result = System::DateTime::SpecifyKind(result, System::DateTimeKind::Local);
        else
            result = System::DateTime::SpecifyKind(result, System::DateTimeKind::Utc);

        return result;
    }
    catch (const System::ArgumentOutOfRangeException& e)
    {
        throw std::out_of_range(e->get_Message().ToUtf8String());
    }
}

/// Convert QDate to System::DateTime.
inline System::DateTime Convert(const QDate& date)
{
    if (!date.isValid())
        throw std::invalid_argument("invalid date");

    int year = 0;
    int month = 0;
    int day = 0;
    date.getDate(&year, &month, &day);

    if (year < 1 || year > 9999)
        throw std::out_of_range("date is out of range (1..9999 year)");

    return System::DateTime(year, month, day);
}

/// Convert QTime to System::TimeSpan.
inline System::TimeSpan Convert(const QTime& time)
{
    if (!time.isValid())
        throw std::invalid_argument("invalid time");

    return System::TimeSpan(0, time.hour(), time.minute(), time.second(), time.msec());
}

/// Convert System::Guid to QUuid.
inline QUuid Convert(const System::Guid& guid)
{
    return QUuid(Convert(guid.ToString()));
}

/// Convert QUuid to System::Guid.
inline System::Guid Convert(const QUuid& guid)
{
    const auto str = guid.toByteArray();
    return System::Guid(System::String::FromAscii(str.data(), str.length()));
}

/// Convert System::Uri to QUrl.
inline QUrl Convert(const System::SharedPtr<System::Uri>& uri)
{
    if (uri == nullptr)
        return QUrl();

    return QUrl(Convert(uri->ToString()), QUrl::ParsingMode::StrictMode);
}

/// Convert QUrl to System::Uri.
inline System::SharedPtr<System::Uri> Convert(const QUrl& url)
{
    if (url.isEmpty())
        return nullptr;

    if (!url.isValid())
        throw std::invalid_argument("invalid url");

    return System::MakeObject<System::Uri>(Convert(url.toString()));
}

/// System::IO::Stream compatible wrapper around QIODevice.
class IODeviceWrapper : public System::IO::Stream
{
public:
    IODeviceWrapper(QIODevice& device)
        : m_device(device)
    {}

    int ReadByte() override
    {
        char c;
        if (m_device.getChar(&c))
            return c;

        ThrowLastError();
    }

    void WriteByte(uint8_t value) override
    {
        if (!m_device.putChar(static_cast<char>(value)))
            ThrowLastError();
    }

    int Read(System::ArrayPtr<uint8_t> buffer, int offset, int count) override
    {
        if (buffer == nullptr)
            throw System::ArgumentNullException(u"buffer");

        if (offset < 0)
            throw System::ArgumentOutOfRangeException(u"offset", u"Value is less than zero");

        if (count < 0)
            throw System::ArgumentOutOfRangeException(u"count", u"Value is less than zero");

        if (count == 0)
            return 0;

        if (buffer->get_Length() - count < offset)
            throw System::ArgumentOutOfRangeException(u"offset", u"Invalid offset");

        const qint64 readed = m_device.read(reinterpret_cast<char*>(buffer->data_ptr() + offset), count);
        if (readed < 0)
            ThrowLastError();

        return static_cast<int>(readed);
    }

    void Write(System::ArrayPtr<uint8_t> buffer, int offset, int count) override
    {
        if (buffer == nullptr)
            throw System::ArgumentNullException(u"buffer");

        if (offset < 0)
            throw System::ArgumentOutOfRangeException(u"offset", u"Value is less than zero");

        if (count < 0)
            throw System::ArgumentOutOfRangeException(u"count", u"Value is less than zero");

        if (count == 0)
            return;

        if (buffer->get_Length() - count < offset)
            throw System::ArgumentOutOfRangeException(u"offset", u"Invalid offset");

        const qint64 written = m_device.write(reinterpret_cast<const char*>(buffer->data_ptr() + offset), count);
        if (written < 0)
            ThrowLastError();
    }

    int64_t Seek(int64_t offset, System::IO::SeekOrigin origin) override
    {
        qint64 pos = 0;
        switch (origin)
        {
        case System::IO::SeekOrigin::Begin:
            pos = offset;
            break;

        case System::IO::SeekOrigin::Current:
            pos = get_Position() + offset;
            break;

        case System::IO::SeekOrigin::End:
            pos = get_Length() + offset;
            break;
        }

        if (!m_device.seek(pos))
            ThrowLastError();

        return pos;
    }

    void SetLength(int64_t value) override
    {
	(void)value;
        throw System::NotSupportedException(u"SetLength() method is not supported");
    }

    void Flush() override
    {
        throw System::NotSupportedException(u"Flush() method is not supported");
    }

    void Close() override
    {
        m_device.close();
    }

    int64_t get_Position() const override
    {
        return m_device.pos();
    }

    void set_Position(int64_t value) override
    {
        if (!m_device.seek(value))
            ThrowLastError();
    }

    int64_t get_Length() const override
    {
        return m_device.size();
    }

    bool get_CanRead() const override
    {
        return m_device.isReadable();
    }

    bool get_CanSeek() const override
    {
        return !m_device.isSequential();
    }

    bool get_CanWrite() const override
    {
        return m_device.isWritable();
    }

protected:
    QIODevice& m_device;

    [[noreturn]]
    void ThrowLastError()
    {
        throw System::IO::IOException(Convert(m_device.errorString()));
    }
};

/// System::IO::Stream compatible wrapper around QFileDevice.
class FileDeviceWrapper : public IODeviceWrapper
{
public:
    FileDeviceWrapper(QFileDevice& device)
        : IODeviceWrapper(device)
    {}

    void SetLength(int64_t value) override
    {
        if (value < 0)
            throw System::ArgumentOutOfRangeException(u"value", u"Value is less than zero");

        if (!static_cast<QFileDevice&>(m_device).resize(value))
            ThrowLastError();
    }

    void Flush() override
    {
        if (!static_cast<QFileDevice&>(m_device).flush())
            ThrowLastError();
    }
};

System::SharedPtr<System::IO::Stream> Wrap(QIODevice& device)
{
    return System::MakeObject<IODeviceWrapper>(device);
}

System::SharedPtr<System::IO::Stream> Wrap(QFileDevice& device)
{
    return System::MakeObject<FileDeviceWrapper>(device);
}

}} // namespace Aspose::QtHelpers

#endif // ASPOSE_QTCOREHELPERS_H
