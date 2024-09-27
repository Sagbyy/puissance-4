#include "color.h"

void red() {
    printf("\033[0;31m");
}

void green() {
    printf("\033[0;32m");
}

void yellow() {
    printf("\033[0;33m");
}

void resetColor() {
    printf("\033[0m");
}