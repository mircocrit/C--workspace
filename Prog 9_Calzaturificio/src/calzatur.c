#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 20
#define PATH_ORD "D:\\C-workspace\\Prog 9_Calzaturificio\\ordini.txt"
#define PATH_CALZ "D:\\C-workspace\\Prog 9_Calzaturificio\\calzature.txt"

typedef struct{
	 char cod_calz[MAX];
	 float costo_calz;
	 int num_pezzi;
}calzatura;

typedef struct{
	char cod_clie[MAX];//== codice negozio
	char cod_zona[MAX];
	char cod_calz[MAX];
	int pezzi_rich;
	char data_ord[MAX];
}ordine;

int leggi_ordine(ordine o[]){
	FILE *fp;
	int i=0;
	fp=fopen(PATH_ORD,"r");
	if(fp==NULL)	printf("Errore\n");
	else
		while(!feof(fp)){
			fscanf(fp,"%s %s %s %d %s",o[i].cod_clie,o[i].cod_zona,o[i].cod_calz,&o[i].pezzi_rich,o[i].data_ord);
			i++;
		}
	return i;
}

int leggi_calz(calzatura c[]){
	FILE *fp;
	int i=0;
	fp=fopen(PATH_CALZ,"r");
	if(fp==NULL)	printf("Errore\n");
	else
		while(!feof(fp)){
			fscanf(fp,"%s %f %d",c[i].cod_calz,&c[i].costo_calz,&c[i].num_pezzi);
			i++;
		}
	return i;

}

void stampa_record(ordine o){
	printf("%-10s%-10s%-10s%-8d%-12s\n",o.cod_clie,o.cod_zona,o.cod_calz,o.pezzi_rich,o.data_ord);
}

void stampa_ord(ordine o[],int dim){
	printf("%-10s%-10s%-10s%-8s%-12s\n","Cod Cli","Cod Zona","Cod calz","N pezzi","Data ord");
	for(int i=0;i<dim;i++)
		printf("%-10s%-10s%-10s%-8d%-12s\n",o[i].cod_clie,o[i].cod_zona,o[i].cod_calz,o[i].pezzi_rich,o[i].data_ord);
	printf("\n");
}

void stampa_calz(calzatura c[],int dim){
	printf("%-10s%-10s%-10s\n","Cod calz","Costo calz","Pezzi disp");
	for(int i=0;i<dim;i++)
		printf("%-10s%-10.2f%10d\n",c[i].cod_calz,c[i].costo_calz,c[i].num_pezzi);
	printf("\n");
}

void calcola_max(ordine o[],int num,char search[]){
	int i,max=0;
	for(i=0;i<num;i++){
		if(strcmp(o[i].cod_clie,search)==0)
			if(o[i].pezzi_rich>max)
				max=o[i].pezzi_rich;
	}
	for(i=0;i<num;i++){
		if(strcmp(o[i].cod_clie,search)==0)
			if(o[i].pezzi_rich==max){
				printf("Ordine della calzatura %s in data %s: %d pezzi richiesti\n",o[i].cod_calz,o[i].data_ord,o[i].pezzi_rich);
			}
	}
	printf("\n");
}

int calcola_totale(ordine ord[],int n_ord,char cod_ric[MAX]){
	int i,tot=0;
	for(i=0;i<n_ord;i++){
		if(strcmp(cod_ric,ord[i].cod_calz)==0)
			tot+=ord[i].pezzi_rich;
	}
	return tot;
}

void ordina(ordine o[],int dim){
	void swap(ordine*,ordine*);
	int i,j;
	for(i=0;i<dim-1;i++)
		for(j=0;j<dim-i-1;j++)
			if(o[j].pezzi_rich>o[j+1].pezzi_rich){
				swap(&o[j],&o[j+1]);
			}
}

void swap(ordine*a,ordine*b){
	ordine scambio;
	scambio=*a;
	*a=*b;
	*b=scambio;
}

void evasione(ordine o[], calzatura c[],int n_ord,int n_calz){
	int i,j;
	int flag;
	for(i=0;i<n_calz;i++){
		flag=0;
		for(j=0;j<n_ord && flag==0;j++){
			if(strcmp(o[i].cod_calz,c[j].cod_calz)==0){
				flag=1;
 				if(o[i].pezzi_rich<=c[j].num_pezzi){
 					c[j].num_pezzi-=o[i].pezzi_rich;
					printf("Prenotazione effettuata per l'ordine %s della calzatura %s\n",o[i].cod_clie,o[i].cod_calz);
				}else
					printf("Prenotazione fallita per l'ordine %s della calzatura %s, posti insufficienti\n",o[i].cod_clie,o[i].cod_calz);
				}
			}
	}
}

ordine inserim_ordini(){
	ordine r;
	printf("Codice cliente\n");
	scanf("%s",r.cod_clie);
	printf("Codice zona\n");
	scanf("%s",r.cod_zona);
	printf("Codice calzatura da ordinare\n");
	scanf("%s",r.cod_calz);
	printf("Num pezzi richiesti\n");
	scanf("%d", &r.pezzi_rich);
	printf("Data ordine\n");
	scanf("%s",r.data_ord);
	return r;
}

calzatura inserim_calz(){
	calzatura c;
	printf("Codice cliente\n");
	scanf("%s",c.cod_calz);
	printf("Costo calzatura\n");
	scanf("%f",&c.costo_calz);
	printf("Numero pezzi diponibili\n");
	scanf("%d", &c.num_pezzi);
	return c;
}
