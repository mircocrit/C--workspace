#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PATH_RISULTATI "D:\\C-workspace\\Lab 9.8 Squadre\\Debug\\risultati.txt"
#define PATH_CLASSIFICA "D:\\C-workspace\\Lab 9.8 Squadre\\Debug\\classifica.txt"
#define MAX_CHAR 12
#define WIN 3
#define DRAW 1
#define LOSE 0

typedef struct{
	int id;
	char nome[MAX_CHAR];
}squadra;

typedef struct{
	int ris1;
	int ris2;
	char squadra1[MAX_CHAR];
	char squadra2[MAX_CHAR];
}partita;

typedef struct{
	int posizione;
	char squadra[MAX_CHAR];
	int punti;
	int partite_giocate;
	int vinte;
	int pareggiate;
	int perse;
	int gol_fatti;
	int gol_subiti;
	int differenza_reti;
}classifica;

int leggi_partite(partita p[]){
	FILE* fp;
	int i=0;
	fp=fopen(PATH_RISULTATI,"r");
	if(p==NULL)
		printf("Errore,path errato\n");
	else{
		while(!feof(fp)){
			fscanf(fp,"%d-%d	%s %s\n",&p[i].ris1,&p[i].ris2,p[i].squadra1,p[i].squadra2);
			i++;
		}
		fclose(fp);
	}
	return i;
}


void visual_partite(partita p[],int dim){
	printf("%-14s%-14s%-5s%-5s\n\n","Squadra1","Squadra2","Punt1","Punt2");
	for(int i=0;i<dim;i++)
		printf("%-14s%-14s%-5d%-5d\n",p[i].squadra1,p[i].squadra2,p[i].ris1,p[i].ris2);
	printf("\n");
}


int creaz_array_squadre(partita p[],int n_part,squadra s[]){
	int rimozione_duplicati(squadra[],int);
	int i,j=0,k=0,flag=0;
	strcpy(s[0].nome,p[0].squadra1);
	strcpy(s[1].nome,p[0].squadra2);
	k=2;
	for(i=1;i<n_part;i++){
		for(j=0;j<k;j++){
			flag=0;
			if(strcmp(s[j].nome,p[i].squadra1)==0){
				flag=1;
			}
			if(flag==0){
				k++;
				strcpy(s[k].nome,p[i].squadra1);
			}
			flag=0;
			if(strcmp(s[j].nome,p[i].squadra2)==0){
				flag=1;
			}
			if(flag==0){
				k++;
				strcpy(s[k].nome,p[i].squadra2);
				}
		}
	}
	printf("%d",k);
	/*for(i=0;i<n_sq;i++){
		s[i].id=0;
	}*/
	return k;
}

int rimozione_duplicati(squadra s[],int dim){
	void copy(squadra*,squadra);
	int i,j=0,k=0,dup=0;
	for(i=0;i<dim;i++){
	    dup=0;
	 	for(j=0;j<i;j++){
	 		if(strcmp(s[j].nome,s[i].nome)==0){
	 			dup=1;
		  }
	    }
		if(!dup){
		  	copy(&s[k],s[i]);
		  	k++;
		}
	 }
	return k;
}

void copy(squadra *s1,squadra s2){
	*s1=s2;
}

void crea_classifica(squadra s[],int dim,classifica c[]){
	for(int i=0;i<dim;i++){
		strcpy(c[i].squadra,s[i].nome);
		c[i].posizione=s[i].id;
		c[i].punti=0;
		c[i].vinte=0;
		c[i].partite_giocate=0;
		c[i].pareggiate=0;
		c[i].perse=0;
		c[i].gol_fatti=0;
		c[i].gol_subiti=0;
	}
}

void visual_classifica(classifica c[],int dim){
	printf("%-6s%-14s%-8s%-8s%-8s%-9s%-8s%-8s%-8s%-8s\n","Pos","Squadra","N part","Punti","Vinte","Pareggi","Perse","Fatti","Subiti","Diff Reti");
	for(int i=0;i<dim;i++)
		printf("%-6d%-14s%-8d%-8d%-8d%-9d%-8d%-8d%-8d%-8d\n",i+1,c[i].squadra,c[i].partite_giocate,c[i].punti,c[i].vinte,c[i].pareggiate,c[i].perse,c[i].gol_fatti,c[i].gol_subiti,c[i].differenza_reti);
	printf("\n");
}

void calcola_classifica(squadra s[],int num_sq,partita p[],int num_part,classifica c[]){
	void assegna_punti(classifica[],int,char[],int,int,int);
		int i;
		for(i=0;i<num_part;i++){
			if(p[i].ris1>p[i].ris2){
				assegna_punti(c,num_sq,p[i].squadra1,WIN,p[i].ris1,p[i].ris2);
				assegna_punti(c,num_sq,p[i].squadra2,LOSE,p[i].ris2,p[i].ris1);
			}
			else if(p[i].ris1<p[i].ris2){
				assegna_punti(c,num_sq,p[i].squadra1,LOSE,p[i].ris1,p[i].ris2);
				assegna_punti(c,num_sq,p[i].squadra2,WIN,p[i].ris2,p[i].ris1);
				}
			else{
				assegna_punti(c,num_sq,p[i].squadra1,DRAW,p[i].ris1,p[i].ris2);
				assegna_punti(c,num_sq,p[i].squadra2,DRAW,p[i].ris2,p[i].ris1);
				}
		}
		for(int i=0;i<num_sq;i++){
			c[i].differenza_reti=(c[i].gol_fatti-c[i].gol_subiti);
		}

}

void assegna_punti(classifica c[],int num_sq,char team[],int value,int gol_fatti,int gol_subiti){		//winner =+3, loser=+0; draw=+1;
	for(int i=0;i<num_sq;i++){
		if(strcmp(c[i].squadra,team)==0){
			c[i].punti+=value;
			c[i].partite_giocate++;
			c[i].gol_fatti+=gol_fatti;
			c[i].gol_subiti+=gol_subiti;
			if(value==0)		c[i].perse++;
			else if(value==3)	c[i].vinte++;
			else 				c[i].pareggiate++;
				}
		}
}

void insertion_sort(classifica c[],int dim){
	void copy_field(classifica *,classifica);
	int i,j;
	classifica key;
	for(i=1;i<dim;i++){
		copy_field(&key,c[i]),
		j=i-1;
		while((j>=0)&& (c[j].punti<key.punti ||	((c[j].punti==key.punti )&&(c[j].differenza_reti<key.differenza_reti)))){
			copy_field(&c[j+1],c[j]);
			j=j-1;
		}
		copy_field(&c[j+1],key);
	}
}

void copy_field(classifica *s1,classifica s2){
	*s1=s2;
}

void scrivi_classifica(classifica c[],int dim){
	FILE* p;
	int i=0;
	p=fopen(PATH_CLASSIFICA,"w");
	if(p==NULL)
		printf("Errore,path errato\n");
	else{
		fprintf(p,"%-6s%-14s%-8s%-8s%-8s%-9s%-8s%-8s%-8s%-8s\n","Pos","Squadra","N part","Punti","Vinte","Pareggi","Perse","Gol fatti","Gol sub","Diff reti");
		for(i=0;i<dim;i++)
			fprintf(p,"%-6d%-14s%-8d%-8d%-8d%-9d%-8d%-8d%-8d%-8d\n",i+1,c[i].squadra,c[i].partite_giocate,c[i].punti,c[i].vinte,c[i].pareggiate,c[i].perse,c[i].gol_fatti,c[i].gol_subiti,c[i].differenza_reti);
		fclose(p);
	}
}
