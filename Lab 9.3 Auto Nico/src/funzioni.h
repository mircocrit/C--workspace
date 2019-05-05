/*
 * funzioni.h
 *
 *  Created on: 04 lug 2018
 *      Author: studente
 */

#ifndef FUNZIONI_H_
#define FUNZIONI_H_
#define M_MARCA 10
#define M_MODELLO 15
#define M_COLORE 10
#define M_ORA 5

typedef struct{
	char marca[M_MARCA];
	char modello[M_MODELLO];
	unsigned int cilindrata;
	char colore[M_COLORE];
    char ora[M_ORA];
	unsigned int id_posto;
	float costo;
}autovettura;

/**
La funzione getAuto acquisisce dal file "auto.txt" le autovetture salvate al suo interno
@param[in] autovettura[] è l'array di record dove andremo a salvare la auto acquisiste; esso viene passato dal main
@return ritorna un intero che corrisponde alla dimensione effettiva dell'array di record calcolata acquisendo il file
**/
int getAuto(autovettura []);

/**
 *la procedure printArray stampa a console l'array di autovetture passato come parametro
 @param[in] autovettura[] è l'array di autovetture da stampare
 @param[in] int size è la dimensione dell'array di record
 **/
void printArray(autovettura [],int);

/**la procedure printArray stampa a console l'array di autovetture passato come parametro
 *  che sono presenti fino all'orario di uscita
@param[in] autovettura[] è l'array di autovetture da stampare
@param[in] int size è la dimensione dell'array di record
**/
void printArrayOrario(autovettura [], int);

/**la procedure calcoloCosto calcola il costo in base all'orario di uscita passato come parametro e
 *  aggiorna l'array di record
 *  che sono presenti fino all'orario di uscita
@param[in] autovettura[] è l'array di autovetture da aggiornre
@param[in] int size è la dimensione dell'array di record
@param[in] int costo è l'orario che passiamo in input
**/
void calcoloCosto(autovettura [],int ,int);
int deleteAuto(int , autovettura [], int);
void ordinaAuto(autovettura [], int );
void saveAutoOrdinate(autovettura [], int);
int getOrario(void);

#endif /* FUNZIONI_H_ */
