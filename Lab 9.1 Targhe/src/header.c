#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATH "D:\\C-workspace\\Lab 9.1 Targhe\\autovetture.txt"
#define PATH2 "D:\\C-workspace\\Lab 9.1 Targhe\\autovetture_ordinate.txt"

#define MAX_CHAR 25
#define MAX_AUTO 20


typedef struct{
	int anno;
	int mese;
	int giorno;
}data;

typedef struct{
	int cilindrata;
	char modello[MAX_CHAR];
	char targa[MAX_CHAR];
	data date;
}autovettura;


int leggi_auto(autovettura autom[]){
	FILE *fp=NULL;
	int i=0;
	fp=fopen(PATH,"r");
	if(fp==NULL)	printf("Errore, percorso invalido, riprovare\n");
	else{
		while(!feof(fp)){
			fscanf(fp,"%s %s %d %d %d %d\n",autom[i].modello,autom[i].targa,&autom[i].cilindrata,&autom[i].date.giorno,&autom[i].date.mese,&autom[i].date.anno);
			i++;
		}
		fclose(fp);
	}
	return i;
}

void visual_auto(autovettura autom[],int dim){
	printf("\t%-12s %-12s %-10s %-10s %-10s %-10s\n\n","Modello","Targa","Cilindrata","Giorno","Mese","Anno");
	for(int i=0;i<dim;i++)
			printf("\t%-12s %-12s %-10d %-10d %-10d %-10d\n",autom[i].modello,autom[i].targa,autom[i].cilindrata,autom[i].date.giorno,autom[i].date.mese,autom[i].date.anno);
}

void insertion_sort(autovettura autom[],int dim){
	int i,j;
	void copy_field(autovettura*,autovettura);

	autovettura key;
	for(i=1;i<dim;i++){
		copy_field(&key,autom[i]);
		j=i-1;
		while(j>=0 && ((autom[j].cilindrata<key.cilindrata)||(	(autom[j].cilindrata==key.cilindrata) && (strcmp(autom[j].targa,key.targa)==1))	)){
			copy_field(&autom[j+1],autom[j]);
			j=j-1;
	}
	copy_field(&autom[j+1],key);
	}
}

void selection_sort(autovettura autom[],int dim){
	void swap(autovettura*,autovettura*);
	int i,j,iMin;

	for(j=0;j<dim-1;j++){
		iMin=j;
		for(i=j+1;i<dim;i++){
			if((autom[i].cilindrata<autom[iMin].cilindrata)||(	(autom[i].cilindrata==autom[iMin].cilindrata) && (strcmp(autom[i].targa,autom[iMin].targa)==-1))	)
				iMin=i;
		}

		if(iMin!=j){
			swap(&autom[j],&autom[iMin]);
		}
	}
}

 void swap(autovettura *a,autovettura *b){
	 autovettura temp;
	 temp=*a;
	 a=*b;
	 b=temp;
 }

void copy_field(autovettura *receive,autovettura autom){
	*receive=autom;
}

void scrivi_auto(autovettura autom[],int dim){
	FILE *fp=NULL;
	int i=0;
	fp=fopen(PATH2,"w");
	if(fp==NULL)	printf("Errore, percorso invalido, riprovare\n");
	else{
		for(i=0;i<dim;i++)
			fprintf(fp,"%d %s %s %d %d %d\n",autom[i].cilindrata,autom[i].modello,autom[i].targa,autom[i].date.giorno,autom[i].date.mese,autom[i].date.anno);
		printf("File scritto\n");
		fclose(fp);
	}
}

void input_data(data* date){

	printf("Giorno	");
	scanf("%d", &date->giorno);
	printf("Mese	");
	scanf("%d", &date->mese);
	printf("Anno	");
	scanf("%d", &date->anno);
}


int ricerca_data(autovettura autom[],int dim, autovettura buffer[]){
	void input_data(data*);

	int j=0;
	data date_inizio,date_fine;

	printf("Inserire data di inizio della ricerca (GG MM YY)\n");
	input_data(&date_inizio);
	printf("Inserire data di fine della ricerca  (GG MM YY)\n");
	input_data(&date_fine);

	for(int i=0;i<dim;i++){
		if(autom[i].date.anno<date_inizio.anno || autom[i].date.anno>date_fine.anno){
			copy_field(&buffer[j],autom[i]);
			j++;
		}
		else if(autom[i].date.anno==date_inizio.anno && autom[i].date.anno==date_fine.anno){
				if(autom[i].date.mese<date_inizio.mese && autom[i].date.mese>date_fine.mese){
					copy_field(&buffer[j],autom[i]);
					j++;
				}
				else if(autom[i].date.mese==date_inizio.mese && autom[i].date.mese==date_fine.mese){
						if(autom[i].date.giorno<date_inizio.giorno && autom[i].date.giorno>date_fine.giorno){
							copy_field(&buffer[j],autom[i]);
							j++;
							}
				}
		}
	}
	return j-1;
}

void ricerca_max(autovettura autom[],int dim){
	int i=0,imax;
	float max;
	max=autom[0].cilindrata;

	for(i=0;i<dim;i++){
		if(autom[i].cilindrata>max)
			imax=i;
		}

	printf("Le fatture con numero max di saldo e che rientrano nelle date cercate sono:\n");
	for(i=0;i<dim;i++){
		if(autom[imax].cilindrata==autom[i].cilindrata)
			printf("\t%-23s %-23s %-10d %-10d %-10d %-10d\n",autom[i].modello,autom[i].targa,autom[i].cilindrata,autom[i].date.giorno,autom[i].date.mese,autom[i].date.anno);
				}
}

