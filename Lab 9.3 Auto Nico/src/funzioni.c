/*
 * funzioni.c
 *
 *  Created on: 04 lug 2018
 *      Author: studente
 */
#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"
#define PATH "C:\\Users\\studente\\eclipse-workspace\\679594__04_07_2018\\Debug\\auto.txt"
#define PATH_O "C:\\Users\\studente\\eclipse-workspace\\679594__04_07_2018\\Debug\\auto_ordinate.txt"


int getAuto(autovettura at[]) {
	FILE *file;
	int c = 0;

	if ((file = fopen(PATH, "r+")) == NULL)
		puts("file non aperto");
	else {
		while (!feof(file)) {
			fscanf(file, "%s %s %d %s %s %d \n", at[c].marca, at[c].modello,
					&at[c].cilindrata, at[c].colore, at[c].ora,
					&at[c].id_posto);
			c++;
		}
		puts("\n\n File acquisito\n\n");
		fclose(file);
	}
	return c;
}

void printArray(autovettura at[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		if (at[i].id_posto != 0)
			printf("- ID:%d %s %s %d %s h: %s %.2f Euro \n",at[i].id_posto, at[i].marca,
					at[i].modello, at[i].cilindrata, at[i].colore,
					at[i].ora, at[i].costo);
	}

	puts("\n\n");

}

void printArrayOrario(autovettura at[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		if (at[i].id_posto != 0 && at[i].costo>0)
			printf("- ID:%d %s %s %d %s h: %s %.2f Euro \n",at[i].id_posto, at[i].marca,
					at[i].modello, at[i].cilindrata, at[i].colore,
					at[i].ora, at[i].costo);
	}

	puts("\n\n");

}

void calcoloCosto(autovettura at[], int size, int orario_uscita) {

	int i;

	for (i = 0; i < size; i++) {
		int key_ora = atoi(at[i].ora);
		int ore = orario_uscita - key_ora;
		if(ore>=0) at[i].costo = 1 * ore;
	}
}

int deleteAuto(int id_auto, autovettura at[], int size) {
	int i, r = 0;
	float costo;

	for (i = 0; i < size || r == 0; i++) {

		if (at[i].id_posto == id_auto)
		{
			at[i].id_posto = 0;
			costo = at[i].costo;
			r = 1;
		}

	}
	if(r==0)	puts("\n\n--NESSUNA AUTO TROVATA CON QUESTO ID, INSERISCI UN ID DIVERSO");
	else	{puts("\n\n--AUTO RIMOSSA DAL PARCHEGGIO--"); printf("Costo totale: %.2f Euro\n\n",costo);}
	return r;
}

void ordinaAuto(autovettura at[], int size)
{
	int i,j=0;
	int size_r,c=0;
	autovettura at_r[size];
	autovettura key;


	for(i=0;i<size;i++)
	{
		if(at[i].costo>6)
		{
			at_r[c]=at[i];
			c++;
		}
	}
	size_r = c;

	for(i=1;i<size_r;i++)
	{
		key=at_r[i];
		j = i-1;

		if(j>=0 && at_r[j].costo>key.costo)
		{
			at_r[j+1] = at_r[j];
			j--;
		}

		at_r[j+1] = key;
	}

	//int min = 0;
	/*for(i=0;i<size-1;i++)
	{
		min=i;
		for(j=i+1;j<size;j++)
		{
			if(at_r[i]>at_r[min])
			{
				min=i;
			}
			at_r
		}
	}*/

	if(size_r>0)
	{
		puts("\n\n--AUTO ORDINATE PARCHEGGIATE DA PIU' DI 6 ORE--\n\n");
		printArray(at_r,size_r);
		saveAutoOrdinate(at_r,size_r);
	}else 	puts("\n\n--NON CI SONO AUTO PARCHEGGIATE DA PIU' DI 6 ORE--\n\n");


}

void saveAutoOrdinate(autovettura at[], int size)
{
	FILE *file;
	int i = 0;

	if ((file = fopen(PATH_O, "w")) == NULL)
		puts("file non aperto");
	else {

		for(i=0;i<size;i++)
		{
			fprintf(file,"%s %s %d %s %s %d %.2f € \n",at[i].marca, at[i].modello,
					at[i].cilindrata, at[i].colore,at[i].ora,
					at[i].id_posto,at[i].costo);

		}

		puts("\n\n File salvato\n\n");
		fclose(file);
	}
}

int getOrario()
{
	int ora,r=0;
	char ora_input[M_ORA];
	do
	{
		printf("-> Inserisci orario uscita (in formato HH:00 oppure HH): ");
		scanf("%s",ora_input);
		ora= atoi(ora_input);
		if(ora<=23 && ora>=0) r = 1;
		else puts("Inserisci un orario che va dalle 00:00 alle 23:00");
	}while(r==0);
	return ora;
}
