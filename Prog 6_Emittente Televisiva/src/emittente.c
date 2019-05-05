#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 20
#define PATH "D:\\C-workspace\\Prog 6_Emittente Televisiva\\text.txt"

typedef struct{
	char cod_spot[MAX];
	char titolo[MAX];
	int durata;
	float costo;
	int orario;
}pubblicita;

int lettura_file(pubblicita p[]){
	FILE *fp;
	int i=0;
	fp=fopen(PATH,"r");
	if(fp==NULL)	printf("Errore\n");
	else
		while(!feof(fp)){
			fscanf(fp,"%s %s %d %f %d\n",p[i].cod_spot, p[i].titolo,&p[i].durata,&p[i].costo,&p[i].orario);
			i++;
		}
	return i;
}

void stampa(pubblicita d[],int dim){
	printf("%-10s%-10s%-10s%-10s%-10s\n","Codice","Titolo","Durata","Costo","Fascia");
	for(int i=0;i<dim;i++){
		printf("%-10s%-10s%-10d%-10.2f",d[i].cod_spot,d[i].titolo,d[i].durata,d[i].costo);
		switch(d[i].orario){
			case 0: printf("%-10s\n","Mattina");
					break;
			case 1: printf("%-10s\n","Pomeriggio");
					break;
			case 2: printf("%-10s\n","Sera");
					break;
    		}
	}
	printf("\n");
}

void massimo(pubblicita d[],int dim, int search){
	int i,max=0;
	for(i=0;i<dim;i++){
		if(d[i].orario==search)
			if(d[i].durata>max)
				max=d[i].durata;
	}

	for(i=0;i<dim;i++){
		if(d[i].orario==search)
			if(d[i].durata==max)
				printf("%s\n",d[i].titolo);
		}
}

void bubble_sort(pubblicita d[],int dim){
	int i,j;
	void swap(pubblicita*,pubblicita*);

	for(i=0;i<dim-1;i++){
		for(j=0;j<dim-i-1;j++){
			if(d[j].costo>d[j+1].costo){
				swap(&d[j],&d[j+1]);
					}
			}
	}
}

void swap(pubblicita* d1,pubblicita* d2){
	void swap_stringhe(char[],char[]);
	void swap_float(float*,float*);

	swap_stringhe(d2->cod_spot,d1->cod_spot);
	swap_stringhe(d2->titolo,d1->titolo);

	swap_float(&d2->durata,&d1->durata);	//e' un intero
	swap_float(&d2->costo,&d1->costo);
	swap_float(&d2->orario,&d1->orario);

}

void swap_float(float *val1,float *val2){
	float temp;

	temp=*val1;
	*val1=*val2;
	*val2=temp;
}

void swap_stringhe(char string1[],char string2[]){
	char buffer[MAX];

	strcpy(buffer,string1);
	strcpy(string1,string2);
	strcpy(string2,buffer);
}

pubblicita inserimento(){
	pubblicita d;
	printf("Inserire il codice dello spot: ");
	scanf("%s",d.cod_spot);
	printf("Inserire il titolo dello spot: ");
	scanf("%s",d.titolo);
	printf("Inserire la durata (in minuti) dello spot: ");
	scanf("%d",&d.durata);
	printf("Inserire il costo in euro dello spot: ");
	scanf("%f",&d.costo);
	printf("Inserire la fascia oraria (0 - mattina, 1- pomeriggio, 2 - sera) dello spot: ");
	scanf("%d",&d.orario);
	return d;
}
