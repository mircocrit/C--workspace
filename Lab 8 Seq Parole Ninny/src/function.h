/*
 * function.h
 *
 *  Created on: 09 giu 2018
 *      Author: utente
 */

#ifndef FUNCTION_H_
#define FUNCTION_H_

#define MAX 20

typedef struct
{
	char w[MAX];
}word;


void inserimento(void);
void scrivi_file(char[],int);
int conta_record();
void leggi_file();
void ordina(word[],int);
void scrivi_file_ordinato(word[],int);
void palindroma(word[],int);
void scrivi_file_palindromi(word[],int);



#endif /* FUNCTION_H_ */
