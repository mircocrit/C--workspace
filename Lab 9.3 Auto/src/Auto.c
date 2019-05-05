/**
 *@file header.h
 *@authors matr 683254.
 *@date 24 lug 2018.
 */
/**

/*Fuznoinalita di un parcheggio per auto offerte da menu utente
 1) Acquisiizone di una collezione di dati di autovetture,ciascuna descritta da:
  Marca, Modello,Cilindrata,Colore,Orario di ingresso, IdentificativoPosto			 da file
  -la collezione si riferisce ad autovetture gia parcheggiate
 2) Aggiornamento della collezione con calcolo del costo del parcheggio in base all'orario fornito in input
 -La tariffa e' di 1 euro ogni ora
 -L'orario di uscita deve essere fornito in input in formato ora (11:00,12:00)
 -La collezione aggiornata dovra essere visualizzata a console
 3) Messa in uscita di un'autovettura fornita in input con visualizzazione del costo del parcheggio
 -L'uscita prevede la rimozone dell'auto dalla collezione
 4) Selezine delle autovetture che stanno nel parcheggio da piu di 6 ore e ordinamento di esse sulla base del costo
 -Le auto ordinate dovranno essere memorizzate su un file e visualizzate a console
 -Lo sudente puo scegliere autonomamente quale algoritmo di ordinamento usare.

 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

#define MAX_AUTO 20
#define PRICE 1

int main() {
	int scelta,flag=0,i=0;
	int num_auto=0,id=0;
	automobile a[MAX_AUTO];
	orario ora_uscita;
	num_auto=leggi_auto(a);
	visual_auto(a,num_auto);
	do{
		printf("Menu:\n");
		printf("0: Esci\n");
		printf("1: Acquisizione autovetture\n");
		printf("2: Calcolo costo parcheggio\n");
		printf("3: Uscita autovettura\n");
		printf("4: Selezione autovetture\n");
		printf("Scelta:	");
		scanf("%d",&scelta);
		switch(scelta){
			default:
				printf("Errore\n");
				break;
			case 0:
				flag=1;
				printf("Uscita\n");
				break;
			case 1:
				num_auto=leggi_auto(a);
				visual_auto(a,num_auto);
				break;
			case 2:
				if(num_auto==0)
					printf("Eseguire prima l'acquisizione\n");
				else{
					printf("Inserire orario di uscita:	");
					ora_uscita=get_orario();
					calcola_costo(a,num_auto,ora_uscita);
					visual_auto(a,num_auto);
				}
				break;
			case 3:
				if(num_auto==0)
					printf("Errore: costo non acquisito oppure veicoli non acquisiti\n");
				else{
					do{
						printf("Idenitificativo auto da mettere in uscita:	");
						scanf("%d",&id);
						for(i=0;i<num_auto;i++)
							if(a[i].posteggio==id)
								flag=1;
					}while(flag==0);
					flag=0;
					visual_prezzo(a,num_auto,id);
					num_auto=rimuovi_auto(a,num_auto,id);
					scrivi_auto(a,num_auto);
					printf("Tabella auto aggiornata\n\n");
					visual_auto(a,num_auto);
					}
				break;
			case 4:
				if(num_auto==0)
					printf("veicoli non acquisiti\n");
				else{
					selection_sort(a,num_auto);
					printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", "Marca", "Modello","Cilindr","Colore","Ora ingr", "Posteggio","Costo");
					for(i=0;i<num_auto;i++){
						if((ora_uscita.ora-a[i].orario_ingr.ora)>6)
							scrivi_record_auto(a[i]);
					}
				}
				break;
		}
	}while(scelta>0 && scelta<5 && flag==0);

	system("pause");
	return 0;
}
