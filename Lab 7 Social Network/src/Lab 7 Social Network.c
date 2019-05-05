/*Scrivere un programma in c che fornisca funzionalita per social network, offerte da menu:
 1) Iscrizione di un nuovo utente,descritto da:
  nome, cognome, nickname_lista di amici, lista utenti che hanno espresso un like:
  -i nickname sono univoci
  -tutti gli utenti dovranno essere memorizzati in un file
  -un utente puo avere massimo 5 amici e 10 like
2) Creare una relazione d'amicizia tra 2 utenti forniti in input
-tutte le relazioni di amicizia dovranno essere memorizzate in un secondo file
3) Mettere like da un utente ad un altro, entrambi dati in input, se questi non sono gia amici
-tutti i like dovranno essere memorizzati in un terzo file
4) Visualizzare il contenuto dei 3 file
 */

#include <stdio.h>
#include <stdlib.h>
#include "social.h"

#define TRUE 1
#define FALSE 0
#define MAX 20
#define MAX_AMICI 3
#define MAX_LIKES 3

int main() {
	int scelta,chiudi=FALSE,dim,flag=0,num_amiciz,num_likes;
	int test=1;
	char mittente[MAX]={},destinatario[MAX]={},user1[MAX],user2[MAX];
	utente user[MAX],work;
	amicizia a[MAX];
	likes l[MAX];
	dim=leggi_utenti(user);
	visual_utenti(user,dim);
	do{
		printf("0-Esci\n");
		printf("1-Richiesta amicizia fra utenti(max %d amici)\n",MAX_AMICI);
		printf("2-Aggiunta like fra utenti non amici(max %d likes)\n",MAX_LIKES);
		printf("3-Visualizzazione utenti\n");
		printf("4-Visualizzazione amicizie\n");
		printf("5-Visualizzazione likes\n");
		printf("5-Iscrizione utente\n");
		printf("Scelta:	");
		scanf("%d",&scelta);
		switch(scelta){
			case 0:
				chiudi=TRUE;
				break;

			case 1://AMICIZIA
				num_amiciz=leggi_amicizie(a);
				visual_amicizie(a,num_amiciz);
				test=FALSE;
				printf("Mittente-->	");
				inserim_utenti_a(user,dim,a,num_amiciz,mittente);
				printf("Destinatario-->	");
				inserim_utenti_a(user,dim,a,num_amiciz,destinatario);
				scrivi_amicizie(mittente,destinatario);
				printf("%s e %s hanno stretto amicizia.\n",mittente,destinatario);
				break;

			case 2://LIKE
				if(dim==0)
					printf("Errore, no utenti nel social netwotk\n");
				else{
					inserim_utenti_l(user,dim,l,num_likes,user1);
					do{
						num_likes=leggi_likes(l);
						test=FALSE;
						printf("Utente 1--->	");
						inserim_utenti_l(user,dim,l,num_likes,user1);
						printf("Utente 2--->	");
						inserim_utenti_l(user,dim,l,num_likes,user2);
						num_amiciz=leggi_amicizie(a);
						test=controlla_amici(user1,user2,a,num_amiciz);
					}while(test==TRUE);//esco per false, cioe se non sono amici
					scrivi_like(user1,user2);
					printf("%s ha messo mi piace a %s \n",user1,user2);
					}
				break;
			case 3:
				dim=leggi_utenti(user);
				visual_utenti(user,dim);
				break;
			case 4:
				num_amiciz=leggi_amicizie(a);
				visual_amicizie(a,num_amiciz);
				break;
			case 5:
				do{
					work=inserimento(user,dim);
					scrivi_utente(work);
					printf("Ripetere? 0=no 1=si\n");
					scanf("%d",&flag);
				}while(flag==1);
				dim=leggi_utenti(user);

				break;
		}
	}while(scelta>0 && scelta<=4 && chiudi==FALSE);
	system("pause");
	return 0;
}
