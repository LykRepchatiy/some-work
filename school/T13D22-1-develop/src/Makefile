CC = gcc
FLAGS = -std=c11 -Wall -Werror -Wextra
BUILD = ../build/

all: cipher

cipher: cipher.o 
	$(CC) $(FLAGS) cipher.o -o $(BUILD)cipher

cipher.o: cipher.o
	$(CC) $(FLAGS) -c cipher.c -o cipher.o

clean: 
	rm -rf *.o ../build/cipher

rebuild: clean all