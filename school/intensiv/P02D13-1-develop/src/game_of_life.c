#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define HEIGHT 25
#define WIDTH 80
#define GENERATION 500
#define MODE_1 1
#define MODE_2 2
#define MODE_3 3
#define MODE_4 4
#define MODE_5 5

void input(int *matrix, FILE *file);
int axis_x(int i, int k);
int axis_y(int j, int l);
int find_neigh(int matrix[HEIGHT][WIDTH], int i, int j);
void calculation(int (*matrix)[WIDTH], int (*new_matrix)[WIDTH], int delay);

int main(int argc, char *argv[]) {
    int matrix[HEIGHT][WIDTH], new_matrix[HEIGHT][WIDTH];
    int delay, mode;
    if (argc < 2)
        delay = 1000;
    else {
        delay = atoi(argv[1]);
    }
    FILE *file;
    printf("1. Gun 2. Locomotive 3. Moving 4. Periodically 5. Spaceship_Orion\n");
    scanf("%d", &mode);
    switch (mode) {
        case MODE_1:
            file = fopen("Initial_State/Gun.txt", "r ");
            break;
        case MODE_2:
            file = fopen("Initial_State/Locomotive.txt", "r ");
            break;
        case MODE_3:
            file = fopen("Initial_State/Moving.txt", "r ");
            break;
        case MODE_4:
            file = fopen("Initial_State/Periodically.txt", "r ");
            break;
        case MODE_5:
            file = fopen("Initial_State/Spaceship_Orion.txt", "r ");
            break;
        default:
            printf("n/a");
            return 1;
    }
    input(&matrix[0][0], file);
    calculation(matrix, new_matrix, delay);
}

void calculation(int (*matrix)[WIDTH], int (*new_matrix)[WIDTH], int delay) {
    int i, j, k, neigh;
    for (k = 0; k < GENERATION; k++) {
        for (i = 0; i < HEIGHT; i++) {
            for (j = 0; j < WIDTH; j++) {
                neigh = find_neigh(matrix, i, j);
                if (neigh != 3 && matrix[i][j] == 0)
                    new_matrix[i][j] = 0;
                else if (neigh < 2 && matrix[i][j] != 0)
                    new_matrix[i][j] = 0;
                else if (neigh > 3 && matrix[i][j] != 0)
                    new_matrix[i][j] = 0;
                else
                    new_matrix[i][j] = 1;
                if (matrix[i][j] == 1)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }
        usleep(1000000 / delay);
        system("clear");
        for (i = 0; i < HEIGHT; i++) {
            for (j = 0; j < WIDTH; j++) {
                matrix[i][j] = new_matrix[i][j];
            }
        }
    }
}

void input(int *matrix, FILE *file) {
    if (file != NULL) {
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                fscanf(file, "%d", (matrix + i * WIDTH + j));
            }
        }
        fclose(file);
    }
}

int axis_x(int i, int k) {
    i = i + k;
    if (i >= HEIGHT) i = i - HEIGHT;
    if (i < 0) i = i + HEIGHT;
    return i;
}

int axis_y(int j, int l) {
    j = j + l;
    if (j >= WIDTH) j = j - WIDTH;
    if (j < 0) j = j + WIDTH;
    return j;
}

int find_neigh(int matrix[HEIGHT][WIDTH], int i, int j) {
    int k, l, counter = 0;
    for (k = -1; k <= 1; k++) {
        for (l = -1; l <= 1; l++)
            if (k || l)
                if (matrix[axis_x(i, k)][axis_y(j, l)] != 0) counter++;
    }
    return counter;
}