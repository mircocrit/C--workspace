#ifndef PACCHI_H_
#define PACCHI_H_

#include<stdlib.h>
#include <stdio.h>
#include <string.h>

int dispsett[]={0,0,0,0,0,0,0};
typedef enum {mattina,pomeriggio}fasciaoraria;
typedef enum {lun,mar,mer,gio,ven,sab,dom}settimana;

#define DIM_STR 100
#define MAX 100
#define DIM_DATE 11

typedef struct{
	int id;
	char indirizzo[DIM_STR];
	char data[DIM_DATE];
	float prezzo;
	fasciaoraria fasciaoraria; //gg_mm_aaaa,/0
	}consegna;

void prenotazione_cons(consegna[],int);
int verificadisp(int);
void impostadisp(int[],int,int);

#endif /* PACCHI_H_ */
