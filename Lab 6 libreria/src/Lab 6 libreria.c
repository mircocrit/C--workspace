/*Scrivere un programma in C che fornisca funzionalità per la gestione di libri, offerte da menù:
1) inserimento di un nuovo libro da tastiera. Il libro è caratterizzato da
codice, autore, titolo, anno di pubblicazione.
2) il libro va memorizzato in un file, aggiornando l’elenco di libri già inseriti in precedenza.
 un libro ha una unica copia

3) prestito di un libro ad uno studente. Uno studente è caratterizzato da una matricola.
 i prestiti vanno memorizzati in un file.
 i prestiti sono associati alla data di prestito e alla data di restituzione.
4) restituzione di un libro da parte di uno studente (con rimozione dall’elenco prestito)
5) conteggio dei libri ancora in prestito (non consegnati) rispetto ad una data fornita in input.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"
#define RW "w+"
#define WRITE "w"
#define APPEND_PLUS "a+"

int main() {
    int flag=0,repeat=1,scelta,count=0,n_lib,n_stud;
    int ricerca;
    libro lib[MAX_LIB],libr;
    studente stud[MAX_STUD],work;
    data date;
    n_lib=lettura_libri(lib);
    visual_libri(lib,n_lib);
    n_stud=lettura_prestiti(stud);
    visual_prestiti(stud,n_stud);

    do{
        printf("Menu\n");
        printf("1: Visualizzazoni libri\n");
        printf("2: Visualizza prestiti\n");
        printf("3: Restituzione libro\n");
        printf("4: Conteggio libri\n");
        printf("5: Aggiunta libro\n");
        printf("6: Aggiunta prestiti\n");
        printf("scelta: ");
        scanf("%d",&scelta);
        switch(scelta){
            case 0:
                flag=1;
                break;
            case 1:
               	n_lib=lettura_libri(lib);
               	visual_libri(lib,n_lib);
               	break;
            case 2:
               	n_stud=lettura_prestiti(stud);
               	visual_prestiti(stud,n_stud);
                break;

            case 3:
            	if(n_stud==0)	printf("Prima acquisitre i prestiti\n");
            	else {
					//visual_prestiti(stud,n_stud);
					printf("Codice del libro da restituire:   ");
					scanf("%d",&ricerca);
					n_stud=elimina_campo(stud,n_stud,ricerca);
					visual_prestiti(stud,n_stud);
					scrittura_campi(stud,n_stud);
            	}
                break;

            case 4:
            	if(n_stud==0)	printf("Prima acquisitre i prestiti\n");
            	else{
					printf("Data dopo cui cercare libri: gg mm aa:	");
					scanf("%d %d %d",&date.giorno,&date.mese,&date.anno);
					count=conteggio(stud,n_stud,date);
					printf("N libri in prestito dopo data fornita in input: %d\n",count);
            	}
            	break;


            case 5:
            	n_lib=lettura_libri(lib);
                do{
                   libr=inserimento_libro(n_lib);
                   scrittura_libro(libr);
                   n_lib++;
                   printf("Ripetere? si=1, no=0:	");
                   scanf("%d",&repeat);
                 }while(repeat==1);

                 n_lib=lettura_libri(lib);
                 visual_libri(lib,n_lib);
                 break;
              case 6:
                  do{
            		work=inserimento_prestito();
            		scrittura_prestito(work);;
            		printf("Ripetere? si=1, no=0:	");
            		scanf("%d",&repeat);
                  }while(repeat==1);

                  n_stud=lettura_prestiti(stud);
                  visual_prestiti(stud,n_stud);
                  break;
        }
    }while(scelta>0 && scelta<7 && flag==0);
    system("pause");
    return 0;
}
