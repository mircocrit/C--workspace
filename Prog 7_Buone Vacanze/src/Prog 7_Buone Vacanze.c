/* L'agenzia buone vacanze gestisce le prenotazioni per un villaggio turistico mediante una tabella che, per ogni appartamento riporta:
codice appartamento, numero stanze, occupazione(libero/occupato), per ogni mese da giugno a settembre,
I clienti dell'agenzia effettuano le loro richieste inviando:
numero delle stanze, mese di interesse.
Progettare una soluzione al problema di gestione delle richieste che fornisca in output:
1) Per ogni richiesta un messaggio di richiesta accettata o rifiutata e,in caso di accettazione, il codice dell'appartamento assegnato;
2) Il mese e la tipologia dell'appartamento piu richiesto;
3) La tabella aggiornata.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "vacanze.h"

#define MAX 20

int main(){
	appartamento a[MAX];
	richiesta r[MAX];
	int scelta,chiudi=0,n_app,n_rich;
	do{
		printf("0-Esci\n");
		printf("1-Lettura dati\n");
		printf("2-Evasione prenotazione\n");
		printf("3-Ricerca appartam piu richiesto\n");
		printf("4 Stampa appartamenti\n");
		printf("5 Stampa richieste\n");
		printf("scelta: ");
		scanf("%d",&scelta);
		switch(scelta){
			default:
				printf("Errore inserimento\n");
		  		break;
			case 0:
				chiudi=1;
				break;
			case 1:
			    n_app=leggi_app(a);
			    n_rich=leggi_rich(r);
			    stampa_app(a,n_app);
			    stampa_rich(r,n_rich);
				break;
			case 2:
				evasione(r,a,n_rich,n_app);
				stampa_rich(r,n_rich);
		   		break;
		    case 3:
		    	printf("Gli appartamenti piu richiesti sono:\n");
		    	ricerca_max(a,n_app);
		    	break;
		    case 4:
				stampa_app(a,n_app);
				break;
			case 5:

				stampa_rich(r,n_rich);
				break;
		}
	}while(scelta>0 && scelta<6 && chiudi==0);
	system("pause");
	return 0;
}
