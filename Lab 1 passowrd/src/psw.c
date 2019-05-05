#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char nome[15];
    char cognome[20];
    char email[30];
    char psw[26];
    char level[7];//0=poco sicura, 1=sicurezza media, 2=sicura
}user;

user inserimeto(){
    user u;
    printf("inserire nome utente\n");
    scanf("%s",u.nome);
    printf("inserire cognome utente\n");
    scanf("%s",u.cognome);
    printf("inserire email\n");
    scanf("%s",u.email);
    printf("inserire password\n");
    scanf("%s",u.psw);
    return u;
}

void verifica(user u){
    int j,dig=0,punct=0;
    for(j=0;j<strlen(u.psw);j++){
        if(isalpha(u.psw[j])!=0){
            if(isdigit(u.psw[j])==0)    dig++;
            else punct++;
        }
        
        if(dig<=2 || punct<=2){
            strcpy(u.level,"low");
            printf("la password inserita e' poco sicura\n");
        }
        else if(dig<=4 || punct<=4){
            strcpy(u.level,"medium");
            printf("la password inserita e' di media sicurezza\n");}
        else{ strcpy(u.level,"high");
            printf("la password e' sicura\n");
        }
    }
}

void scrittura(user u[5]){
    FILE *p;
    if((p=fopen("/Users/mircocrit/Desktop/codice_ex/text.txt","w+"))==NULL)
        puts("Errore apertura\n");
    else{
        puts("File aperto\n");
        for(int i=0;i<5;i++){
            fprintf(p,"%s %s ",u[i].psw,u[i].level);
        }
    }
    fclose(p);
}


