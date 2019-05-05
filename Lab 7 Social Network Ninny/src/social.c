#include <stdio.h>
#include <string.h>

#define MAX 20
#define MAX_AMICI 50
#define TRUE 1
#define FALSE 0
#define PATH_UTENTI "D:\\C-workspace\\Lab 7 Social Network Ninny\\utenti.txt"
#define PATH_AMICIZIE "D:\\C-workspace\\Lab 7 Social Network Ninny\\lista_amicizie.txt"
#define PATH_LIKE "D:\\C-workspace\\Lab 7 Social Network Ninny\\lista_like.txt"

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

utente inserimento(){
	int verifica_nickname(char[]);
	utente user;
	int test=FALSE;
	printf(" Nome utente : ");
	scanf("%s",user.nome);
	printf(" Cognome utente : ");
	scanf("%s",user.cognome);
	do{
		printf(" Nickname utente : ");
		scanf("%s",user.nickname);
		test=verifica_nickname(user.nickname);
	}while(test==TRUE);
	return user;
}

void scrivi_file(){
	utente user;
	FILE* q;
	user=inserimento();
	if((q=fopen(PATH_UTENTI,"a")) == NULL)
		puts("File non aperto");
	else{
		fprintf(q,"%s	%s	%s\n",user.nome,user.cognome,user.nickname);
	}
	fclose(q);
}

int verifica_nickname(char search[MAX]){
	utente user;
	FILE* q;
	int flag=FALSE ;
	if((q=fopen(PATH_UTENTI,"r")) == NULL)
		puts("File non aperto");
	else{
		while(!feof(q)){
	     fscanf(q,"%s	%s	%s",user.nome,user.cognome,user.nickname);
	     if(strcmp(search,user.nickname)==0){
	    	 flag = TRUE;
	     }
		}
        fclose(q);
	}
	return flag;
}

void richiesta_amicizia(){
	int verifica_nickname(char[]);
	FILE* q;
	int test = FALSE;
	char mittente[MAX],destinatario[MAX];
	puts("*** Richiesta di amicizia ***");
	do{
		printf("Nickname richiedente amicizia : ");
		scanf("%s",mittente);
        test=verifica_nickname(mittente);
	}while(!(test==TRUE));

	test = FALSE;
	do{
		printf("Nickname destinatario amicizia : ");
		scanf("%s",destinatario);
		test = verifica_nickname(destinatario);
	}while (!(test == TRUE));
	//////////////////
	if((q=fopen(PATH_AMICIZIE,"a")) == NULL)
		puts("File non aperto");
	else{
		fprintf(q,"%s	%s\n",mittente,destinatario);
		printf("%s e %s hanno stretto amicizia \n",mittente,destinatario);
	}
	fclose(q);
}

void like(){
	int not_amici(char[],char[]);
	FILE* q;
	int test = FALSE;
	char mittente[MAX],destinatario[MAX];
	puts("*** Metti un like :) ***");
	do
	{
		do
		{
			printf("Chi sei? (nickname) -- >  ");
			scanf("%s",mittente);
			test=verifica_nickname(mittente);
		}while(!(test == TRUE) );
		test=FALSE ;
        do
        {

        	printf("A chi vuoi mettere un like ? (nikcname) -- > ");
        	scanf("%s",destinatario);
        	test=verifica_nickname(destinatario);
        }while(!(test == TRUE));
        test=FALSE ;

		test=not_amici(mittente,destinatario);
	}while(test==TRUE);
	/////////
	if((q=fopen(PATH_LIKE,"a")) == NULL)
		puts("File non aperto");
	else{
		fprintf(q,"%s	%s\n",mittente,destinatario);
		printf("%s ha messo mi piace a %s  \n",mittente,destinatario);
	}
	fclose(q);
}

int not_amici(char search1[MAX], char search2[MAX]){
	FILE* q;
	int flag = FALSE ;
	char s1[MAX], s2[MAX];
	///////////
	if((q=fopen(PATH_AMICIZIE,"r")) == NULL)
		puts("File non aperto");
	else{
		while(!feof(q)){
	     fscanf(q,"%s	%s",s1,s2);
	     if((strcmp(search1,s1) == 0)  && (strcmp(search2,s2) == 0)){
	    	 flag = TRUE;
	     }
		}
    fclose(q);
	}
	return flag;
}
