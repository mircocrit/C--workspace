/*
L'azienda di distribuzione pacchi pugliese ha bisogno di gestire
	le prenotazioni di consegne da parte dei commercianti locali.
L'azienda ha a disposizione un numero di impiegati che varia per
	ogni giorno della settimana e ogni impiegato pu? effettuare
	una consegna al giorno.
Le consegne costano al cliente 20? ciascuna (prelevati dal suo conto
	a termine della consegna).

Progettare un sistema online che permetta le seguenti operazioni:
 V - L'amministrazione pu? modificare il numero di impiegati disponibili in una giornata specifica.
 V - I clienti possono prenotare una consegna specificando indirizzo, data, fascia oraria (mattina o pomeriggio). Se nella data specificata c'? disponibilit?, il cliente riceve un identificatore della consegna.
 - L'amministrazione pu? modificare lo stato di una consegna
 	(in attesa di ritiro, corriere in arrivo per il ritiro,
	 arrivato in sede, pronto alla consegna, affidato al corriere, consegnato)
 - I clienti possono controllare lo stato di una consegna
 	tramite il codice identificativo
 - L'amministrazione pu? richiedere l'elenco ordinato per data delle consegne
 - L'amministrazione pu? richiedere gli incassi totali per
 	un periodo definito dall'utente
 - L'amministrazione pu? richiedere la lista di consegne in un
 	determinato stato
 - L'amministrazione pu? applicare sconti a consegne in attesa
 	da pi? di un tot di giorni definiti dall'utente

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Definizione COSTANTI
#define MAX 100
#define DIM_STR 100
#define DIM_DATE 11

//Definizione TIPI
typedef enum {
	mattina, pomeriggio
}FasciaOraria;

typedef struct{
	int id;
	char indirizzo[DIM_STR];
	char data[DIM_DATE];
	float prezzo;
	FasciaOraria fascia_oraria;
}Consegna;

typedef enum {
	lun, mar, mer, gio, ven, sab, dom
}Settimana;
//Prototipi Funzioni/Procedure
int inserisciConsegne(Consegna[], int);
int verificaDisp(int);

//void impostaDisp(int[], int, int)
int dispSett[] = {0,0,0,0,0,0,0};

int main(){
	Consegna consegne[MAX];
	int n_consegne=0;
	int giorno=0;

	//MENU
	int chiudi=0;
	do{
		int scelta;
		printf("Scegli azione:\n");
		printf("\t 0 - ESCI \n");
		printf("\t 1 - Aggiorna disponibilit? settimanale \n");
		printf("\t 2 - Prenota una consegna \n");
		printf("\t 3 - ... \n");
		printf("\t 4 - ... \n");
		printf("\t 5 - ... \n");
		printf("\t 6 - ... \n");
		printf("\t 7 - ... \n");
		printf("\t 8 - ... \n");

		scanf("%d", &scelta);
		switch(scelta){
			default:
				printf("Scelta NON valida!");
				break;
			case 0:
				chiudi=1;
				break;
			case 1:
				do{
					printf("Giorno della settimana: (1-7)\n");
					scanf("%d", &giorno);
					if(giorno<1 || giorno>7){
						printf("Giorno NON valido!\n");
					}
				}while(giorno<1 || giorno>7);

				do{
					printf("Impiegati disponibili:\n");
					scanf("%d", &dispSett[giorno-1]);
					if(dispSett[giorno-1]<0){
						printf("Valore NON valido!\n");
					}
				}while(dispSett[giorno-1]<0);
				break;
			case 2:
				n_consegne = inserisciConsegne(consegne, n_consegne);
				break;
			case 3:
				printf("Non ancora implementato");
				break;
			case 4:
				printf("Non ancora implementato");
				break;
			case 5:
				printf("Non ancora implementato");
				break;
			case 6:
				printf("Non ancora implementato");
				break;
			case 7:
				printf("Non ancora implementato");
				break;
			case 8:
				printf("Non ancora implementato");
				break;
		}
	}while(chiudi==0);
	system("pause");
	return 0;
}

int inserisciConsegne(Consegna database[], int dim){
	char risp;
	do{
		int gg;
		printf("Inserire Indirizzo\n");
		scanf("%s", database[dim].indirizzo);
		printf("Inserire Data (AAAA/MM/GG)\n");
		scanf("%s", database[dim].data);
		printf("Giorno della settimana: (1-7)\n");
		scanf("%d", &gg);
		printf("Inserire Fascia Oraria \n\t0 - mattina \n\t1 - pomeriggio)");
		scanf("%d", &database[dim].fascia_oraria);

		//Se ? disponibile assegno un codice
		if(verificaDisp(gg)==1){
			database[dim].id=(dim*10+5);
			printf("Prenotazione effettuata, COD: %d\n", database[dim].id);
			dispSett[gg]--;
			dim++;
		}else{
			printf("Nessun operatore disponibile per questa data!\n");
		}

		printf("Inserire altre Consegne? (s/n)");
		scanf("%s", &risp);
	}while(risp=='s');
	return dim;
}

int verificaDisp(int giorno_settimana){
	int disp=0;
	if(dispSett[giorno_settimana]>0) disp=1;
	return disp;
}

/*
void impostaDisp(int settimana[], int giorno, int impiegati){
	settimana[giorno]=impiegati;
}
*/
