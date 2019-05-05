#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main(){
	int scelta, chiudi = 0,dimensione = 0;
	partita partite[MAX_PARTITE];
	partita p;
	squadra squadre[MAX_SQUADRE];
	do{
		puts("0-Esci");
		puts("1-Aquisisci dati partite");
		puts("2-Aquisisci  risultato partita");
		puts("3-Aggiornamento calssifica");
		printf("scelta --> ");
		scanf("%d",&scelta);
		switch(scelta){
			case 0:
				chiudi = 1;
				break;
			case 1:
			    dimensione = leggi_file(partite,dimensione);
			    break;
			case 2:
				p = acquisizione_partita();
		        scrivi_file(p);
		        break;
			case 3:
				inserisci_squadre(partite,dimensione,squadre);
				break;
		}
	}while(scelta > 0 && scelta <= 3 && chiudi == 0);
	system("pause");
	return 0;
}
