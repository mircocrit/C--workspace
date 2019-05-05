/*prog in c che fornisc funzonalita:
 acqusir seq d in interi e memoriazzaròa in 1 file
 ordiniamo seq in maniera cresc e memoriziamo di un secondo file
 scriverre in 1 terzo file valori maggiori di uno detto da 1 utente*/

#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#define MAX 10

int main() {
    FILE *fp1=NULL,*fp2=NULL,*fp3=NULL;
    int vett[MAX],n,k=0,search;
    printf("Inserire numerosita elementi:   ");
    scanf("%d",&n);
    printf("\n");
    acquisizone(vett, n);
    mem_file(vett,n,fp1,&k);
    printf("\n");
    
    printf("Inizio ordinamento\n");
    inserction_sort(vett, n);
    printf("Scrivo vettore ordinato su file...\n");
    mem_file(vett,n,fp2,&k);
    printf("\n");
    
    printf("Inserire da tastiera l'elemento di cui cercarne i maggiori\n");
    scanf("%d",&search);
    ricerca_magg(vett,n,search,fp3,&k);
    printf("\n");
    
    printf("Stampa dei files\n");
    printf("File 1\n");
    fp1=fopen("file.txt","r+");
    leggi_file(fp1);
    printf("File 2\n");
    fp2=fopen("file2.txt","r+");
    leggi_file(fp2);
    printf("File 3\n");
    fp3=fopen("file3.txt","r+");
    leggi_file(fp3);
    return 0;
}
