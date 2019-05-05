/*Scrivere un programma in c che fornisca le seguenti funzonalita:
1) Acquisire una sequenza di parole(la cui dimensioen e scelta dall'utente) e memorizzarla in un file
2) Ordinare in modo crescente le parole e memorizzare l'ordine in un file
3) verificare la presenza di parole palindrome(anna,oro) e nel caso memorizzarle in un file
4) verificare la presenza di consonanti doppie (tt) e vocali doppie(ee) e nel caso memorizzarle in un file
5) visualizzare a console il contenuto del file
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"

#define PATH "D:\\eclipse-workspace\\Lab 8 Seq Parole\\parole.txt"
#define PATH_ORDINATE "D:\\eclipse-workspace\\Lab 8 Seq Parole\\parole_ordinate.txt"
#define PATH_PALINDROME "D:\\eclipse-workspace\\Lab 8 Seq Parole\\parole_palindrome.txt"
#define PATH_DOPPIE "D:\\eclipse-workspace\\Lab 8 Seq Parole\\parole_doppie.txt"

int main(){
    int scelta,chiudi=0,risp=0,dim,i=0,flag=0;
    parola stringa;
    parola parole[MAX];
    do{
    	printf("0-Esci\n");
    	printf("1-Inserire parola\n");
    	printf("2-Ordina le parole\n");
    	printf("3-Cerca le parole palindrome\n");
    	printf("4-Cerca doppie\n");
    	printf("5-Visualizza file\n");
    	printf("scelta -- >  ");
    	scanf("%d",&scelta);
    	switch(scelta){
    	case 0:
    		chiudi=TRUE;
    		break;
    	case 1:
    		do{
    			stringa=inserimento_parola();
    		    scrivi_parola(stringa.word,PATH);
    		    printf ("Altre?  1-si / 0-no -- >  ");
    		    scanf("%d",&risp);
    		}while(risp==TRUE);
    		dim=leggi_parole(parole,dim);
    		visual_parole(parole,dim);
    		break;
    	case 2:
    		dim=leggi_parole(parole,dim);
    		insertion_sort(parole,dim);
    		visual_parole(parole,dim);
    		for(i=0;i<dim;i++)
    			scrivi_parola(parole[i].word,PATH_ORDINATE);
    		break;
    	case 3:
    		dim=leggi_parole(parole,dim);
    		for(i=0;i<dim;i++){
    			parole[i].palindroma=palindroma(parole[i]);
    			scrivi_parola((char*)(parole[i].palindroma),PATH_PALINDROME);
    		}
    		break;
    	case 4:
    		dim=leggi_parole(parole,dim);
    		for(i=0;i<dim;i++)
    			flag=doppie(parole[i]);
    		break;
    	case 5:
    		dim=leggi_parole(parole,dim);
    		visual_parole(parole,dim);
    		break;
    	}
    }while(scelta>0 && scelta<=5 && chiudi==FALSE);
    system("pause");
	return 0;
}
