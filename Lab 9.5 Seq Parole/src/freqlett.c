/*Si scriva un programma in grado di analizzare il contenuto di un file di testo e di calcolare la distribuzione di frequenza della lunghezza delle varie parole in esso contenute.
Per le finalità del presente programma, si definisce “parola” una sequenza di caratteri alfanumerici.
Il programma riceve sulla linea di comando il nome del file da analizzare e produce in uscita una tabella con le frequenze, espresse in valore assoluto (non in percentuale).
Si supponga che il file diario.txt contenga il seguente testo:

C’era una volta... "Un Re", diranno i miei piccoli lettori.
No, c’era una volta un pezzo di legno!

e che il programma (denominato freqlett.c) venga invocato con il seguente comando:
freqlett diario.txt
Il programma dovrà produrre in uscita:

Frequenza delle lunghezze delle parole
Parole lunghe 1 caratteri: 3
Parole lunghe 2 caratteri: 5
Parole lunghe 3 caratteri: 4
Parole lunghe 4 caratteri: 1
Parole lunghe 5 caratteri: 4
Parole lunghe 7 caratteri: 3
Infatti le parole di 1 carattere sono “C i c”, quelle di 2 caratteri sono “Un Re No un di”,
quelle di 3 caratteri sono “era una era una”, quelle di 4 caratteri sono “miei”, quelle di 5
caratteri sono “volta volta pezzo legno” e quelle di 7 caratteri sono “diranno piccoli lettori”.

*/
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lett.h"

#define MAX 700
#define MAX_ITA 26

int main() {
	int cont[MAX_ITA]={};
	int num_parole=0,lungh=0;
	stringa s,array[MAX];

	s= leggi_parole(s);
	//visual_testo(s);
	num_parole=tokenizza(array,s);
	visual_parole(array,num_parole);
	conta_occorr(array,num_parole,cont);
	for(int i=0;i<MAX_ITA;i++)
		printf("Frequenza parole di lunghezza %d:  %d\n",i+1,cont[i]);
	system("pause");
	return 0;
}
