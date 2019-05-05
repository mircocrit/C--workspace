#include <stdio.h>
#include <stdlib.h>
#define SIZE 8
#define dim 40

int main(void) {
	int array[dim]={1,2,3,4,0,5,2,3,3,1,2,4,0,0,2,5,5,2,5,1,1,5,5,1,5,6,0,0,6,1,2,3,3,1,2,2,0,1,5,2},i;
	int freq[SIZE]={0,0,0,0,0,0,0,0},j;

	for(i=0;i<dim;i++)
		++freq[array[i]];
	printf("%-10s%-10s\n","Risposta","Frequenza");
	for(j=0;j<SIZE;j++)
		printf("%-10d%-10d\n",j,freq[j]);
	system("pause");
	return 0;
}
