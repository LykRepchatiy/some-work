#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

int s21_strlen(char* arr) {
    int count = 0;
    while (*arr != 0) count++;
    return count;
}