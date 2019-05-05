#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define PATH "D:\\C-workspace\\Lab 9.5 Seq Parole\\testo.txt"
#define MAX_CHAR 2000
#define MAX 700

typedef struct{
	char parola[MAX_CHAR];
	int dimens;
}stringa;

stringa leggi_parole(stringa s){
	FILE* q;
	int j=0;
	char c;
	if((q=fopen(PATH,"r"))==NULL)
		puts("File non aperto");
	else{
		while(!feof(q)){
			c=fgetc(q);
			if((ispunct(c))==0){
				s.parola[j]=c;
				j++;
			}
		}
		s.parola[j]='\0';
		fclose(q);
	}
	return s;
}

void visual_testo(stringa s){
	printf("%s",s.parola);
}

int tokenizza(stringa parole[MAX],stringa words){
	char* p;
	int i=0;
	p=strtok(words.parola," \n");
	while(p!=NULL){
        strcpy(parole[i].parola,p);
        i++;
		p=strtok(NULL," \n");
	}
	printf("Il testo ha %d parole\n\n",i);
	for(int j=0;j<i;j++)
		parole[j].dimens=strlen(parole[j].parola);
	return i;
}

void visual_parole(stringa array[], int num_parole){
	for(int i=0;i<num_parole;i++)
		printf("%s  %d\n",array[i].parola,array[i].dimens);
}

void conta_occorr(stringa array[],int num_parole,int cont[]){
	int lungh=0;
	for(int i=0;i<num_parole;i++){
		lungh=strlen(array[i].parola);
		cont[lungh-1]++;
		}
	}
