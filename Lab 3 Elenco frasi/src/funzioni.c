#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 26

#define TRUE 1
#define FALSE 0
#define PATH_READ "D:\\C-workspace\\Lab 3 Elenco frasi\\testo.txt"
#define PATH_WRITE "D:\\C-workspace\\Lab 3 Elenco frasi\\parole_scritte.txt"

typedef struct{
	char string[MAX_CHAR];
}parola;


void leggi_file(char s[]){
	FILE* q;
	int j=0;
	if((q=fopen(PATH_READ,"r"))==NULL)
		puts("File non aperto");
	else{
		printf("File aperto\n");
		while(!feof(q)){
			s[j]=fgetc(q);
			j++;
		}
		s[j]='\0';
		fclose(q);
	}
}

int leggi_stringhe(parola a[]){
	FILE* q;
	int i=0,j;
	char c;
	if((q=fopen(PATH_READ,"r"))==NULL)
		puts("File non aperto");
	else{
		i=0;
		j=0;
		while(!feof(q)){
			c=fgetc(q);
			if(c!='\n'){
				a[i].string[j]=c;
				j++;
			}
			else{
				a[i].string[j]='\0';
				i++;
				j=0;
			}
		}
		fclose(q);
	}
	return i;
}

void output_testo(char stringa[]){
	printf("%s\n",stringa);
}

int rimuovi_punteggiatura(char s[]){
	int i=0,k;
	k=0;
	for(i=0;i<strlen(s);i++){
		if((ispunct(s[i]))==0){//se non e' punteggiatura
			s[k]=s[i];
			k++;
			}
		else
			if(s[i]=='\n'){
				s[k]='#';
				k++;
			}
	}
	s[k]='\0';
	return k;
}

int tokenizza(parola words[],char stringa[]){
	char* p;
	int i=0;
	p=strtok(stringa," ");
	while(p!=NULL){
        strcpy(words[i].string,p);
        i++;
		p=strtok(NULL," ");
	}
	return i;
}

void output_token(parola words[],int dim){
	for(int i=0;i<dim;i++){
		printf("%s\n",words[i].string);
	}
	printf("\n");
}
/**
 * char string e' la parola di max frequenza
 * parole e' l'array tokenizzato
 */

int parola_max_freq(parola parole[],int dim,char word_max[]){
	int i,j,cont=0,max_cont=0;

	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			if(strcmp(parole[i].string,parole[j].string)==0){
				cont++;
			}
		}
		if(cont>max_cont){
			max_cont=cont;
			strcpy(word_max,parole[i].string);
		}
		cont=0;
	}
	return max_cont;
}

void scrivi_file(char word[],int cont){
	FILE* p=NULL;
	if((p=fopen(PATH_WRITE,"a")) == NULL)
		puts("File non aperto");
	else{
		fprintf(p,"%s	%d\n",word,cont);
	}
	fclose(p);
}

int elimina_stringa(parola word[],int dim,char search[]){
	int i,k=0;
	for(i=0;i<dim;i++){
	  if(strcmp(word[i].string,search)!=0){
		  strcpy(word[k].string,word[i].string);
		  k++;
	  }
	}
	return k;
}

void visual_nomi(parola word[],int dim){
    int i;
    for(i=0;i<dim;i++){
        if((isupper(word[i].string[0])==1))
            printf("%s\n",word[i].string);
    }
    printf("\n");
}

void input_testo(char parole[]){
	char c;
	int i=0;
	printf("Testo:	");
	while((c=getchar())!='.'){
		parole[i]=c;
		i++;
	}
	parole[i]='\0';
}
