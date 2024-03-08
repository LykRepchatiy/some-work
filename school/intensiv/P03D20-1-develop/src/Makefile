CC = gcc 
BUILD = ../build/
CFLAGC = -Wall -Werror -Wextra
RM = rm -rf

all: graph.o draw.o all_functions.o
	$(CC) $(CFLAGC) draw.o all_functions.o graph.o -o $(BUILD)Quest_1

draw.o:
	$(CC) $(CFLAGC) draw.c -c

all_functions.o:
	$(CC) $(CFLAGC) all_functions.c -c

graph.o: 
	$(CC) $(CFLAGC) graph.c -c 

clean:
	$(RM) $(BUILD)Quest* *.o

rebuild: clean all 


