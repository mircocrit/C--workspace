#ifndef header_h
#define header_h

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#include <stdio.h>

void acquisizone(int[MAX],int n);
void mem_file(int[MAX],int n,FILE *fp,int *k);
void inserction_sort(int vett[MAX],int n);
void ricerca_magg(int vett[MAX],int,int,FILE *fp,int *k);
void leggi_file(FILE *fp);

#endif /* header_h */
