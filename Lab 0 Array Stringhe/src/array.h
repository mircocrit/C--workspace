#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DIM 100
#define LENGHT 100

int leggi_stringhe(char[][LENGHT]);
void stampa(char[][LENGHT],int);
void scambia(char[][LENGHT],int,int);
int conta_parole(char[][LENGHT],int,char[]);
void rimpiazza(char[][LENGHT],int,char[],char[]);
#endif /* ARRAY_H_ */
