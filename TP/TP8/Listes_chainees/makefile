main : main.o fonctions.o
	gcc -Wall -o main.exe main.o fonctions.o

main.o : main.c fonctions.h
	gcc -Wall -c main.c

fonctions.o : fonctions.c fonctions.h
	gcc -Wall -c fonctions.c