#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 40
#define MAX_S 40
#define PATH "D:\\C-workspace\\Lab 3 elenco frasi prima versione\\text.txt"

void acqusizione_elenco(char string[40][40],int n){
    int i;
    for(i=0;i<n;i++){
        gets(string[i]);
    }
}

void visualizzazione_elenco(char string[40][40],int n){
    int i;
    for(i=0;i<n;i++){
        puts(string[i]);
    }
}

int tokenizzatore(char string[40],char *work[40],int i){
    work[i]=strtok(string," ");
    while(work[i]!= NULL){
        i++;
        work[i]=strtok(NULL," ");
    }
    return i-1;
}

void contaoccorr(char *parole[40],int counter[40],int k){
    int i,j;
    for(i=0;i<k;i++)
        for(j=0;j<k;j++)
            if(strcmp(parole[i],parole[j])==0)
                 counter[i]++;
    }

void max_3_occorr(char *parole[40],int counter[40],int k,int max,int max_2,int max_3, char word_max[40],char word_max_2[40],char word_max_3[40]){

    max=counter[0];
    int i;
    for(i=1;i<k;i++){
        if(counter[i]>max){
            max=counter[i];
            strcpy(word_max,parole[i]);
        }
    }
    printf("La parola con n max di occorr e' %s con %d occorr\n",word_max,max);

    max_2=counter[0];
    for(i=1;i<k;i++){
        if(counter[i]>max_2 && counter[i]!=max){
            max_2=counter[i];
            strcpy(word_max_2,parole[i]);
        }
    }
    printf("La parola con il secondo n max di occorr e' %s con %d occorr\n",word_max_2,max_2);

    max_3=counter[0];
    for(i=1;i<k;i++){
        if(counter[i]>max_3 && counter[i]!=max && counter[i]!=max_2){
            max_3=counter[i];
            strcpy(word_max_3,parole[i]);
        }
    }
    printf("La parola con il terzo n max di occorr e' %s con %d occorr\n",word_max_3,max_3);
}

void scrivi_file(FILE *p ,char str_max[40],int max){
    p=fopen(PATH, "a+");
    if(p==NULL)   printf("Errore\n");
    else{
        fprintf(p,"\n%s       %d",str_max,max);
        fclose(p);
    }
}

void visual_nomi(char *parole[40],int n_tok,int k){
    int i;
    for(i=0;i<k;i++){
        if(isupper(parole[i][0])==1)
            printf("%s\n",parole[i]);
    }
}
