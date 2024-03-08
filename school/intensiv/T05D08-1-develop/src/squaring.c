#include <stdio.h>
#define NMAX 10

int input(int *pdata, int *pn);      // прототип функции input
void output(int *pdata, int *pn);    // прототип функции output
void squaring(int *pdata, int *pn);  // прототип функции squaring

int main() {
    int n, data[NMAX];
    if ((input(data, &n)) == 1) {  // если вернулся флаг 1, то продолжаем программу
        squaring(data, &n);  // в параметры функции вписываем значения массива и адрес переменной n
        output(data, &n);  // в параметры функции вписываем значения массива
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *pdata,
          int *pn)  // функция input принимает указатель на data(его первую ячейку) и указатель на n
{
    int t = scanf("%d", pn), flag = 1;  // считываем размер массива, ставим флаг = 1
    if (t == 1) {
        for (int i = 0; i < *pn; i++)  // циклом проходимся по индексам массива, начиная с 0
        {
            int check = scanf("%d", &pdata[i]);  // считываем значения в массиве
            if (check != 1) {
                flag = 0;
                break;
            }
        }
    } else {
        flag = 0;  // если не выполняется условие, флаг = 0
    }
    return flag;
}

void output(int *pdata, int *pn) {
    for (int i = 0; i < *pn; i++) {  // циклом проходимся по индексам массива, начиная с 0
        printf("%d ", *pdata);  // печатаем значение в массиве
        pdata++;                // переходим на следующий элемент массива
    }
}

void squaring(int *pdata, int *pn) {
    for (int i = 0; i < *pn; i++) {  // циклом проходимся по индексам массива, начиная с 0
        *pdata = *pdata * *pdata;  // элементы массива возводим в квадрат (указатель разыменован)
        pdata++;                   // переходим на следующий элемент массива
    }
}