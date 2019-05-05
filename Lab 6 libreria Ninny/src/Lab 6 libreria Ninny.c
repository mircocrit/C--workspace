#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#define MAX_LIBRI 3

int main(){
    libro libri[MAX_LIBRI];
    int scelta,i=0,chiudi=0,count=0,risp;
    char data[11];

    do{
        puts("0-ESCI");
        puts("1-Inserisci libro");
        puts("2-Prestito libro");
        puts("3-Restituzione libro");
        puts("4-Conteggio libri");
        printf("scelta : ");
        scanf("%d",&scelta);
        switch(scelta){
            case 0:
                chiudi=1;
                break;
            case 1: do{
                libri[i]=inserimento();
                libri[i].codice = i;
                i++;
                count++;
                printf("Nuovo libro ? (1-si ; 0-no)");
                scanf("%d",&risp);
            }while(risp == 1);
                scrivi_file_libro(libri,count);
                break;

            case 2: prestito(libri,count);
                break;

            case 3: restituzione();
                break;

            case 4:
                printf("Inserire data (aaaa\\mm\\gg) : ");
                scanf("%s",data);
                printf("I libri ancora da restituire alla data %s sono %d",data,conteggio(data));
                break;
        }
    }while(scelta > 0 && scelta < 5 && chiudi == 0 );
    system("pause");
    return 0;
}


