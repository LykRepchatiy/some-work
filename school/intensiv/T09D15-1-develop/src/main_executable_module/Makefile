cc = gcc
flag = -std=c11 -Wall -Werror -Wextra
libs = ../data_libs/
module = ../data_module/
yet = ../yet_another_decision_module/
build = ../../build/

all: Quest3

Quest3 : data_io.o data_process.o data_sort.o data_stat.o data_decision.o main_executable_module.o
	$(cc) $(flag) data_io.o data_process.o data_sort.o data_stat.o data_decision.o main_executable_module.o -o $(build) Quest3

# data_io.o: $(libs) data_io.c $(libs) data_io.h
# 	$(cc) $(flag) -c $(libs) data_io.c -o data_io.o

# data_process.o: $(module) data_process.c $(module) data_process.h
# 	$(cc) $(flag) -c $(module) data_process.c -o data_process.o

# data_sort.o: $(libs) data_sort.c $(libs) data_sort.h
# 	$(cc) $(flag) -c $(libs) data_sort.c -o data_stat.o

# data_stat.o: $(libs) data_stat.c $(libs) data_stat.h
# 	$(cc) $(flag) -c $(libs) data_stat.c -o data_stat.o

# data_decision.o: $(yet) decision.c $(yet) decision.h
# 	$(cc) $(flag) -c $(yet) decision.c -o decision.o

# main_executable_module.o: main_executable_module.c
# 	$(cc) $(flag) -c main_executable_module.c -o main_executable_module.o
data_io.o : $(libs)data_io.c $(libs)data_io.h
	$(cc) $(fl) -c $(libs)data_io.c -o data_io.o

data_sort.o: $(libs) data_sort.c $(libs) data_sort.h
	$(cc) $(flag) -c $(libs) data_sort.c -o data_sort.o

decision.o : $(yet)decision.h $(yet)decision.c
	$(cc) $(fl) -c $(yet)decision.c -o decision.o

data_stat.o : $(libs)data_stat.c $(libs)data_stat.h
	$(cc) $(fl) -c $(libs)data_stat.c -o data_stat.o

data_process.o : $(module)data_process.c
	$(cc) $(fl) -c $(module)data_process.c -o data_process.o

main_executable_module.o: main_executable_module.c
	$(cc) $(flag) -c main_executable_module.c -o main_executable_module.o

