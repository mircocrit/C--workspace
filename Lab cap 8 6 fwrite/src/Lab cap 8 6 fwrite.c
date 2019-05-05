#include <stdio.h>
#include <stdlib.h>
#define PATH "D:\\C-workspace\\Lab cap 8 6 fwrite\\text.txt"
//
typedef struct {
	int acctNum;
	char lastName[15];
	char firstName[10];
	double balance;
}clientData;
//
int main() {
	int i;
	clientData blankClient={0, """", """", 0.0};

	FILE *p;

	if((p=fopen(PATH,"wb"))==NULL)
		printf("File non aperto\n");
	else{
		puts("File aperto\n");
		for(i=1;i<=10;i++){
			fwrite(&blankClient,sizeof(clientData),1,p);
		}
		fclose(p);
	}
	system("pause");
	return 0;
}
