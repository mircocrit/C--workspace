#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STRLEN 100


int calcolaCognome(char cognome[], char codice[], int insertChars){
	char vocali[3];
	int v=0;
	int i;
	for(i=0; i<strlen(cognome) && insertChars<3; i++){
		if(!vocale(cognome[i])){
			codice[insertChars++]=toupper(cognome[i]);
		}else if(v<3){
			vocali[v++]=cognome[i];
		}
	}
	for(i=0; i<strlen(vocali) && insertChars<3; i++){
		codice[insertChars++]=toupper(vocali[i]);
	}
	while(insertChars<3){
		codice[insertChars++]='X';
	}
	return insertChars;
}

int calcolaNome(char nome[], char codice[], int insertChars){
	char vocali[3];
	int v=0;
	char consonanti[4];
	int c=0;
	int i;
	for(i=0; i<strlen(nome); i++){
		if(vocale(nome[i]) && v<3){
			vocali[v++]=nome[i];
		}else if(c<4){
			consonanti[c++]=nome[i];
		}
	}

	if(c<4){
		for(i=0; i<v; i++){
			codice[insertChars++]=toupper(vocali[i]);
		}
		while(insertChars<6){
			codice[insertChars++]='X';
		}
	}else{
		codice[insertChars++]=toupper(consonanti[0]);
		codice[insertChars++]=toupper(consonanti[2]);
		codice[insertChars++]=toupper(consonanti[3]);
	}
	return insertChars;
}

int calcolaMese(int mese, char codice[], int insertChars){
	switch(mese){
		case 1:
			codice[insertChars++]='A';
			break;
		case 2:
			codice[insertChars++]='B';
			break;
		case 3:
			codice[insertChars++]='C';
			break;
		case 4:
			codice[insertChars++]='D';
			break;
		case 5:
			codice[insertChars++]='E';
			break;
		case 6:
			codice[insertChars++]='H';
			break;
		case 7:
			codice[insertChars++]='L';
			break;
		case 8:
			codice[insertChars++]='M';
			break;
		case 9:
			codice[insertChars++]='P';
			break;
		case 10:
			codice[insertChars++]='R';
			break;
		case 11:
			codice[insertChars++]='S';
			break;
		case 12:
			codice[insertChars++]='T';
			break;
	}
	return insertChars;
}

int calcolaGiorno(int giorno, char sesso, char codice[], int insertChars){
	char giorno_s[3];
	sesso=toupper(sesso);

	if(sesso=='F') giorno += 40;

	sprintf(giorno_s, "%d", giorno);

	if(giorno<10){
		codice[insertChars++]='0';
		codice[insertChars++]=giorno_s[0];
	}else{
		codice[insertChars++]=giorno_s[0];
		codice[insertChars++]=giorno_s[1];
	}
	return insertChars;
}

int calcolaComune(char provincia[], char comune[], char codice[], int insertChars){
	char com[STRLEN];
	char prov[3];
	char cod[5];

	FILE *stream;
	stream = fopen("listacomuni.csv", "r");

   	char record[STRLEN];
   	int cont=0;
   	while(!feof(stream)){
   		fgets(record, STRLEN, stream);
   		toUpperCase(record);
   		getProv(record, prov);
   		if(strcmp(prov, provincia)==0){
   			getComune(record, com);
   			if(strcmp(com, comune)==0){
   				int length=strlen(record);
				codice[insertChars++]=record[length-5];
				codice[insertChars++]=record[length-4];
				codice[insertChars++]=record[length-3];
				codice[insertChars++]=record[length-2];
			}
		}
	}
	return insertChars;
}

int calcolaControlChar(char codice[], int insertChars){
	char pari[7];
	char dispari[8];
	int p=0;
	int d=0;
	int i;
	int q=1;
	for(i=0; i<=insertChars; i++){
		if(q==0){
			pari[p++]=codice[i];
			q=1;
		}else{
			dispari[d++]=codice[i];
			q=0;
		}
	}
	int somma=0;
	somma+=convertiPari(pari, p);
	somma+=convertiDispari(dispari, d);
	int resto=somma%26;
	codice[insertChars++]=convertiUltimoCarattere(resto);

	return insertChars;
}

void getProv(char record[], char prov[]){
	int length=strlen(record);
	prov[0]=record[length-8];
	prov[1]=record[length-7];
	prov[2]='\0';
}

void getComune(char record[], char com[]){
	int length=strlen(record);
	strncpy(com,record,length-9);
	com[length-9]='\0';
}

void toUpperCase(char stringa[]){
	int i;
	for(i=0; i<strlen(stringa); i++){
		stringa[i]=toupper(stringa[i]);
	}
}

int vocale(char c){
	c=toupper(c);
	return (c=='A' || c=='E' || c=='I' || c=='O' || c=='U');
}

