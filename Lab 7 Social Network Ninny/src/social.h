
#ifndef SOCIAL_H_
#define SOCIAL_H_

#define MAX 20
#define MAX_AMICI 50

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

utente inserimento();
void scrivi_file();
int verifica_nickname(char[]);
void richiesta_amicizia();
void like();
int not_amici(char[],char[]);

#endif /* SOCIAL_H_ */
