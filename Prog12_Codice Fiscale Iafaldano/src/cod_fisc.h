#ifndef COD_FISC_H_
#define COD_FISC_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STRLEN 100

int calcolaCognome(char[], char[], int);
int calcolaNome(char[], char[], int);
int calcolaMese(int, char[], int);
int calcolaGiorno(int, char, char[], int);
int calcolaComune(char[], char[], char[], int);
int calcolaControlChar(char[], int);
void getProv(char[], char[]);
void getComune(char[], char[]);
void toUpperCase(char stringa[]);
int vocale(char);
int convertiPari(char[], int);
int convertiDispari(char[], int);
char convertiUltimoCarattere(int);

#endif /* COD_FISC_H_ */
