#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

#define PATH1 "D:\\C-workspace\\Prog 5_Buon Appetito\\ristoranti.txt"
#define PATH2 "D:\\C-workspace\\Prog 5_Buon Appetito\\prenotazioni.txt"

typedef struct{
	int cod_sede;
	char citta_sede[MAX];
	int posti_disp;
	int posti_occup;
}ristorante;

typedef struct{
	int cod_pren;
	int cod_sede;
	int posti_rich;
	int accettaz;
}prenotazione;

int leggi_rist(ristorante r[]){
	FILE *fp;
	int i=0;
	fp=fopen(PATH1,"r");
	if(fp==NULL)	printf("Errore\n");
	else
		while(!feof(fp)){
			fscanf(fp,"%d %s %d %d\n",&r[i].cod_sede,r[i].citta_sede,&r[i].posti_disp,&r[i].posti_occup);
			i++;
		}
	return i;
}

int leggi_pren(prenotazione p[]){
	FILE *fp;
	int i=0;
	fp=fopen(PATH2,"r");
	if(fp==NULL)	printf("Errore\n");
	else
		while(!feof(fp)){
			fscanf(fp,"%d %d %d %d\n",&p[i].cod_sede,&p[i].cod_pren,&p[i].posti_rich,&p[i].accettaz);
			i++;
		}
	return i;
}

void stampa_rist(ristorante r[],int dim){
	printf("%-10s%-15s%-10s%-10s\n","Cod sede","Citta Sede","Posti disp","Posti occup");
	for(int i=0;i<dim;i++)
		printf("%-10d%-15s%-10d%-10d\n",r[i].cod_sede,r[i].citta_sede,r[i].posti_disp,r[i].posti_occup);

}


void stampa_pren(prenotazione p[],int dim){
	printf("%-10s%-10s%-11s%-11s\n","Cod sede","Cod pren","Posti rich","Accettaz");
	for(int i=0;i<dim;i++)
		printf("%-10d%-10d%-11d%-11d\n",p[i].cod_sede,p[i].cod_pren,p[i].posti_rich,p[i].accettaz);

}
void stampa_pren_r(prenotazione p){
	printf("%-10d%-10d%-11d%-11d\n",p.cod_sede,p.cod_pren,p.posti_rich,p.accettaz);
}

void evasione(ristorante r[], prenotazione p[],int n,int m){
	int i,j,flag=0;

	for(i=0;i<m;i++){
		flag=0;
		for(j=0;j<n && flag==0;j++)
			if(p[i].cod_sede==r[j].cod_sede){
				flag=1;
	 			if(p[i].posti_rich<r[j].posti_disp){
	 				r[j].posti_disp-=p[i].posti_rich;
					r[j].posti_occup+=p[i].posti_rich;
					printf("Prenotazione %d effettuata\n",p[i].cod_pren);
					p[i].accettaz=1;
				}else
					printf("Prenotazione %d fallita, posti insufficienti\n",p[i].cod_pren);
			}
		}
}

void ricerca_max(prenotazione p[],int n){
	int max=0,i;

	for(i=0;i<n;i++)
		if(p[i].posti_rich>max)
			max=p[i].posti_rich;

	for(i=0;i<n;i++)
		if(p[i].posti_rich==max){
			printf("%d	",p[i].cod_sede);
		}
}


void bubble_sort(prenotazione p[],int dim){
	int i,j;
	void swap(prenotazione*,prenotazione*);

	for(i=0;i<dim-1;i++){
		for(j=0;j<dim-i-1;j++){
			if(p[j].posti_rich>p[j+1].posti_rich){
				swap(&p[j],&p[j+1]);
					}
			}
	}
}

void swap(prenotazione* p1,prenotazione* p2){
	void swap_int(int*,int*);

	swap_int(&p2->cod_sede,&p1->cod_sede);
	swap_int(&p2->cod_pren,&p1->cod_pren);
	swap_int(&p2->posti_rich,&p1->posti_rich);
	swap_int(&p2->accettaz,&p1->accettaz);
}

void swap_int(int *val1,int *val2){
	int temp;

	temp=*val1;
	*val1=*val2;
	*val2=temp;
}
