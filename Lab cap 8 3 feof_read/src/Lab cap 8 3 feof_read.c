#include <stdio.h>
#include <stdlib.h>

#define PATH "D:\\C-workspace\\Lab cap 8 3 feof_read\\text.txt"

int main() {
	char account[30]={};
	char name[30];
	float balance;

	FILE *p;

	if((p=fopen(PATH,"r"))==NULL)
		puts("Errore apertura\n");
	else{
		puts("File aperto\n");
		printf("%-10s%-13s%-10s\n","Account","Nome","Conto");

		//fscanf(p,"%d %s %lf",&account,name,&balance);

		while(!feof(p)){
			fscanf(p,"%s %s %f",account,name,&balance);
			printf("%-10s%-13s%-10.2f\n",account,name,balance);
		}
		fclose(p);
	}
	system("pause");
	return 0;
}
