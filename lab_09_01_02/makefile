FUNC_TESTS = ./func_test/
INC=./inc/
OUT=./out/
SRC=./src/
UNIT=./unit_tests/
DEBUG=-g
CHECK_FLAGS= -std=gnu99 -Wall -Werror -lcheck -lpthread -lrt
FLAGS=-std=gnu99 -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion

app.exe: dirs funcs.o main.o
	gcc $(FLAGS) -o $@ $(OUT)funcs.o $(OUT)main.o

dirs:
	mkdir -p $(OUT)

funcs.o: $(SRC)funcs.c $(INC)funcs.h
	gcc $(FLAGS) -c $(SRC)funcs.c -o $(OUT)$@ -I$(INC)

main.o: $(SRC)main.c
	gcc $(FLAGS) -c $(SRC)main.c -o $(OUT)$@ -I$(INC)

debug.exe: funcs.o main.o
	gcc $(FLAGS) -o $(FUNC_TESTS)$@ $(OUT)main.o $(OUT)funcs.o -g

check_unit_funcs.o: $(UNIT)check_unit_funcs.c $(UNIT)check_header.h
	gcc $(FLAGS)  -c $(UNIT)check_unit_funcs.c -o $(OUT)$@ -I $(INC)

check_main.o: $(UNIT)check_main.c $(UNIT)check_header.h
	gcc $(FLAGS)  -c $(UNIT)check_main.c -o $(OUT)$@ -I $(INC)

unit_tests.exe: dirs check_unit_funcs.o check_main.o funcs.o
	gcc $(FLAGS) $(OUT)check_unit_funcs.o $(OUT)check_main.o $(OUT)funcs.o -o $@ $(CHECK_FLAGS)

deb_unit_tests.exe: dirs check_unit_funcs.o check_main.o funcs.o
	gcc $(FLAGS) $(OUT)check_unit_funcs.o $(OUT)check_main.o $(OUT)funcs.o -o $@ $(CHECK_FLAGS) $(DEBUG)
	valgrind --tool=memcheck  --leak-check=yes --leak-check=full --show-leak-kinds=all ./deb_unit_tests.exe

clean:
	rm -rf $(OUT) *.exe
