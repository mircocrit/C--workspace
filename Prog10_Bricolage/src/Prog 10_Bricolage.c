/*Un negozio di bricolage gestisce onlone la prenotazione del materiale sotto scorta. Invia al deposito il:
 codice negozio, codice materiale, numero pezzi richiesti,descrizione materiale
 Il deposito gestisce le prenotazoni mediante una tabella che riporti:
 codice materiale, numero pezzi disponibili, descrizione, costo.
 Il programma deve gestire ciascuna prenotazione dando in output:
 1) Messaggio di prenotazione accettata o rifiutata
 2) il costo totale dell'acquisto da parte del negozio
 3) Mostrare la tabella aggiornata e ordinata in base al codice del materiale.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bricol.h"

#define MAX 20

int main(){
	prenotaz p[MAX];
	deposito d[MAX];
	int scelta, chiudi=0;
	int n_pren,n_dep,i,j,search,tot=0;
	do{
		printf("0- Esci\n");
		printf("1- Lettura dati\n");
		printf("2- Evasione prenotazione\n");
		printf("3- Costo totale acquisto per negozio\n");
		printf("4- Ordinamento per codice materiale\n");

		printf("5- Stampa prenotazioni\n");
		printf("6- Stampa negozio\n");
		printf("7- Inserimento dati deposito\n");
		printf("8- Inserimento prenotazioni\n");
		printf("scelta: ");
		scanf("%d",&scelta);
		switch(scelta){
			default:
				printf("Errore inserimento!\n");
				break;
			case 0:
				chiudi=1;
				break;
			case 1:
				n_pren=leggi_prenotaz(p);
				n_dep=leggi_deposito(d);
				stampa_dep(d,n_dep);
				stampa_pren(p,n_pren);
				break;
			case 2:
				evasione(d,p,n_dep,n_pren);
				break;
			case 3:
				printf("Codice negozio:		");
				scanf("%d",&search);
				tot=calcola_tot(p,n_pren,d,n_dep,search);
				printf("Costo toale acquisto per negozio:	%d\n\n",tot);
				break;
			case 4:
		        ordina(d,n_dep);
		    	printf("Il deposito ordinato rispetto ai codici dei materiali presenti al suo interno e':\n");
		    	stampa_dep(d,n_dep);
			    break;

			case 5:
				if(n_dep==0) printf("Niente da visualizzare\n");
				else
					stampa_dep(d,n_dep);
				break;
			case 6:
				if(n_pren==0) printf("Niente da visualizzare\n");
				else
					stampa_pren(p,n_pren);
				break;
		    case 7:
				printf("N materiali deposito:	");
				scanf("%d",&n_dep);
				for(i=0;i<n_dep;i++)
					d[i]=inserim_depos();
				break;
			case 8:
				printf("N prenotazioni:	");
				scanf("%d",&n_pren);
				for(j=0;j<n_pren;j++)
					p[j]=inserim_pren();
				break;
			}
		}while(scelta>0 && scelta<9 && chiudi==0);
	system("pause");
	return 0;
}

