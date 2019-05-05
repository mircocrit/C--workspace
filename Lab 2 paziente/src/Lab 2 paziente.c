/*gestione stato paziente lun-dom
 Lo stato paziente in giorni della settimana e' memorizzato sul file
 Il paziente e' caratterizzato da: peso,temperatura,esame,esame da eseguire. :
 1) acquisizione file
 2) calcolo media, minimo, massimo, deviaz standard per peso e temp sui giorni della settimana
 3) visual peso, temperatura ed esame, dato in input il giorno della settimana
 4) visualizzaz dei giorni in cui e' ripetuto l'esame piu' frequente*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "header.h"

int main(){
    int scelta,flag=0,count;
    float med_peso,med_temp;
    paziente paz;
    char search[MAX];

    paz=acquisiz_pazienti();
    printf("%-10s%-7s%-9s%-13s\n","Settim","Peso","Temperat","Esame");
    stampa(paz);
    printf("\n");

    do{
		printf("Menu\n");
		printf("0: Esci\n");
		printf("1: Media peso e temperatura\n");
		printf("2: Minimo e massimo peso e temperatura\n");
		printf("3: Deviazione standard per peso e temperatura\n");
		printf("4: peso,temperatura ed esame, dato un giorno della settimana\n");
		printf("5: giorni in cui e' ripetuto esame piu frequente\n");
		printf("Scelta: ");
		scanf("%d",&scelta);
		system("CLS");
        switch(scelta){
            case 0:
                flag=1;
                break;
            case 1:
            	med_peso=calcola_media(paz.peso);
            	med_temp=calcola_media(paz.temperatura);
                printf("La media del peso del paziente e'  %.3f\n",med_peso);
                printf("La media delle temperature del paziente e'  %.3f\n",med_temp);
                break;
            case 2:
                printf("Il massimo del peso del paziente e' %f, il minimo e' %f\n",calcola_max(paz.peso),calcola_min(paz.peso));
                printf("Il massimo delle temperature del paziente e' %f, il minimo e' %f\n",calcola_max(paz.temperatura),calcola_min(paz.temperatura));
                break;
            case 3:
                printf("La deviazione standard dei valori di peso e' %f\n",deviazione_standard(paz.peso, med_peso));
                printf("La deviazione standard dei valori di temperatura e' %f\n",deviazione_standard(paz.temperatura, med_temp));
                break;
            case 4:
                printf("Inserire il giorno della settimana in cui visualizzare dati\n");
                scanf("%s",search);
                visualdati_giorno(paz,search);
                break;
            case 5:
            	count=esame_max(paz,search);
            	printf("L'esame piu frequente e' %s, fatto %d volte\n",search,count);
            	visual_giorni(paz,search);
                break;
        }
    }while(scelta>0 && scelta<6 && flag==0);
    system("pause");
    return 0;
}
