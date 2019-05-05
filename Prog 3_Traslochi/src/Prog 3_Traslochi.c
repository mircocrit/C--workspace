/*La ditta traslochi quick move intende creare una tabella per una efficiente gestione delle prenotazioni di traslochi
Per ogni trasloco il sistema deve memorizzare:
codice del trasloco,data,indirizzo di partenza,indirizzo di destinazione,codice della squadra di dipendenti coinvolti,tipo di automezzo necessario(furgone,camion,autoscala),ore di lavoro previste,costo totale
Progettare una soluzione al problema che consenta di:
1) Visualizzare tutti i traslochi previsti in una specifica data.
2) Poiche la ditta assegna un premio ai dipendenti che hano effettuato il maggior numero di traslochi, visualizzare il codice della squadra da premiare
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "trasl.h"

#define MAX 20
#define TRUE 1
#define FALSE 0

int main(){
	int scelta,chiudi=1;
	int i=0,n,repeat=FALSE;
	trasloco t[MAX];
    int cont[4]={0,0,0,0};
    char date[11];

    do{
    	printf("0-Esci\n");
    	printf("1-Acquisizone da file\n");
    	printf("2-Ricerca traslochi da fare in una specifica data\n");
    	printf("3-Ricerca squadra con maggior numero traslochi effettuati\n");
    	printf("4-Stampa tabella traslochi\n");
    	printf("5-Inserisci trasloco\n");
    	printf("Scelta ");
    	scanf("%d",&scelta);
    	switch(scelta){
    		case 0:
    			chiudi=0;
    		   break;
    		case 1:
   		 		n=lettura_file(t);
    			stampa(t,n);
    		    break;
    		case 2:
    			printf("Data da cercare: (gg/mm/aaaa):	");
    			scanf("%s",date);
    			ricerca_data(t,n,date);
    			break;
    		case 3:
    			conta_traslochi(t,n,cont);
    		   	ricerca_max(cont);
    		    break;
   		 	case 4:
   		 		stampa(t,n);
    			break;
   		 	case 5:
    			do{
    				t[i]=inserimento();
    				i++;
    				printf("Ripetere?	T=1, F=0	");
    				scanf("%d",&repeat);
    			}while(repeat==TRUE);
    			n=i;
    			break;
			}
   		 }while(scelta>=0 && scelta<6 && chiudi==1);
    system("pause");
	return 0;
	}
