#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define PATH "D:\\C-workspace\\Lab 9.9 Twitter\\Debug\\nomi.txt"
#define PATH_FOLL "D:\\C-workspace\\Lab 9.9 Twitter\\Debug\\follower.txt"
#define MAX_CHAR 24
#define MAX_SEGUACI 500
#define MAX_FOLL 300
//
//

typedef struct{
	char nickname[MAX_CHAR];
	char follower[MAX_CHAR];
	int data_inizio;
}nome;

typedef struct{
	char nickname[MAX_CHAR];
}dati;

int leggi_nomi(nome n[]){
	void elimina_cancell(char[]);
	FILE *p;
	int i=0;
	//char string[MAX_CHAR];
	p=fopen(PATH,"r");
	if(p==NULL)
		printf("Errore,percorso non trovato\n");
	else{
		while(!feof(p)){
			//fscanf(p,"%s\n",string);
			//elimina_cancell(string);
			fscanf(p,"%s %s %d\n",n[i].nickname,n[i].follower,&n[i].data_inizio);
			i++;
		}
	fclose(p);
	}
	return i;
}
/*
void elimina_cancell(char s[]){
	int i=0;
	while(s[i]!='\n'){
		if(s[i]=='#')
			s[i]=' ';
		i++;
	}
	s[i]='\n';
}
*/
void visual_nomi(nome n[],int dim){
	int i=0;
	printf("%-20s%-20s%-12s\n","Nickname","Follower","Data Inizio");
	for(i=0;i<dim;i++)
		printf("%-20s%-20s%-12d\n",n[i].nickname,n[i].follower,n[i].data_inizio);
	printf("\n");
}

void scrivi_file(char nick[],char follower[],int data){
	FILE *p;
	p=fopen(PATH,"a");
	if(p==NULL)
		printf("Errore,percorso non trovato\n");
	else{
		fprintf(p,"%s %s %d\n",nick,follower,data);
	}
	fclose(p);
}

int calcola_follower(nome n[],int dim,char nick[]){
	int i=0,cont=0;
	for(i=0;i<dim;i++){
		if(strcmp(nick,n[i].nickname)==0)
			cont++;
	}
	return cont;
}

int calcola_following(nome n[],int dim,char nick[]){
	int i=0,cont=0;
	for(i=0;i<dim;i++){
		if(strcmp(nick,n[i].follower)==0)
			cont++;
	}
	return cont;
}


void ricerca_max_follower(nome n[],int dim){
	int i=0,folr_max=0,work=0,work2=0,flag=0;
	int calcola_follower(nome[],int,char[]);

	for(i=0;i<dim;i++){
		work=calcola_follower(n,dim,n[i].nickname);
		if(work>folr_max)
			folr_max=work;
	}
	flag=0;
	for(i=0;i<dim && flag==0;i++){
		work2=calcola_following(n,dim,n[i].nickname);
		if(work==work2){
			printf("Il nick con num max di follower e': %s\n",n[i].nickname);
			flag=1;
		}
	}
}

void ricerca_max_following(nome n[],int dim){
	int i=0,folg_max=0,work=0,work2=0,flag=0;
	int calcola_following(nome[],int,char[]);

	for(i=0;i<dim;i++){
		work=calcola_following(n,dim,n[i].nickname);
		if(work>folg_max)//massimo following
			folg_max=work;
	}

	flag=0;
	for(i=0;i<dim && flag==0;i++){
		work2=calcola_following(n,dim,n[i].nickname);
		if(work==work2){
			printf("Il nick con num max di following e': %s\n",n[i].nickname);
			flag=1;
		}
	}
}



void select_follower(nome n[],int dim,int data_low,int data_high,char search[]){
	void insertion_sort(char[20][MAX_CHAR],int);
	void scrivi_record(char[]);

	int i=0,j=0,k=0,limit=0;
	char array[20][MAX_CHAR];

	for(i=0;i<dim;i++){
		if(n[i].data_inizio>data_low && n[i].data_inizio<data_high)
			if(strcmp(n[i].nickname,search)==0){
				strcpy(array[j],n[i].follower);
				j++;
			}
	}
	limit=j;

	for(k=0;k<limit;k++)
		printf("%s\n",array[k]);

	insertion_sort(array,j);

	for(k=0;k<limit;k++)
		scrivi_record(array[k]);
}


void insertion_sort(char follower[20][MAX_CHAR],int dim){
	int i=0,j=0;
	char key[MAX_CHAR];

	for(i=1;i<dim;i++){
		strcpy(key,follower[i]);
		j=i-1;
		while(j>=0 && (strcmp(key,follower[j])<0)){
			strcpy(follower[j+1],follower[j]);
			j=j-1;
		}
	strcpy(follower[j+1],key);
	}
}

void scrivi_record(char foll[]){
	FILE *p;
	p=fopen(PATH_FOLL,"a");
	if(p==NULL)
		printf("Errore,percorso non trovato\n");
	else{
		fprintf(p,"%s\n",foll);
	}
	fclose(p);
}

/*
 *
void bubble_sort(char follower[20][MAX_CHAR],int dim){
	int i,j;
	for(i=0;i<dim-1;i++)
		for(j=0;j<dim-i-1;j++)
			if(strcmp(follower[j],follower[j+1])>0)
				swap(follower[j],follower[j+1]);

}

int elabora_nomi(nome n[],int n_nomi, dati d[],int n_dati){
	int rimuovi_duplicati(dati[],int);
	int i;
	for(i=0;i<n_nomi;i++){
		strcpy(d[i].nickname,n[i].nickname);
	}
	n_dati=rimuovi_duplicati(d,n_dati);
	return n_dati;
}

int rimuovi_duplicati(dati d[],int n_dati){
	void copy_field(dati*,dati);
	int i,k=0,j,dup;
	for(i=0;i<n_dati;i++)
		for(j=0;j<i;j++){
			if(strcmp(d[i].nickname,d[j].nickname)==0)
				dup=1;
		}
		if(!dup){
			copy_field(&d[k],d[i]);
			k++;
		}
	return k;
}

void copy_field(dati *d1,dati d2){
	*d1=d2;
}
*/
