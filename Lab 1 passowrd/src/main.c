/*
 Scrivere un programma in grado di:
 1) acquisire info immesse da tastiera relative a 5 utenti caratterizzati da nome, cognome indirizzo, password
    Lo studente puo scegliere liberamente come modellare un utente
 2) calcolo sicurezza password, eseguito come segue
    a)password poco sicura: numero di caratteri numerici e caratteri punteggiatura <=2
    b)password medio sicura: numero di caratteri numerici e caratteri punteggiatura <=4 e >=2
    c)Password sicura: numero di caratteri numerici e caratteri punteggiatura >4
 3) Scrivere su pile e su righe consecutive la stringa password + livello composta da password immessa da ciascun utente e livello associate
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "psw.h"

int main() {
    int flag=1;
    int i,s;
    user u[5];
    do{
    printf("menu\n");
    printf("1: inserimento\n");
    printf("2: verifica password\n");
    printf("3: scrittura su file\n");
    printf("inserire scelta:");
    printf("scelta: ");
    scanf("%d",&s);
    
    switch (s) {
        case 1:
            for(i=0;i<5;i++){
                u[i]=inserimento();
            }
            break;
            
        case 2:
            printf("verifica della password\n");
            for(i=0;i<5;i++){
                verifica(u[i]);
            }
            break;
        case 3:
            printf("scrittura su file\n");
            scrittura(u);
            break;
            
        default:
            flag=0;
            break;
        }
    }while (s>0 && s<4 && flag==1);
    return 0;
}

