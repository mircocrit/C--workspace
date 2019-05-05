#ifndef EMITTENTE_H_
#define EMITTENTE_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 20

typedef struct{
	char cod_spot[MAX];
	char titolo[MAX];
	int durata;
	float costo;
	int orario;
}pubblicita;

int lettura_file(pubblicita[]);
void stampa(pubblicita[],int);
void massimo(pubblicita[],int,int);
void bubble_sort(pubblicita[],int,int);
void swap(pubblicita*,pubblicita*);
void swap_float(float*,float*);
void swap_stringhe(char[],char[]);
pubblicita inserimento();

#endif /* EMITTENTE_H_ */
