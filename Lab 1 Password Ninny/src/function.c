#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 20
#define N_UTENTI 2
#define PATH "D:\\C-workspace\\Lab 1 password ninny\\archivio.txt"

typedef struct{
    char nome[MAX_CHAR];
    char cognome[MAX_CHAR];
    char indirizzo[MAX_CHAR];
    char password[MAX_CHAR];
    char sicurezza[MAX_CHAR];
}utente;

utente inserimento(){
	int verifica_psw(char[]);
    utente u;
    printf("Nome: ");
    scanf("%s",u.nome);
    printf("Cognome: ");
    scanf("%s",u.cognome);
    printf("Indirizzo e-mail: ");
    scanf("%s",u.indirizzo);
    printf("Password: ");
    scanf("%s",u.password);

    switch(verifica_psw(u.password)){
        case 1:
        	strcpy(u.sicurezza,"bassa");
            break;
        case 2: strcpy(u.sicurezza,"media");
            break;
        case 3: strcpy(u.sicurezza,"alta");
            break;
    }
    printf("\n");
    return u;

}

int verifica_psw(char password[]){
    int lung=0,ris,i;
    int cont_digit=0;
    int cont_punt=0;

    lung=strlen(password);
    for(i=0;i<lung;i++){
        if (isdigit(password[i])==1){
            cont_digit++;
        }
        if (ispunct(password[i])==1){
            cont_punt++;
        }
    }
    if((cont_digit+cont_punt)<=2){
        ris=1;
    }else if((cont_digit+cont_punt)<=4){
        ris=2;
    }
    else ris=3;
    return ris;
}

void visual_utenti(utente u[]){
	printf("%-10s%-13s%-20s%-13s%-9s\n\n","Nome","Cognome","Indirizzo","Password","Protezione");
	for(int i=0;i<N_UTENTI;i++)
		printf("%-10s%-13s%-20s%-13s%-9s\n",u[i].nome,u[i].cognome,u[i].indirizzo,u[i].password,u[i].sicurezza);
	printf("\n");
}


void scrivi_file(utente u[]){
	FILE* q;
    int i=0;
    if((q=fopen(PATH,"ab"))==NULL)
    	puts("Errore apertura file");
    else{
        while(i<N_UTENTI){
            fwrite(&u[i],sizeof(utente),1,q);
            i++;
        }
        fclose(q);
    }
}

void leggi_file(utente u[]){
	FILE* q;
    int i=0;
    if((q=fopen(PATH,"rb"))==NULL)
    	puts("Errore apertura");
    else{
        while(!feof(q)){
            fseek(q,i*sizeof(utente),SEEK_SET);
            fread(&u[i],sizeof(utente),1,q);
            i++;
        }
        fclose(q);
    }
    printf("%d",i);
    //return i;
}
