#include <stdio.h>
#include <stdlib.h>

#define PATH "D:\\C-workspace\\Lab cap 8 1 fscanf_printf\\text.txt"

int main() {
	FILE *fp;
	int read;
	//READ
	if((fp=fopen(PATH,"r"))==NULL)
		puts("Errore di apertura\n");
	else{
		puts("File aperto\n");
		fscanf(fp,"%d",&read);
		printf("Valore letto: %d\n",read);
	}
	//WRITE
	if((fp=fopen(PATH,"w"))==NULL)
	puts("Errore di apertura\n");
		else{
		puts("File aperto\n");
		fprintf(fp, "%d",123);
		puts("Valore scritto\n");
	}
	fclose(fp);
	system("pause");
	return 0;
}
