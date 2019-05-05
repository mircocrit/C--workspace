#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef HEADER_H_
#define HEADER_H_

#define MAX_CHAR 12

typedef struct{
	int id;
	char nome[MAX_CHAR];
}squadra;

typedef struct{
	int squadra1;
	int squadra2;
	int ris1;
	int ris2;
}partita;

typedef struct{
	int posizione;
	char squadra[MAX_CHAR];
	int punti;
	int vinte;
	int pareggiate;
	int perse;
	int gol_fatti;
	int gol_subiti;
}classifica;

int leggi_partite(partita[]);
void visual_partite(partita[],int dim);
int creaz_array_squadre(partita[],int,squadra[]);
int rimozione_duplicati(squadra[],int);
void copy(squadra*,squadra);
void crea_classifica(squadra[],int,classifica[]);
void calcola_classifica(squadra[],int,partita[],int,classifica[]);
void assegna_punti(classifica[],int,char[],int,int,int);

void insertion_sort(classifica[],int);
void copy_field(classifica *,classifica);
void scrivi_classifica(classifica[],int);
void visual_classifica(classifica[],int);

#endif /* HEADER_H_ */
