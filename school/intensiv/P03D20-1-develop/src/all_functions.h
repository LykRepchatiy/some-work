#ifndef ALL_FUNCTIONS_H
#define ALL_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGHT 80
#define MAX_HEIGHT 25
#define MAX_LENGHT_OF_FUNC 100

struct letter {  // Структура для букв, стек, добавляем в начало
    char data;
    int priority;
    struct letter *next;
};

struct polish_notation {  // Структура для всех символов, добавляем в конец
    char symbol;
    struct polish_notation *next;
};

struct letter *push_letter(struct letter *first_letter, char letter,
                           int priority);  // Функции для пуша и попа в/из стека букв
struct letter *pop_letter(struct letter *top_letter);

struct polish_notation *push_symbol(struct polish_notation *last_symbol,
                                    char data);  // Функции для пуша и попа в/из общего стека
struct polish_notation *pop_symbol(struct polish_notation *first_symbol, char data);

void check(struct polish_notation *last, struct letter *top, char *a, int count);
int input(char *a);
void test_output(struct polish_notation *first);

#endif