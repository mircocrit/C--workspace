//programma che scrive su file 10 20 30 40 50

#include <stdio.h>
#include <stdlib.h>

#define PATH "D:\\C-workspace\\Lab cap 8 8 fread_fwrite_fseek\\text.txt"


int main() {
	FILE* file;
	int value;
	if((file=fopen(PATH, "rb+"))==NULL)
		puts("Errore nell'apertura\n");
	else{
		printf("Valori scritti\n");
		for(int i=1;i<=5;i++){
			value= i*10;
			fwrite(&value,sizeof(i),1,file);
			printf("%d	",value);
		}
	printf("\nValori letti\n");
		for(int i=0;i<5;i++){
			int value=0;
			fseek(file,i*sizeof(i),SEEK_SET);
			fread(&value,sizeof(value),1,file);
			printf("%d	",value);
		}
	}
	system("pause");
	return 0;
}
