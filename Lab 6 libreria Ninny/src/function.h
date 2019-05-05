#ifndef FUNCTION_H_
#define FUNCTION_H_

#define MAX_CHAR 20
#define DATA 11

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

libro inserimento(void);
void scrivi_file_libro(libro[],int);
void prestito(libro[],int);
void scrivi_file_prestito(studente);
void restituzione();
int conteggio(char[]);

#endif /* FUNCTION_H_ */
