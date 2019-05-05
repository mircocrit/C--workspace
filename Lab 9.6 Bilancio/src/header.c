#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 50
#define N_MOV 10
#define PATH_ENTRATE "D:\\C-workspace\\Lab 9.6 Bilancio\\Debug\\entrate.txt"
#define PATH_USCITE "D:\\C-workspace\\Lab 9.6 Bilancio\\Debug\\uscite.txt"
#define PATH_OGGI "D:\\C-workspace\\Lab 9.6 Bilancio\\Debug\\oggi.txt"

typedef struct{
	int data;//1 366
	float importo;
	char motivazione[MAX_CHAR];
}entrata;

typedef struct{
	int data;//1 366
	float importo;
	char motivazione[MAX_CHAR];
}uscita;

typedef struct{
	char tipo;
	float importo;
	char motivazione[MAX_CHAR];
}movimento;

typedef struct{
	int data;
	movimento m[N_MOV];
}data_odierna;

int leggi_entrate(entrata e[]){
	FILE *p;
	int i=0;
	p=fopen(PATH_ENTRATE,"r");
	if(p==NULL)
		printf("Errore, percorso errato");
	else{
		while(!feof(p)){
			fscanf(p,"%d %f %s\n",&e[i].data,&e[i].importo,e[i].motivazione);
			i++;
		}
		fclose(p);
	}
	return i;
}

int leggi_uscite(uscita u[]){
	FILE *p;
	int i=0;
	p=fopen(PATH_USCITE,"r");
	if(p==NULL)
		printf("Errore, percorso errato");
	else{
		while(!feof(p)){
			fscanf(p,"%d %f %s\n",&u[i].data,&u[i].importo,u[i].motivazione);
			i++;
		}
		fclose(p);
	}
	return i;
}

void visual_entrate(entrata e[],int dim){
	printf("%s\n%-10s%-10s%-25s\n","Entrate","Data","Importo","Motivazione");
	for(int i=0;i<dim;i++)
		printf("%-10d%-10.2f%-25s\n",e[i].data,e[i].importo,e[i].motivazione);
}


void visual_uscite(uscita u[],int dim){
	printf("%s\n%-10s%-10s%-25s\n","Uscite","Data","Importo","Motivazione");
	for(int i=0;i<dim;i++)
		printf("%-10d%-10.2f%-25s\n",u[i].data,u[i].importo,u[i].motivazione);
}

int leggi_spesa(data_odierna*date){
	FILE *p;
	int i=0;
	p=fopen(PATH_OGGI,"r");
	if(p==NULL)
		printf("Errore, percorso errato");
	else{
		fscanf(p,"%d\n",&date->data);
		while(!feof(p)){
			fscanf(p,"%c %f %s\n",&date->m[i].tipo,&date->m[i].importo,date->m[i].motivazione);
			i++;
		}
		fclose(p);
	}
	return i;
}

void visual_data(data_odierna d,int n_mov){
	printf("Oggi\n");
	printf("Data:	%d\n",d.data);
	printf("%-5s%-10s%-25s\n","Tipo","Importo","Motivazione");
	for(int i=0;i<n_mov;i++)
		printf("%-5c%-10.2f%-25s\n",d.m[i].tipo,d.m[i].importo,	d.m[i].motivazione);
}

void aggiorna_dati(data_odierna d,int n_movim){
	void scrivi_uscita(int,float,char[]);
	void scrivi_entrata(int,float,char[]);
	for(int i=0;i<n_movim;i++){
		if(d.m[i].tipo=='E')
			scrivi_entrata(d.data,d.m[i].importo,d.m[i].motivazione);
		else
			scrivi_uscita(d.data,d.m[i].importo,d.m[i].motivazione);
	}
}

void scrivi_uscita(int data,float importo, char motiv[]){
	FILE *p;
	p=fopen(PATH_USCITE,"a");
	if(p==NULL)
		printf("Errore, percorso errato");
	else{
			fprintf(p,"%d %.2f %s\n",data,importo,motiv);
		}
		fclose(p);
	}


void scrivi_entrata(int data,float importo, char motiv[]){
	FILE *p;

	p=fopen(PATH_ENTRATE,"a");
	if(p==NULL)
		printf("Errore, percorso errato");
	else{
			fprintf(p,"%d %.2f %s\n",data,importo,motiv);
		}
		fclose(p);
	}

float calcola_saldo(entrata e[],int n_entr,uscita u[],int n_usc){
	float tot_entr=0,tot_usc=0;
	int i;
	for(i=0;i<n_entr;i++){
		tot_entr+=e[i].importo;
	}
	for(i=0;i<n_usc;i++)
		tot_usc+=u[i].importo;
	return tot_entr-tot_usc;

}
