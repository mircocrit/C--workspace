#ifndef HEADER_H_
#define HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int n;
	int p;
}array2;

int inserimento();
void print_array(int[],int);
int ricerca_flag(int[],int,int);
int conteggio(int[],int,int);
float media(int[],int);
int minimo(int[],int);
void prenotazoine(array2[],array2[],int,int);
void bubble_sort(int[],int);
void swap(int*,int*);
int ricerca_binaria(int[],int,int);

#endif /* HEADER_H_ */
