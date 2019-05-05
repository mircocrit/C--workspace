#ifndef COMMERCIO_H_
#define COMMERCIO_H_

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define DATE 11
#define CODE 5
#define TESTO 50

typedef struct{
	char cod_sito[CODE];
	char data_ric[DATE];
	char cod_art[CODE];
	char cod_clie[CODE];
	char descr_art[TESTO];
	int n_pezzi_rich;
	float costo_pezzo;
	float costo_tot;
}richiesta;

int lettura_file(richiesta[]);
void stampa_richieste(richiesta[],int);
void stampa(richiesta);
void bubble_sort(richiesta[],int);
void swap(richiesta*,richiesta*);
void swap_float(float*,float*);
void swap_stringhe(char[],char[]);
void ricerca_max(richiesta[],int,char[]);
richiesta inserimento();

#endif /* COMMERCIO_H_ */
