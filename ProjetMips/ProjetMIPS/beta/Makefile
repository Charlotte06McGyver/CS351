all: beta.o convert_hexa.o lecture_instructions.o header.o new_main.o
	gcc -g -Wall beta.o convert_hexa.o lecture_instructions.o header.o new_main.o -o beta -lm
convert_hexa.o: convert_hexa.c convert_hexa.h
	gcc -g -Wall -c convert_hexa.c -o convert_hexa.o
lecture_instructionss.o: lecture_instructions.c lecture_instructions.o
	gcc -g -Wall -c lecture_instructions.c -o lecture_instructions.o
beta.o: beta.c beta.h
	gcc -g -Wall -c beta.c -o beta.o -lm
header.o: header.c header.h
	gcc -g -Wall -c header.c -o header.o
new_main.o: new_main.c
	gcc -g -Wall -c new_main.c -o new_main.o -lm	
