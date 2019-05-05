#ifndef header_h
#define header_h

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX 20
#define SETT 7

typedef struct{
    char sett[SETT][MAX];
    float peso[SETT];
    float temperatura[SETT];
    char esame[SETT][MAX];
}paziente;


paziente acquisiz_pazienti();
void stampa(paziente);
float calcola_media(float[SETT]);
float calcola_max(float[SETT]);
float calcola_min(float[SETT]);
float deviazione_standard(float[SETT],float med);
void visualdati_giorno(paziente,char search[MAX]);
int esame_max(paziente,char[]);
void visual_giorni(paziente,char[]);

#endif /* header_h */
