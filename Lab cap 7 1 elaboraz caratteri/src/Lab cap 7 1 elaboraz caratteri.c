#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
	int scelta,flag=0;
	char c;
	do{
		fflush(stdin);
		printf("Carattere:	");
		c=getchar();

		printf("Menu:\n");
		printf("1-ISDIGIT: e' un numero\n");
		printf("2-ISALPHA: e' una lettera\n");
		printf("3-ISALNUM: e' un numero o una lettera\n");
		printf("4-ISLOWER: e' minuscolo\n");
		printf("5-ISUPPER: e' maiuscolon");
		printf("6-TOUPPER: converte min in maiusc\n");
		printf("7-TOLOWER: converte maiusc in min\n");
		printf("8-ISSPACE: e' uno spazio(anche\n)\n");
		printf("9-ISCNTRL: e' un carattere di contollo\n");
		printf("10-ISPUNCT:e' punteggiatura\n");
		printf("11-ISPRINT: e' carattere di stampa\n");
		printf("12-ISGRAPH: e' una carattere grafico\n");
		printf("Scelta:");
		scanf("%d",&scelta);
		//ELABORAZIONE CARATTERI
		//CTYPE.H
		switch(scelta){
		case 1:
			printf("'%c'%s%s\n",c,isdigit(c)?" e' un ":" non e' un ","numero");
			break;
		case 2:
			printf("'%c'%s%s\n",c,isalpha(c)?" e' una ":" non e' una ", "lettera");
			break;
		case 3:
			printf("'%c'%s%s\n",c,isalnum(c)?" e' un ":" non e' un ", "numero o una lettera");
			break;
		case 4:
			printf("'%c'%s%s\n",c,islower(c)?" e' un ":" non e' un ", "lettera minuscola");
			break;
		case 5:
			printf("'%c'%s%s\n",c,isupper(c)?" e' un ":" non e' un ", "lettera maiuscola");
			break;
		case 6:
			printf("'%c'%s%c\n",c," convertita in maiusscola e' ",toupper(c));
			break;
		case 7:
			printf("'%c'%s%c\n",c," convertita in minuscola e' ",tolower(c));
			break;
		case 8:
			printf("'%c'%s%s\n",c,isspace(c)?" e' uno ":" non e' uno ","spazio");
			break;
		case 9:
			printf("'%c'%s%s\n",c,iscntrl(c)?" e' un ":" non e' un ","carattere di controllo");
			break;
		case 10:
			printf("'%c'%s%s\n",c,ispunct(c)?" e' un ":" non e' un ","carattere di punteggiatura");
			break;
		case 11:
			printf("'%c'%s%s\n",c,isprint(c)?" e' un ":"non e' un ","carattere di stampa");
			break;
		case 12:
			printf("'%c'%s%s\n",c,isgraph(c)? " e' un ":" non e' un ","carattere di stampa diverso dallo spazio");
			break;
		}
	}while(scelta>0 && scelta<13 && flag==0);
	system("pause");
	return 0;
}
