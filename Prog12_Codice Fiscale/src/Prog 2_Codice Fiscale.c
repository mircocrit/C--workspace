// Calcolare codice fiscale
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codfisc.h"

void calcolaCognome(char[],char[],int,int);
void calcolaNome(char[],char[],int,int);
void calcolaData(char[],char[],int,int,char);

int main(){
	int max=15, n=3;
	char nome[max],cognome[max];
	char risCognome[n],risNome[n];
	char anno[4],annoDiNascita[5];
	char sesso;
	int mese,giorno;

	printf("Inserire il cognome: ");
	gets(cognome);
	printf("Inserire il nome: ");
	gets(nome);
	printf("Inserire l'anno di nascita in formato aaaa: ");
	gets(anno);
	printf("Inserire mese di nascita formato mm: ");
	scanf("%d",&mese);
    printf("Inserire giorno di nascita formato gg: ");
    scanf("%d",&giorno);
	printf("Inserisci sesso: m=uomo, f=donna ");
	scanf("%c",&sesso);

	calcolaCognome(cognome,risCognome,max,n);
	calcolaNome(nome,risNome,max,n);
    calcolaData(anno,annoDiNascita,mese,giorno,sesso);
	printf("%c%c%c",risCognome[0],risCognome[1],risCognome[2]);
	printf("%c%c%c",risNome[0],risNome[1],risNome[2]);
	printf("%c%c%c%c\n",annoDiNascita[0],annoDiNascita[1],annoDiNascita[2],annoDiNascita[3]);
	system("pause");
	return 0;
}
