#ifndef TRASL_H_
#define TRASL_H_

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 20

typedef enum{alfa,beta,gamm,delta}squa;

typedef struct{
	char cod_trasl[MAX];
	char data[11];
	char indir_part[MAX];
	char indir_arr[MAX];
	int cod_squadra;
	char automezzo[MAX];
	int ore_lav;
	float costo_tot;
}trasloco;

trasloco inserimento();
int lettura_file(trasloco[]);
void stampa(trasloco[],int);
void ricerca_data(trasloco[],int,char[]);
void conta_traslochi(trasloco[],int, int[4]);
void ricerca_max(int[]);

#endif /* TRASL_H_ */
