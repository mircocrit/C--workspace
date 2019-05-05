/*Scrivere un programma in C che legge un vettore di stringhe (matrice di caratteri). Si progetti per tale programma:
1) la procedura SCAMBIO che avendo come argomenti il vettore di stringhe M e due indici I e J, effettui lo scambio tra la stringa memorizzata in posizione M[i] e la stringa
memorizzata in posizione M[j]
2) La funzione CONTAPAROLE che avendo come argomenti il vettore di stringhe M e una parola p conti le occorrenze di p all'interno di M
3) La procedura RIMPIAZZA he avendo come argomenti il vettore di stringhe M, una parola p1 e una parola p2 rimpiazzi in M tutte le occorrenze di p1 con p2.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "array.h"

#define DIM 100
#define LENGHT 100

int main() {
	int a,b,n,count=0,scelta,chiudi=1;
	char array[DIM][LENGHT];
	char ricerca[LENGHT],sostit[LENGHT];
	do{
		printf("Menu\n");
		printf("0 Esci\n");
		printf("1 Acquisiz array di stringhe da file\n");
		printf("2 Scambio tra stringhe\n");
		printf("3 Conta occorrenze di una parola\n");
		printf("4 Rimpiazza stringhe dell'array con una inserita \n");
		printf("5 Stampa array di stringhe\n");
		printf("Scelta:		");
		scanf("%d",&scelta);
		switch(scelta){
			case 0:
				chiudi=0;
				break;
			case 1:
				n=leggi_stringhe(array);
				stampa(array,n);
				break;
			case 2:
				printf("Posizioni stringhe da scambiare: 0 %d:	",n-1);
				scanf("%d %d",&a,&b);
				scambia(array,a,b);
				break;
			case 3:
				printf("Parola di cui contare le occorrenze:	");
				scanf("%s",ricerca);
				count=conta_parole(array,n,ricerca);
				printf("Occorrenze %s: %d\n",ricerca,count);
				break;
			case 4:
				printf("Parola da sostituire:	");
				scanf("%s",sostit);
				printf("Parola con cui sostituire quella cercata:	");
				scanf("%s",sostit);
				rimpiazza(array,n,ricerca,sostit);
				break;
			case 5:
				stampa(array,n);
				break;
			}
	}while(scelta>0 && scelta<6 && chiudi==1);
	system("pause");
	return 0;
}
