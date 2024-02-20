#ifndef GRAPH_H_
#define GRAPH_H_

#define WIDTH 80
#define HEIGHT 25

char **memoryAllocation(int height, int width);
void initGraph(char **graph, int height, int width);
void drawGraph(int height, int width);
void freeMemory(char **graph, int height);

#endif