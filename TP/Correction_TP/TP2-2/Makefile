all :	bib_maths.o main_maths.o
	gcc -o main bib_maths.o main_maths.o -lm
	
main_maths.o:	main_maths.c
	gcc -c -Wall -ansi -pedantic main_maths.c -o main_maths.o
	
bib_maths.o:	bibmaths.c
	gcc -c -Wall -ansi -pedantic bib_maths.c -o bib_maths.o
