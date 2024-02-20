#include "data_sort.h"

double sort(double *data, int n) {
    int i, j;
    double tmp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n; j++) {
            if (data[j] > data[j + 1]) {
                tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
    }
    return data[n];
}