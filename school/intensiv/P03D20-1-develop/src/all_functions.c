#include <stdio.h>
#include <stdlib.h>

#include "all_func.h"

#define MAX_LENGHT_OF_FUNC 100

struct letter *push_letter(struct letter *first_letter, char letter, int priority) {
    struct letter *ptr_letter = malloc(sizeof(struct letter));
    ptr_letter->next = first_letter;
    ptr_letter->priority = priority;
    ptr_letter->data = letter;
    return ptr_letter;
}

struct letter *pop_letter(struct letter *top_letter) {
    if (top_letter == NULL) {
        return top_letter;
    }
    struct letter *ptr_letter = top_letter->next;
    free(top_letter);
    return ptr_letter;
}

struct polish_notation *push_symbol(struct polish_notation *last_symbol, char data) {
    struct polish_notation *ptr_symbol = malloc(sizeof(struct polish_notation));
    last_symbol->next = ptr_symbol;
    ptr_symbol->next = NULL;
    ptr_symbol->symbol = data;
    return ptr_symbol;
}

struct polish_notation *pop_symbol(struct polish_notation *first_symbol, char data) {
    struct polish_notation *ptr_symbol = first_symbol;
    struct polish_notation *prev_symbor;
    if (ptr_symbol->symbol == data) {
        first_symbol = first_symbol->next;
    } else {
        while (ptr_symbol->symbol != data) {
            prev_symbor = ptr_symbol;
            ptr_symbol = ptr_symbol->next;
        }
        prev_symbor->next = ptr_symbol->next;
        free(ptr_symbol);
    }
    return first_symbol;
}

// int input(char* a) {
//     int count = 0;
//     for (int i = 0; i < MAX_LENGHT_OF_FUNC; i++) {
//         scanf("%c", (a+i));
//         if (a[i] == '\n') break;
//         count++;
//     }
//     return count;
// }

void check(struct polish_notation *last, struct letter *top, char *a, int count) {
    int priority;
    char data;
    struct letter *next_letter;
    for (int i = 2; i <= count; i++) {
        if ((a[i] >= '0' && a[i] <= '9') || a[i] == 120) {
            last = push_symbol(last, a[i]);
        } else {
            if (a[i] == '+') {
                data = '+';
                priority = 1;
                if (top == NULL) {
                    top = push_letter(top, data, priority);
                } else if (priority <= top->priority) {
                    next_letter = top->next;
                    last = push_symbol(last, next_letter->data);
                    top = pop_letter(next_letter);
                    top = push_letter(top, data, priority);
                } else
                    top = push_letter(top, data, priority);
            } else if (a[i] == '-') {
                data = '-';
                priority = 1;
                if (top == NULL) {
                    top = push_letter(top, data, priority);
                } else if (priority <= top->priority) {
                    next_letter = top->next;
                    last = push_symbol(last, next_letter->data);
                    top = pop_letter(next_letter);
                    top = push_letter(top, data, priority);
                } else
                    top = push_letter(top, data, priority);
            } else if (a[i] == '*') {
                data = '*';
                priority = 2;
                if (top == NULL) {
                    top = push_letter(top, data, priority);
                } else if (priority <= top->priority) {
                    next_letter = top->next;
                    last = push_symbol(last, next_letter->data);
                    top = pop_letter(next_letter);
                    top = push_letter(top, data, priority);
                } else
                    top = push_letter(top, data, priority);
            } else if (a[i] == '/') {
                data = '/';
                priority = 2;
                if (top == NULL) {
                    top = push_letter(top, data, priority);
                } else if (priority <= top->priority) {
                    next_letter = top->next;
                    last = push_symbol(last, next_letter->data);
                    top = pop_letter(next_letter);
                    top = push_letter(top, data, priority);
                } else
                    top = push_letter(top, data, priority);
            }
        }
    }
    while (top->next != NULL) {
        last = push_symbol(last, top->data);
        top = pop_letter(top);
    }
    last = push_symbol(last, top->data);
    top = pop_letter(top);
}

void test_output(struct polish_notation *first) {
    struct polish_notation *ptr = first;
    while (ptr->next != NULL) {
        ptr = ptr->next;
        printf("%c", first->symbol);
        first = ptr;
    }
}

void destroy(struct polish_notation *root) {
    while (root != NULL) {
        struct polish_notation *elem = root->next;
        free(root);
        root = elem;
    }
}

struct polish_notation *init_pol(char data) {
    struct polish_notation *first = malloc(sizeof(struct polish_notation));
    first->symbol = data;
    first->next = NULL;
    return first;
}

struct letter *init_let(char data) {
    struct letter *first = malloc(sizeof(struct polish_notation));
    first->data = data;
    first->next = NULL;
    return first;
}