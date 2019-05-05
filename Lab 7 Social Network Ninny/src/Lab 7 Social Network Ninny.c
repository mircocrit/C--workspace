
/*Scrivere un programma in c che fornisca funzionalita per social network, offerte da menu:
 1) Iscrizione di un nuovo utente,descritto da nome, cognome,nickname_lista di amici, lista utenti che hanno espresso un like:
  -i nickname sono univoci
  -tutti gli utenti dovranno essere memorizzati in un file
  -un utente puo avere massimo 5 amici e 10 like
2) Creare una relazione d'amicizia tra 2 utenti forniti in input
-tutte le relazioni di amicizia dovranno essere memorizzate in un secondo file
3) Mettere like da un utente ad un altro, entrambi dati in input, se questi non sono gia amici
-tutti i like dovranno essere memorizzati in un terzo file
4) Visualizzare il contenuto dei 3 file
 */

#include <stdio.h>
#include <stdlib.h>
#include "social.h"

#define TRUE 1
#define FALSE 0

int main() {
	int scelta, chiudi=FALSE;
	do
	{
		puts("\t0-Esci");
		puts("\t1-Iscrizione");
		puts("\t2-Chiedi amicizia");
		puts("\t3-Like");
		puts("\t4-Visualizzazione file");
		printf("\tscelta : ");
		scanf("%d",&scelta);
		switch(scelta){
			case 0:
				chiudi = TRUE;
				break;
			case 1:
				scrivi_file();
				break;
			case 2:
				richiesta_amicizia();
				break;
			case 3:
				like();
				break;
			case 4:
				break;
		}
	}while(scelta>0 && scelta<=4 && chiudi==FALSE );
	system("pause");
	return 0;
}
