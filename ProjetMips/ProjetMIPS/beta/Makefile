all: main.o convert_hexa.o header.o
	gcc -Wall -o main main.o convert_hexa.o header.o -lm
convert_hexa.o: convert_hexa.c convert_hexa.h header.h
	gcc -Wall -c convert_hexa.c -o convert_hexa.o -lm
header.o: header.c 
	gcc -Wall -c header.c -o header.o
main.o: main.c convert_hexa.h dictionary.h header.h 
	gcc -Wall -c main.c -o main.o
