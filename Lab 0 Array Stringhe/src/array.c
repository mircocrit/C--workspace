#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 70
#define DIM 100
#define LENGHT 100
#define PATH "D:\\C-workspace\\Lab 0 Array Stringhe\\text.txt"

typedef struct{
	char stringa[MAX_CHAR];
}string;

/**
 * apre un file in lettura per  acquisire stringhe
 * @pre il file deve esistere
 * @post la matrice conterrà i dati delle strignhe
 * @post  restituira un valore >= 0, corrispondente al numero delle stringhe
 */

int leggi_stringhe(char a[][LENGHT]){
	FILE* q;
	int i=0,j;
	char c;
	if((q=fopen(PATH,"r"))==NULL)
		puts("File non aperto");
	else{
		i=0;
		j=0;
		while(!feof(q)){
			c=fgetc(q);
			if(c!='\n'){
				a[i][j]=c;
				j++;
			}
			else{
				a[i][j]='\0';
				i++;
				j=0;
			}
		}
		fclose(q);
	}
	return i;
}

void stampa(char a[][LENGHT],int dim){
	int i;
	for(i=0;i<dim;i++)
		printf ("%s \n",a[i]);
	printf("\n");
}

void scambia(char a[][LENGHT],int i,int j){
	char s[MAX_CHAR];
	strcpy(s,a[j]);
	strcpy(a[j],a[i]);
	strcpy(a[i],s);
}

int conta_parole(char a[][LENGHT],int n,char search[]){
	int count=0;
	for(int i=0;i<n;i++)
		if(strstr(a[i],search)!= NULL)	//search viene cercata in a[i], se trovata restituisce un puntatore a dove la trova
			count++;
	return count;
}

void rimpiazza(char a[][LENGHT],int n,char search[],char replace[]){
	char *ptr;
	for(int i=0;i<n;i++){
		ptr=strstr(a[i],search);
		if(ptr!=NULL)
			strncpy(ptr,replace,strlen(replace));
	}
}
