#include<stdio.h>
#include<string.h>

#define PATH_PARTITE "D:\\utente\\Documents\\eclipse-workspace\\mondiali\\partite.txt"
#define PATH_CLASSIFICA "D:\\utente\\Documents\\eclipse-workspace\\mondiali\\classifica.txt"
#define MAX 15
#define MAX_SQUADRE 30

typedef struct{
	char squadra_a[MAX];
	char squadra_b[MAX];
	int anno;
	int mese;
	int giorno;
	int ris_a;
	int ris_b;
	int codice;
}partita;

typedef struct{
	char nome[MAX];
	int punteggio;
	int partite_giocate;
}squadra;


int conta_record(){
	partita p;
	FILE* q;
	int i = 0;
	if((q=fopen(PATH_PARTITE,"r")) == NULL)
		puts("file non aperto");
	else{
		while(!feof(q)){
			fscanf(q,"%s %s %d %d %d %d %d %d",p.squadra_a,p.squadra_b,&p.anno,&p.mese,&p.giorno,&p.ris_a,&p.ris_b,&p.codice);
			i++;
		}
		fclose(q);
	}
	return i-1;
}

int leggi_file(partita p[],int dim){
	FILE* q;
	int i = 0;

	if((q=fopen(PATH_PARTITE,"r")) == NULL)
	  puts("File non aperto");
	else{
		while(!feof(q)){
			if(!feof(q)){
			fscanf(q,"%s %s %d %d %d %d %d %d",p[i].squadra_a,p[i].squadra_b,&p[i].anno,&p[i].mese,&p[i].giorno,&p[i].ris_a,&p[i].ris_b,&p[i].codice);
			i++;
			dim++;
			}
		}
		fclose(q);
	}
	return dim;
}

partita acquisizione_partita(){
	partita p;
	int conta_record();

	puts("*** Dati Partita ***");
	printf("Squadra di casa -- >  ");
	scanf("%s",p.squadra_a);
	printf("Squadra ospite -- >  ");
	scanf("%s",p.squadra_b);
	printf("Anno -- >  ");
	scanf("%d",&p.anno);
	printf("Mese -- >  ");
	scanf("%d",&p.mese);
	printf("Giorno -- >  ");
	scanf("%d",&p.giorno);
	printf("Punteggio squadra di casa -- >  ");
	scanf("%d",&p.ris_a);
	printf("Punteggio squadra ospite -- >  ");
	scanf("%d",&p.ris_b);
	p.codice = conta_record() + 1;
	return p;
}

void scrivi_file(partita p){
	FILE* q;
	if((q=fopen(PATH_PARTITE,"a")) == NULL)
		puts("file non aperto");
	else{
		fprintf(q,"%s %s %d %d %d %d %d %d\n",p.squadra_a,p.squadra_b,p.anno,p.mese,p.giorno,p.ris_a,p.ris_b,p.codice);
	}
	fclose(q);
}

void inserisci_squadre(partita p[], int dim, squadra s[MAX_SQUADRE]){
	void calcola_punteggio(squadra[],int , partita[], int);
	void stila_classifica(squadra[],int);
	void scrivi_file_classifica(squadra[],int);

	int i, j = 0, k = 0, cont = 0, duplicato = 0;
	//crez elenco squadre con duplicati
	for(i=0;i<dim-1;i++){
		strcpy(s[j].nome,p[i].squadra_a);
		j++;
		strcpy(s[j].nome,p[i].squadra_b);
		j++;
		cont += 2;
	}
	//rimoz duplicati
	for(i=0;i<cont;i++){
	    duplicato=0;
	 	for(j=0;j<i;j++){
	 	 if(strcmp(s[j].nome,s[i].nome) == 0 ){
		        duplicato=1;
		  }
	    }
		if(!duplicato){
		  	strcpy(s[k].nome,s[i].nome);
		  	k++;
		}
	 }
	calcola_punteggio(s,k,p,dim);
	stila_classifica(s,k);
	scrivi_file_classifica(s,k);
}

void calcola_punteggio(squadra s[],int dim1, partita p[], int dim2){
	int i , j ;

	for(i=0;i<dim1;i++){
		s[i].punteggio = 0;
		s[i].partite_giocate = 0;
	}

	for(i=0;i<dim2;i++){
		if(p[i].ris_a > p[i].ris_b){
			for(j=0;j<dim1;j++){
				if(strcmp(s[j].nome,p[i].squadra_a) == 0){
					s[j].punteggio += 3;
					s[j].partite_giocate++;}
			}

			for(j=0;j<dim1;j++){
				if(strcmp(s[j].nome,p[i].squadra_b) == 0)
					s[j].partite_giocate++;
			}
		}
		else if (p[i].ris_a < p[i].ris_b){
			for(j=0;j<dim1;j++){
				 if(strcmp(s[j].nome,p[i].squadra_b) == 0){
					s[j].punteggio += 3;
					s[j].partite_giocate++;}
			}
			for(j=0;j<dim1;j++){
				if(strcmp(s[j].nome,p[i].squadra_a) == 0)
					s[j].partite_giocate++;
			}
		}
		else{
			for(j=0;j<dim1;j++){
				 if(strcmp(s[j].nome,p[i].squadra_a) == 0){
					s[j].punteggio++;
					s[j].partite_giocate++;}
			}
			for(j=0;j<dim1;j++)
			{
				 if(strcmp(s[j].nome,p[i].squadra_b) == 0){
					s[j].punteggio++;
					s[j].partite_giocate++;}
			}

		}
	}
}

void stila_classifica(squadra s[],int dim){
	int i , j;
	int key,key3;
	char key2[MAX];

	for(i=1;i<dim;i++){
		key = s[i].punteggio;
		strcpy(key2,s[i].nome);
		key3= s[i].partite_giocate;

		j =i-1;
		while((j>=0)&& ((s[j].punteggio < key) || (s[j].punteggio==key && s[j].partite_giocate< key3))){
			s[j+1].punteggio = s[j].punteggio;
			strcpy(s[j+1].nome,s[j].nome);
			s[j+1].partite_giocate=s[j].partite_giocate;
			j=j-1;
		}
		s[j+1].punteggio = key;
		strcpy(s[j+1].nome,key2);
		s[j+1].partite_giocate=key3;
	}
}

void scrivi_file_classifica(squadra s[],int dim){
	FILE* q;
	int i ;
	if((q=fopen(PATH_CLASSIFICA,"w")) == NULL)
		puts("file non aperto");
	else{
		for(i=0;i<dim;i++){
			fprintf(q,"%s %d %d\n",s[i].nome,s[i].punteggio,s[i].partite_giocate);
		}
	}
	fclose(q);
}
