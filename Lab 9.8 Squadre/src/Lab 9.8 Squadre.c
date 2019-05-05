/*
Si desidera realizzare un programma in grado di calcolare la classifica di un campionato di calcio giocato tra un massimo di 20 squadre, numerate consecutivamente a partire da 1.
Il programma deve calcolare e presentare in output per ciascuna squadra:
1) il numero di partite giocate
2) i punti conseguiti (si ricorda che la vittoria vale tre punti ed il pareggio un punto)
3) se sono ugiaòi i punti ,si vede chi ha maggior differenza reti fra gol segnati e gol subiti
4) retrocesso (gli ultimi 2)
5) chi va in champions league/europa league
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#define MAX_SQUADRE 30
#define MAX_PARTITE 380

int main(){
	squadra s[MAX_SQUADRE];
	partita p[MAX_PARTITE];
	classifica c[MAX_SQUADRE];
	int num_sq,num_part,scelta,flag=0;

	do{
		printf("Menu\n");
		printf("0-Esci\n");
		printf("1-Acquisizone squadre e partite\n");
		printf("2-Calcola classifica\n");
		printf("Scelta:		");
		scanf("%d",&scelta);
		switch(scelta){
			case 0:
				flag=1;
				break;
			case 1:
				num_part=leggi_partite(p);
				visual_partite(p,num_part);
				//num_sq=creaz_array_squadre(p,num_part,s);
				break;
			case 2:
				crea_classifica(s,num_sq,c);
				calcola_classifica(s,num_sq,p,num_part,c);
				insertion_sort(c,num_sq);
				visual_classifica(c,num_sq);
				scrivi_classifica(c,num_sq);
				break;
		}
	}while(scelta>0 && scelta<3 && flag==0);
	system("pause");
	return 0;
}
