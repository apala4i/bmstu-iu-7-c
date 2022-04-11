INCPATH = inc/
SRCPATH = src/
OUTPATH = out/
OBJ = ${OUTPATH}main.o ${OUTPATH}matrix.o
UNIT_TESTS = unit_tests/
CHECKFLAGS = -lcheck
CHECKOBJS = $(OUTPATH)matrix.o $(UNIT_TESTS)check_main.o $(UNIT_TESTS)check_matrix.o
FLAGS = -std=c99 -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion

app.exe: dirs ${OBJ}
	gcc ${FLAGS} ${OBJ} -o $@

${OUTPATH}matrix.o:
	gcc -c ${FLAGS} -I${INCPATH} ${SRCPATH}matrix.c -o $@

${OUTPATH}main.o:
	gcc -c ${FLAGS} -I${INCPATH} ${SRCPATH}main.c -o $@

.PHONY: clean
clean:
	rm -rf *.exe
	rm -rf out/*.o
dirs:
	mkdir -p ${OUTPATH}

$(UNIT_TESTS)check_matrix.o:
	gcc -std=c99 -o $@ -c $(UNIT_TESTS)check_matrix.c -I $(INCPATH)

$(UNIT_TESTS)check_main.o:
	gcc -std=c99 -o $@ -c $(UNIT_TESTS)check_main.c -I $(INCPATH)

unit_tests.exe: dirs $(CHECKOBJS)
	gcc -o $@ -I${INCPATH} $(CHECKOBJS) $(CHECKFLAGS)

	