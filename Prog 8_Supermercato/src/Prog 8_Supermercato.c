/*Essendo nota la numerosita acquisire le informazioni dei supermercati in una tabella con:
nome resp,cognome resp,indirizzo,numero dipendenti,fatturato ultimo anno;
Scrivere ujn programma per la gesione dei supermercati con:
1) Inserimento dati supermercato
2) Ricerca supermercati dato un responsabile in input
3) Ricerca supermercati presenti in una citta inserita
4) Ricerca supermercato con numero max di dipendenti;*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "superm.h"

#define MAX 100
#define STR 27

int main (){
	int scelta,repeat=0,chiudi=0,i=0,n=0;
    supermerc sup[MAX];
	char cogn_ric[STR],nome_ric[STR],citta_ric[STR];
	do{
		printf("Menu:\n");
		printf("0-Esci\n");
		printf("1-Lettura da file supermercati\n");
		printf("2-Ricerca supermercati dato un responsabile\n");
		printf("3-Ricerca supermercati data una citta'\n");
		printf("4-Ricerca supermercato con n max dipendenti\n");
		printf("5-Visual dati supermercato\n");
		printf("6-Inserimento da tastiera del supermercato\n");
		scanf("%d",&scelta);
		switch(scelta) {
        	default:
        		printf ("Scelta non valida\n");
                break;
        	case 0:
                chiudi=1;
                break;
        	case 1:
        		n=lettura_file(sup);
        		stampa(sup,n);
        		break;
            case 2:
            	printf("Nome e cognome responsabile:	");
                scanf("%s %s",nome_ric,cogn_ric);
                ricerca_resp(sup,n,nome_ric,cogn_ric);
                break;
            case 3:
            	printf("Citta':	");
            	scanf("%s",citta_ric);
            	ricerca_citta(sup,n,citta_ric);
                break;
            case 4:
            	ricerca_max(sup,n);
            	break;
            case 5:
            	stampa(sup,n);
            	break;
            case 6:
            	do{
            		sup[i]=inserimento();
            	    i++;
        			printf("Ripetere?	T=1, F=0	");
        			scanf("%d",&repeat);
                }while(repeat==1);
            	n=i;
                break;
		  }
	}while(scelta>0 && scelta<6 && chiudi==0);
	system("pause");
	return 0;
}
