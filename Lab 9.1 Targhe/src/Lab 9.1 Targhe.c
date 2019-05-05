/*
1) Acquisizione di una collezione di dati di autovetture(descritte da targa, cilindrata, modello, datat di immatricolazione) da file
2) Ordinamneto delle autovetture con criterio decrescente rispetto alla cilindrata e, in caso di uguaglianza, rispetto alla targa
-Si usi la selezione
-Le autovetture ordinate dovrano esser memorizzate in un file
3) Selezine delle autovetture con data al di fuori dell'intervallo fissato da 2 date in input e selezione tra queste, l'autovettura con piu alta cilindrata
-Visualizzazione delle autovetture selezionate e dell'autovettura con cilindrata piu alta a console
 */

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

#define MAX_AUTO 20
#define MAX_CHAR 25

int main(){
	int scelta,chiudi=0,dim=0,dim_buffer=0;
	autovettura autom[MAX_AUTO],buffer[MAX_AUTO];

	dim=leggi_auto(autom);
	visual_auto(autom,dim);
	do{
		printf("0: Esci\n");
		printf("1: Ordinamento decrescente di auto rispetto alla cilindrata \n");
		printf("2: Fatture al di fuori date e ricerca di quella con maggiore cilindrata\n");
		printf("scelta\n");
		scanf("%d",&scelta);

		switch(scelta){
			case 0:
				chiudi=1;
				break;
			case 1:
				selection_sort(autom,dim);
				visual_auto(autom,dim);
				scrivi_auto(autom,dim);
				break;
			case 2:
				dim_buffer=ricerca_data(autom,dim,buffer);
				visual_auto(buffer,dim_buffer);
				//ricerca_max(buffer,dim_buffer);
				break;
		}
	}while(scelta>0 && scelta<3 && chiudi==0);

	return 0;
}
