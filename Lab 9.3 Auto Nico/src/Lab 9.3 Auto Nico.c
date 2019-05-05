/*
 ============================================================================
 Name        : 679594__04_07_2018.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"
#define M_AUTO 20

int main(void) {
	puts("PARCHEGGIO AUTO"); /* prints ciao */
	int scelta = 0;
	int size = 0;
	int orario_uscita=-1; //orario uscita
	autovettura at[M_AUTO] = { };

	do {
		puts("1. Acquisisci da file");
		puts("2. Aggiorna e calcolo costo parcheggio");
		puts("3. Uscita automobile");
		puts("4. Ordinamento");
		puts("0. USCITA\n\n");

		printf("Inserisci una scelta: ");
		scanf("%d", &scelta);

		switch (scelta) {
		case 1:size = getAuto(at);
			break;
		case 2:
			if(size>0)
			{
				orario_uscita = getOrario();
				calcoloCosto(at,size,orario_uscita);
				puts("\n\n-COLLEZIONE AGGIORNATA-\n");
				printArrayOrario(at,size);
			}
			else
				puts("\n\n--Devi prima acquisire il file--\n\n");
			break;
		case 3:
			if(size>0)
			{
				if(orario_uscita!=-1)
				{
					int id,r=0;
					puts("\n\n-AUTO PARCHEGGIATE:-");
					printArrayOrario(at,size);
					do
					{
						printf("Inserisci ID dell'auto che devo rimuovere: ");
						scanf("%d",&id);
						r=deleteAuto(id,at,size);
					}while(r==0);
				}
				else
					puts("\n\n--Devi prima inserire un orario di uscita (punto 2)--\n\n");
			}else
				puts("\n\n--Devi prima acquisire il file--\n\n");
			break;
		case 4:
			if(size>0)
			{
				if(orario_uscita!=-1)
				{
					ordinaAuto(at,size);
				}
				else
					puts("\n\n--Devi prima inserire un orario di uscita (punto 2)--\n\n");
			}else
				puts("\n\n--Devi prima acquisire il file--\n\n");
			break;
		case 0:puts("\n\n--USCITA--\n\n");
			break;
		default:puts("\n\n--INSERISCI UNA SCELTA VALIDA--\n\n");
			break;
		}

	} while (scelta != 0);

	system("pause");
	return EXIT_SUCCESS;

}
