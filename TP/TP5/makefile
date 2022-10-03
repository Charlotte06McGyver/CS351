main : main.o pile.o
	gcc -Wall -o main.exe main.o pile.o

main.o : main.c pile.h
	gcc -Wall -c main.c

pile.o : pile.c pile.h
	gcc -Wall -c pile.c