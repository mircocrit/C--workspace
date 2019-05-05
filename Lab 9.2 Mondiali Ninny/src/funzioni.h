#ifndef FUNZIONI_H_
#define FUNZIONI_H_

#define MAX_PARTITE 15
#define MAX 10
#define MAX_SQUADRE 10

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
}squadra;

int conta_record();
int leggi_file(partita[],int);
partita acquisizione_partita();
void scrivi_file(partita);
void inserisci_squadre(partita[],int,squadra[]);
void calcola_punteggio(squadra[],int);
void stila_classifica(squadra[],int);
void scrivi_file_classifica(squadra[], int);

#endif /* FUNZIONI_H_ */
