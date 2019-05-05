#ifndef APPETITO_H_
#define APPETITO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

typedef struct{
	int cod_sede;
	char citta_sede[MAX];
	int posti_disp;
	int posti_occup;
	}ristorante;

typedef struct{
	int cod_pren;
	int cod_sede;
	int posti_rich;
	int accettaz;
	}prenotazione;

int leggi_rist(ristorante[]);
int leggi_pren(prenotazione[]);
void stampa_pren(prenotazione[],int);
void stampa_rist(ristorante[],int);
void evasione(ristorante[],prenotazione[],int,int);
void ricerca_max(prenotazione[],int);
void bubble_sort(prenotazione[],int);
void swap(prenotazione*,prenotazione*);
void swap_int(int*,int *);
void stampa_pren_r(prenotazione);


#endif /* APPETITO_H_ */
