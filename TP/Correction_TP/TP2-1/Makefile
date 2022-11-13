all: jeu.o main.o
	gcc -o main main.o jeu.o
	
main.o : main.c jeu.h
	gcc -c -Wall -ansi -pedantic  main.c
	
jeu.o : jeu.c jeu.h
	gcc -c -Wall -ansi -pedantic jeu.c