#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

void s21_strlen_test(char* arr, int length);

int main() {
    s21_strlen_test("hello", 5);  // проверка на нормальность
    s21_strlen_test(" ", 0);      // проверка на нормальность
    s21_strlen_test("hello", 4);  // проверка на ненормальность
    s21_strlen_test("bye", 5);    // проверка на ненормальность
    return 0;
}

void s21_strlen_test(char* arr, int length) {
    int output = s21_strlen(arr);
    if (output == length)
        printf("SUCCESS");
    else
        printf("FAIL");
}