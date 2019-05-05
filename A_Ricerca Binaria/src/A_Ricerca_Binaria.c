#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Insertion_sort(int[],int);
int ricerca_binaria(int[],int,int);
void printArray(int[],int);

int main() {
	int index=-1,search;
	int arr[]={12,11,13,5,6,10,4,1,20,3,14,2,7};
	int n=sizeof(arr)/sizeof(arr[0]);
	Insertion_sort(arr,n);
	printArray(arr,n);
	printf("\n");

	printf("Inserire l'elemento da cercare\n");
	scanf("%d",&search);

	index=ricerca_binaria(arr,n,search);

	if(index==-1)	printf("L'elemento non e' stato trovato\n");
	else 	printf("L'elemento e' stato trovato in posizione %d",index+1);
	system("pause");
	return 0;
	}

void Insertion_sort(int arr[],int n){
    int i,key,j;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

void printArray(int arr[],int n){
     int i;
     for(i=0;i<n;i++){
         printf("%d ",arr[i]);
         printf("\n");
     }
}
int ricerca_binaria(int elem[],int dim,int search){
	int p=0;
	int u=dim-1;
	int flag=0,k=-1;

	while(p<=u && flag==0){
		k=(p+u)/2;
		if(elem[k]==search)
			flag=1;
		else
			if(elem[k]<search)		p=k+1;
				else					u=k-1;
		}

	if(flag==0)		k=-1;
	return k;
}
