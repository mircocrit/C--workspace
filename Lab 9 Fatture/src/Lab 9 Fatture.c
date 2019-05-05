/* Scrivere un programma in c in grado do fornire le seguenti funzionalita offerte da menu utente:
 1) acquisizione di una collezione di dati di Fatture (descritte da Codice,saldo,ragione sociale,data) da file;
 2) Ordinamento delle fatture con criterio crescente rispetto al saldo e,
 in caso di uguaglianza, rispetto al codice
 -si usi inserzione
 -Le fatture ordinate devon oessere memorizzare su file
 3) Selezione delle fatture con data inclusa in due date di input e selezione, tra queste, della fattura con piu alto saldo
 4) VIsulaizzazione della fattur selezionate e della fattra con saldo maggoine a console
 */

#include <stdio.h>
#include <stdlib.h>
#include "fatture.h"

#define MAX_FATT 20

int main(){
	int scelta,chiudi=0,dim=0,dim_buffer=0;
	fattura fatt[MAX_FATT],buffer[MAX_FATT];

	dim=leggi_fatture(fatt);
	visual_fatture(fatt,dim);
	do{
		printf("0: Esci\n");
		printf("1: Ordinamento crescente di fatture rispetto al saldo\n");
		printf("2: Fatture entro date e ricerca di quella con maggiore saldo\n");
		printf("scelta\n");
		scanf("%d",&scelta);

		switch(scelta){
			case 0:
				chiudi=1;
				break;
			case 1:
				insertion_sort(fatt,dim);
				visual_fatture(fatt,dim);
				scrivi_fatture(fatt,dim);
				break;
			case 2:
				dim_buffer=ricerca_data(fatt,dim,buffer);
				visual_fatture(buffer,dim_buffer);
				ricerca_max(buffer,dim_buffer);
				break;
		}
	}while(scelta>0 && scelta<3 && chiudi==0);

	return 0;
}
