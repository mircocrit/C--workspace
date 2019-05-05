/*Un'azienda raccoglie le richieste d'acquisto di tutta la settimana che le provengono dai vari siti
per ogni richiesta sono noti:
codice sito, data della richiesta, codice dell'articolo, codice del cliente, descrizione dell'articolo, n pezzi richiesti, costo singolo pezzo
Progettare una soluzione che consenta di:
1) Caricare le richieste in una tabella
2) Dato un input un codice di un articolo e il codice di un sito, visualizzare tutte le richieste in ordine crescente rispetto al costo totale
3) Inserito in input il codice di un sito, visualizzare il codice cliente che ha effettuato l'ordine con il costo maggiore */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "commercio.h"

#define DATE 11
#define CODE 5
#define TESTO 50
#define MAX 20

 int main(){
	 richiesta r[MAX];
	 int scelta,chiudi=0,repeat=0,i=0,n;
	 char site_search[CODE],code_search[CODE];
	 do{
		 printf("0-Esci\n");
		 printf("1-Lettura da file\n");
		 printf("2-Ordina per costo totale\n");
		 printf("3-Cliente con costo maggiore\n");
		 printf("4-Visualizza richieste\n");
		 printf("5-Lettura da tastiera\n");
		 printf("Scelta:	");
		 scanf("%d",&scelta);

		 switch(scelta){
		     default:
			 	printf("Errore, scelta non valida\n");
			 	break;
			 case 0:
			 	chiudi=1;
				break;
		 	 case 1:
		 		n=lettura_file(r);
		 		stampa_richieste(r,n);
		 		break;
	  		case 2:
	  			//printf("Cod articolo:	");//i dati sono pochii!!
	  			//scanf("%s",code_search);
	  			//printf("Cod sito	");
	  			//scanf("%s",site_search);
	  			printf("Ordinamento rispetto al costo totale\n");
		        bubble_sort(r,n);
		        printf("%-10s%-13s%-10s%-10s%-12s%-8s%-8s%-8s\n","Cod_sito","Data","Cod_art","Cod_cli","Descr","Pezzi","Prezzo","totale");
		     	for(i=0;i<n;i++)
		     		//if(r[i].cod_art==code_search && r[i].cod_sito==site_search)
		     			stampa(r[i]);
				 break;
			 case 3:
				printf("Inserire codice sito da cercare:\n");
			    scanf("%s",site_search);
		       	ricerca_max(r,n,site_search);
				break;
			 case 4:
			 	stampa_richieste(r,n);
			 	break;
			 case 5:
				 do{
				 	r[i]=inserimento();
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
