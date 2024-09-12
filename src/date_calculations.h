#ifndef DATE_CALCULATIONS_H
#define DATE_CALCULATIONS_H

enum MonthOffsetError {
    MONTH_OFFSET_SUCCESS = 0,
    MONTH_OFFSET_INVALID_MDAY = -1,
    MONTH_OFFSET_INVALID_WDAY = -2
};

int monthOffset(int m_day, int w_day);

#endif // DATE_CALCULATIONS_H
