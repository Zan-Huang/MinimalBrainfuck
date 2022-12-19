CC=g++
CFLAGS=-I. -O0 -g -Wall -fcheck=all -fbacktrace
DEPS=brainfuck.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

brainfuck: brainfuck.o main.o
	$(CC) -o brainfuck brainfuck.o main.o

.PHONY: clean
clean:
	rm -f *.o