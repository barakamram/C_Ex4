CC=gcc
FLAGS=-Wall -g


all : frequency

frequency: main.o frequency.o
	$(CC) $(-Wall -g) -o frequency main.o frequency.o

frequency.o: frequency.c frequency.h
	$(CC) $(-Wall -g) -c frequency.c

main.o: main.c main.o
	$(CC) $(FLAGS) -c main.c

.PHONY: clean

clean:
	rm -f  *.o frequency
