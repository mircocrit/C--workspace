#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
#define STR 27
#define PATH "D:\\C-workspace\\Prog 8_Supermercato\\text.txt"

typedef struct{
	char cogn_resp[STR];
	char nome_resp[STR];
	char via[STR];
	char citta[STR];
	int num_dip;
	float fatt;
}supermerc;

int lettura_file(supermerc s[]){
	FILE *fp;
	int i=0;
	fp=fopen(PATH,"r");
	if(fp==NULL)	printf("Errore\n");
	else
		while(!feof(fp)){
			fscanf(fp,"%s %s %s %s %d %f",s[i].nome_resp,s[i].cogn_resp,s[i].via,s[i].citta,&s[i].num_dip,&s[i].fatt);
			i++;
		}
	return i;
}

void stampa(supermerc sup[],int dim){
	printf("%-10s%-12s%-12s%-10s%-8s%-6s\n","Nome","Cognome","Via","Citta","N.dip","Fattur");
	for(int i=0;i<dim;i++)
		printf("%-10s%-12s%-12s%-10s%-8d%-6.2f\n",sup[i].nome_resp,sup[i].cogn_resp,sup[i].via,sup[i].citta,sup[i].num_dip,sup[i].fatt);
}

void stampa_record(supermerc sup){
	printf("%-10s%-12s%-12s%-10s%-8d%-6.2f\n",sup.nome_resp,sup.cogn_resp,sup.via,sup.citta,sup.num_dip,sup.fatt);
}

void ricerca_resp(supermerc sup[],int n,char nome_ric[], char cogn_ric[]){
	int i,flag=0;
	printf("%-10s%-12s%-12s%-10s%-8s%-6s\n","Nome","Cognome","Via","Citta","N.dip","Fattur");
    for(i=0;i<n;i++){
       if((strcmp(sup[i].nome_resp,nome_ric)==0) && (strcmp(sup[i].cogn_resp,cogn_ric)==0)){
            flag=1;
            stampa_record(sup[i]);
       }
    }
    if (flag==0)	 printf ("Il responsabile non e' inserito\n");
}


void ricerca_citta(supermerc sup[],int n,char citta_ric[]){
	int i,flag=0;
	printf("%-10s%-12s%-12s%-10s%-8s%-6s\n","Nome","Cognome","Via","Citta","N.dip","Fattur");
	for(i=0;i<n;i++)
		if(strcmp(sup[i].citta,citta_ric)==0){
			flag=1;
			stampa_record(sup[i]);
		}
	if (flag==0)
		printf ("Il responsabile non e' inserito\n");
}

void ricerca_max(supermerc sup[],int n){
	int max=0,i;
	printf("%-10s%-12s%-12s%-10s%-8s%-6s\n","Nome","Cognome","Via","Citta","N.dip","Fattur");
	for(i=0;i<n;i++)
		if(sup[i].num_dip>max)
			max=sup[i].num_dip;
	for(i=0;i<n;i++)
		if(sup[i].num_dip==max){
			stampa_record(sup[i]);
		}
}

supermerc inserimento(){
	supermerc sup;
    printf("Cognome responsabile:	");
    scanf("%s",sup.cogn_resp);
    printf("Nome responsabile:	");
    scanf("%s",sup.nome_resp);
    printf("Via:	");
    scanf("%s",sup.via);
    printf("Citta':	");
    scanf("%s",sup.citta);
    printf("Numero dei dipendenti:	");
    scanf("%d",&sup.num_dip);
    printf("Fatturato:	");
    scanf("%f",&sup.fatt);
    return sup;
}
