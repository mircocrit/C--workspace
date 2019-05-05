#ifndef HEADER_H_
#define HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30
#define NUM_SQUADRE 32

typedef struct{
	char squadraA[MAX];
	char squadraB[MAX];
	int anno;
	int mese;
	int giorno;
	int risA;
	int risB;
	int id;
}partita;

typedef struct{
	char nome[MAX];
	int punteggio;
	int partite_giocate;
}squadra;

int leggi_file(partita[]);
partita acquisiz_partita(int);
void visual_squadre(partita[],int);
void scrivi_file(partita);

int creaz_array_squadre(partita[],int,squadra[]);
int rimozione_duplicati(squadra[],int);
void calcola_punteggio(squadra[],int,partita[],int);
void assegna_punti(squadra s[],int dim,char[],int);
void insertion_sort(squadra[],int);
void copy_field(squadra[],squadra);
void scrivi_file_classifica(squadra[],int);
void visual_classifica(squadra[],int);

#endif /* HEADER_H_ */
