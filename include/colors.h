#include <stdio.h>

void println(void) {
    printf("---------------------------\n");
}

void red(void) {
  printf("\033[1;31m");
}

void yellow(void) {
  printf("\033[1;33m");
}

void reset(void) {
  printf("\033[0m");
}
