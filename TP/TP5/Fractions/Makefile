all: main
fractions.o: fractions.c fractions.h
	gcc -c -Wall -o fractions.o fractions.c
main.o: main.c fractions.h
	gcc -c -Wall -o main.o main.c
main: main.o fractions.o
	gcc -o main main.o fractions.o
