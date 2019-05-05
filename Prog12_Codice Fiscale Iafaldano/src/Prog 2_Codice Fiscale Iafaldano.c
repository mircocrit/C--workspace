#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "cod_fisc.h"
#define STRLEN 100

int main(){
	char cf[17];
	int insertChars=0;

	char cognome[STRLEN];
	printf("Cognome: ");
	scanf("%[A-Za-z ]", cognome);
	fflush(stdin);
	insertChars = calcolaCognome(cognome, cf, insertChars);

	char nome[STRLEN];
	printf("Nome: ");
	scanf("%[A-Za-z ]", nome);
	fflush(stdin);
	insertChars = calcolaNome(nome, cf, insertChars);

	char sesso;
	printf("Sesso M/F: ");
	scanf("%s", &sesso);
	fflush(stdin);

	int anno;
	char anno_s[5];
	printf("Anno di nascita: ");
	scanf("%d", &anno);
	fflush(stdin);
	sprintf(anno_s, "%d", anno);
	cf[insertChars++]=anno_s[strlen(anno_s)-2];
	cf[insertChars++]=anno_s[strlen(anno_s)-1];

	int mese;
	printf("Mese di nascita: ");
	scanf("%d", &mese);
	fflush(stdin);
	insertChars=calcolaMese(mese, cf, insertChars);

	int giorno;
	printf("Giorno di nascita: ");
	scanf("%d", &giorno);
	fflush(stdin);
	insertChars=calcolaGiorno(giorno, sesso, cf, insertChars);

	char comune[STRLEN];
	printf("Nato a:");
	scanf("%[A-Za-z \']", comune);
	fflush(stdin);
	toUpperCase(comune);

	char provincia[3];
	printf("Provincia: (ID)");
	scanf("%s", provincia);
	fflush(stdin);
	toUpperCase(provincia);

	insertChars=calcolaComune(provincia, comune, cf, insertChars);
	if(insertChars<12){
		printf("Comune NON trovato\n");
	}

	insertChars=calcolaControlChar(cf, insertChars);

	cf[insertChars]='\0';
	printf("Codice Fiscale: %s", cf);
	system("pause");
	return 0;
}
