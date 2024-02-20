#include "draw.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

char **memoryAllocation(int height, int width) {
    char **graph;
    graph = (char **)malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        graph[i] = (char *)malloc(width * sizeof(char));
    }
    return graph;
}

void initGraph(char **graph, int height, int width) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            graph[y][x] = '.';
        }
    }
}

void drawGraph(int height, int width) {
    for (int y = height; y >= 0; y--) {
        for (int x = 0; x < width; x++) {
            double yLimit = 1 - y * (1.0 / 12.0);
            double xLimit = x * 4 * M_PI / 80.0;
            if ((0.75 * xLimit) > yLimit && (0.75 * xLimit) < (1 - (y - 1) * (1.0 / 12.0))) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

void freeMemory(char **graph, int height) {
    for (int i = 0; i < height; i++) {
        free(graph[i]);
    }
    free(graph);
}