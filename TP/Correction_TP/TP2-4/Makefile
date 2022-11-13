all :	dessine.o graphlib.o main.o
	gcc -o main dessine.o graphlib.o main.o -lX11
	
main.o:	main.c
	gcc -c -Wall -ansi -pedantic main.c -o main.o
	
dessine.o:	dessine.c
	gcc -c -Wall -ansi -pedantic dessine.c -o dessine.o
	
graphlib.o:	graphlib.c graphlib.h
	gcc -c -Wall -ansi -pedantic graphlib.c -o graphlib.o