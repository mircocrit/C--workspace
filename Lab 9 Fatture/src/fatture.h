#ifndef FATTURE_H_
#define FATTURE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 25

typedef struct{
	int anno;
	int mese;
	int giorno;
}data;


typedef struct{
	int codice;
	float saldo;
	char rag_soc[MAX_CHAR];
	data date;
}fattura;

int leggi_fatture(fattura[]);
void visual_fatture(fattura[],int);
void copy_field(fattura*,fattura);
void insertion_sort(fattura[],int);
void scrivi_fatture(fattura[],int);
void input_data(data*);
int ricerca_data(fattura[],int,fattura[]);
void ricerca_max(fattura[],int);


#endif /* FATTURE_H_ */
