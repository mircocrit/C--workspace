#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

typedef struct{
	char string[MAX];
}str;

int main(){
	str s[MAX];
	int c,flag=0,i=0,tot;
	char string[MAX],*position=NULL,*p=NULL;
	char string1[MAX],string2[MAX];
	int scelta;
	do{
		printf("Menu\n");
		printf("0: Esci\n");
		printf("1: STRCHR: ricerca carattere nella stringa\n");
		printf("2: STRCSPN: lunghezza segmento non contenete caratteri della stringa\n");
		printf("3: STRPBRK: primo carattere a comparire in una stringa dell'altra\n");
		printf("4: STRRCHR: puntatore all'ultima occorrenza di un carattere in una stringa\n");
		printf("5: STRSPN: lungh segm iniziale di sting 1 contenente solo caratteri di string 2\n");
		printf("6: STRSTR: punato allaprima occorrenza della parola in una strinag\n");
		printf("7: STRTOK: tokenizza una stringa\n");
		printf("scelta:");
		scanf("%d",&scelta);
		switch(scelta){
			case 0:
				flag=1;
				printf("Uscita\n");
				break;
			//RICERCA STRINGHE
			//STRING.H

			case 1://STRCHR
				strcpy(string,"This is a test");
				printf("Stringa: %s\nInserire carattere:",string);
				fflush(stdin);
				c=getchar();
				position=strchr(string,c);
				if(position!= NULL){
					printf("Il carattere %c e' stato trovato nella stringa '%s'\n",c,string);
					printf("%s\n",position);
				}else
					printf( "Il carattere %c non e' stato trovato nella stringa %s\n",c,string);
				break;

			case 2://STRSPN
				strcpy(string1,"The value is 3.14159"); strcpy(string2,"1234567890");
				printf("%s\n%s\n",string1,string2);
				printf("%s %d \n",
						"La lunghezza del segmento iniziale di string1 non contenente nessun carattere di string2 e'",strcspn(string1,string2));
				break;

			case 3://STRPBRK
				strcpy(string1,"This is a test"); strcpy(string2,"beware");
				printf("%s\n%s\n",string2,string1);
				printf("%s %s, %c %s %s\n",
						"Fra i caratteri di ",string2,*strpbrk(string1,string2),"e' il primo carattere a comparire in ",string1);
				break;

			case 4://STRRCHR
				strcpy(string,"A zoo has many animals including zebras");
				printf("Stringa: %s\nInserire carattere:",string);
				fflush(stdin);
				c=getchar();
				printf("%s %s %s '%c'%s: %s\n",
				"Il puntatore di",string,"che inizia con l'ultima occorrenza del carattere ", c," e':",strrchr(string,c));
				break;

			case 5://STRSPN
				strcpy(string1,"The value is 3.14159"); strcpy(string2,"aehi lsTuv") ;
				printf("%s\n%s\n",string1,string2);
				printf("%s: %d\n",
						"La lunghezza del segmento iniziale di string1 contenente solo caratteri di string2 e'",strspn(string1,string2));
				break;

			case 6://STRSTR
				strcpy(string1,"abcdefabcdef"); strcpy(string2,"def");
				printf("%s\n%s\n",string1,string2);
				printf("%s %s %s %s %s: %s\n",
				"Il puntatore di",string1,"che punta  alla prima occorrenza di",string2,"e': ",strstr(string1,string2));
				break;
			case 7://STRTOK
				i=0;
				strcpy(string,"This is a test");
				printf("Stringa iniziale:	%s\n",string);
				printf("Stringa tokenizzata\n");
				p=strtok(string," ");
				while(p!=NULL){
					strcpy(s[i].string,p);//o copia in array di stringhe
					i++;
					p=strtok(NULL," ");
				}
				tot=i;
				for(i=0;i<tot;i++)
					printf("%s\n",s[i].string);
				break;
		}
	}while(scelta>0 && scelta<8 && flag==0);
	system("pause");
	return 0;
}
