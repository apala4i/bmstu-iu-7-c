INC_PATH=./inc/
OUT_PATH=./out/
SRC_PATH=./src/

APP=app.exe

CC=gcc
FLAGS=-std=gnu99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion
CHECK_FLAGS_HOME=-lcheck -lm -lrt -lsubunit -lpthread
CHECK_FLAGS=-lcheck

SRC=$(wildcard $(SRC_PATH)*.c)
OUT=$(patsubst $(SRC_PATH)%.c, $(OUT_PATH)%.o, $(SRC))

$(APP): dirs $(OUT) $(OUT_PATH)main.o
	$(CC) $(OUT) -o $@

$(OUT_PATH)%.o: $(SRC_PATH)%.c $(INC_PATH)%.h
	$(CC) $(FLAGS) $< -c -o $@ -I $(INC_PATH)

$(OUT_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(FLAGS) $< -c -o $@ -I $(INC_PATH)

.PHONY: clean
clean:
	rm -rf *.exe $(OUT_PATH)

.PHONY: dirs
dirs:
	mkdir -p $(OUT_PATH)
