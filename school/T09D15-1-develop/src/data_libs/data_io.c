#include "data_io.h"

#include <stdio.h>
#include <stdlib.h>

void input(double *data, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%lf", &data[i]);
    }
}
void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", data[i]);
    }
    printf("\b");
}