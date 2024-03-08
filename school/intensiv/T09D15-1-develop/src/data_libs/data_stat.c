#include "data_stat.h"

double max(double *data, int n) {
    double max = data[0];
    for (int i = 1; i < n; i++)
        if (data[i] > max) max = data[i];
    return max;
}
double min(double *data, int n) {
    double min = data[0];
    for (int i = 1; i < n; i++)
        if (data[i] < min) min = data[i];
    return min;
}
double mean(double *data, int n) {
    double mean = 0;
    for (int i = 0; i < n; i++) mean += data[i];
    mean = mean / n;
    return mean;
}
double variance(double *data, int n) {
    double mean = 0;
    double pow_num = 0;
    double variance = 0;

    for (int i = 0; i < n; i++) mean += data[i];
    mean = mean / n;

    for (int i = 0; i < n; i++) pow_num += data[i] * data[i];
    pow_num = pow_num / n;
    variance = pow_num - (mean * mean);

    return variance;
}