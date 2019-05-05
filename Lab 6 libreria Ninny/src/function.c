#include<stdio.h>
#include<string.h>

#define MAX_CHAR 50
#define DATA 11
#define MAX_STUD 3

typedef struct{
    int codice;
    char autore[MAX_CHAR];
    char titolo[MAX_CHAR];
    int anno;
}libro;

typedef struct{
    int matricola;
    char data_inizio[DATA];
    char data_fine[DATA];
    char libro[MAX_CHAR];
}studente;

libro inserimento(){
    libro l;
    printf("Autore : ");
    scanf("%s",l.autore);
    printf("Titolo : ");
    gets(l.titolo);
    printf("Anno di pubblicazione : ");
    scanf("%d",&l.anno);
    return l;
}

void scrivi_file_libro(libro l[], int dim){
    FILE* p;
    int i;
    if((p=fopen("archivio.txt","ab+")) == NULL)
        puts("File non aperto");
    else{
        for(i=0;i<dim;i++){
            fseek(p,i*sizeof(i),SEEK_SET);
            fwrite(&l[i],sizeof(libro),1,p);
        }
        fclose(p);
    }
}

void prestito(libro l[], int dim){
    studente s;
    int i,trovato,p;
    char string[MAX_CHAR];
    void scrivi_file_prestito(studente);

    printf("Nome libro da chiedere in prestito : ");
    scanf("%s",string);

    for(i=0;i<dim;i++){
        if(strcmp(string,l[i].titolo) == 0){
            trovato = 1;
            p=i;
        }
        else puts("libro non trovato");
    }

    if(trovato == 1){
        printf("Matricola che ha chiesto il prestito : ");
        scanf("%d",&s.matricola);
        printf("Data inizio (aaaa/mm/gg) : ");
        scanf("%s",s.data_inizio);
        printf("Data fine (aaaa/mm/gg) : ");
        scanf("%s",s.data_fine);
        strcpy(s.libro,l[p].autore);
    }
    scrivi_file_prestito(s);

}

void scrivi_file_prestito(studente stud){
    FILE *p;
    if((p=fopen("prestiti.txt","ab+")) == NULL)
        puts("File non aperto");
    else    fwrite(&stud,sizeof(studente),1,p);

    fclose(p);
}

void restituzione(){
    FILE* p;
    int matr,i=0,conta=0,conta1=0;
    studente s[MAX_STUD];

    printf("Matricola che deve restituire un libro");
    scanf("%d",&matr);

    if((p=fopen("prestiti.txt","rb")) == NULL)
        puts("File non aperto");
    else{
        while(!feof(p)){
            fseek(p,i*sizeof(i),SEEK_SET);
            fread(&s[i],sizeof(studente),1,p);
            conta++;
            i++;
        }
        fclose(p);
    }

    for(i=0;i<conta;i++){
        if(matr == s[i].matricola){
            strcpy(s[i].data_inizio, "");
            strcpy(s[i].data_fine, "");
            strcpy(s[i].matricola, "");
            s[i].matricola = 0;
            conta1++;
        }
    }

    if((p=fopen("prestiti.txt","wb")) == NULL)
        puts("File non aperto");
    else
        for(i=0;i<conta-conta1;i++){
            fseek(p,i*sizeof(i),SEEK_SET);
            fwrite(&s[i],sizeof(studente),1,p);
        }
        fclose(p);
}

int conteggio(char* date){
    int conteggio=0;
    studente s;
    FILE* p;

    if((p=fopen("prestiti.txt","rb")) == NULL)
        puts("File non aperto");
    else{
        while(!feof(p)){
            int i=0;
            fseek(p,i*sizeof(i),SEEK_SET);
            fread(&s,sizeof(studente),1,p);
            if(strcmp(date,s.data_inizio) < 0 )
                conteggio++;
        }
        fclose(p);
    }
    return conteggio;
}
