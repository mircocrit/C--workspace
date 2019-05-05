#ifndef header_h
#define header_h

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 40
#define MAX_S 40

void acqusizione_elenco(char[40][40],int);
void visualizzazione_elenco(char[40][40],int);
int tokenizzatore(char*,char*[40],int i);
void contaoccorr(char*[40],int[40],int);
void max_3_occorr(char*[40],int[40],int,int,int,int,char[40],char[40],char[40]);
void scrivi_file(FILE*,char[40],int);
void visual_nomi(char*[40],int,int);

#endif /* header_h */
