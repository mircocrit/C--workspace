/*scrivere un programma in grado di:
 1-acquisire informazioni immesse da tastiera relative a 5 utenti, carateerizzati da nome ,cognome,indirizzo,password.
 Lo studente puo' scegliere liberamente come modellare l'utente
 2-calcolo sicurezza password ,eseguito come segue:
 Password poco sicura, numero di caratteri numerici e punteggiatura <=2
 Password medio sicura,numero di caratteri numerici e punteggiatura <=4 e >2
 Password sicura numero di caratteri numerici e punteggiatura
 3-scrivere su file e su righe consecutive la stringa "password"+"livello" composta da password immessa da ciascun utente e livello associato  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "function.h"

#define N_UTENTI 2
#define TRUE 1
#define FALSE 0

int main(){
    utente user[N_UTENTI],prova[N_UTENTI];
    int scelta,chiudi=FALSE,i=0;
    do{
        puts("0-Esci");
        puts("1-Inserimento utente");
        puts("2-Stampa archivio");
        printf("Scelta: ");

        scanf("%d",&scelta);
        switch(scelta){
            case 0:
            	chiudi=TRUE;
                break;
            case 1:
            	i=0;
                while(i<N_UTENTI){
                    user[i]=inserimento();
                    i++;
                }
                visual_utenti(user);
                scrivi_file(user);
                break;
            case 2:
            	leggi_file(prova);
            	visual_utenti(prova);
                break;
        }
    }while(scelta>0 && scelta<3 && chiudi==FALSE);
    system("pause");
    return 0;
}
