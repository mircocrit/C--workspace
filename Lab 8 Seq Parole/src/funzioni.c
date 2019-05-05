#include<stdio.h>
#include<string.h>

#define MAX 20
#define MAX_PATH 50
#define TRUE 1
#define FALSE 0
#define PATH "D:\\C-workspace\\Lab 8 Seq Parole\\parole.txt"
#define PATH_ORDINATE "D:\\C-workspace\\Lab 8 Seq Parole\\parole_ordinate.txt"
#define PATH_PALINDROME "D:\\C-workspace\\Lab 8 Seq Parole\\parole_palindrome.txt"
#define PATH_DOPPIE "D:\\C-workspace\\Lab 8 Seq Parole\\parole_doppie.txt"

typedef struct{
	char word[MAX];
	int palindroma;
}parola;

parola inserimento_parola(){
	parola p;
	printf("Parola da inserire : ");
	scanf("%s",p.word);
	p.palindroma=0;
	return p;
}

void visual_parole(parola p[],int dim){
	for(int i=0;i<dim;i++){
		printf("%s	",p[i].word);
		printf("%d\n",p[i].palindroma);
	}
}

void scrivi_parola(char word[MAX],char PATH_NAME[MAX_PATH]){
	FILE* q;
	if((q=fopen(PATH_NAME,"a"))==NULL)
		puts("File non aperto");
	else{
		fprintf(q,"%s\n",word);
	}
	fclose(q);
}

int leggi_parole(parola p[],int dim){
	FILE* q;
	int i=0;
	if((q=fopen(PATH,"r"))==NULL)
		puts("File non aperto");
	else{
		while(!feof(q)){
			fscanf(q,"%s",p[i].word);
			i++;
		}
		fclose(q);
	}
	return i;
}

void bubble_sort(parola p[],int dim){
	void swap(parola*,parola*);
	int i,j;
	for(i=0;i<dim-1;i++)
		for(j=0;j<dim-i-1;j++)
			if(strcmp(p[j].word,p[j+1].word)>0)
				swap(&p[j],&p[j+1]);

}

void selection_sort(parola p[],int dim){
	void swap(parola *,parola*);
	int i=0,j,iMin=0;
	for(j=0;j<dim-1;j++){
		iMin=j;
		for(i=j+1;i<dim;i++){
			if(strcmp(p[i].word,p[iMin].word)>0)
				iMin=i;
		}
		if(iMin!=j)
			swap(&p[j],&p[iMin]);
	}
}

void swap(parola *p1,parola *p2){
	p1->palindroma=p2->palindroma;
	strcpy(p1->word,p2->word);
}

void insertion_sort(parola p[],int dim){
	int i,j;
	char key[MAX];

	for(i=1;i<dim;i++){
		strcpy(key,p[i].word);
		j=i-1;
		while(j>=0 && (strcmp(p[j].word,key))>0){
			strcpy(p[j+1].word,p[j].word);
			j=j-1;
		}
		strcpy(p[j+1].word,key);
	}
}

int palindroma(parola word){
	int i,j=0,dim=0;
	int flag=FALSE;

	dim=strlen(word.word);
	char mirror[dim+1];

	for(i=dim-1;i>=0;i--){
		mirror[j]=word.word[i];
		j++;
		}
	mirror[j]='\0';

	if(strcmp(mirror,word.word)==0)		flag=TRUE;
		else		flag = FALSE;
	return flag;
}

int doppie(parola p){
	int j,dim=0,flag=0;
	char doppia[3];

		dim=strlen(p.word);
		for(j=0;j<dim;j++){
			if(p.word[j]==p.word[j+1]){
				flag=1;
				doppia[0]=p.word[j];
				doppia[1]=p.word[j];
				doppia[2]='\0';
				scrivi_parola(doppia,PATH_DOPPIE);
			}
		}
		return flag;
}

