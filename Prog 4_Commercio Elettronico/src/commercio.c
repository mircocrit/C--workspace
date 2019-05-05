#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define DATE 11
#define CODE 5
#define TESTO 50
#define PATH "D:\\C-workspace\\Prog 4_Commercio Elettronico\\text.txt"

typedef struct{
	char cod_sito[CODE];
	char data_ric[DATE];
	char cod_art[CODE];
	char cod_clie[CODE];
	char descr_art[TESTO];
	int n_pezzi_rich;
	float costo_pezzo;
	float costo_tot;
}richiesta;

int lettura_file(richiesta r[]){
	FILE *fp;
	int i=0;
	fp=fopen(PATH,"r");
	if(fp==NULL)	printf("Errore\n");
	else
		while(!feof(fp)){
			fscanf(fp,"%s %s %s %s %s %d %f %f\n",r[i].cod_sito, r[i].data_ric,r[i].cod_art,r[i].cod_clie,r[i].descr_art,&r[i].n_pezzi_rich,&r[i].costo_pezzo,&r[i].costo_tot);
			i++;
		}
	return i;
}

void stampa_richieste(richiesta r[],int dim){
	printf("%-10s%-13s%-10s%-10s%-12s%-8s%-8s%-8s\n","Cod_sito","Data","Cod_art","Cod_cli","Descr","Pezzi","Prezzo","totale");
	for(int i=0;i<dim;i++)
		printf("%-10s%-13s%-10s%-10s%-12s%-8d%-8.2f%-8.2f\n",r[i].cod_sito,r[i].data_ric,r[i].cod_art,r[i].cod_clie,r[i].descr_art,r[i].n_pezzi_rich,r[i].costo_pezzo,r[i].costo_tot);

}

void stampa(richiesta r){
	 printf("%-10s%-13s%-10s%-10s%-12s%-8d%-8.2f%-8.2f\n",r.cod_sito,r.data_ric,r.cod_art,r.cod_clie,r.descr_art,r.n_pezzi_rich,r.costo_pezzo,r.costo_tot);
}

void bubble_sort(richiesta d[],int dim){
	int i,j;
	void swap(richiesta*,richiesta*);

	for(i=0;i<dim-1;i++){
		for(j=0;j<dim-i-1;j++){
			if(d[j].costo_tot>d[j+1].costo_tot){
				swap(&d[j],&d[j+1]);
					}
			}
	}
}

void swap(richiesta* d1,richiesta* d2){
	void swap_stringhe(char[],char[]);
	void swap_float(float*,float*);

	swap_stringhe(d2->cod_art,d1->cod_art);
	swap_stringhe(d2->cod_clie,d1->cod_clie);
	swap_stringhe(d2->cod_sito,d1->cod_sito);
	swap_stringhe(d2->data_ric,d1->data_ric);
	swap_stringhe(d2->descr_art,d1->descr_art);

	swap_float(&d2->n_pezzi_rich,&d1->n_pezzi_rich);	//e' un intero
	swap_float(&d2->costo_pezzo,&d1->costo_pezzo);
	swap_float(&d2->costo_tot,&d1->costo_tot);

}

void swap_float(float *val1,float *val2){
	float temp;

	temp=*val1;
	*val1=*val2;
	*val2=temp;
}

void swap_stringhe(char string1[],char string2[]){
	char buffer[TESTO];

	strcpy(buffer,string1);
	strcpy(string1,string2);
	strcpy(string2,buffer);
}


void ricerca_max(richiesta d[],int dim,char search[]){
	int i;
	float max=0;

	for(i=0;i<dim;i++){
		if(strcmp(search,d[i].cod_sito)==0)
			if(d[i].costo_tot>max)
				max=d[i].costo_tot;
	}
	for(i=0;i<dim;i++)
		if(strcmp(search,d[i].cod_sito)==0)
			if(d[i].costo_tot==max)
				printf("il codice cliente che ha effettuato l'ordine di costo maggiore e' %s\n",d[i].cod_clie);

}

richiesta inserimento(){
	 richiesta r;
	 printf("Codice sito: ");
	 scanf("%s",r.cod_sito);
	 printf("Data (gg/mm/aaaa): ");
	 scanf("%s",r.data_ric);
	 printf("Codice articolo: ");
	 scanf("%s",r.cod_art);
	 printf("Codice cliente: ");
	 scanf("%s",r.cod_clie);
	 printf("Descrizione: ");
	 scanf("%s",r.descr_art);
	 printf("Pezzi richiesti: ");
	 scanf("%d",&r.n_pezzi_rich);
	 printf("Prezzo singolo in euro ");
	 scanf("%f",&r.costo_pezzo);
	 r.costo_tot=r.n_pezzi_rich*r.costo_pezzo;
	 return r;
 }
