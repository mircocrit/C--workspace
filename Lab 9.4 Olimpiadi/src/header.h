#ifndef HEADER_H_
#define HEADER_H_

#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 50


typedef struct{
	int gg;
	char sport[MAX_CHAR];
	int finale;
}disciplina;

int acquisiz_lista(disciplina[]);
void visual_classifica(disciplina[],int);
void ordina_lista(disciplina[],int);
void copy_field(disciplina*,disciplina);
void consiglia_gara(disciplina[],int);

#endif /* HEADER_H_ */
