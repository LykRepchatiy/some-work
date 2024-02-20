#include <stdio.h>
#include <stdlib.h>

#include "all_func.h"
#include "draw.h"

#define MAX_LENGHT_OF_FUNC 100

int main() {
    char **graph = memoryAllocation(HEIGHT, WIDTH);
    initGraph(graph, HEIGHT, WIDTH);
    char arr_of_func[MAX_LENGHT_OF_FUNC];
    int count = 0;
    for (int i = 0; i < MAX_LENGHT_OF_FUNC; i++) {
        scanf("%c", &arr_of_func[i]);
        if (arr_of_func[i] == '\n') break;
        count++;
    }
    struct polish_notation *first = init_pol(arr_of_func[0]);
    struct polish_notation *last = first;
    struct letter *top = init_let(arr_of_func[1]);
    check(last, top, arr_of_func, count);
    drawGraph(HEIGHT, WIDTH);
    test_output(first);
    destroy(first);
    freeMemory(graph, HEIGHT);
    return 0;
}
