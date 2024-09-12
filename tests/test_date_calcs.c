#include "unity.h"
#include "../src/date_calculations.h"

void setUp(void) {}
void tearDown(void) {}

void test_monthOffset_valid_inputs(void) {
    TEST_ASSERT_EQUAL(0, monthOffset(0 /*m_day*/, 0 /*w_day*/));  // Assuming 1st is Sunday
    TEST_ASSERT_EQUAL(1, monthOffset(0, 1));  // Assuming 1st is Monday, offset 1
    TEST_ASSERT_EQUAL(2, monthOffset(0, 2));  // Assuming 1st is Tuesday, offset 2
    TEST_ASSERT_EQUAL(3, monthOffset(0, 3));  // Assuming 1st is Wednesday, offset 3
    TEST_ASSERT_EQUAL(4, monthOffset(0, 4));  // Assuming 1st is Thursday, offset 4
    TEST_ASSERT_EQUAL(5, monthOffset(0, 5));  // Assuming 1st is Friday, offset 5
    TEST_ASSERT_EQUAL(6, monthOffset(0, 6));  // Assuming 1st is Saturday, offset 6
    TEST_ASSERT_EQUAL(0, monthOffset(7 /*m_day*/, 0 /*w_day*/));  // Assuming 8th is Sunday, offset 0
}

void test_monthOffset_invalid_mday(void) {
    TEST_ASSERT_EQUAL(MONTH_OFFSET_INVALID_MDAY, monthOffset(-1, 0)); // 0 represents the first day of the month
    TEST_ASSERT_EQUAL(MONTH_OFFSET_INVALID_MDAY, monthOffset(31, 0)); // at MOST a month has 31 days, so 30 is max
}

void test_monthOffset_invalid_wday(void) {
    TEST_ASSERT_EQUAL(MONTH_OFFSET_INVALID_WDAY, monthOffset(1, -1));
    TEST_ASSERT_EQUAL(MONTH_OFFSET_INVALID_WDAY, monthOffset(1, 7));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_monthOffset_valid_inputs);
    RUN_TEST(test_monthOffset_invalid_mday);
    RUN_TEST(test_monthOffset_invalid_wday);
    return UNITY_END();
}
