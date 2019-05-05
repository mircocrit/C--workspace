#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef HEADER_H_
#define HEADER_H_
#define MAX_CHAR 24
#define MAX_SEGUACI 500;
#define MAX_FOLL 300

typedef struct{
	char nickname[MAX_CHAR];
	char follower[MAX_CHAR];
	int data_inizio;
}nome;

typedef struct{
	char nickname[MAX_CHAR];
}dati;

/**
 * la funzine legge da file i dati restituendone la dimensoine
 *
 */
int leggi_nomi(nome[]);
//void elimina_cancell(char s[]);
/**
 * la funzine viusalizza i dati a schermo
 *
 */
void visual_nomi(nome[],int);
void scrivi_file(char[],char[],int);


int calcola_follower(nome[],int,char[]);
int calcola_following(nome[],int,char[]);

void ricerca_max_following(nome[],int);
void ricerca_max_follower(nome[],int);

void select_follower(nome[],int,int,int,char[]);
void insertion_sort(char[20][MAX_CHAR],int);
void scrivi_record(char[]);

//void bubble_sort(char[20][MAX_CHAR],int);
/*
int elabora_nomi(nome[],int,dati[],int);
int rimuovi_duplicati(dati[],int);
void copy_field(dati*,dati*);

*/

#endif /* HEADER_H_ */
