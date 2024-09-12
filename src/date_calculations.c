#include <stdio.h>
#include "date_calculations.h"
#include "log.h"

/**
 *  w_day is 0 for Sunday and 6 for Saturday
 *  m_day starts at 0 and ends (at most) at 30
 *  so m_day is considered an index for the month
 */ 
int monthOffset(int m_day, int w_day) {
    if (m_day < 0 || m_day > 30) {
        LOG_ERROR("Invalid m_day: %d", m_day);
        return MONTH_OFFSET_INVALID_MDAY;
    } else if (w_day < 0 || w_day > 6) {
        LOG_ERROR("Invalid w_day: %d", w_day);
        return MONTH_OFFSET_INVALID_WDAY;
    }
    // This will ensure we'll have a value between 0 and 6
    int reduced = m_day % 7;

    // return reduced % w_day;
    return w_day - reduced;
}
