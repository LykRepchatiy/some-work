cc = gcc 
flag = -std=c11 -Wall -Werror -Wextra
build = ../build/

all: door_struct

door_struct: dmanager_module.o
	$(cc) $(flag) dmanager_module.o -o $(build)Quest_1

dmanager_module.o: dmanager_module.o
	$(cc) $(flag) -c dmanager_module.c -o dmanager_module.o

clean: 
	rm -rf *.o ../build/Quest_1
	
rebuild: clean all