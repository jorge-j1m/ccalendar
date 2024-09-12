#include <stdio.h>
#include <string.h>
#include <time.h>
#include "date_calculations.h"
#include "colors.h"

void println(void);

char *months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
int lens[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main(void) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int month = tm.tm_mon;
    int m_day = tm.tm_mday;
    int w_day = tm.tm_wday;
    // int month = 6;
    // int m_day = 4; // 1 based day of the month. 1 <= x <= 31
    // int w_day = 4; // 0 based week day. 0 is Sunday

    printf("Showing the current calendar!\n");
    printf("Current month: %d %s\n", month + 1, months[month]);

    println();
    red();
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    reset();
    println();

    int offset = monthOffset(m_day - 1, w_day);
    for (int i = 0; i < offset; i++) printf("    ");
    for (int i = 0; i < lens[month]; i++) {
        if ((i + offset) % 7 == 0 && i != 0) printf("\n");
        if (i == m_day - 1) {
            yellow();
            printf("%2.d  ", i + 1);
            reset();
        } else {
            printf("%2.d  ", i + 1);
        }
    }
    printf("\n");
    return 0;
}
