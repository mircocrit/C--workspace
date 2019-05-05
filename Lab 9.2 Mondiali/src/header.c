#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
#define NUM_SQUADRE 32
#define PATH  "D:\\C-workspace\\Lab 9.2 Mondiali\\partite.txt"
#define PATH_CLASSIFICA "D:\\C-workspace\\Lab 9.2 Mondiali\\classifica.txt"

typedef struct{
	char nome[MAX];
	int punteggio;
	int partite_giocate;
}squadra;

typedef struct{
	char squadraA[MAX];
	char squadraB[MAX];
	int giorno;
	int mese;
	int anno;
	int risA;
	int risB;
	int id;
}partita;

int leggi_file(partita p[MAX]){
	FILE *fp;
	int i=0;
	fp=fopen(PATH,"r");
	if(fp==NULL)	printf("Errore\n");
	else{
		while(!feof(fp)){
			fscanf(fp,"%s %s %d %d %d %d %d %d",p[i].squadraA,p[i].squadraB,&p[i].giorno,&p[i].mese,&p[i].anno,&p[i].risA,&p[i].risB,&p[i].id);
			i++;
		}
		fclose(fp);
	}
	return i;
}

void visual_squadre(partita p[],int dim){
	printf("%-15s%-15s%-9s%-9s%-9s%-5s%-5s%-5s\n","Squadra A","Squadra_B","Giorno"," Mese","Anno","RisA","RisB","Id");
	for(int i=0;i<dim;i++)
		printf("%-15s%-15s%-9d%-9d%-9d%-5d%-5d%-5d\n",p[i].squadraA,p[i].squadraB,p[i].giorno,p[i].mese,p[i].anno,p[i].risA,p[i].risB,p[i].id);
}

partita acquisiz_partita(int dim){
	partita p;
	printf("Acquisizione squadra:\n");
	printf("Squadra in casa  ");
	scanf("%s",p.squadraA);
	printf("Squadra ospite  ");
	scanf("%s",p.squadraB);
	printf("Giorno   ");
	scanf("%d",&p.giorno);
	printf("Mese   ");
	scanf("%d",&p.mese);
	printf("Anno   ");
	scanf("%d",&p.anno);
	printf("Punteggio sq casa");
	scanf("%d",&p.risA);
	printf("Puteggio sq trasferta  ");
	scanf("%d",&p.risB);
	p.id=dim+1;
	return p;
}

void scrivi_file(partita p){
	FILE *fp;
	fp=fopen(PATH,"a+");
	if(fp==NULL)	printf("Errore\n");
	else{
		fprintf(fp,"%s %s %d %d %d %d %d %d",p.squadraA,p.squadraB,p.giorno,p.mese,p.anno,p.risA,p.risB,p.id);
		printf("File scritto\n");
		fclose(fp);
	}
}

int creaz_array_squadre(partita p[],int dim,squadra s[]){
	int i,j=0,cont=0;
	for(i=0;i<dim-1;i++){
		strcpy(s[j].nome,p[i].squadraA);
		j++;
		strcpy(s[j].nome,p[i].squadraB);
		j++;
		cont+= 2;
	for(i=0;i<cont;i++){
		s[i].punteggio=0;
		s[i].partite_giocate=0;
		}
	}
	return cont;
}

int rimozione_duplicati(squadra s[],int dim){
	int i,j=0,k=0,dup=0;
	for(i=0;i<dim;i++){
	    dup=0;
	 	for(j=0;j<i;j++){
	 		if(strcmp(s[j].nome,s[i].nome)==0){
	 			dup=1;
		  }
	    }
		if(!dup){
		  	strcpy(s[k].nome,s[i].nome);
		  	k++;
		}
	 }
	return k;
}

void calcola_punteggio(squadra s[],int dim_sq,partita p[], int dim_par){
	void result(squadra[],int,char[],int value);
	int i;
	for(i=0;i<dim_par;i++){
		if(p[i].risA>p[i].risB){
			assegna_punti(s,dim_sq,p[i].squadraA,3);
			assegna_punti(s,dim_sq,p[i].squadraB,0);
		}
		else if(p[i].risA<p[i].risB){
			assegna_punti(s,dim_sq,p[i].squadraA,0);
			assegna_punti(s,dim_sq,p[i].squadraB,3);
			}
		else{
			assegna_punti(s,dim_sq,p[i].squadraA,1);
			assegna_punti(s,dim_sq,p[i].squadraB,1);
		}
	}
}

void assegna_punti(squadra s[],int dim,char team[],int value){		//winner =+3, loser=+0; draw=+1;
	for(int i=0;i<dim;i++){
		if(strcmp(s[i].nome,team)==0){
			s[i].punteggio+=value;
			s[i].partite_giocate++;
		}
	}
}

void insertion_sort(squadra s[],int dim){
	void copy_field(squadra *,squadra);
	int i,j;
	squadra key;
	for(i=1;i<dim;i++){
		copy_field(&key,s[i]),
		j=i-1;
		while((j>=0)&& ((s[j].punteggio<key.punteggio)||((s[j].punteggio==key.punteggio) && (s[j].partite_giocate<key.partite_giocate)))){
			copy_field(&s[j+1],s[j]);
			j=j-1;
		}
		copy_field(&s[j+1],key);
	}
}

void copy_field(squadra *s1,squadra s2){
	*s1=s2;
}
void visual_classifica(squadra s[],int dim){
	printf("%-15s%-6s%-5s\n","Nome","Punti","N_Part.");
	for(int i=0;i<dim;i++)
		printf("%-15s%-6d%-5d\n",s[i].nome,s[i].punteggio,s[i].partite_giocate);
}

void scrivi_file_classifica(squadra s[],int dim){
	FILE* q;
	int i;
	if((q=fopen(PATH_CLASSIFICA,"w")) == NULL)
		puts("File non aperto");
	else{
		for(i=0;i<dim;i++){
			fprintf(q,"%s %d %d\n",s[i].nome,s[i].punteggio,s[i].partite_giocate);
		}
	}
	fclose(q);
}

