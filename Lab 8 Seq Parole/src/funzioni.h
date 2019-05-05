#ifndef FUNZIONI_H_
#define FUNZIONI_H_

#define MAX 20
#define TRUE 1
#define FALSE 0
#define PATH "D:\\eclipse-workspace\\Lab 8 Seq Parole\\parole.txt"

typedef struct{
	char word[MAX];
	int palindroma;

}parola;

parola inserimento_parola();
void scrivi_parola(char[],char[]);
int leggi_parole(parola[],int);
void visual_parole(parola[],int);
void bubble_sort(parola p[],int);
void insertion_sort(parola[],int);
void selection_sort(parola p[],int);
void swap(parola*,parola*);
int palindroma(parola);
int doppie(parola);

#endif /* FUNZIONI_H_ */
