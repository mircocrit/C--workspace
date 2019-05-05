#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 20
#define PATH "D:\\C-workspace\\Prog 3_Traslochi\\text.txt"

typedef struct{
	char cod_trasl[MAX];
	char data[11];
	char indir_part[MAX];
	char indir_arr[MAX];
	int cod_squadra;
	char automezzo[MAX];
	int ore_lav;
	float costo_tot;
}trasloco;

typedef enum{alfa,beta,gamma,delta}squa;

int lettura_file(trasloco t[]){
	FILE *fp;
	int i=0;
	fp=fopen(PATH,"r");
	if(fp==NULL)	printf("Errore\n");
	else
		while(!feof(fp)){
			fscanf(fp,"%s %s %s %s %d %s %d %f\n",t[i].cod_trasl, t[i].data,t[i].indir_part,t[i].indir_arr,&t[i].cod_squadra,t[i].automezzo,&t[i].ore_lav,&t[i].costo_tot);
			i++;
		}
	return i;
}

void stampa(trasloco t[],int dim){
	printf("%-9s%-11s%-13s%-13s%-7s%-10s%-5s%-8s\n","Codice","Data","Ind_Part","Ind_arr","Squa ","Auto", "Ore","Costo_lav");
	for(int i=0;i<dim;i++)
		printf("%-9s%-11s%-13s%-13s%-7d%-10s%-5d%-8.2f\n",t[i].cod_trasl,t[i].data,t[i].indir_part,t[i].indir_arr,t[i].cod_squadra,t[i].automezzo,t[i].ore_lav,t[i].costo_tot);
}

void ricerca_data(trasloco t[], int dim,char date[]){
	int i,flag=0;

	for(i=0;i<dim;i++){
       if(strcmp(date, t[i].data)==0){
    	   printf("Trasloco in %s nella data specificata\n",t[i].indir_arr);
    	   flag=1;
       }
	}
	if(flag==0)	 printf("Nessun trasloco trovato");
	printf("\n");
}

void conta_traslochi(trasloco t[],int dim,int cont[4]){
  	for(int i=0;i<dim;i++){
  		switch(t[i].cod_squadra){
	  		case 0:
	  			cont[alfa]+=1;
	  			break;
	   		case 1:
	   			cont[beta]+=1;
	 			break;
		    case 2:
		    	cont[gamma]+=1;
	 			break;
		    case 3:
		    	cont[delta]+=1;
	   			break;
	 		  }
 		  }
}

void ricerca_max(int cont[4]){
    int max=0,i,imax=0;

    for(i=0;i<4;i++)
    	if(cont[i]>max)
    		max=cont[i];

    int counter=0;
    for(i=0;i<4;i++){
    	if(cont[i]==max){
    		counter++;
    		imax=i;
    	}
    }

    if(counter==1)
    	printf("La squadra numero %d vince con %d traslochi\n",imax+1,max);
    else{
    	printf("Le squadre ");
    	for(i=0;i<4;i++){
    	    if(cont[i]==max){
    	    	printf("%d ", i+1);
    	    	}
    	}
    	printf("vincono a parimerito con %d traslochi:\n",max);
	}
}

trasloco inserimento(){
	trasloco t;
	printf("Codice trasloco: ");
	scanf("%s",t.cod_trasl);
	printf("Data trasloco: (gg/mm/aaaa) ");
	scanf("%s",t.data);
	printf("Indirizzo di partenza: ");
	scanf("%s",t.indir_part);
	printf("Indirizzo di destinazione: ");
	scanf("%s",t.indir_arr);
	printf("Codice squadra: 0 - squadra A, 1 - squadra B, 2 - squadra C, 3 - squadra D:	");
	scanf("%d",&t.cod_squadra);
	printf("Tipo automezzo (furgone-camion-autoscala):  ");
	scanf("%s",t.automezzo);
	printf("Ore di lavoro  ");
	scanf("%d",&t.ore_lav);
	printf("Costo del lavoro in euro:  ");
	scanf("%f",&t.costo_tot);
	printf("\n");
	return t;
}
