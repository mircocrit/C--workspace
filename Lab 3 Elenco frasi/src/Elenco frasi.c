/*Scrivere un programma che esegua:
 1) acquisizone testo da tasitera elenco di frasi, avente dimensone non definita (frase=insieme di parole, con parola=seq di caratteri diverso dallo spazio)
 2) identificare le prime 3 parole che compaiono con piu frequenza
 3) scrivere su file parole e conteggi del punto 2
 4) identificare i nomi (parole che iniziano con lett maiusc) e visualizzarli su console
 */
#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

#define MAX_CHAR 26
#define MAX_STRING 1000
#define MAX_TOKEN 500
#define NUM 3
#define FALSE 0
#define TRUE 1


int main(){
	int scelta,chiudi=FALSE,dim=0,cont=0,i;
	char testo[MAX_STRING],word_freq_max[MAX_CHAR];
	parola word[MAX_TOKEN];
	leggi_file(testo);
    output_testo(testo);

	do{
		printf("Menu\n");
		printf("0-Esci\n");
		printf("1-Acquisizione da file,token,visualizzazoine token\n");
		printf("2-Prime 3 parole con frequenza maggiore\n");
		printf("3-Ricerca nomi\n");
		printf("4-Inserimento frasi da tastiera\n");
		printf("scelta --->  ");
		scanf("%d", &scelta);
		switch(scelta){
			case 0:
				chiudi = TRUE;
				break;
			case 1:
				dim=leggi_stringhe(word);
				output_token(word,dim);
				//leggi_file(testo);
				//rimuovi_punteggiatura(testo);
				//output_testo(testo);
				//dim=tokenizza(word,testo);
				//output_token(word,dim);
				break;
			case 2:
				for(i=0;i<NUM;i++){
					cont=parola_max_freq(word,dim,word_freq_max);
					scrivi_file(word_freq_max,cont);
					printf("Parola:  %s	  Frequenza:  %d\n",word_freq_max,cont);
					dim=elimina_stringa(word,dim,word_freq_max);
				}
				break;
			case 3:
				leggi_file(testo);
				rimuovi_punteggiatura(testo);
				dim=tokenizza(word,testo);
				printf("I nomi del testo sono:\n");
				visual_nomi(word,dim);
				break;
			case 4:
				input_testo(testo);
				printf("Il testo inserito e':\n");
				output_testo(testo);
				break;
			}
	}while(scelta>0 && scelta<5 && chiudi==FALSE);
	system("pause");
	return 0;
}
