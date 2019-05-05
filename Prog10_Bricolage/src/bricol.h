#ifndef BRICOL_H_
#define BRICOL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

typedef struct{
	int cod_neg;
	int cod_mater;
	int n_pezzi;
	char descr_mat[MAX];
}prenotaz;

typedef struct{
	int cod_mat;
	int n_pezzi;
	char descriz[10];
	float costo_mat;
}deposito;

int leggi_prenotaz(prenotaz p[]);
int leggi_deposito(deposito d[]);
void stampa_dep(deposito[],int);
void stampa_pren(prenotaz[],int);
void evasione(deposito[],prenotaz[],int,int);
int calcola_tot(prenotaz[],int,deposito d[],int,int);
void ordina(deposito[],int);
void swap(deposito *,deposito*);
deposito inserim_depos();
prenotaz inserim_pren();

#endif /* BRICOL_H_ */
