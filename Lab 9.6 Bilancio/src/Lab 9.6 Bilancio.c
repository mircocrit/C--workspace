/*Un utente memorizza l’elenco delle proprie entrate ed uscite su due file di testo, chiamati rispettivamente entrate.dat e uscite.dat.
 * Questi file hanno il seguente formato:
 * ogni riga del file corrisponde ad una specifica entrata (o uscita, rispettivamente) ed è composta da tre campi
data		 importo 		motivazione,		dove:
1) data indica la data dell’entrata (o uscita) ed è rappresentata da un numero intero tra 1 e 366;
2) importo indica l’importo dell’entrata (o uscita) espresso in Euro con due cifre decimali per i centesimi;
3) movitazione descrive la tipologia di spesa, ed è una stringa priva di spazi lunga al massimo 50 caratteri.

Si scriva un programma che riceva sulla linea di comando il nome di un terzo file di testo, relativo alle spese della data odierna.
Tale file contiene, sulla prima riga,
il numero intero (tra 1 e 366) che indica la data odierna,
mentre sulle righe successive contiene una lista di movimenti in tale data.
 Ciascun movimento è rappresentato da una lettera maiuscola (E per le entrate ed U per le uscite), da un importo e da una motivazione.

Il programma deve leggere tale file, ed aggiornare di conseguenza i file entrate.dat e uscite.dat aggiungendo in coda le opportune righe.

Al termine, il programma deve calcolare e visualizzare il saldo totale, ossia la differenza tra la somma delle entrate e la somma delle uscite.

*/

#include <stdio.h>
#include <stdlib.h>

#include "header.h"
#define MAX_ENTR 20
#define MAX_USC 20

int main() {
	int scelta,flag=1,n_entr,n_usc,n_movim;
	entrata e[MAX_ENTR];
	uscita u[MAX_USC];
	data_odierna d;
	float saldo;

	n_entr=leggi_entrate(e);
	n_usc=leggi_uscite(u);
	visual_entrate(e,n_entr);
	visual_uscite(u,n_usc);
	do{
		printf("Menu\n");
		printf("0-Esci\n");
		printf("1-Acquisizione entrate e uscite\n");
		printf("2-Leggi spese in data odierna\n");
		printf("3-Aggiorna entrate e uscite\n");
		printf("4-Calcolo saldo\n");
		printf("scelta-->");
		scanf("%d",&scelta);
		switch(scelta){
			case 0:
				flag=0;
				printf("Esco\n");
				break;
			case 1:
				n_entr=leggi_entrate(e);
				n_usc=leggi_uscite(u);
				visual_entrate(e,n_entr);
				visual_uscite(u,n_usc);
				break;
			case 2:
				n_movim=leggi_spesa(&d);
				visual_data(d,n_movim);
				break;
			case 3:
				aggiorna_dati(d,n_movim);

				n_entr=leggi_entrate(e);
				n_usc=leggi_uscite(u);

				visual_entrate(e,n_entr);
				visual_uscite(u,n_usc);
				break;
			case 4:
				saldo=calcola_saldo(e,n_entr,u,n_usc);
				printf("Il saldo e' %.2f\n",saldo);
				break;
		}
	}while(scelta>0 && scelta<5 && flag==1);
	system("pause");
	return 0;
}
