#ifndef CALZATUR_H_
#define CALZATUR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

typedef struct{
	char cod_calz[MAX];
	float costo_calz;
	int num_pezzi;
}calzatura;

typedef struct{
	char cod_clie[MAX];
	char cod_zona[MAX];
	char cod_calz[MAX];
	int pezzi_rich;
	char data_ord[MAX];
}ordine;

int leggi_ordine(ordine[]);
int leggi_calz(calzatura[]);
void stampa_ord(ordine[],int);
void stampa_calz(calzatura[],int);
void calcola_max(ordine[],int,char[]);
int calcola_totale(ordine[],int,char[]);
void stampa_record(ordine);
void ordina(ordine[],int);
void swap(ordine*,ordine*);
void evasione(ordine[],calzatura[],int,int);
ordine inserim_ordini();
calzatura inserim_calz();

#endif /* CALZATUR_H_ */
