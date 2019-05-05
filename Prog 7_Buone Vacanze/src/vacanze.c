#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 20
#define PATH1 "D:\\C-workspace\\Prog 7_Buone Vacanze\\appartamenti.txt"
#define PATH2 "D:\\C-workspace\\Prog 7_Buone Vacanze\\richieste.txt"

typedef struct{
	int cod_app;
	int num_stanze;
	int mese[4][2];					//0=libero, 1= occupato
	int tipo; 						//0=mono, 1=bilo,2=trilo
	int cont;						//per ricercamax, appart + richiesto
}appartamento;

 typedef struct{
	int cod_rich;
	int stanze_rich;
	int mese;						//0=giugno..
	int accettaz; 					//0=rifiutata , 1=accettata
}richiesta;

int leggi_app(appartamento a[]){
	FILE *fp;
	int i=0;
	fp=fopen(PATH1,"r");
	if(fp==NULL)		printf("Errore\n");
	else
		while(!feof(fp)){
			fscanf(fp,"%d %d %d %d %d %d %d %d\n",&a[i].cod_app,&a[i].num_stanze,&a[i].mese[0][0],&a[i].mese[1][0],&a[i].mese[2][0],&a[i].mese[3][0],&a[i].tipo,&a[i].cont);
			i++;
		}
	return i;
}

int leggi_rich(richiesta r[]){
	FILE *fp;
	int i=0;
	fp=fopen(PATH2,"r");
	if(fp==NULL)		printf("Errore\n");
	else
		while(!feof(fp)){
			fscanf(fp,"%d %d %d %d\n",&r[i].cod_rich,&r[i].stanze_rich,&r[i].mese,&r[i].accettaz);
			i++;
		}
	return i;
}

void stampa_app(appartamento a[],int dim){
	printf("%-10s%-10s%-10s%-10s%-10s%-10s%-15s%-10s\n","Cod. app","Num stanze","Disp giu","Disp lug","Disp ago","Disp sett","Tipo","Cont");
	for(int i=0;i<dim;i++){
		printf ("%-10d%-10d" ,a[i].cod_app,a[i].num_stanze);
		for(int j=0;j<4;j++){
			switch(a[i].mese[j][0]){
				case 0: printf("%-10s","Libero");
							break;
				case 1: printf("%-10s","Occupato");
							break;
				}
		}
		switch(a[i].tipo){
			case 0: printf("%-15s","Monolocale");
					break;
			case 1: printf("%-15s","Bilocale");
					break;
			case 2: printf("%-15s","Trilocale");
					break;
					}
		printf ("%-10d\n" ,a[i].cont);
	}
	printf("\n");
}

void stampa_rich(richiesta d[],int dim){
	printf("%-10s%-12s%-10s%-12s\n","Cod. app","Mese","Num stanze","Accettaz");
	for(int i=0;i<dim;i++){
		printf("%-10d",d[i].cod_rich);
		switch(d[i].mese){
			case 0: printf("%-12s","Giugno");
					break;
			case 1: printf("%-12s","Luglio");
					break;
			case 2: printf("%-12s","Agosto");
					break;
			case 3: printf("%-12s","Settembre");
					break;
		}
		printf("%-10d",d[i].stanze_rich);
		switch(d[i].accettaz){
			case 0:
				printf("%-12s\n","Rifiutata");
				break;
			case 1:
				printf("%-12s\n","Accettata");
				break;
		}
	}
	printf("\n");
}

void evasione(richiesta r[], appartamento a[],int n_rich,int n_app){
	int i,j,flag;
	for(j=0;j<n_rich;j++){
		flag=0;
		for(i=0;i<n_app && flag==0;i++){
			if(a[i].cod_app==r[j].cod_rich){
				a[i].cont++;	//
				flag=1;
				if(r[j].stanze_rich<a[i].num_stanze && a[i].mese[r[j].mese][0]==0){
					a[i].num_stanze-=r[j].stanze_rich;
					(a[i].mese[r[j].mese][1])++;
					printf("Prenotazione %d dell'appartamento %d accettata\n",r[j].cod_rich,a[i].cod_app);
					r[j].accettaz=1;
				}
				else printf("Prenotazione %d dell'appartamento %d rifiutata\n",r[j].cod_rich,a[i].cod_app);
		     }
		}
	}
	printf("\n");
}

void ricerca_max(appartamento a[],int n){
	int i,max=0;
	for(i=0;i<n;i++)
		if(a[i].cont>max)
			max=a[i].cont;

	for(i=0;i<n;i++){
		if(a[i].cont==max){
			printf("%d\n",a[i].cod_app);
			printf("Tipo:	");
			switch(a[i].tipo){
				case 0: printf("%s\n","Monolocale");
								break;
				case 1: printf("%s\n","Bilocale");
								break;
				case 2: printf("%s\n","Trilocale");
								break;
				}
			printf("Mese piu richesto:	");
			max=0;
			for(int j=0;j<4;j++)
				if(a[i].mese[j][1]>max)
					max=a[i].mese[j][1];
			for(int j=0;j<4;j++)
				if(a[i].mese[j][1]==max)
					switch(a[i].mese[j][0]){
						case 0: printf("%s\n","Giugno");
								break;
						case 1: printf("%s\n","Luglio");
								break;
						case 2: printf("%s\n","Agosto");
								break;
						case 3: printf("%s\n","Settembre");
								break;
					}

			}
	}
}
