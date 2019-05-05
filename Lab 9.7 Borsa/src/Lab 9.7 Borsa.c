/* Un file ASCII contiene l’elenco dei clienti di una banca che possiedono azioni.
Si suppone che esistano solo cinque aziende quotate in borsa e quindi ogni riga del file contiene sei numeri interi non negativi che sono, rispettivamente,
 il numero identicativo del cliente e la quantità posseduta di azioni delle cinque aziende quotate.
Si desidera scrivere un programma che:
1) legga i dati dei clienti da un file il cui nome è passato come primo argomento sulla riga di comando
2) esegua le azioni specificate dai successivi 5 argomenti sulla riga di comando, che rappresentano rispettivamente:
– il numero identicativo del cliente (1 . . . 10000)
– il numero identicativo dell’azienda (1 . . . 5)
– l’operazione da svolgere (A per acquisto, V per vendita, G per assegnazione gratuita)
– il numero di azioni coinvolte (se l’operazione è G allora il numero seguente è la percentuale di azioni assegnate gratuitamente al cliente in base a quante già possedute, in tutti gli altri casi è un numero assoluto di azioni)
– il nome di un file nel quale scrivere l’elenco dei clienti così modificato.

A titolo di esempio, si supponga che il file CLIENTI.TXT contenga i seguenti dati:
Se il programma (chiamato GESTIONE) venisse attivato nel modo seguente:
GESTIONE CLIENTI.TXT 97 1 A 50 CLIENTI2.TXT
allora il file CLIENTI2.TXT dovrebbe contenere i seguenti dati (a seguito dell’acquisto di 50 azioni della società n. 1 da parte del cliente n. 97):

Se invece il programma venisse attivato nel modo seguente:
GESTIONE CLIENTI.TXT 9 2 G 10 CLIENTI2.TXT
allora il file CLIENTI2.TXT dovrebbe contenere i seguenti dati (a seguito dell’assegnazione gratuita del 10% di azioni della società n. 2 al cliente n. 9):
23 0 0 100 200 0
9 0 110 0 200 0
97 0 0 10 94 0
È opzionale – ma fornisce punti aggiuntivi – considerare che se il numero del cliente è zero allora l’azione deve essere applicata a tutti i clienti.
 */

#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#define MAX_CLIENTI 20
#define MAX_ACTION 20

int main(){
	int n_clie=0,n_azio=0,i;
	action a[MAX_ACTION];
	cliente c[MAX_CLIENTI];

	n_clie=leggi_clienti(c);
	visual_clienti(c,n_clie);
	n_azio=leggi_azioni(a);
	visual_azioni(a,n_azio);
	for(i=0;i<n_azio;i++)
		elabora_azione(a[i],c,n_clie);
	printf("ORDINAMENTO PER ID:\n");
	selection_sort(c,n_clie);
	n_clie=elimina_campo(c,n_clie,"24");
	visual_clienti(c,n_clie);
	n_clie=rimuovi_duplicati(c,n_clie);
	visual_clienti(c,n_clie);
	//for(i=0;i<n_clie;i++)
		//scrivi_clienti(c[i]);

	system("pause");
	return 0;
}
