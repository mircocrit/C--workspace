#include<stdlib.h>
#include <stdio.h>
#include <string.h>

#define DIM_STR 100
#define MAX 100
#define DIM_DATE 11

int dispsett[]={0,0,0,0,0,0,0};
typedef enum {mattina,pomeriggio}fasciaoraria;
typedef enum {lun,mar,mer,gio,ven,sab,dom}settimana;

typedef struct{
	int id;
	char indirizzo[DIM_STR];
	char data[DIM_DATE];
	float prezzo;
	fasciaoraria fasciaoraria; //gg_mm_aaaa,/0
	}consegna;

void prenotazione_cons(consegna cons[], int n){
	char risp;
	int gg;
	do{
		printf("	Inserire indirizzo\n");
		scanf("%s",cons[n].indirizzo);
		printf("Inserire data aaaa/mm/gg\n");
		scanf("%s",cons[n].data);
		printf("Inserire il giorno della settimana in cui prenotare la consegna (1-7):\n");
		scanf("%d",&gg);
		printf("Inserire la fascia oraria\n (1=mattina) (2=pomeriggio)");
		scanf("%d",&cons[n].fasciaoraria);
		if(verificadisp(gg)==1){
			cons[n].id=(n*10+5);
			printf("Prenotazione effettuata con codice %d\n",cons[n].id);
			dispsett[gg]--;
			n++;
		}else		printf("Nessuna disponibilita per questa data\n");
		printf("Inserire altre consegne? s/n");
		scanf("%s",&risp);
	}while(risp!='s');

}

int verificadisp(int giorno){
		int disp=0;
		if(dispsett[giorno]>0) disp=1;
		return disp;
	}

void impostadisp(int sett[],int giorno,int impiegati){
		sett[giorno]=impiegati;
	}

