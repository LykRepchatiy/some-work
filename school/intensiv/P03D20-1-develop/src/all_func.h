#ifndef ALL_FUNC_H
#define ALL_FUNC_H

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

void destroy(struct polish_notation *root);

struct polish_notation *init_pol(char data);

struct letter *init_let(char data);
#endif