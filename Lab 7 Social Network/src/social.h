#ifndef SOCIAL_H_
#define SOCIAL_H_

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

int leggi_utenti(utente[]);
int presenza_nickname(utente[],int dim,char[]);
void visual_utenti(utente[],int);
void scrivi_utente(utente);
void inserim_utenti_a(utente[],int,amicizia[],int,char[]);
void inserim_nickname_pres(utente[],int,char[]);
int limite_amici(amicizia[],int,char[]);
void scrivi_amicizie(char[],char[]);
int leggi_amicizie(amicizia[]);
int controlla_amici(char[],char[],amicizia[],int);
void inserim_utenti_l(utente[],int,likes[],int,char[]);
int limite_likes(likes[],int,char[]);
void scrivi_like(char[],char[]);
void visual_amicizie(amicizia[],int);
int leggi_likes(likes[]);
void visual_likes(likes[],int);
utente inserimento(utente[],int);

#endif /* SOCIAL_H_ */
