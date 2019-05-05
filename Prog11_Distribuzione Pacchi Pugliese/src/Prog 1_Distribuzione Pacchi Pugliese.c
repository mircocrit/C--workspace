/* L'azienda di distribuzione dei pacchi pugliese ha bisogno di gestire le prenotazioni di consegne da parte dei commerciani locali.
L'azienda ha a disposizione un numero di impiegati che varia per ogni giorno della settimana e ogni impiegato puo effettuare una consegna al giorno
Le consegne costano al cliente 20 euro ciascuna( prelevati dal suo conto  a termine della consegna).
Progettare un sistema online che permetta le seguenti operazioni
1) L'amministrazione puo modificare il numero di impiegati(tipo dei corrieri) disponibili in una giornata specifica *
2) L clienti possono prenotare una consegna specificando indirizzo,data fascia oraria (mattina o pomeriggio) *
 Se nella data specificata c'e disponibilita, il cliente riceve un identificatore della consegna
3) L'amministrazione puo modificare lo stato di una consegna (in attesa di ritiro, corriere in arrivo per il ritiro,arrivato in sede, pronto alla consegna,affidato al conrrire,consegnato)
4) I clienti possono controllarte lo stato della consegna tramite codice identificativo
5) L'amministrazione puo richiedere l'elenco ordinato per data delle consegne
6) L'amministratore puo richiedere gli incassi totali per un periodo definito dall'utente
7) L'amministratore puo richiedere la lista di consegne in undeterminato stato
8) L'amministrazione puo applicare sconti a consegne in attesa da piu di un tot di giorni definiti dall'utente */

#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pacchi.h"

#define DIM_STR 100
#define MAX 100
#define DIM_DATE 11


int main(){
	consegna consegne[MAX];
	int n=0;
	int giorno=0;
	int scelta,chiudi=0;
	do{
		printf("Scegli azione:\n");
		printf("0 - Esci \n");
		printf("1 - Aggiorna disponibilita settimanale \n");
		printf("2 - Prenota  una consegna \n");
		scanf("%d",&scelta);
		switch(scelta){
			default:
				printf("Scelta non valida\n");
				break;
			case 0:
				chiudi=1;
				break;
			case 1:
				do{
					printf("inserire giorno della settimana: (1,7)");
					scanf("%d",&giorno);
					if (giorno<1 || giorno>7)	printf("Giorno non valido\n");
				}while(giorno<1 || giorno>7);
				do{
					printf("Inserire il numero di impiegati disponibili:\n");
					scanf("%d", &dispsett[giorno-1]);
					if(dispsett[giorno-1]<0)		printf("Valore non valido\n");
				}while(dispsett[giorno-1]<0);
				break;
			case 2:
				prenotazione_cons(consegne,n);
				break;
		}
	}while(chiudi==0);
	system("pause");
	return 0;
}

