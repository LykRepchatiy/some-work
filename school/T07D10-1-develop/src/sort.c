#include <stdio.h>
#include <stdlib.h>
int input(int* parr, int n);
void sort(int* parr, int n);
void output(int* parr, int n);

int main() {
    int n;
    if ((scanf("%d", &n) == 1)) {
        int* parr = (int*)malloc(n * sizeof(int));
        if ((input(parr, n)) == 1) {
            sort(parr, n);
            output(parr, n);
        } else
            printf("n/a");
    } else
        printf("n/a");
    return 0;
}
int input(int* parr, int n) {
    int flag = 1;
    char symb;

    for (int i = 0; i < n; i++) {
        if ((scanf("%d%c", &parr[i], &symb)) != 2 || (symb != '\n' && symb != ' ')) {
            flag = 0;
            break;
        }
    }

    return flag;
}
void sort(int* parr, int n) {
    int i, j, tmp;
    for (i = 0; i < n; i++) {  // это до какого числа должны проверяться индексы
        for (j = 0; j < n - 1;
             j++) {  // в этом цикле будут проверяться значения в массиве (сортировка пузырьком)
            if (parr[j] > parr[j + 1]) {
                tmp = parr[j];
                parr[j] = parr[j + 1];
                parr[j + 1] = tmp;
            }
        }
    }
}
void output(int* parr, int n) {
    for (int i = 0; i < n; i++) {
        if (i != n - 1)
            printf("%d ", parr[i]);
        else
            printf("%d", parr[i]);
    }
    free(parr);
}
