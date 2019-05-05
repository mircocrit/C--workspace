/*
Uno sportivo vuole seguire gli eventi delle olimpiadi invernali di Torino 2006.
Poich� molte gare si svolgono in parallelo, lo sportivo ha il problema di riuscire a selezionare il maggior numero possibile di gare di suo interesse.
L�elenco di tutte le gare � contenuto in un file di testo, in cui le gare sono indicate una per riga, in ordine casuale, nel formato (che si pu� supporre privo di errori, e composto al
massimo da 100 righe):
		giorno tipo_gara finale
dove:
� giorno � il giorno in cui si svolge la gara (un numero intero compreso tra 10 e 26, poich� mese ed anno sono sottintesi)//dic 2006
� tipo_gara � la disciplina che viene disputata, rappresentata come stringa priva di spazi lunga al massimo 50 caratteri (esempio: slalom_gigante, pattinaggio_artistico,...).
 � ovviamente possibile che lo stesso tipo_gara compaia pi� volte (molte gare impiegano diversi giorni)
� finale � un intero (con significato Booleano) che indica se la gara � una finale (valore pari a 1) oppure una gara eliminatoria (valore pari a 0)

Il programma riceve come primo argomento sulla linea di comando il nome del file contenente il calendario delle gare e deve produrre in output un elenco in cui, per ogni giorno
(in ordine da 10 e 26), si suggerisca all�utente quale disciplina guardare in TV.
La disciplina suggerita deve essere scelta secondo le seguenti regole:

1. se in un determinato giorno vi � una sola disciplina, indicare quelle
2. se in un determinato giorno vi sono due o pi� discipline in parallelo, ne verr� scelta una arbitrariamente dal programma
3. se in un determinato giorno non vi sono discipline, si scriva �niente di interessante�

� opzionale � ma fornisce punti aggiuntivi � considerare che se una gara � una finale, deve avere la precedenza rispetto alle altre gare.
Ad esempio se il file delle gare contenesse i seguenti dati:
12 pattinaggio 0
14 discesa 1
13 discesa 0
12 discesa 0
11 slalom 0
12 slalom 1
allora in il programma potrebbe generare il seguente output (si noti la scelta obbligata della finale il giorno 12):

giorno 11: slalom
giorno 12: slalom
giorno 13: discesa
giorno 14: discesa
giorno 15: niente di interessante
. . .
giorno 26: niente di interessante
 */

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

#define MAX 20

int main(){
	int dim=0;
	disciplina d[MAX];
	dim=acquisiz_lista(d);
	ordina_lista(d,dim);
	visual_classifica(d,dim);
	printf("\n\n\n");
	consiglia_gara(d,dim);
	system("pause");
	return 0;
}
