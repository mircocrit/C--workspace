/*La catena di ristoranti buon appetito gestisce le prenotazioni dei clienti mediante una tabella che, per ogni sede, riporta:
codice della sede, citta della sede, numero totale dei posti disponibili, numero posti occupati
Le prenotazioni vengono raccolte da un'agenzia che invia l'elenco che per ciascuna prenotazione riporta:
codice di prenotazione ,codice della sede, numero di posti che si vogliono prenotare
Si suppone che i tavoli vengano organizzati in base alle prenotazioni.
Progettare una soluzione al problema delle prenotazioni che fornisca in output:
1)Per ogni prenotazione trattata un messaggio di prenotazione accettata o rifiutata
2)Il codice e i corrispondenti codice dela sede e citta della sede,della prenotazione con il numero maggiore di posti richiesti, indipendentemente dall'esito della prenotazione.
3)L'elenco ordinato per numero di posti da prenotare rispetto ad una sede inserita in input
4)Tabella aggiornata */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "appetito.h"

#define MAX 20

int main(){
	prenotazione p[MAX];
	ristorante r[MAX];
	int scelta,chiudi=0;
	int i,j,n_pren=0,n_rist=0,cod_ric;
	do{
		printf("0-Esci\n");
		printf("1-Lettura file \n");
		printf("2-Evasione prenotazioni\n");
		printf("3-Prenotaz con n maggiore posti richiesti\n");
		printf("4-Ordina rispetto alla sede\n");
		printf("5-Stampa ristoranti\n");
		printf("6-Stampa prenotazioni\n");
		printf("Scelta:\n");
		scanf("%d",&scelta);
		switch(scelta){
			default:
				printf("Comando errato\n");
				break;
			case 0:
				chiudi=1;
				break;
			case 1:
				n_rist=leggi_rist(r);
				n_pren=leggi_pren(p);
				stampa_rist(r,n_rist);
				stampa_pren(p,n_pren);
				break;
			case 2:
				evasione(r,p,n_rist,n_pren);
				break;

			case 3:
				printf("Ristoranti con n maggiore di posti richiesti:	");
				ricerca_max(p,n_pren);
				printf("\n");
				break;
			case 4:
				bubble_sort(p,n_pren);

				//printf("Codice sede:	");
				//scanf("%d",&cod_ric);
				printf("%-10s%-10s%-11s%-11s\n","Cod sede","Cod pren","Posti rich","Accettaz");
				for(i=0;i<n_pren;i++){
					//if(p[i].cod_sede==cod_ric)
						stampa_pren_r(p[i]);
				}
				break;
			case 5:
				stampa_rist(r,n_rist);
				break;
			case 6:
				stampa_pren(p,n_pren);
				 break;

			}
	}while(scelta>0 && scelta<7 && chiudi==0);
	system("pause");
	return 0;
}
