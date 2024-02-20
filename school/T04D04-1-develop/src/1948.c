#include <stdio.h>

int is_prime(int x); // функция для наиб общ делителя
for (j = 2; i < x; j++){
    if (x % j == 0){
        return 0;
    }
    return 1;
}

int main(){
int a;
scanf("%d", &a); // вводим число с консоли

int i;
for (i = 2; i <= is_prime(a); i++){ // i - это пересчет всех чисел от 2 до введенного числа включительно
    if (is_prime(a) % i == 0){
        return 0;
    }
    return 1;
}
    return 0;
}
