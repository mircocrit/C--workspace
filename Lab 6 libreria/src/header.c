#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX_CHAR 20
#define BASE 20
#define MAX_LIB 20
#define MAX_STUD 20
#define PATH1 "D:\\C-workspace\\Lab 6 Libreria\\libri.txt"
#define PATH2 "D:\\C-workspace\\Lab 6 Libreria\\prestiti.txt"

typedef struct{
	int giorno;
	int mese;
	int anno;
}data;

typedef struct{
    int codice;
    char autore[MAX_CHAR];
    char titolo[MAX_CHAR];
    int anno;
}libro;

typedef struct{
    int matricola;
    int cod_libro;
    data data_prest;
    data data_restit;
}studente;

int lettura_libri(libro lib[]){
	FILE *p;
	int i=0;
	p=fopen(PATH1,"r");
	if(p==NULL)
		printf("Errore apertura\n");
	else{
		while(!feof(p)){
			fscanf(p,"%s %s %d %d",lib[i].autore,lib[i].titolo,&lib[i].anno,&lib[i].codice);
			i++;
		}
		fclose(p);
	}
	return i-1;
 }

void visual_libri(libro lib[],int dim){
	printf("Libri\n");
	printf("%-15s%-20s%-13s%-11s\n","Autore","Titolo","Anno","Codice");
	for(int i=0;i<dim;i++)
		printf("%-15s%-20s%-13d%-11d\n",lib[i].autore,lib[i].titolo,lib[i].anno,lib[i].codice);
	printf("\n");
}

libro inserimento_libro(int n_lib){
	 libro lib;
	 printf("Autore:    ");
	 scanf("%s",lib.autore);
	 printf("Titolo   ");
	 scanf("%s",lib.titolo);
	 printf("Anno ");
	 scanf("%d",&lib.anno);
	 lib.codice=n_lib+1;
	 printf("\n");
	 return lib;
}

void scrittura_libro(libro lib){
	FILE* p;
    p=fopen(PATH1,"a+");
    if(p==NULL) 	 printf("Errore apertura\n");
    else{
    	fprintf(p,"%s %s %d %d\n",lib.autore,lib.titolo,lib.anno,lib.codice);
    	fclose(p);
    }
}

int lettura_prestiti(studente stud[]){
	FILE* p=NULL;
	int i=0;
	p=fopen(PATH2,"r");
	if(p==NULL)
		printf("Errore apertura\n");
	else{
		while(!feof(p)){
			fscanf(p,"%d %d %d %d %d %d %d %d\n",&stud[i].matricola,&stud[i].cod_libro,&stud[i].data_prest.giorno,&stud[i].data_prest.mese,&stud[i].data_prest.anno,&stud[i].data_restit.giorno,&stud[i].data_restit.mese,&stud[i].data_restit.anno);
			i++;
		}
		fclose(p);
	}
	return i;
 }

void inserimento_prestito(){
    studente stud;
    printf("Matricola studente a cui prestare libro:	");
    scanf("%d",&stud.matricola);
    printf("Codice libro da prestare:	");
    scanf("%d",&stud.cod_libro);
    printf("Data prestito libro:\n");
    printf("Anno:	");
    scanf("%d",&stud.data_prest.anno);
    printf("Mese:	");
    scanf("%d",&stud.data_prest.mese);
    printf("Giorno:	");
    scanf("%d",&stud.data_prest.giorno);
    printf("Data restituzione libro:\n");
    printf("Anno:	");
    scanf("%d",&stud.data_restit.anno);
    printf("Mese:	");
    scanf("%d",&stud.data_restit.mese);
    printf("Giorno:	");
    scanf("%d",&stud.data_restit.giorno);
}

void scrittura_prestito(studente stud){
	FILE* p;
    p=fopen(PATH2,"a+");
    if(p==NULL)
    	printf("Errore apertura\n");
    else{
    	fprintf(p,"%d %d %d %d %d %d %d %d\n",stud.matricola,stud.cod_libro,stud.data_prest.giorno,stud.data_prest.mese,stud.data_prest.anno,stud.data_restit.giorno,stud.data_restit.mese,stud.data_restit.anno);
    	fclose(p);
    }
}

void visual_prestiti(studente stud[],int dim){
	printf("Prestiti\n");
	printf("%-11s%-11s%-17s%-17s\n","Matricola","Cod_libro","Data Prestito","Data Restituzione");
	for(int i=0;i<dim;i++){
		printf("%-11d%-11d%-4d%-4d%-9d%-4d%-4d%-9d\n",stud[i].matricola,stud[i].cod_libro,stud[i].data_prest.giorno,stud[i].data_prest.mese,stud[i].data_prest.anno,stud[i].data_restit.giorno,stud[i].data_restit.mese,stud[i].data_restit.anno);
	}
	printf("\n");
}

int elimina_campo(studente stud[],int dim,int code){
	void copy_field(studente*, studente);
	int i,k=0;
	for(i=0;i<dim;i++){
	  if(stud[i].cod_libro!=code){
		  copy_field(&stud[k],stud[i]);
		  k++;
	  }
	}
	return k;
}


void scrittura_campi(studente stud[],int dim){
	FILE* p;
    p=fopen(PATH2,"w");
    if(p==NULL)
    	printf("Errore apertura\n");
    else{
    	for(int i=0;i<dim;i++)
    		fprintf(p,"%d %d %d %d %d %d %d %d\n",stud[i].matricola,stud[i].cod_libro,stud[i].data_prest.giorno,stud[i].data_prest.mese,stud[i].data_prest.anno,stud[i].data_restit.giorno,stud[i].data_restit.mese,stud[i].data_restit.anno);
    	fclose(p);
    }
}


void copy_field(studente* s1, studente s2){
	*s1=s2;
	/*s1->cod_libro=s2.cod_libro;
	s1->matricola=s2.matricola;
	s1->data_prest=s2.data_prest;
	s1->data_restit=s2.data_restit;*/
}

int conteggio(studente stud[],int n,data data_max){
	int data_to_int(data);
    int count=0;
    int work=data_to_int(data_max);

    for(int i=0;i<n;i++){
    	if((data_to_int(stud[i].data_restit))>work)
    		count++;
        }
    return count;
}

int data_to_int(data date){
	return (date.giorno+(100*date.mese)+(10000*date.anno));
}
