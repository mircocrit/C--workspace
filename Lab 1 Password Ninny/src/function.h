#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 20
#define MAX 2

typedef struct{
    char nome[MAX_CHAR];
    char cognome[MAX_CHAR];
    char indirizzo[MAX_CHAR];
    char password[MAX_CHAR];
    char sicurezza[MAX_CHAR];
}utente;

utente inserimento();
void visual_utenti(utente[]);
void scrivi_file(utente[]);
int verifica_psw(char[]);
void leggi_file(utente[]);

