#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATH "D:\\C-workspace\\Lab 9 Fatture\\fatture.txt"
#define PATH2 "D:\\C-workspace\\Lab 9 Fatture\\fatture_ordinate.txt"

#define MAX_CHAR 25
#define MAX_FATT 20

typedef struct{
	int anno;
	int mese;
	int giorno;
}data;

typedef struct{
	int codice;
	float saldo;
	char rag_soc[MAX_CHAR];
	data date;
}fattura;


int leggi_fatture(fattura fatt[]){
	FILE *fp=NULL;
	int i=0;
	fp=fopen(PATH,"r");
	if(fp==NULL)	printf("Errore, percorso invalido, riprovare\n");
	else{
		while(!feof(fp)){
			fscanf(fp,"%d %f %s %d %d %d\n",&fatt[i].codice,&fatt[i].saldo,fatt[i].rag_soc,&fatt[i].date.giorno,&fatt[i].date.mese,&fatt[i].date.anno);
			i++;
		}
		fclose(fp);
	}
	return i;
}

void visual_fatture(fattura fatt[],int dim){
	printf("\t%-10s %-10s %-23s %-10s %-10s %-10s\n\n","Codice","Saldo","Ragione sociale","Giorno","Mese","Anno");
	for(int i=0;i<dim;i++)
			printf("\t%-10d %-10.2f %-23s %-10d %-10d %-10d\n",fatt[i].codice,fatt[i].saldo,fatt[i].rag_soc,fatt[i].date.giorno,fatt[i].date.mese,fatt[i].date.anno);

}

void insertion_sort(fattura fatt[],int dim){
	int i,j;
	void copy_field(fattura*,fattura);

	fattura key;
	for(i=1;i<dim;i++){
		copy_field(&key,fatt[i]);
		j=i-1;
		while(j>=0 && ((fatt[j].saldo>key.saldo)||(fatt[j].saldo==key.saldo && fatt[j].codice>key.codice))){
			copy_field(&fatt[j+1],fatt[j]);
			j=j-1;
	}
	copy_field(&fatt[j+1],key);
	}
}

void copy_field(fattura *receive,fattura fatt){
	receive->codice = fatt.codice;
	receive->saldo = fatt.saldo;
	strcpy(receive->rag_soc,fatt.rag_soc);
	receive->date.giorno = fatt.date.giorno;
	receive->date.mese = fatt.date.mese;
	receive->date.anno = fatt.date.anno;
}

void scrivi_fatture(fattura fatt[],int dim){
	FILE *fp=NULL;
	int i=0;
	fp=fopen(PATH2,"w");
	if(fp==NULL)	printf("Errore, percorso invalido, riprovare\n");
	else{
		for(i=0;i<dim;i++)
			fprintf(fp,"%d %f %s %d %d %d\n",fatt[i].codice,fatt[i].saldo,fatt[i].rag_soc,fatt[i].date.giorno,fatt[i].date.mese,fatt[i].date.anno);
		printf("File scritto\n");
		fclose(fp);
	}
}

void input_data(data* date){

	do{
	printf("Giorno	");
	scanf("%d", &date->giorno);
	}while(date->giorno<1 || date->giorno >31);

	do{
	printf("Mese	");
	scanf("%d", &date->mese);
	}while(date->mese<0 || date->mese>12);

	do{
	printf("Anno	");
	scanf("%d", &date->anno);
	}while(date->anno<1900 || date->anno>2018);
}


int ricerca_data(fattura fatt[],int dim, fattura buffer[]){
	void input_data(data*);

	int j=0,temp;
	data date_inizio,date_fine;

	printf("Inserire data di inizio della ricerca (GG MM YY)\n");
	input_data(&date_inizio);
	printf("Inserire data di fine della ricerca  (GG MM YY)\n");
	input_data(&date_fine);

	int base=date_inizio.giorno+100*date_inizio.mese+10000*date_inizio.anno;
	int limit=date_fine.giorno+100*date_fine.mese+10000*date_fine.anno;
	for(int i=0;i<dim;i++){
		temp=fatt[i].date.giorno+100*fatt[i].date.mese+10000*fatt[i].date.anno;
		if(temp>base && temp<limit){
			copy_field(&buffer[j],fatt[i]);
			j++;
		}
	}

	return j;
}

void ricerca_max(fattura fatt[],int dim){
	int i=0,imax;
	float max;
	max=fatt[0].saldo;

	for(i=0;i<dim;i++){
		if(fatt[i].saldo>max)
			imax=i;
		}

	printf("Le fatture con numero max di saldo e che rientrano nelle date cercate sono:\n");
	for(i=0;i<dim;i++){
		if(fatt[imax].saldo==fatt[i].saldo)
			printf("\t%-10d %-10.2f %-23s %-10d %-10d %-10d\n",fatt[i].codice,fatt[i].saldo,fatt[i].rag_soc,fatt[i].date.giorno,fatt[i].date.mese,fatt[i].date.anno);
				}
}


//MODULO RICERCA_DATA_2
/*for(int i=0;i<dim;i++){
	if(fatt[i].date.anno>date_inizio.anno && fatt[i].date.anno<date_fine.anno){
		copy_field(&buffer[j],fatt[i]);
		j++;
	}else{
		if(fatt[i].date.anno==date_inizio.anno){
				if(fatt[i].date.mese>date_inizio.mese){
						copy_field(&buffer[j],fatt[i]);
						j++;
					}
					else
						if(fatt[i].date.mese==date_inizio.mese){
							if(fatt[i].date.giorno>date_inizio.giorno){
								copy_field(&buffer[j],fatt[i]);
								j++;
								}
					}
		}

	else{
		if(fatt[i].date.anno==date_fine.anno){
			if(fatt[i].date.mese<date_fine.mese){
				copy_field(&buffer[j],fatt[i]);
				j++;
			}
		else
			if(fatt[i].date.mese==date_fine.mese){
				if(fatt[i].date.giorno<date_fine.giorno){
					copy_field(&buffer[j],fatt[i]);
				j++;
				}
			}
		}
	}
}*/
