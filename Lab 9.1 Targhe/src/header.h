
#ifndef HEADER_H_
#define HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 25
#define MAX_AUTO 20

typedef struct{
	int anno;
	int mese;
	int giorno;
}data;

typedef struct{
	int cilindrata;
	char modello[MAX_CHAR];
	char targa[MAX_CHAR];
	data date;
}autovettura;

int leggi_auto(autovettura[]);
void visual_auto(autovettura[],int);
void copy_field(autovettura*,autovettura);
void insertion_sort(autovettura[],int);
void selection_sort(autovettura[],int);
void swap(autovettura*,autovettura*);
void scrivi_auto(autovettura[],int);
void input_data(data*);
int ricerca_data(autovettura[],int,autovettura[]);
void ricerca_max(autovettura[],int);

#endif /* HEADER_H_ */