int convertiDispari(char arr[], int dim){
	int i;
	int somma=0;
	for(i=0; i<dim; i++){
		switch(arr[i]){
			case '0':
				somma+=1;
				break;
			case '1':
				somma+=0;
				break;
			case '2':
				somma+=5;
				break;
			case '3':
				somma+=7;
				break;
			case '4':
				somma+=9;
				break;
			case '5':
				somma+=13;
				break;
			case '6':
				somma+=15;
				break;
			case '7':
				somma+=17;
				break;
			case '8':
				somma+=19;
				break;
			case '9':
				somma+=21;
				break;
			case 'A':
				somma+=1;
				break;
			case 'B':
				somma+=0;
				break;
			case 'C':
				somma+=5;
				break;
			case 'D':
				somma+=7;
				break;
			case 'E':
				somma+=9;
				break;
			case 'F':
				somma+=13;
				break;
			case 'G':
				somma+=15;
				break;
			case 'H':
				somma+=17;
				break;
			case 'I':
				somma+=19;
				break;
			case 'J':
				somma+=21;
				break;
			case 'K':
				somma+=2;
				break;
			case 'L':
				somma+=4;
				break;
			case 'M':
				somma+=18;
				break;
			case 'N':
				somma+=20;
				break;
			case 'O':
				somma+=11;
				break;
			case 'P':
				somma+=3;
				break;
			case 'Q':
				somma+=6;
				break;
			case 'R':
				somma+=8;
				break;
			case 'S':
				somma+=12;
				break;
			case 'T':
				somma+=14;
				break;
			case 'U':
				somma+=16;
				break;
			case 'V':
				somma+=10;
				break;
			case 'W':
				somma+=22;
				break;
			case 'X':
				somma+=25;
				break;
			case 'Y':
				somma+=24;
				break;
			case 'Z':
				somma+=23;
				break;
		}
	}
	return somma;
}
int convertiPari(char arr[], int dim){
	int i;
	int somma=0;
	for(i=0; i<dim; i++){
		switch(arr[i]){
			case '0':
				somma+=0;
				break;
			case '1':
				somma+=1;
				break;
			case '2':
				somma+=2;
				break;
			case '3':
				somma+=3;
				break;
			case '4':
				somma+=4;
				break;
			case '5':
				somma+=5;
				break;
			case '6':
				somma+=6;
				break;
			case '7':
				somma+=7;
				break;
			case '8':
				somma+=8;
				break;
			case '9':
				somma+=9;
				break;
			case 'A':
				somma+=0;
				break;
			case 'B':
				somma+=1;
				break;
			case 'C':
				somma+=2;
				break;
			case 'D':
				somma+=3;
				break;
			case 'E':
				somma+=4;
				break;
			case 'F':
				somma+=5;
				break;
			case 'G':
				somma+=6;
				break;
			case 'H':
				somma+=7;
				break;
			case 'I':
				somma+=8;
				break;
			case 'J':
				somma+=9;
				break;
			case 'K':
				somma+=10;
				break;
			case 'L':
				somma+=11;
				break;
			case 'M':
				somma+=12;
				break;
			case 'N':
				somma+=13;
				break;
			case 'O':
				somma+=14;
				break;
			case 'P':
				somma+=15;
				break;
			case 'Q':
				somma+=16;
				break;
			case 'R':
				somma+=17;
				break;
			case 'S':
				somma+=18;
				break;
			case 'T':
				somma+=19;
				break;
			case 'U':
				somma+=20;
				break;
			case 'V':
				somma+=21;
				break;
			case 'W':
				somma+=22;
				break;
			case 'X':
				somma+=23;
				break;
			case 'Y':
				somma+=24;
				break;
			case 'Z':
				somma+=25;
				break;
		}
	}
	return somma;
}
char convertiUltimoCarattere(int resto){
	char ultimo;
	switch(resto){
		case 0:
			ultimo='A';
			break;
		case 1:
			ultimo='B';
			break;
		case 2:
			ultimo='C';
			break;
		case 3:
			ultimo='D';
			break;
		case 4:
			ultimo='E';
			break;
		case 5:
			ultimo='F';
			break;
		case 6:
			ultimo='G';
			break;
		case 7:
			ultimo='H';
			break;
		case 8:
			ultimo='I';
			break;
		case 9:
			ultimo='J';
			break;
		case 10:
			ultimo='K';
			break;
		case 11:
			ultimo='L';
			break;
		case 12:
			ultimo='M';
			break;
		case 13:
			ultimo='N';
			break;
		case 14:
			ultimo='O';
			break;
		case 15:
			ultimo='P';
			break;
		case 16:
			ultimo='Q';
			break;
		case 17:
			ultimo='R';
			break;
		case 18:
			ultimo='S';
			break;
		case 19:
			ultimo='T';
			break;
		case 20:
			ultimo='U';
			break;
		case 21:
			ultimo='V';
			break;
		case 22:
			ultimo='W';
			break;
		case 23:
			ultimo='X';
			break;
		case 24:
			ultimo='Y';
			break;
		case 25:
			ultimo='Z';
			break;
	}
	return ultimo;
}
