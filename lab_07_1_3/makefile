CFLAGS := -std=c99 -pedantic -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion
CC := gcc
OBJ := mysort.o key_func.o
IO/OBJ := input.o output.o
OBJ_PATH := ./
INC_PATH := inc/
SRC_PATH := src/
UNIT_TESTS_PATH := unit_tests/
CHECKFLAGS = -lcheck	
CHECKOBJS = $(OBJ_PATH)mysort.o $(OBJ_PATH)key_func.o $(UNIT_TESTS_PATH)check_mysort.o $(UNIT_TESTS_PATH)check_main.o $(UNIT_TESTS_PATH)check_key_func.o 



$(OBJ_PATH)mysort.o: $(SRC_PATH)mysort.c $(INC_PATH)defines.h
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_PATH)

$(OBJ_PATH)key_func.o: $(SRC_PATH)key_func.c $(INC_PATH)defines.h
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_PATH)

	
$(OBJ_PATH)input.o: $(SRC_PATH)input.c $(INC_PATH)defines.h
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_PATH)
	
$(OBJ_PATH)output.o: $(SRC_PATH)output.c $(INC_PATH)defines.h
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_PATH)

$(OBJ_PATH)main.o: $(SRC_PATH)main.c $(INC_PATH)defines.h
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_PATH)

app.exe: $(OBJ_PATH)mysort.o $(OBJ_PATH)key_func.o $(OBJ_PATH)input.o $(OBJ_PATH)output.o $(OBJ_PATH)main.o
	$(CC) $(CFLAGS) -o $@ $^ -I $(INC_PATH)


$(UNIT_TESTS_PATH)check_mysort.o: $(UNIT_TESTS_PATH)check_mysort.c $(INC_PATH)defines.h
	$(CC) -std=c99 -o $@ -c $< -I $(INC_PATH)

$(UNIT_TESTS_PATH)check_main.o: $(UNIT_TESTS_PATH)check_main.c $(INC_PATH)defines.h
	$(CC) -std=c99 -o $@ -c $< -I $(INC_PATH)

$(UNIT_TESTS_PATH)check_key_func.o: $(UNIT_TESTS_PATH)check_key_func.c  $(INC_PATH)defines.h
	$(CC) -std=c99 -o $@ -c $< -I $(INC_PATH)
	
unit_tests.exe: $(CHECKOBJS)
	$(CC) -o $@ $(CHECKOBJS) $(CHECKFLAGS)