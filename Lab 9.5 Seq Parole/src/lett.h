#ifndef LETT_H_
#define LETT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 2000

typedef struct{
	char parola[MAX_CHAR];
}stringa;

stringa leggi_parole(stringa);
void visual_testo(stringa);
int tokenizza(stringa[],stringa);
void visual_parole(stringa[],int);
void conta_occorr(stringa[],int,int[]);

#endif /* LETT_H_ */
