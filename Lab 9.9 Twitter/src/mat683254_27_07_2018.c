/*Scrivere un programma in c in grado di fornire funzionalita simili a quelle di Twitter offerte da menu utente:
A) Acquisizione di una collezione di dati di Nicjname con relativi Follower e Data di inizio FOllowing da file in input
B) Aggiornamento della collezine con inserimento di un nuovo follower per un nickname e data forniti in input
La collezione aggiornata dovra essere visualizzata a console
C) Calcolo del numero di follower e following di un nickname fornito in input
Il risultato dovra essere visualizzato a console
D) Ricerca dei sue Nickname con maggior numero di follower e maggiorn numero di following
Il risultato dovra essere visualizzato a console
E)Selezione dei follower (per un Nickname fornito in input) con data di inizio following incluso in due date forniute in input
I follower dovranno essere ordinati con criterio crescente, memorizzati su un file e visualizzati a console
Lo studente puo scegliere autonomamaente quale algoritmo di ordinamento usare
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

// following=vengono seguiti

#define MAX_NOMI 30
#define MAX_CHAR 24
#define MAX_DATI 30;
//

int main() {
	int scelta,flag=0,num_nomi=0,data=0,num_folr,num_folg,data_low=0,data_high=0;

	nome n[MAX_NOMI];
	char nick[MAX_CHAR],follower[MAX_CHAR];

	do{
	printf("Menu\n");
	printf("1-Acquisizione Nickname e Follower\n");
	printf("2-Aggiornamento collezione\n");
	printf("3-Calcolo numero follower e following\n");
	printf("4-Ricerca 2 nick con maggion num follower e following\n");
	printf("5-Selezione follower in data\n");
	printf("Scelta-->");
	scanf("%d",&scelta);
	switch(scelta){
		case 0:
			flag=1;
			break;
		case 1:
			num_nomi=leggi_nomi(n);
			visual_nomi(n,num_nomi);
			break;
		case 2:
			printf("Nickname:	");
			scanf("%s",nick);
			printf("Follower:	");
			scanf("%s",follower);
			printf("Data:aaaammgg");
			scanf("%d",&data);
			scrivi_file(nick,follower,data);
			num_nomi=leggi_nomi(n);
			visual_nomi(n,num_nomi);
			break;
		case 3:
			printf("Nickname-->");
			scanf("%s",nick);
			printf("Calcolo num follower...\n");
			num_folr=calcola_follower(n,num_nomi,nick);
			printf("Num follower:    %d\n",num_folr);
			printf("Calcolo num following...\n");
			num_folg=calcola_following(n,num_nomi,nick);
			printf("Num following:    %d\n",num_folg);
			break;
		case 4:
			ricerca_max_follower(n,num_nomi);
			ricerca_max_following(n,num_nomi);
			break;

		case 5:
			fflush(stdin);
			printf("Nickname:	");
			scanf("%s",nick);
			printf("Data di input_BASE-->aaaammgg");
			scanf("%d",&data_low);
			printf("Data di input_LIMIT--->aaaammgg");
			scanf("%d",&data_high);

			select_follower(n,num_nomi,data_low,data_high,nick);
			break;

		}
	}while(scelta>0 && scelta<6 && flag==0);
	system("pause");
	return 0;
}
