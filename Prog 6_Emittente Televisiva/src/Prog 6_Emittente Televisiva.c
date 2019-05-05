/* Un'emittente telelvisiva deve pianificare la messa in onda di spot pubblicitari che uo avvenire in tre fasce orarie: di mattina(8.00,12.00),di pomeriggio(13,17) o di sera(18,22)
L'emittente dispone l'elenco degli spot che riporta per ciascuno le seguenti informazioni:
codice dello spot, titolo ,durata in minuti, costo, fascia oraria
Progettare una soluzione al problema che consenta di:
1) Caricare info relative agli spot in una tabella
2) Inserita in input una fascia oraria, visualizzare lo spot ,relativo alla fascia oraria inserita, di durata massima
3) Inserito in input un periodo di tempo, visualizzare tutti gli spot che hanno la durata inserita in ordine crescente rispetto al costo
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "emittente.h"

#define MAX 20

int main(){
	pubblicita pub[10];
	int scelta,chiudi=0;
	int i,n,fascia_or,durata_ric;
	do{
		printf("0-Esci\n");
		printf("1-Lettura da file\n");
		printf("2-Spot di durata massima\n");
		printf("3-Ordinamento crescende spot rispetto al costo\n");
		printf("4-Visualizza spot\n");
		printf("5-Inserimento spot da tastiera\n");
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
				n=lettura_file(pub);
				stampa(pub,n);
				break;
			case 2:
				do{
					printf("Fascia oraria (0-matt,1-pom,2-sera):	");
					scanf("%d",&fascia_or);
					if(fascia_or<0 || fascia_or>2)
						printf("Fascia oraria errata\n");
				}while(fascia_or<0 || fascia_or>2);

		      	printf("Gli spot di durata piu' lunga sono\n");
		       	massimo(pub,n,fascia_or);
				break;
			case 3:
				printf("Durata degli spot:");
				scanf("%d",&durata_ric);
		        bubble_sort(pub,n,durata_ric);
		       	stampa(pub,n);
			    break;
			case 4:
				stampa(pub,n);
				break;
			case 5:
				printf("Inserire il numero di spot da inserire: ");
				scanf("%d",&n);
				for(i=0;i<n;i++){
					pub[i]=inserimento();
		      	}
				break;
			}
	}while(scelta>0 && scelta<5 && chiudi==0);
	system("pause");
	return 0;
	}
