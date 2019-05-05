/*
 * function.c
 *
 *  Created on: 09 giu 2018
 *      Author: utente
 */
#include <stdio.h>
#include <string.h>
#include <malloc.h>


#define PATH "D:\\utente\\Documents\\eclipse-workspace\\parole\\parola.txt"
#define PATH1 "D:\\utente\\Documents\\eclipse-workspace\\parole\\parole_ordinate.txt"
#define PATH2 "D:\\utente\\Documents\\eclipse-workspace\\parole\\parole_palindrome.txt"
#define MAX 20
#define TRUE 1
#define FALSE 0

typedef struct
{
	char w[MAX];
	int voc_doppie;
	int cons_doppie;
	int palindroma;

}word;

void inserimento()
{
	void scrivi_file(char[],int);

	int i = 0;
	int dim = 0;
	int lunghezza = 0;
	char* parola = NULL;
	char carattere;

    printf("Lunghezza parola : ");
    scanf("%d",&lunghezza);

	parola = (char*)malloc(lunghezza*sizeof(char));

	printf("inserisci parola : ");
	while((carattere = getchar()) != '.')
	{
		parola[i++] = carattere;
		dim++;
	}

	scrivi_file(parola,dim);


}

void scrivi_file(char p[],int dimensione)
{
	FILE* q;

	if((q=fopen(PATH,"a")) == NULL)
	{
		puts("Errore apertura file");
	}
	else
	{
		fprintf(q,"%s",p);
	}

	puts("File scritto");
}

int conta_record()
{
	FILE* q;
	char s[MAX];
	int i = 0;


	if((q=fopen(PATH,"r")) == NULL)
	{
		puts("File non aperto");
	}
	else
	{
		while(!feof(q))
		{
         fscanf(q,"%s",s);
         i++;
		}
	}
	fclose(q);

	return i;
}

void leggi_file()
{
	int conta_record();
	void ordina(word[],int);
	void scrivi_file_ordinato(word[],int);


	int dim = conta_record();

	word stringa[dim];


	FILE* q;
	int i = 0;

	if((q=fopen(PATH,"r")) == NULL)
	{
		puts("File non aperto");
	}
	else
	{
		while(!feof(q))
		{
			fscanf(q,"%s",stringa[i].w);
			i++;
		}
	}
	fclose(q);



	ordina(stringa,dim);
    scrivi_file_ordinato(stringa,dim);

/*
    printf("%d\n",stringa[0].palindroma);
    printf("%d\n",stringa[1].palindroma);
    printf("%d\n",stringa[2].palindroma);
    printf("%d\n",stringa[3].palindroma);
    printf("%d\n",stringa[4].palindroma);
*/



}

void ordina(word tab[],int dimensione)
{

	int i , j;
	char key[MAX];

	for(i=1;i<dimensione;i++)
	{
		strcpy(key,tab[i].w);
		j = i - 1;

		while(j >= 0 && strcmp(tab[j].w,key) > 0)
		{
			strcpy(tab[j+1].w,tab[j].w);
			j = j - 1;
		}
		strcpy(tab[j+1].w,key);
	}

}

void scrivi_file_ordinato(word tab[],int dimensione)
{
	FILE* q;
    int i;

	if((q=fopen(PATH1,"w")) == NULL)
	{
		puts("File non aperto");
	}
	else
	{
	  for(i=0;i<dimensione;i++)
	  {
		  if(!feof(q))
		  fprintf(q,"%s\t",tab[i].w);
	  }
	}
	fclose(q);
}

void palindroma(word tab[] ,int dimensione)
{


	int dim = 0;
	int i,k,j = 0;

	for(i=0;i<dimensione;i++)
	{
		dim = strlen(tab[i].w);
		j=dim-1;
		char temp[dim];

		//for(k=dim-1;k>=0;k--)
		for(k=0;k<dim;k++)
		{
			temp[j]=tab[k].w;
			j--;
		}


		if(strcmp(temp,tab[i].w) == 0)
		{
		    tab[i].palindroma = TRUE;
		}

	}

}

void scrivi_file_palindromi(word tab[],int dimensione)
{
	FILE* q;
    int i;

	if((q=fopen(PATH2,"w")) == NULL)
	{
		puts("File non aperto");
	}
	else
	{
	  for(i=0;i<dimensione;i++)
	  {
		  if(tab[i].palindroma == TRUE)
		  fprintf(q,"%s\t",tab[i].w);
	  }
	}
	fclose(q);
}
