#include <stdio.h>

void version_if_imbriques (char lettre){
	
	if (lettre == 'A'){
		printf("Tres bien\n");
	}
	else {
		if (lettre == 'B'){
			printf("Bien\n");
		}
		else {
			if (lettre == 'C'){
				printf("Assez Bien\n");
			}
			else {
				if (lettre == 'D'){
					printf("Passable\n");
				}
				else {
					if (lettre == 'E'){
						printf("Insuffisant\n");
					}
					else {  //si l'utilisateur entre une autre lettre qui n'est pas definie
						printf("Vous n'avez pas entre une lettre entre A et E\n");
					}
					
				}
			}
		}
	}
}


void version_if_sequence (char lettre){
	
	if (lettre == 'A'){
		printf("Tres bien\n");
	}
	if (lettre == 'B'){
		printf("Bien\n");
	}
	if (lettre == 'C'){
		printf("Assez bien\n");
	}
	if (lettre == 'D'){
		printf("Passable\n");
	}
	if (lettre == 'E'){
		printf("Insuffisant\n");
	}
	else { //si l'utilisateur entre une autre lettre qui n'est pas definie
		printf("Vous n'avez pas entre une lettre entre A et E\n");
	}

}

void version_switch (char lettre){

	switch (lettre){
		case 'A' :
			printf("Tres bien\n");
			break;
		case 'B' :
			printf("Bien\n");
			break;
		case 'C' :
			printf("Assez bien\n");
			break;
		case 'D' :
			printf("Passable\n");
			break;
		case 'E' :
			printf("Insuffisant\n");
			break;
		default :  //si l'utilisateur entre une autre lettre qui n'est pas definie
			printf("Vous n'avez pas entre une lettre entre A et E\n");
			break;
	}
}


int main(){

	char note;
	printf("Entrez une note : ");
	scanf("%c", &note);
	printf("----Version if imbriques-----\n");
	version_if_imbriques(note);
	printf("----Version if sequence-----\n");
	version_if_sequence(note);
	printf("----Version switch-----\n");
	version_switch(note);


}

