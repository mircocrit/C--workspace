#ifndef VACANZE_H_
#define VACANZE_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 20

typedef struct{
	int cod_app;
	int num_stanze;
	int mese[4];//0=libero, 1= occupato
	int tipo; //0=mono, 1=bilo,2=trilo
	int cont;
	}appartamento;

 typedef struct{
	int cod_rich;
	int stanze_rich;
	int mese;
	int accettaz; //0=rifiutata , 1=accettata
	}richiesta;

int leggi_app(appartamento[]);
int leggi_rich(richiesta[]);
void stampa_app(appartamento[],int);
void stampa_rich(richiesta[],int);
void evasione(richiesta[],appartamento[],int,int);
void ricerca_max(appartamento[],int);

#endif /* VACANZE_H_ */
