# QtCreator debugging helpers for CodePorting.Native.Cs2Cpp
from dumper import Children, SubItem
from utils import DisplayFormat


NULL_VALUE = '<null>'
EMPTY_VALUE = '<empty>'
OBJECT_DELETED = '<object deleted>'
NOT_INITIALIZED = '<not initialized>'

DAY_OF_WEEK = [ 'Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday' ]
DATE_TIME_KIND = [ 'Unspecified', 'Utc', 'Local', 'LocalAmbiguousDst' ]


def putFloatItem(d, name, value):
    with SubItem(d, name):
        if isinstance(value, d.Value):
            d.putValue(value.display())
        else:
            d.putValue(value)
        d.putType('float')


def putStringItem(d, name, value):
    with SubItem(d, name):
        if isinstance(value, d.Value):
            d.putValue(value.display())
        else:
            d.putValue(value)
        d.putType('utf16')


def get_date_components(days):  # -> (year, month, day, day_of_year)
    y400 = days // 146097     # number of 400-year periods since 1 Jan 0001
    n = days - y400 * 146097  # day number within 400-year period
    y100 = min(3, n // 36524) # number of 100-year periods within 400-year period
    n -= y100 * 36524         # day number within 100-year period
    y4 = n // 1461            # number of 4-year periods within 100-year period
    n -= y4 * 1461            # day number within 4-year period
    y1 = min(3, n // 365)     # number of 1-year periods within 4-year period
    n -= y1 * 365             # day number within year

    year = y400 * 400 + y100 * 100 + y4 * 4 + y1 + 1

    is_leap_year = (y1 == 3) and (y4 != 24 or y100 == 3)
    if is_leap_year:
        days_to_month = [ 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 ]
    else:
        days_to_month = [ 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 ]
            
    month = (n >> 5) + 1;
    while n >= days_to_month[month]:
        month += 1

    day = n - days_to_month[month - 1] + 1;
    return (year, month, day, n + 1)


def qdump__System__Array(d, value):
    d.putItem(value['m_data'])
    d.putBetterType(value.type)


def qdump__System__DateTime(d, value):
    data = value.split('Q')[0]
    ticks = data & 0x3FFF_FFFF_FFFF_FFFF
    flags = data >> 62

    millisecond = (ticks // 10_000) % 1000
    second = (ticks // 10_000_000) % 60
    minute = (ticks // 600_000_000) % 60
    hour = (ticks // 36_000_000_000) % 24
    days = ticks // 864_000_000_000
    year, month, day, day_of_year = get_date_components(days)

    s = '%04d-%02d-%02d %02d:%02d:%02d' % (year, month, day, hour, minute, second)
    if millisecond != 0:
        s += '.%03d' % (millisecond, )
        
    if flags == 1:
        s += ' (UTC)'
    elif flags == 2 or flags == 3:
        s += ' (Local)'

    d.putValue(s)

    d.putExpandable()
    if d.isExpanded():
        with Children(d):
            putStringItem(d, 'Kind', DATE_TIME_KIND[flags])
            d.putIntItem('Year', year)
            d.putIntItem('Month', month)
            d.putIntItem('Day', day)
            putStringItem(d, 'DayOfWeek', DAY_OF_WEEK[(days + 1) % 7])
            d.putIntItem('DayOfYear', day_of_year)
            d.putIntItem('Hour', hour)
            d.putIntItem('Minute', minute)
            d.putIntItem('Second', second)
            d.putIntItem('Millisecond', millisecond)
            d.putIntItem('Ticks', ticks)


def qdump__System__DateTimeOffset(d, value):
    datetime, offset = value.split('Qq')
    datetime = datetime & 0x3FFF_FFFF_FFFF_FFFF

    millisecond = (datetime // 10_000) % 1000
    second = (datetime // 10_000_000) % 60
    minute = (datetime // 600_000_000) % 60
    hour = (datetime // 36_000_000_000) % 24
    days = datetime // 864_000_000_000
    year, month, day, day_of_year = get_date_components(days)

    offset_minutes = (abs(offset) // 600_000_000) % 60
    offset_hours = (abs(offset) // 36_000_000_000) % 24

    s = '%04d-%02d-%02d %02d:%02d:%02d' % (year, month, day, hour, minute, second)
    if millisecond != 0:
        s += '.%03d' % (millisecond, )

    s += ' +' if offset >= 0 else ' -'
    s += '%02d:%02d' % (offset_hours, offset_minutes)

    d.putValue(s)

    d.putExpandable()
    if d.isExpanded():
        with Children(d):
            d.putIntItem('Year', year)
            d.putIntItem('Month', month)
            d.putIntItem('Day', day)
            putStringItem(d, 'DayOfWeek', DAY_OF_WEEK[(days + 1) % 7])
            d.putIntItem('DayOfYear', day_of_year)
            d.putIntItem('Hour', hour)
            d.putIntItem('Minute', minute)
            d.putIntItem('Second', second)
            d.putIntItem('Millisecond', millisecond)
            d.putIntItem('Ticks', datetime)
            d.putSubItem('DateTime', value['m_date_time'])
            d.putSubItem('Offset', value['m_offset'])


def qdump__System__Guid(d, value):
    data = value.split('B' * 16)
        
    a0 = (data[0] << 24) + (data[1] << 16) + (data[2] << 8) + data[3]
    a1 = (data[4] << 8) + data[5]
    a2 = (data[6] << 8) + data[7]
    a3 = (data[8] << 8) + data[9]
    a4 = (data[10] << 40) + (data[11] << 32) + (data[12] << 24) + (data[13] << 16) + (data[14] << 8) + data[15]

    s = '%08X-%04X-%04X-%04X-%012X' % (a0, a1, a2, a3, a4)
    d.putValue(s)


def qdump__System__Nullable(d, value):
    if value['m_has_value'].integer() == 0:
        d.putValue(NULL_VALUE)
        return

    d.putItem(value['m_value'])
    d.putBetterType(value.type)


def qdump__System__Object(d, value):
    d.putValue('shared_count=%d' % (value['m_shared_count']['m_count'].integer(),))


def qform__System__String():
    return [DisplayFormat.Simple, DisplayFormat.Separate]


def qdump__System__String(d, value):
    try:
        if value['m_is_null'].integer() != 0:
            d.putValue(NULL_VALUE)
            return
    except:
        pass  # value is System::Text::StringBuilder

    vptr, length_and_flags = value.split('ph')
    if (length_and_flags & 2) != 0:  # Flag UnicodeString::kUsingStackBuffer
        # Short strings
        capacity = 64 - d.ptrSize() - 2
        length = length_and_flags >> 5
        data = value.address() + d.ptrSize() + 2
    else:
        # Heap-allocated and aliased strings
        vptr, length_and_flags, pad, length, capacity, pad, data = value.split('ph@ii@p')
        if length_and_flags >= 0:
            length = length_and_flags >> 5
        
    if length == 0:
        d.putValue(EMPTY_VALUE)
    else:
        char_type = d.createType('QChar')  # QChar has better support in debugger than char16_t
        d.putCharArrayValue(data, length, char_type.size(), d.currentItemFormat())
        
        d.putExpandable()
        if d.isExpanded():
            d.putArrayData(data, length, char_type)


def qform__System__Text__StringBuilder():
    return qform__System__String()


def qdump__System__Text__StringBuilder(d, value):
    qdump__System__String(d, value['m_storage'])


def qdump__System__SmartPtr(d, value):
    data = value['m_data']
    pointee = data['m_pointee']
    mode = data['m_mode'].integer(bitsize=8)
    
    if pointee.pointer() == 0:
        d.putValue(NULL_VALUE)
        return

    if mode == 1 and data['m_counter']['m_object'].pointer() == 0:
        d.putValue(OBJECT_DELETED)
        return

    d.putItem(pointee.dereference())
    d.putBetterType(value.type)


def qdump__System__WeakPtr(d, value):
    qdump__System__SmartPtr(d, value)


def qdump__System__TimeSpan(d, value):
    ticks = value.integer(bitsize=64)
    is_negative = ticks < 0
    sign = -1 if is_negative else 1
    ticks = abs(ticks)

    fraction = ticks % 10_000_000;
    seconds = (ticks // 10_000_000) % 60
    minutes = (ticks // 600_000_000) % 60
    hours = (ticks // 36_000_000_000) % 24
    days = ticks // 864_000_000_000

    total_milliseconds = ticks / 10_000;
    total_seconds = ticks / 10_000_000
    total_minutes = ticks / 600_000_000
    total_hours = ticks / 36_000_000_000
    total_days = ticks / 864_000_000_000

    s = ''
    if days != 0:
        s += str(sign * days) + '.'

    s += '%02d:%02d:%02d' % (hours, minutes, seconds)

    if fraction != 0:
        s += '.%07d' % (fraction, )

    d.putValue(s)

    d.putExpandable()
    if d.isExpanded():
        with Children(d):
            d.putIntItem('Days', sign * days)
            d.putIntItem('Hours', sign * hours)
            d.putIntItem('Minutes', sign * minutes)
            d.putIntItem('Seconds', sign * seconds)
            d.putIntItem('Milliseconds', sign * (fraction // 1000))
            d.putIntItem('Ticks', sign * ticks)
            putFloatItem(d, 'TotalDays', sign * total_days)
            putFloatItem(d, 'TotalHours', sign * total_hours)
            putFloatItem(d, 'TotalMinutes', sign * total_minutes)
            putFloatItem(d, 'TotalSeconds', sign * total_seconds)
            putFloatItem(d, 'TotalMilliseconds', sign * total_milliseconds)


def qdump__System__Collections__Generic__ArrayList(d, value):
    d.putItem(value['m_data'])
    d.putBetterType(value.type)


def qdump__System__Collections__Generic__Dictionary(d, value):
    d.putItem(value['m_map'])
    d.putBetterType(value.type)


def qdump__System__Collections__Generic__HashSet(d, value):
    d.putItem(value['m_data'])
    d.putBetterType(value.type)


def qdump__System__Collections__Generic__List(d, value):
    d.putItem(value['m_data'])
    d.putBetterType(value.type)


# Throws exception with message "Check failed: False"
#def qdump__System__Collections__Generic__SortedDictionary(d, value):
#    d.putItem(value['m_map'])
#    d.putBetterType(value.type)


def qdump__System__Collections__Generic__Detail__FlatMap(d, value):
    d.putItem(value['m_data'])
    d.putBetterType(value.type)


def qdump__System__Collections__Generic__SortedList(d, value):
    d.putItem(value['m_map'])
    d.putBetterType(value.type)


def qdump__System__Collections__Generic__Stack(d, value):
    d.putItem(value['m_data'])
    d.putBetterType(value.type)


def qdump__System__IO__FileStream(d, value):
    position = value['m_file_pos'].integer() - value['m_read_length'].integer() + value['m_read_pos'].integer() + value['m_write_pos'].integer()
    d.putValue('FileStream[pos=%d]' % (position,))
    d.putExpandable()
    if d.isExpanded():
        with Children(d):
            d.putSubItem('Name', value['m_path'])
            d.putIntItem('Position', position)
            d.putSubItem('BufferSize', value['m_buffer_size'])
            d.putSubItem('FileAccess', value['m_access'])
            d.putSubItem('FileMode', value['m_mode'])
            d.putSubItem('FileOptions', value['m_options'])
            d.putSubItem('FileShare', value['m_share'])


def qdump__System__IO__MemoryStream(d, value):
    d.putValue('MemoryStream[pos=%d]' % (value['position'],))
    d.putExpandable()
    if d.isExpanded():
        with Children(d):
            d.putSubItem('CanRead', value['m_readable'])
            d.putIntItem('CanSeek', value['m_seekable'])
            d.putSubItem('CanWrite', value['m_writable'])
            d.putSubItem('Capacity', value['capacity'])
            d.putSubItem('Length', value['length'])
            d.putSubItem('Position', value['position'])
            d.putSubItem('InternalBuffer', value['internalBuffer'])


def qdump__System__Drawing__Color(d, value):
    a, r, g, b, is_empty = value.split('BBBBI')
    known_color_name = value['m_known_color_name']
    s = 'ARGB(%d, %d, %d, %d)' % (a, r, g, b)
    if known_color_name.integer() != 0:
        s += ' Name = ' + known_color_name.display().split(' (')[0]
    d.putValue(s)
    d.putExpandable()
    if d.isExpanded():
        with Children(d):
            d.putBoolItem('IsEmpty', is_empty)
            d.putIntItem('A', a)
            d.putIntItem('R', r)
            d.putIntItem('G', g)
            d.putIntItem('B', b)
            with SubItem(d, 'KnownColor'):
                d.putItem(known_color_name)


def qdump__System__Drawing__Point(d, value):
    x, y = value.split('ii')
    d.putValue('X = %d Y = %d' % (x, y))
    d.putExpandable()
    if d.isExpanded():
        with Children(d):
            d.putBoolItem('IsEmpty', x == 0 and y == 0)
            d.putIntItem('X', x)
            d.putIntItem('Y', y)


def qdump__System__Drawing__PointF(d, value):
    x, y = value.split('ff')
    d.putValue('X = %g Y = %g' % (x, y))
    d.putExpandable()
    if d.isExpanded():
        with Children(d):
            d.putBoolItem('IsEmpty', x == 0 and y == 0)
            putFloatItem(d, 'X', x)
            putFloatItem(d, 'Y', y)


def qdump__System__Drawing__Rectangle(d, value):
    x, y, w, h = value.split('iiii')
    d.putValue('X = %d Y = %d Width = %d Height = %d' % (x, y, w, h))
    d.putExpandable()
    if d.isExpanded():
        with Children(d):
            d.putBoolItem('IsEmpty', x == 0 and y == 0 and w == 0 and h == 0)
            d.putIntItem('X', x)
            d.putIntItem('Y', y)
            d.putIntItem('Width', w)
            d.putIntItem('Heigth', h)
            d.putIntItem('Left', x)
            d.putIntItem('Right', x + w)
            d.putIntItem('Bottom', y)
            d.putIntItem('Top', y + h)


def qdump__System__Drawing__RectangleF(d, value):
    x, y, w, h = value.split('ffff')
    d.putValue('X = %g Y = %g Width = %g Height = %g' % (x, y, w, h))
    d.putExpandable()
    if d.isExpanded():
        with Children(d):
            d.putBoolItem('IsEmpty', x == 0 and y == 0 and w == 0 and h == 0)
            putFloatItem(d, 'X', x)
            putFloatItem(d, 'Y', y)
            putFloatItem(d, 'Width', w)
            putFloatItem(d, 'Heigth', h)
            putFloatItem(d, 'Left', x)
            putFloatItem(d, 'Right', x + w)
            putFloatItem(d, 'Bottom', y)
            putFloatItem(d, 'Top', y + h)


def qdump__System__Drawing__Size(d, value):
    w, h = value.split('ii')
    d.putValue('Width = %d Height = %d' % (w, h))
    d.putExpandable()
    if d.isExpanded():
        with Children(d):
            d.putBoolItem('IsEmpty', w == 0 and h == 0)
            d.putIntItem('Width', w)
            d.putIntItem('Heigth', h)


def qdump__System__Drawing__SizeF(d, value):
    w, h = value.split('ff')
    d.putValue('Width = %g Height = %g' % (w, h))
    d.putExpandable()
    if d.isExpanded():
        with Children(d):
            d.putBoolItem('IsEmpty', w == 0 and h == 0)
            putFloatItem(d, 'Width', w)
            putFloatItem(d, 'Heigth', h)


def qdump__System__Drawing__Drawing2D__Matrix(d, value):
    m0, m1, m2, m3, m4, m5, m6, m7, m8, mask = value['m_sk_matrix'].split('fffffffffI')
    
    d.putValue('Matrix')
    d.putExpandable()
    if d.isExpanded():
        with Children(d):
            putFloatItem(d, '[0]', m0)
            putFloatItem(d, '[1]', m3)
            putFloatItem(d, '[2]', m1)
            putFloatItem(d, '[3]', m4)
            putFloatItem(d, '[4]', m2)
            putFloatItem(d, '[5]', m5)
            d.putBoolItem('IsIdentity', mask == 0)
            putFloatItem(d, 'OffsetX', m2)
            putFloatItem(d, 'OffsetY', m5)


def qdump__System__Details__LazyValueStorage(d, value):
    if value.type[1] == 0:
        # Static storage
        d.putItem(value.cast(value.type[0]))
        d.putBetterType(value.type)
    else:
        # Dynamic storage
        d.putItem(value['m_value_ptr'].dereference())
        d.putBetterType(value.type)


def qdump__System__Details__Lazy(d, value):
    if value['m_call_once']['m_called'].integer() == 0:
        d.putValue(NOT_INITIALIZED)
        return

    d.putItem(value['m_value'])
    d.putBetterType(value.type)


def qdump__System__Details__SynchronizedValue(d, value):
    d.putItem(value['m_value'])
    d.putBetterType(value.type)
