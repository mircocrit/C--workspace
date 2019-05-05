#include <stdio.h>
#include <stdlib.h>

#define PATH "D:\\C-workspace\\Lab cap 8 4 rewind\\text.txt"

int main(){
	FILE *p;
	if((p=fopen(PATH,"w"))==NULL)
		puts("Errore apertura\n");
	else{
		puts("File aperto\n");
		fprintf(p,"%d",1234);
		rewind(p);
		fprintf(p,"%d",4565);
		puts("Valore scritto\n");
		}
	fclose(p);
	system("pause");
	return 0;
}
