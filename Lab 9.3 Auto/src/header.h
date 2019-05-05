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
/**
 * massimo caratteri ammissibili.
 */
#define MAX_CHAR 20
/**
 * massimo automobili ammissibili.
 */
#define MAX_AUTO 20

#include <stdio.h>
#include <stdlib.h>
/**
 * struttura di tipo orario.
 */
typedef struct{
	int ora;
	int minuti;
}orario;

/**
 * struttura di tipo automobile.
 */
typedef struct{
	char marca[MAX_CHAR];///marca autovettura
	char modello[MAX_CHAR];///modello auto.
	int cilidrata;///cilindrata auto.
	char colore[MAX_CHAR];///colore auto.
	orario orario_ingr;/// orario di ingresso.
	int posteggio;///postazione che occupa nel parcheggio.
	float costo;///tarriffa totale calcolata all uscita.
}automobile;

/**
 * procedura che apre un file dal file system per essere letto.
 * @param[in] struttura che ospiterà i dati da file.
 * @return dimensione dell'array contenente i dati
 */
int leggi_auto(automobile[]);
/**
 * procedura che rimuove il simbolo '#' da una stringa data,sostituendolo con ' '.
 * @param[in] stringa inserita.
 * @return stringa priva di #.
 */
void rimuovi_cancell(char[]);
/**
 * procedura che stampa a schermo le caratteristiche delle autovetture.
 * param[in] struttura con i dati delle vetture.
 * param[in] dimensione struttura.
 */
void visual_auto(automobile[],int);
/**
 * procedura permette l'acquisizione di un orario.
 */

orario get_orario(void);
/**
 * funzione che controlla se l'ora inserita e' accettabile..
 * param[in] ora da verificare.
 * @return 1 se il valore e' accettato, 0 se non lo e'
 */

int controlla_ora(orario);
/**
 * funzione che calcola la tariffa oraria al momento dell' ora inserita.
 * param[in] struttura con i dati delle vetture.
 * param[in] dimensione struttura.
 * param[in] ora di uscita.

 */
void calcola_costo(automobile[],int,orario);
/**
 * funzione che visualizza la tariffa oraria di un'automobile dato il suo posteggio
 * param[in] struttura con i dati delle vetture.
 * param[in] dimensione struttura.
 * param[in] posteggio automobile.
 */
void visual_prezzo(automobile[],int,int);
/**
 * procedura che mette in uscita dal parcheggio un auto.
 * param[in] struttura con i dati delle vetture.
 * param[in] dimensione struttura.
 * param[in] posteggio automobile in uscita
 */
int rimuovi_auto(automobile[],int,int);
/**
 * funzione che rimuove tutti i duplicati delle automobili.
 * param[in] struttura con i dati delle vetture.
 * param[in] dimensione struttura.
 * @return dimensione nuova struttura
 */
int rimozione_duplicati(automobile[],int);
/**
 * procedura che copia tutti i campi da una stuttura A ad una B.
 * param[in] struttura su cui copiare.
 * param[in] struttura da cui copiare.
 */
void copy_field(automobile*,automobile);
/**
 * procedura che apre un file dal file system per essere aggiornato.
 * param[in] struttura con i dati delle vetture.
 * param[in] dimensione struttura.
 */
void scrivi_auto(automobile[],int);
/**
 * procedura che ordina le automobili in base ad un criterio prestabilito.
 * param[in] struttura con i dati delle vetture.
 * param[in] dimensione struttura.
*/
void insertion_sort(automobile[],int);
/**
 * procedura che ordina le automobili in base ad un criterio prestabilito.
 * param[in] struttura con i dati delle vetture.
 * param[in] dimensione struttura.
 */
void bubble_sort(automobile[],int);
/**
 * procedura che ordina le automobili in base ad un criterio prestabilito.
 * param[in] struttura con i dati delle vetture.
 * param[in] dimensione struttura.
 */
void selection_sort(automobile[],int);
/**
 *  procedura che scambia tutti i campi di una stuttura A con quelli di una struttura B
 *  param[in] struttura da scambiare.
 *  param[in] struttura con cui scambiare l'altra.
 */
void swap(automobile*,automobile*);

/**
 * procedura che apre un file dal file system per essere aggiornato.
 * param[in] dato strutturato autovettura.
 */
void scrivi_record_auto(automobile);

#endif/* HEADER_H_ */
