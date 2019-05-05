/**
 *@file header.h
 *@version 0.1
 *@date 24/07/2018
 *@authors matr 683254.
 *@copyright //
 *@bug no bug
 *@warning no warnings
 */

#ifndef HEADER_H_
#define HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#define MAX_CHAR 24
#define NUM_AZIENDE 5

typedef struct{
	char id[MAX_CHAR];
	int num_azioni[NUM_AZIENDE];
}cliente;

typedef struct{
	char id_cliente[MAX_CHAR];
	int id_azienda;		//0-5
	char azione;		//A,V,G
	int n_azioni;
	char percorso[MAX_CHAR];//FILE_MOD
}action;

/**
 * procedura che apre un file dal file system per essere letto.
 * @param[in] struttura che ospiterà i dati da file.
 * @return dimensione dell'array contenente i dati
 */

int leggi_clienti(cliente[]);
void visual_clienti(cliente[],int);
int leggi_azioni(action[]);
void visual_azioni(action[],int);
void elabora_azione(action,cliente[],int);
void scrivi_clienti(cliente);
int rimuovi_duplicati(cliente[],int);
int elimina_campo(cliente[],int,char[]);
void bubble_sort(cliente[],int);
void swap(cliente*,cliente*);
void insertion_sort(cliente[],int);
void copy_field(cliente*,cliente);
void selection_sort(cliente[],int);

#endif /* HEADER_H_ */
