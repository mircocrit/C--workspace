
#ifndef HEADER_H_
#define HEADER_H_
#define MAX_CHAR 50
#define N_MOV 10

typedef struct{
	int data;//1 366
	float importo;
	char motivazione[MAX_CHAR];
}entrata;

typedef struct{
	int data;//1 366
	float importo;
	char motivazione[MAX_CHAR];
}uscita;

typedef struct{
	char tipo;
	float importo;
	char motivazione[MAX_CHAR];
}movimento;

typedef struct{
	int data;
	movimento m[N_MOV];
}data_odierna;

int leggi_entrate(entrata[]);
int leggi_uscite(uscita[]);
void visual_entrate(entrata[],int);
void visual_uscite(uscita[],int);
int leggi_spesa(data_odierna*);
void visual_data(data_odierna,int);
void aggiorna_dati(data_odierna,int);
void scrivi_uscita(int,float,char[]);
void scrivi_entrata(int,float,char[]);
float calcola_saldo(entrata[],int,uscita[],int);

#endif /* HEADER_H_ */
