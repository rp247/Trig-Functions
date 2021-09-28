CC = clang
CFLAGS = -Wall -Wextra  -Werror  -Wpedantic

all: mathlib-test

mathlib-test: mathlib.o
	$(CC) -o mathlib-test mathlib-test.o mathlib.o -lm

mathlib.o: 
	$(CC) $(CFLAGS) -c mathlib-test.c mathlib.c 

clean:
	rm -f mathlib-test mathlib.o mathlib-test.o

scan-build: clean
	scan-build make

