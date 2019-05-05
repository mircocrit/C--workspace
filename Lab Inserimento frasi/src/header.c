#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>

#define MAX 50
#define MAX_WORD 20


int scrivi_frase(char parole[MAX][MAX_WORD],int dim_parole){
	char c='\0';
	int i,j=0;
	i=dim_parole;
	printf("Inserire frase:\n");
	getchar();
	while((c=getchar())!= '\n'){
		if(c==' ' ||	(ispunct(c))){
			parole[i][j]='\0';
			i++;
			j=0;
			if((ispunct(c)) && c!='\'')
				getchar();
			c=getchar();
				//c!='"'	analizzarlo con coppie di 2 caratteri
		}
		parole[i][j]=c;
		j++;
	}

	return i+1;
}
