#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int scelta,flag=0;
	char x[] = "Happy Birthday to You",y[25];
	char s1[30] = "Happy New Year", *s2 = "Happy New Eve";
	do{
		printf("0-Menu\n");
		printf("1-STRCPY: copia valore str1 in str2\n");
		printf("2-STRNCPY:copia n valori di str1 in str2\n");
		printf("3-STRCAT: concatena str2 a str1\n");
		printf("4-STRNCAT: concatena n caratteri di str2 a str1\n");
		printf("5-STRCMP: confronta str1 con str2\n");
		printf("6-STRNCMP: confronta n caratteri di str1 con str2\n");

		printf("Scelta:\n");
		scanf("%d",&scelta);
		switch(scelta){
		case 0:
			flag=1;
			break;
		//COPIA STRINGHE
		//STRING.H
		case 1://STRCPY
			printf("%s\n",x);
			strcpy(y,x);
			printf( "%s%s\n","La stringa copiata in y e':",y);
			break;
		case 2://STRNCPY
			printf("%s\n",x);
			strncpy(y,x,14);
			y[14] ='\0';
			printf("%s %s\n","La stringa copiata in y e': ",y);
			break;
		case 3://STRCAT
			printf("s1:%s,s2:%s\n",s1,s2);
			strcat(s1,s2);
			printf("La nuova stringa e' '%s'\n",s1);
			break;
		case 4://STRNCAT
			strcpy(s1,"Happy New Year");
			printf("s1:%s,s2:%s\n",s1,s2);
			strncat(s1,s2,6);
			printf("La nuova stringa con 6 caratteri concatenati e' '%s'\n",s1);
			break;

		//CONFORNTO STRINGHE
		//STRING.H
		case 5://STRCMP
			printf("stringa1:'%s',stringa2: '%s'\n",s1,s2);//S1<S2--> return=-1
			if((strcmp(s1,s2))==0)
				printf("Le stringhe sono uguali\n");
			else
				printf("Le stringhe sono diverse:  %d\n",(strcmp(s1,s2)));
			break;
		case 6://STRNCMP
			printf("stringa1:'%s',stringa2: '%s',comparazione primi 3 caratteri\n",s1,s2);
			if((strncmp(s1,s2,3))==0)
				printf("I primi 3 caratteri delle stringhe sono uguali\n");
			else
				printf("I primi 3 caratteri delle stringhe sono diversi: %d\n",(strncmp(s1,s2,3)));
			break;
		}
	}while(scelta>0 && scelta<7 && flag==0);
	system("pause");
	return 0;
}
