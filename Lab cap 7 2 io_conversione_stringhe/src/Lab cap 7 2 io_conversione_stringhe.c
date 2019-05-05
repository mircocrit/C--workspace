#include <stdio.h>
#include <stdlib.h>

void reverse(const char * const sPtr);

int main() {
	int scelta,i=0,flag=0;
	char frase[80],c,s[80];
	float x,y;
	char s2[] = "Valore1: 31298, Valore2: 87.375";
	char sentence[80]= "Enter a line of text",string[10];

	do{
	printf("Menu\n");
	printf("0-Esci\n");
	printf("1-ATOF: Converte stinga in float\n");
	printf("2-ATOI: converte string ain intero\n");
	printf("3-ATOL: coverte strinag in long\n");
	printf("4-STRTOI: converte parte di strinag in intero\n");//STRTOD//STRTOL//STRTOUL
	printf("5-GETCHAR/PUTCHAR: acqusiz stringa e stampa\n");
	printf("6-SPRINTF: scrive variabili su una stringa in un modo definito da utente\n");
	printf("7-SSCANF: estrae valori da una stinga in modo definito da utente\n");
	printf("8-REVERSE/PUTS/GETS: inverte la stringa\n");
	printf("Scelta\n");
	scanf("%d",&scelta);
	fflush(stdin);
	switch(scelta){
		case 0:
			flag=1;
			break;
		//CONVERSIONE STRINGHE
		//STDLIB.H
		case 1: //ATOF
			printf("Inserire stringa contenente un double:	");
			gets(string);
			printf("%s %s %s %.3f\n", "La stringa",string,"convertita in double e'",atof(string));
			break;
		case 2: //ATOI
			printf("Inserire stringa contenente un intero:	");
			gets(string);
			printf("%s %s %s %d\n", "La stringa",string,"convertita in intero e'",atoi(string));
			break;
		case 3: //ATOL
			printf("Inserire stringa contenente un long:	");
			gets(string);
			printf("%s %s %s %ld\n", "La stringa",string,"convertita in long e'",atol(string));
			break;
		case 4://STRTOI

			break;
		//IO STRINGHE
		//STDIO.H
		case 5://INPUT//GETCHAR
			puts("Inserire testo:");
			fflush(stdin);
			while((c=getchar())!='\n'){
				frase[i]=c;
				i++;
				}
			frase[i]='\0';
			//OUTPUT//PUTCHAR
			printf("Frase inserita:");
			i=0;
			while(frase[i]!='\0'){
				putchar(frase[i]);
				i++;
			}
			break;

		case 6:	//SPRINTF
			printf("Inserire 2 numeri da scrivere sulla stringa:  ");
			scanf("%f %f",&x,&y);
			sprintf(s,"Valori: %.2f, %.2f",x,y);
			printf("La stringa scritta e':\n%s\n",s);
			break;

		case 7:	//SSCANF:
			printf("Stringa da cui estrarre valori:\n'%s'\n",s2);
			sscanf(s2,"Valore1: %f, Valore2: %f",&x,&y);
			printf("%s  %.3f,%.3f\n",
					"I valori estratti dalla stringa sono:",x,y);
			break;

		case 8:	//REVERSE//PUTS//GETS
			puts("Inserire stringa:");
			gets(sentence);
			printf("Inversione stringa:\n");
			reverse(sentence);
			printf("\n");
			break;
		}
	}while(scelta>0 && scelta<9 && flag==0);
	system("pause");
	return 0;
}


void reverse(const char *sPtr){
	if (sPtr[0]=='\0')	return;
	else{
		reverse(&sPtr[1]);
		putchar(sPtr[0]);
		}
}
