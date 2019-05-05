#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 20
#define SETT 7
#define PATH "D:\\C-workspace\\Lab 2 paziente\\paziente.txt"

typedef struct{
    char sett[SETT][MAX];
    float peso[SETT];
    float temperatura[SETT];
    char esame[SETT][MAX];
}paziente;

paziente acquisiz_pazienti(){
	FILE* p=NULL;
	paziente paz;
    p=fopen(PATH,"r");
    if(p==NULL) 	printf("Errore\n");
    else
    for(int i=0;i<SETT;i++)
        fscanf(p, "%s       %f  %f  %s",paz.sett[i],&paz.peso[i],&paz.temperatura[i],paz.esame[i]);
    return paz;
}

void stampa(paziente paz){
    for(int i=0;i<SETT; i++)
        printf("%-10s%-7.2f%-9.2f%-13s\n",paz.sett[i],paz.peso[i],paz.temperatura[i],paz.esame[i]);
}

float calcola_media(float campo[SETT]){
    float med=0;
    for(int i=0;i<SETT;i++){
        med+=campo[i];
    }
    return med/SETT;
}

float calcola_max(float campo[SETT]){
    float max=campo[0];
    for(int i=0;i<SETT;i++){
        if(campo[i]>max)    max=campo[i];
    }
    return max;
}

float calcola_min(float campo[SETT]){
	float min=campo[0];
    for(int i=0;i<SETT;i++){
       if(campo[i]<min)    min=campo[i];
   }
   return min;
}

float deviazione_standard(float campo[SETT],float med){
    float sum=0;
    for(int i=0;i<SETT;i++){
        sum=pow((campo[i]-med),2);
    }
    sum=sqrt(sum/SETT);
    return sum;
}

void visualdati_giorno(paziente p, char search[MAX]){
    for(int i=0;i<SETT;i++){
        if(strcmp(search,p.sett[i])==0)
            printf("I dati del paziente nel giorno %s sono:\n peso: %f\n temperatura: %f\n esame: %s\n",p.sett[i],p.peso[i],p.temperatura[i] ,p.esame[i]);
    }
}

int esame_max(paziente paz,char esame_max[]){
    int i,j,count=0;
    int c_max=0;

    for(j=0;j<7;j++){
    	for(i=0;i<7;i++){
    		if(strcmp(paz.esame[i],paz.esame[j])==0)
    			count++;
			}
			if(count>c_max){
				c_max=count;
				strcpy(esame_max,paz.esame[i]);
			}
			count=0;
		}
    return c_max;
}
void visual_giorni(paziente paz,char esame[]){
	printf("L'esame e' stato effettuato nei giorni:\n");
    for(int i=0;i<7;i++){
    	if(strcmp(paz.esame[i],esame)==0)
    		printf("%s, ",paz.sett[i]);
    }
    printf("\n");
}
