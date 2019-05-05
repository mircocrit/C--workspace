#include <stdio.h>
#include <stdlib.h>
# define PATH "D:\\C-workspace\\Lab cap 8 2 feof_stdin\\text.txt"

int main() {
	int account;
	char name[30];
	double balance;

	FILE *p;
	//
	if((p=fopen(PATH,"w"))==NULL)
		puts("Errore apertura\n");
	else{
		puts("File aperto\n");

		printf("Inserisci l'account, il nome e il conto,premere Ctrl+D per interrompere\n");
		scanf("%d %s %lf",&account,name,&balance);
		while(!feof(stdin)){//CTRL+D
			fprintf(p,"%d %s %.2f\n",account,name,balance);

			printf("Inserisci l'account, il nome e il conto,premere Ctrl+D per interrompere");
			scanf("%d %s %lf",&account,name,&balance);
		}
	}
	fclose(p);
	system("pause");
	return 0;
}
