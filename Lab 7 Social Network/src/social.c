//

#include <stdio.h>
#include <string.h>


#define TRUE 1
#define FALSE 0
#define PATH_UTENTI "D:\\C-workspace\\Lab 7 Social Network\\Debug\\utenti.txt"
#define PATH_AMICIZIE "D:\\C-workspace\\Lab 7 Social Network\\lista_amicizie.txt"
#define PATH_LIKE "D:\\C-workspace\\Lab 7 Social Network\\lista_like.txt"
#define MAX 20
#define MAX_AMICI 3
#define MAX_LIKES 3

typedef struct{
	char mittente[MAX];
	char destinatario[MAX];
}amicizia;

typedef struct{
	char user1[MAX];
	char user2[MAX];
}likes;

typedef struct{
	char nome[MAX];
	char cognome[MAX];
	char nickname[MAX];
}amico;

typedef struct{
	char nome[MAX];
	char cognome[MAX];
	char nickname[MAX];
	amico amici[MAX_AMICI];
    amico like[MAX_AMICI];
}utente;

int leggi_utenti(utente user[MAX]){
	FILE* q;
	int i=0;
	if((q=fopen(PATH_UTENTI,"r")) == NULL)
		puts("File non aperto");
	else{
		while(!feof(q)){
			fscanf(q,"%s %s %s\n",user[i].nome,user[i].cognome,user[i].nickname);
			i++;
			}
		fclose(q);
		}
	return i;
}

int presenza_nickname(utente user[MAX],int dim,char search[MAX]){
	int flag=FALSE ;
	for(int i=0;i<dim;i++)
		if(strcmp(search,user[i].nickname)==0){	//nick presente=TRUE
	    	flag=TRUE;
	}
	return flag;
}

void visual_utenti(utente user[],int dim){
	printf("%-15s\n%-15s%-20s%-18s\n","Utenti","Nome","Cognome","Nickname");
	for(int i=0;i<dim;i++)
		printf("%-15s%-20s%-18s\n",user[i].nome,user[i].cognome,user[i].nickname);
	printf("\n");
}

void scrivi_utente(utente user){
	FILE* q;
	if((q=fopen(PATH_UTENTI,"a")) == NULL)
		puts("File non aperto");
	else{
		fprintf(q,"%s %s %s\n",user.nome,user.cognome,user.nickname);
	}
	fclose(q);
}
void inserim_utenti_a(utente user[],int dim,amicizia a[],int n_amiciz,char utenza[]){
	void inserim_nickname_pres(utente[],int,char[]);
	int limite_amici(amicizia[],int,char[]);
	int test=1;
	do{
		inserim_nickname_pres(user,dim,utenza);
		test=limite_amici(a,n_amiciz,utenza);
		if(test==TRUE)
			printf("L'utente %s ha superato il num max di %d amicizie strette\n",utenza,MAX_AMICI);
	}while(test==TRUE);
}


void inserim_nickname_pres(utente user[],int dim,char value[]){
	int test=FALSE;
	do{
		//e' presente il nickname? NO --> allora ripeto
		printf("Nickname: ");
		scanf("%s",value);
		test=presenza_nickname(user,dim,value);
		if(test==FALSE)
			printf("Errore,nickname non presente, inserire nick presente\n");
	}while(test==FALSE);
	//esco se nick presente
}

int limite_amici(amicizia a[],int dim,char user[]){
	int count=0,flag=FALSE;
	for(int i=0;i<dim;i++)
		if((strcmp(a[i].destinatario,user)==0 )||(strcmp(a[i].mittente,user)==0))
			count++;
	if(count>=MAX_AMICI)	flag=TRUE;
	else 				flag=FALSE;
	return flag;
}

void scrivi_amicizie(char mittente[],char destinatario[]){
	FILE* q;
	if((q=fopen(PATH_AMICIZIE,"a")) == NULL)
		puts("File non aperto");
	else{
		fprintf(q,"%s %s\n",mittente,destinatario);
	}
	fclose(q);
}

void scrivi_like(char user1[],char user2[]){
	FILE* q;
	if((q=fopen(PATH_LIKE,"a")) == NULL)
		puts("File non aperto");
	else{
		fprintf(q,"%s %s\n",user1,user2);
	}
	fclose(q);
}

int leggi_amicizie(amicizia a[]){
	FILE* q;
	int i=0;
	if((q=fopen(PATH_AMICIZIE,"r"))== NULL)
		puts("File non aperto");
	else{
		while(!feof(q)){
			fscanf(q,"%s %s\n",a[i].mittente,a[i].destinatario);
			i++;
		}
		fclose(q);
	}
	return i;
}

int leggi_likes(likes l[]){
	FILE* q;
	int i=0;
	if((q=fopen(PATH_LIKE,"r"))== NULL)
		puts("File non aperto");
	else{
		while(!feof(q)){
			fscanf(q,"%s %s\n",l[i].user1,l[i].user2);
			i++;
		}
		fclose(q);
	}
	return i;
}

void inserim_utenti_l(utente user[],int dim,likes l[], int num_likes,char utenza[]){
	void inserim_nickname_pres(utente [],int,char[]);
	int limite_likes(likes[],int,char[]);
	int test=1;
	do{
		inserim_nickname_pres(user,dim,utenza);
		test=limite_likes(l,num_likes,utenza);
		if(test==TRUE)
			printf("L'utente %s ha superato il num max di %d likes messi\n",utenza,MAX_LIKES);
	}while(test==TRUE);
}

int limite_likes(likes l[],int dim,char user[]){
	int count=0,flag=FALSE;
	for(int i=0;i<dim;i++)
		if((strcmp(l[i].user1,user)==0 )||(strcmp(l[i].user2,user)==0))
			count++;
	if(count>=MAX_LIKES)	flag=TRUE;
	else 				flag=FALSE;
	return flag;
}

int controlla_amici(char user1[],char user2[],amicizia a[],int dim){
	int flag=FALSE ;
		for(int i=0;i<dim;i++)
			 if(((strcmp(user1,a[i].mittente)==0)&&(strcmp(user2,a[i].destinatario)==0)) || ((strcmp(user1,a[i].destinatario)==0)&&(strcmp(user2,a[i].mittente)==0))){
				 flag=TRUE;
		}
	return flag;
}

void visual_amicizie(amicizia a[],int dim){
	printf("%-13s\n%-13s%-15s\n","Amicizie","Mittente","Destinatario");
	for(int i=0;i<dim;i++)
		printf("%-13s%-15s\n",a[i].mittente,a[i].destinatario);
	printf("\n");
}

void visual_likes(likes l[],int dim){
	printf("%-13s\n%-13s%-15s\n","Likes","Utente1","Utente2");
	for(int i=0;i<dim;i++)
		printf("%-13s%-15s\n",l[i].user1,l[i].user2);
	printf("\n");
}

utente inserimento(utente u[],int dim){
	void not_get_nickname(char[]);
	utente user;
	int test=FALSE;
	printf("Nome:	");
	scanf("%s",user.nome);
	printf("Cognome:	");
	scanf("%s",user.cognome);
	do{
		printf("Nickname:	");
		scanf("%s",user.nickname);
		test=presenza_nickname(u,dim,user.nickname);
		if(test==TRUE)
			printf("Nickname gia presente,reinserire\n");
	}while(test==TRUE);
	return user;
}
