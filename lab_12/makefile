CFLAGS := -std=c99 -Wall -Werror -Wextra -Wfloat-equal -Wfloat-conversion
CC := gcc
OBJ := mysort.o key_func.o
IO/OBJ := input.o output.o
OBJ_PATH := ./out/
INC_PATH := ./inc/
SRC_PATH := ./src/
UNIT_TESTS_PATH := unit_tests/
CHECKFLAGS = -lcheck	
CHECKOBJS = $(OBJ_PATH)mysort.o $(OBJ_PATH)key_func.o $(UNIT_TESTS_PATH)check_mysort.o $(UNIT_TESTS_PATH)check_main.o $(UNIT_TESTS_PATH)check_key_func.o



$(OBJ_PATH)libmysort.so: $(SRC_PATH)mysort.c $(INC_PATH)defines.h
	$(CC) $(CFLAGS) -o $(patsubst %.so, %.o, $@) -c $< -fPIC -I $(INC_PATH)
	$(CC) -o $@ -shared $(OBJ_PATH)libmysort.o

$(OBJ_PATH)libkey_func.so: $(SRC_PATH)libkey_func.c $(INC_PATH)defines.h
	$(CC) $(CFLAGS) -o $(patsubst %.so, %.o, $@) -c -fPIC $< -I $(INC_PATH)
	$(CC) -o $@ -shared  $(OBJ_PATH)libkey_func.o

	
$(OBJ_PATH)libinput.a: $(SRC_PATH)input.c $(INC_PATH)defines.h
	$(CC) $(CFLAGS) -o $(patsubst %.a, %.o, $@) -c $< -fPIC -I $(INC_PATH)
	ar rc $@ $(patsubst %.a, %.o, $@)
	
$(OBJ_PATH)liboutput.a: $(SRC_PATH)output.c $(INC_PATH)defines.h
	$(CC) $(CFLAGS) -o $(patsubst %.a, %.o, $@) -c $< -fPIC -I $(INC_PATH)
	ar rc $@ $(patsubst %.a, %.o, $@)

$(OBJ_PATH)main.o: $(SRC_PATH)main.c $(INC_PATH)defines.h
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_PATH)

app.exe: dirs $(OBJ_PATH)libinput.a $(OBJ_PATH)liboutput.a $(OBJ_PATH)main.o
	$(CC) $(CFLAGS) -o $@ $(filter-out $<, $^) -L$(OBJ_PATH) -ldl -loutput -linput -lmysort -I $(INC_PATH)


$(UNIT_TESTS_PATH)check_mysort.o: $(UNIT_TESTS_PATH)check_mysort.c $(INC_PATH)defines.h
	$(CC) -std=c99 -o $@ -c $< -I $(INC_PATH)

$(UNIT_TESTS_PATH)check_main.o: $(UNIT_TESTS_PATH)check_main.c $(INC_PATH)defines.h
	$(CC) -std=c99 -o $@ -c $< -I $(INC_PATH)

$(UNIT_TESTS_PATH)check_key_func.o: $(UNIT_TESTS_PATH)check_key_func.c  $(INC_PATH)defines.h
	$(CC) -std=c99 -o $@ -c $< -I $(INC_PATH)
	
unit_tests.exe: $(CHECKOBJS)
	$(CC) -o $@ $(CHECKOBJS) $(CHECKFLAGS)

.PHONY: dirs
dirs:
	mkdir -p $(OBJ_PATH)