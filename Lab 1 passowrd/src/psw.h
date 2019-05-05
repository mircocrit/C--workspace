#ifndef psw_h
#define psw_h

typedef struct{
    char nome[15];
    char cognome[20];
    char email[30];
    char psw[26];
    char level[7];//0=poco sicura, 1=sicurezza media, 2=sicura
}user;

user inserimento(void);
void verifica(user);
void scrittura(user[5]);

#endif /* psw_h */


