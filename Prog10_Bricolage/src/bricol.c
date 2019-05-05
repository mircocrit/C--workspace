#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 20
#define PATH_PREN "D:\\C-workspace\\Prog10_Bricolage\\prenotaz.txt"
#define PATH_DEPOS "D:\\C-workspace\\Prog10_Bricolage\\depos.txt"

typedef struct{
	int cod_neg;
	int cod_mater;
	int n_pezzi;
	char descr_mat[MAX];
}prenotaz;

typedef struct{
	int cod_mat;
	int n_pezzi;
	char descriz[10];
	float costo_mat;
}deposito;

int leggi_prenotaz(prenotaz p[]){
	FILE *fp;
	int i=0;
	fp=fopen(PATH_PREN,"r");
	if(fp==NULL)	printf("Errore\n");
	else
		while(!feof(fp)){
			fscanf(fp,"%d %d %d %s",&p[i].cod_neg,&p[i].cod_mater,&p[i].n_pezzi,p[i].descr_mat);
			i++;
		}
	return i;
}

int leggi_deposito(deposito d[]){
	FILE *fp;
	int i=0;
	fp=fopen(PATH_DEPOS,"r");
	if(fp==NULL)	printf("Errore\n");
	else
		while(!feof(fp)){
			fscanf(fp,"%d %d %s %f",&d[i].cod_mat,&d[i].n_pezzi,d[i].descriz,&d[i].costo_mat);
			i++;
		}
	return i;
}

void stampa_dep(deposito d[],int dim){
	printf("%-10s%-10s%-10s%-10s\n","Cod Mat","Costo Mat","Descriz","N pezzi disp");
	for(int i=0;i<dim;i++)
		printf("%-10d%-10.2f%-10s%-10d\n",d[i].cod_mat,d[i].costo_mat,d[i].descriz,d[i].n_pezzi);
	printf("\n");
}

void stampa_pren(prenotaz p[],int dim){
	printf("%-10s%-10s%-10s%-10s\n","Materiale","Negozio","Descriz","N pezzi");
	for(int i=0;i<dim;i++)
		printf("%-10d%-10d%-10s%-10d\n",p[i].cod_mater,p[i].cod_neg,p[i].descr_mat,p[i].n_pezzi);
	printf("\n");
}

void evasione(deposito d[],prenotaz p[],int n_dep,int n_pren){
	int i,j;
	int flag;
	for(j=0;j<n_pren;j++){
		flag=0;
		for(i=0;i<n_dep && flag==0;i++){
			if(d[i].cod_mat==p[j].cod_mater){
				flag=1;
	 			if(d[i].n_pezzi>=p[j].n_pezzi){
	 				d[i].n_pezzi-=p[j].n_pezzi;
					printf("Prenotazione effettuata per il negozio %d del materiale %d\n",p[j].cod_neg,p[j].cod_mater);
				}else
					printf("Prenotazione fallita per il negozio %d del materiale %d, posti insufficienti\n",p[j].cod_neg,p[j].cod_mater);
				}
			}
	}
}


int calcola_tot(prenotaz p[],int n_pren,deposito d[],int n_dep,int search){
	int tot=0,j=0;
	for(j=0;j<n_pren;j++){
		if(p[j].cod_neg==search){	//1234

			for(int i=0;i<n_dep;i++){
				if(p[j].cod_mater==d[i].cod_mat)
						tot+=(p[j].n_pezzi*d[i].costo_mat);
			}

		}
	}
	return tot;
}

void ordina(deposito d[] ,int dim){
	int i,j=0;
	void swap(deposito*,deposito*);
	for(i=0;i<dim-1;i++)
		for(j=0;j<dim-i-1;j++)
			if(d[j].cod_mat<d[j+1].cod_mat){
				swap(&d[j],&d[j+1]);
		}
}

void swap(deposito *a,deposito *b){
	deposito scambio;
	scambio=*a;
	*a=*b;
	*b=scambio;
}

deposito inserim_depos(){
	deposito n;
	printf("Codice materiale:	");
	scanf("%d",&n.cod_mat);
	printf("Costo materiale:	");
	scanf("%f",&n.costo_mat);
	printf("Descrizione materiale:	");
	scanf("%s",n.descriz);
	printf("Numero pezzi disponib:	");
	scanf("%d",&n.n_pezzi);
	return n;
}

prenotaz inserim_pren(){
	prenotaz p;
	printf("Codice materiale da prenotare:	");
	scanf("%d",&p.cod_mater);
	printf("Codice negozio:	");
	scanf("%d",&p.cod_neg);
	printf("Descrizione materiale richiesto:	");
	scanf("%s",p.descr_mat);
	printf("Numero pezzi richiesti:	");
	scanf("%d",&p.n_pezzi);
	return p;
}
