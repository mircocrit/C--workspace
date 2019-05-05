#ifndef FUNZIONI_H_
#define FUNZIONI_H_

#define MAX_CHAR 26

typedef struct{
	char string[MAX_CHAR];
}parola;

void leggi_file(char[]);
int leggi_stringhe(parola[]);
void output_testo(char[]);
int rimuovi_punteggiatura(char[]);
int tokenizza(parola[],char[]);
void output_token(parola[],int);
int parola_max_freq(parola[],int,char[]);
int elimina_stringa(parola[],int,char[]);
void scrivi_file(char[],int);
void visual_nomi(parola[],int);
void input_testo(char[]);

#endif /* FUNZIONI_H_ */
