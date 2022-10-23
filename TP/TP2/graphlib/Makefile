all: main
graphlib.o: graphlib.c graphlib.h
	gcc -Wall -c graphlib.c  -o graphlib.o -L/usr/X11/lib -lX11 -lstdc++
dessine.o: dessine.c dessine.h
	gcc -c dessine.c -Wall -o dessine.o
main.o: main.c
	gcc -Wall -o main.o -c main.c
main: main.o dessine.o graphlib.o
	gcc -o main main.o graphlib.o dessine.o
