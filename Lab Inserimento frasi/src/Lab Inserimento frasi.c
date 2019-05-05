/*Scrivere un programma che esegua:
 1) acquisizone  testo da tasitera elenco di frasi, avente dimensone non definita (frase=insieme di parole, con parola=seq di caratteri diverso dallo spazio)
 2) identificare le prime 3 parole che compaiono con piu frequenza;
 3) scrivere su file parole e conteggi del punto 2
 4) identificare i nomi (parole che iniziano con lett maiusc) e visualizzarli su console
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define MAX 50
#define MAX_WORD 20

int main(){
	int scelta,chiudi=0,flag=1;
	int i=0;
	char parole[MAX][MAX_WORD];
	int dim_parole=0;
	do{
		printf("Menu:\n");
		printf("1: inserimeto frasi da tastiera\n");
		printf("Scelta:	");
		scanf("%d",&scelta);
		switch (scelta){

		case 0:
			chiudi=1;
			break;
		case 1:
			do{
				dim_parole=scrivi_frase(parole,dim_parole);
				printf("Ripetere? SI =1, NO=0\n");
				scanf("%d",&flag);
			}while(flag==1);
			printf("Le parole che compangono le frasi sono:\n");
			for(i=0;i<dim_parole;i++){
				printf("%s\n",parole[i]);
				}
			break;
		}
	}while(scelta>0 && scelta<5 &&chiudi ==0);

	return 0;
}
