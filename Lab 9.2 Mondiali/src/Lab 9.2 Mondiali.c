/* 1)Acquisizione collez di dati di partite d calcio, descritte da:
	squadra a, squadra b, data, risultato, id partita, 					da file;
 	 Russia Arabia 14 giugno 2018 3-0
2) Acquisiz da tastiera di risultato partita fornita in input;
3) Aggiornmaento classifica sulla base dei risultati acquisiti:
	calcolo classifica: 3pti vitt, 1 pto pareggio, 0 pti sconftta
	Classifica memorizzata su unico file
	visulaizzata a console secondo 1 ordinamento decrescente per punteggio totalizzato e, in caso uguaglianza, crescente sulla base delle partite giocate
 */

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
	int scelta,chiudi=0,dim=0,flag=0,num_sq=0;
	squadra s[NUM_SQUADRE];
	partita p[MAX],work;

	dim=leggi_file(p);
	visual_squadre(p,dim);
	do{
		printf("Menu:\n");
		printf("0: Esci\n");
		printf("1  Acquisiz risultati partite\n");
		printf("2: Visuaizzazione classifica\n");
		printf("Scelta:\n");
		scanf("%d",&scelta);
		switch(scelta){
			case 0:
				chiudi=1;
				break;
			case 1:
				dim=leggi_file(p);
				do{
					dim++;
					work=acquisiz_partita(dim);
					scrivi_file(work);
					printf("Ripetere?\n");
					scanf("%d",&flag);
				}while(flag==1);

				dim=leggi_file(p);
				visual_squadre(p,dim);
				printf("\n");
				break;
			case 2:
				num_sq=creaz_array_squadre(p,dim,s);
				num_sq=rimozione_duplicati(s,num_sq);
				calcola_punteggio(s,num_sq,p,dim);
				insertion_sort(s,num_sq);
				visual_classifica(s,num_sq);
				scrivi_file_classifica(s,num_sq);
				break;
			}
	}while(scelta>0 && scelta<3 && chiudi==0);
	system("pause");
	return 0;
}
