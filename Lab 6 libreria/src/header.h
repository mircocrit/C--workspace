#ifndef header_h
#define header_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_CHAR 20
#define MAX_LIB 20
#define MAX_STUD 20
#define PATH1 "D:\\eclipse-workspace\\Lab 6 libreria\\libri.txt"
#define PATH2 "D:\\eclipse-workspace\\Lab 6 libreria\\prestiti.txt"

typedef struct{
	int giorno;
	int mese;
	int anno;
}data;

typedef struct{
    int codice;
    char autore[MAX_CHAR];
    char titolo[MAX_CHAR];
    int anno;
}libro;

typedef struct{
    int matricola;
    data data_prest;
    data data_restit;
}studente;

int lettura_libri(libro[]);
void visual_libri(libro[],int);
libro inserimento_libro(int);
void scrittura_libro(libro);

studente inserimento_prestito();
void scrittura_prestito(studente);
int lettura_prestiti(studente[]);
void visual_prestiti(studente[],int);

int elimina_campo(studente[],int,int);
void copy_field(studente*, studente);
void scrittura_campi(studente[],int);
int conteggio(studente[],int,data);
int data_to_int(data);

#endif
