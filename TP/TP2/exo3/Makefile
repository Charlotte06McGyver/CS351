all: main
main.o: main.c fonctions3.h
	gcc -Wall -c main.c

estUneDecompostionDe.o: estUneDecompostionDe.c fonctions3.h
	gcc -Wall -c estUneDecompostionDe.c

pgcd.o: pgcd.c fonctions3.h
	gcc -Wall -c pgcd.c

ppcm.o: ppcm.c fonctions3.h
	gcc -Wall -c ppcm.c

puissanceMB.o: puissanceMB.c fonctions3.h
	gcc -Wall -c puissanceMB.c

quotient.o: quotient.c fonctions3.h
	gcc -Wall -c quotient.c

reste.o: reste.c fonctions3.h
	gcc -Wall -c reste.c

sommeDesImpairs.o: sommeDesImpairs.c fonctions3.h
	gcc -Wall -c sommeDesImpairs.c

valeurAbsolue.o: valeurAbsolue.c fonctions3.h
	gcc -Wall -c valeurAbsolue.c


main: main.o valeurAbsolue.o sommeDesImpairs.o reste.o quotient.o puissanceMB.o ppcm.o pgcd.o estUneDecompostionDe.o
	gcc -Wall -o main main.o valeurAbsolue.o sommeDesImpairs.o reste.o quotient.o puissanceMB.o ppcm.o pgcd.o estUneDecompostionDe.o
