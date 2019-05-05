#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 *@file header.h
 *@authors matr 683254.
 *@date 25 lug 2018.
 */
#define PATH_UPDATE "D:\\C-workspace\\Lab 9.7 Borsa\\Debug\\clienti_upd.txt"
#define PATH_CLIENTI "D:\\C-workspace\\Lab 9.7 Borsa\\Debug\\clienti.txt"
#define PATH_AZIONI "D:\\C-workspace\\Lab 9.7 Borsa\\Debug\\azioni.txt"
#define MAX_CHAR 24
#define NUM_AZIENDE 5

typedef struct{
	char id[MAX_CHAR];
	int num_azioni[NUM_AZIENDE];
}cliente;

typedef struct{
	char id_cliente[MAX_CHAR];
	int id_azienda;		//0-5
	char tipo;		//A,V,G
	int n_azioni;
	char percorso[MAX_CHAR];//FILE_MOD
}action;

/**
 * apre un file in lettura per  acquisire i clienti
 * @pre il file deve esistere
 * @post il vettore conterrà i dati delli clienti
 * @post  restituira un valore >= 0, corrispondente al numero dei record
 */

int leggi_clienti(cliente c[]){
	FILE *p=NULL;
	int i=0;
	p=fopen(PATH_CLIENTI,"r");
	if(p==NULL)
		printf("Errore,percorso errato\n");
	else{
		while(!feof(p)){
			fscanf(p,"%s %d %d %d %d %d\n",c[i].id,&c[i].num_azioni[0],&c[i].num_azioni[1],&c[i].num_azioni[2],&c[i].num_azioni[3],&c[i].num_azioni[4]);
			i++;
		}
		fclose(p);
	}
	return i;
}

void visual_clienti(cliente c[],int dim){
	printf("%-10s%-10s%-10s%-10s%-10s%-10s\n","Id cliente","Azioni 1","Azioni 2","Azioni 3","Azioni 4","Azioni 5");
	for(int i=0;i<dim;i++)
		printf("%-10s%-10d%-10d%-10d%-10d%-10d\n",c[i].id,c[i].num_azioni[0],c[i].num_azioni[1],c[i].num_azioni[2],c[i].num_azioni[3],c[i].num_azioni[4]);
	printf("\n");
}

int leggi_azioni(action a[]){
	FILE *p=NULL;
	int i=0;
	p=fopen(PATH_AZIONI,"r");
	if(p==NULL)
		printf("Errore,percorso errato\n");
	else{
		while(!feof(p)){
			fscanf(p,"%s %d %c %d %s\n",a[i].id_cliente,&a[i].id_azienda,&a[i].tipo,&a[i].n_azioni,a[i].percorso);
			i++;
		}
		fclose(p);
	}
	return i;
}

void visual_azioni(action a[],int dim){
	printf("%-10s%-10s%-10s%-10s%-10s\n","Id cliente","Id azienda","Tipo","N Azioni","Percorso");
	for(int i=0;i<dim;i++)
			printf("%-10s%-10d%-10c%-10d%-10s\n",a[i].id_cliente,a[i].id_azienda,a[i].tipo,a[i].n_azioni,a[i].percorso);
		printf("\n");
}

void elabora_azione(action a,cliente c[],int n_cli){
	int i,j,flag=0;
	for(i=0;i<n_cli && flag==0;i++){
		if(strcmp(a.id_cliente,c[i].id)==0){
			flag=1;
			switch(a.tipo){
				case 'A'://ACQUISTO
					c[i].num_azioni[a.id_azienda-1]+=a.n_azioni;
					break;
				case 'V'://VENDITA
					c[i].num_azioni[a.id_azienda-1]-=a.n_azioni;
					break;
				case 'G'://GRATUITO
					for(j=0;j<5;j++){
						c[i].num_azioni[j]+=a.n_azioni;
					}
					break;
				}
		}
	}
}

void scrivi_clienti(cliente c){
	FILE *p=NULL;
	p=fopen(PATH_UPDATE,"a");
	if(p==NULL)
		printf("Errore,percorso errato\n");
	else{
		fprintf(p,"%s %d %d %d %d %d\n",c.id,c.num_azioni[0],c.num_azioni[1],c.num_azioni[2],c.num_azioni[3],c.num_azioni[4]);
		fclose(p);
	}
}

int rimuovi_duplicati(cliente c[],int dim){
	void copy_field(cliente *,cliente);
	int i,j,dup=0,k=0;
	for(i=1;i<dim;i++){
		dup=0;
		for(j=0;j<i;j++){
			if(strcmp(c[i].id,c[j].id)==0)
				dup=1;
		}
		if(!dup){
			copy_field(&c[k],c[j]);
			k++;
		}
	}
	return k;
}


void bubble_sort(cliente c[],int dim){
	void swap(cliente *,cliente*);
	int i,j;
	for(i=0;i<dim-1;i++)
		for(j=0;j<dim-i-1;j++)
			if(strcmp(c[j].id,c[j+1].id)==1)
				swap(&c[j],&c[j+1]);
}

void swap(cliente*c1,cliente*c2){
	cliente temp;
	temp=*c1;
	*c1=*c2;
	*c2=temp;
}


void insertion_sort(cliente c[],int dim){
	void copy_field(cliente *,cliente);
	cliente key;
	int i,j;
	for(i=1;i<dim;i++){
		copy_field(&key,c[i]);
		j=i-1;
		while(j>=0 &&(strcmp(c[j].id,key.id)==1)){
			copy_field(&c[j+1],c[j]);
			j=j-1;
		}
		copy_field(&c[j+1],key);
		}
}

void copy_field(cliente *c1,cliente c2){
	*c1=c2;
}

void selection_sort(cliente c[],int dim){
	void swap(cliente *,cliente*);
	int i,j,iMin;
	for(j=0;j<dim-1;j++){
		iMin=j;
		for(i=j+1;i<dim;i++){
			if(strcmp(c[i].id,c[iMin].id)==-1)
				iMin=i;
		}
		if(iMin!=j)
			swap(&c[j],&c[iMin]);
	}
}

int elimina_campo(cliente c[],int dim,char search[]){
	void copy_field(cliente *,cliente);
	int i,k=0;
	for(i=0;i<dim;i++){
		if(strcmp(c[i].id,search)!=0){
			copy_field(&c[k],c[i]);
			k++;
		}
	}
	return k;
}


void tokenizer()
