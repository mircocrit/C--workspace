#ifndef SUPERM_H_
#define SUPERM_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
#define STR 27

typedef struct{
	char cogn_resp[STR];
	char nome_resp[STR];
	char via[STR];
	char citta[STR];
	int num_dip;
	float fatt;
}supermerc;

int lettura_file(supermerc[]);
void stampa(supermerc[],int);
void stampa_record(supermerc);
void ricerca_resp(supermerc[],int,char[],char[]);
void ricerca_citta(supermerc[],int,char[]);
void ricerca_max(supermerc[],int);
supermerc inserimento();

#endif /* SUPERM_H_ */
