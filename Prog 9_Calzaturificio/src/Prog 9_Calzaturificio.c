/*Un azienda che produce calzature riceve quotidianamente ordini da vari negozi dislocati in varie zone territoriali.
Per ogni tipo di calzatura sono noti i seguenti dati:
codice calzatura, costo calzatura, numero pezzi in magazzino.
Ogni ordine riporta i seguenti dati:
codice negozio(cliente) codice zona, codice calzatura, numero pezzi, data dell'ordine.
Sviluppare un programma che risponda alle seguenti richieste:
1) Caricare i dati delle calzature/ordini in una tabella
2) Inserito il codice di un negozio (cliente), fornire in output l'ordine con il numero massimo di pezzi richiesti
3) Inserito il codice di una calzatura, fornire in output il numero totale dei pezzi richiesti dai negozi (clienti)
4) Inserito il codice di una calzatura, fornire l'elenco ordinato per numero pezzi decrescente degli ordini
5) Per ogni ordine fornire in output il messaggio di ordine evadibile o non evadibile
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "calzatur.h"

#define MAX 20

int main() {
	ordine ord[MAX];
	calzatura calz[MAX];
	int scelta,chiudi=0;
	int i,j,n_calz,n_ord,tot=0;
	char neg_ric[MAX],cod_ric[MAX];
	do{
		printf("0-Esci\n");
		printf("1-Acquisizione dati\n");
		printf("2-Ordine con num max di pezzi richiesti\n");
		printf("3-N totale pezzi richiesti di una data calzatura\n");
		printf("4-Elenco ordini ordinato per n pezzi\n");
		printf("5-Evasione ordini\n");

		printf("6-Visualizza ordini\n");
		printf("7-Visualizza calzature\n");
		printf("8-Inserimento ordine\n");
		printf("9-Inserimeno calzatura\n");
		printf("Scelta: ");
		scanf("%d",&scelta);

		switch(scelta){
			default:
			  	printf("Errore\n");
			   	break;
			case 0:
		    	   chiudi=1;
			   break;
			case 1:
				n_ord=leggi_ordine(ord);
				n_calz=leggi_calz(calz);
				printf("Ordini\n");
				stampa_ord(ord,n_ord);
				printf("Calzature\n");
				stampa_calz(calz,n_calz);
				break;
			case 2:
			   if(n_calz==0)  	printf("Ordini inesistenti\n");
		       	else{
			   	 	printf("Codice negozio:	");
		       		scanf("%s",neg_ric);
		      		printf("Ordine con n. massimo di pezzi richiesti e':\n");
		      		calcola_max(ord,n_ord,neg_ric);
		      		}
				   break;
			case 3:
				printf("Codice calzatura:	");
				scanf("%s",cod_ric);
				tot=calcola_totale(ord,n_ord,cod_ric);
				printf("N. totale pezzi ordinati della calzatura:	%d\n",tot);
				break;
			case 4:
				//printf("Codice calzatura:	");
				//scanf("%s",cod_ric);
				ordina(ord,n_ord);
				printf("%-10s%-10s%-10s%-8s%-12s\n","Cod Cli","Cod Zona","Cod calz","N pezzi","Data ord");
				for(i=0;i<n_ord;i++)
					//if(strcmp(ord[i].cod_calz,calz[j].cod_calz)==0)
						stampa_record(ord[i]);
				break;
			case 5:
				evasione(ord,calz,n_ord,n_calz);
				break;

			case 6:
				if(n_ord==0) printf("Niente da visualizzare\n");
				stampa_ord(ord,n_ord);
				break;
			case 7:
				if(n_calz==0) printf("Niente da visualizzare\n");
				stampa_calz(calz,n_calz);
				break;
			case 8:
				printf("Num ordini:	");
				scanf("%d",&n_ord);
				for(i=0;i<n_ord;i++)
					ord[i]=inserim_ordini();
				 break;
			case 9:
				printf("Num calzature:	");
				scanf("%d",&n_calz);
				for(j=0;j<n_calz;j++)
					calz[j]=inserim_calz();
			break;
		}
	}while(scelta>0 && scelta<9 && chiudi==0);
	system("pause");
	return 0;
}
