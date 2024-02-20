#include <stdio.h>
int input(int* parray);
void sort(int* parray);
void output(int* parray);

int main() {
    int array[10];

    if ((input(array)) == 1) {
        sort(array);
        output(array);
    } else
        printf("n/a");
    return 0;
}

int input(int* parray) {
    int flag = 1;
    for (int i = 0; i < 10; i++) {
        if ((scanf("%d", &parray[i])) != 1) {
            flag = 0;
            break;
        }
    }
    return flag;
}

void sort(int* parray) {
    int i, j, tmp;
    for (i = 0; i < 10; i++) {  // это до какого числа должны проверяться индексы
        for (j = 0; j < 10;
             j++) {  // в этом цикле будут проверяться значения в массиве (сортировка пузырьком)
            if (parray[j] > parray[j + 1]) {
                tmp = parray[j];
                parray[j] = parray[j + 1];
                parray[j + 1] = tmp;
            }
        }
    }
}

void output(int* parray) {
    for (int i = 0; i < 10; i++) {
        printf("%d ", parray[i]);
    }
}