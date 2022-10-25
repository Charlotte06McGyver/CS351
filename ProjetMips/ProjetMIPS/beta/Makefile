all: main.o convert_hexa.o header.o lecture_instructions.o
	gcc -Wall -o main main.o convert_hexa.o header.o lecture_instructions.o -lm

convert_hexa.o: convert_hexa.c convert_hexa.h header.h
	gcc -Wall -c convert_hexa.c -o convert_hexa.o -lm

header.o: header.c 
	gcc -Wall -c header.c -o header.o

lecture_instructions.o: lecture_instructions.c lecture_instructions.h header.h
	gcc -Wall -c lecture_instructions.c -o lecture_instructions.o

main.o: main.c convert_hexa.h dictionary.h header.h lecture_instructions.h
	gcc -Wall -c main.c -o main.o
