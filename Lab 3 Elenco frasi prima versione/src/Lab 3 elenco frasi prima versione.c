/*Scrivere un programma che esegua:
 1) acquisizone testo da tasitera elenco di frasi, avente dimensone non definita (frase=insieme di parole, con parola=seq di caratteri diverso dallo spazio)
 2) identificare le prime 3 parole che compaiono con piu frequenza
 3) scrivere su file parole e conteggi del punto 2
 4) identificare i nomi (parole che iniziano con lett maiusc) e visualizzarli su console
 */

#include "header.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 40
#define MAX_S 40

int main(){
    int scelta,flag=0,num,i,n_tok,k=0,n;
    int max,max_2,max_3;
    char frasi[40][40];
    char *token[40];
    int counter[40];
    char word_max[40],word_max_2[40],word_max_3[40];
    FILE *p=NULL;

    do{
        printf("Menu\n");
        printf("0: Esci\n");
        printf("1: Acquisizone elenco di frasi e visualizzazione\n");
        printf("3: Visualizzazione prime 3 parole con occorrenze maggiori\n");
        printf("4: Scrittura prime 3 parole su file\n");
        printf("5: Visualizzazione nomi all'interno delle frasi\n");
        printf("Scelta: ");
        scanf("%d",&scelta);
        switch(scelta) {
            case 0:
                flag=1;
                break;
            case 1:
                printf("Inserire il numero di frasi\n");
                scanf("%d",&n);
                acqusizione_elenco(frasi,n);
                visualizzazione_elenco(frasi,n);
                break;
            case 2:
                for(i=0;i<n;i++)
                    n_tok=tokenizzatore(frasi[i],&token[i],n_tok);
                k=i+n_tok;  //n token + n frasi= limite
                contaoccorr(token,counter,k);
                max_3_occorr(token,counter,k,max,max_2,max_3,word_max,word_max_2,word_max_3);
                break;
            case 4:
                scrivi_file(p,word_max,max);
                scrivi_file(p,word_max_2,max_2);
                scrivi_file(p,word_max_3,max_3);
                printf("Scrittura completata\n");
                break;
            case 5:
                visual_nomi(token,n_tok,k);
                break;
        }
    }while(scelta>0 && scelta<6 && flag==0);
    system("pause");
    return 0;
}
