#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble_sort(int[],int);
void printArray(int[],int);
void swap(int*,int*);

int main() {
    int arr[]={12,11,13,5,6,10,4,1,20,3,14,2,7};
    int n=sizeof(arr)/sizeof(arr[0]);

    bubble_sort(arr,n);
    printArray(arr,n);
    system("pause");
    return 0;
}

void bubble_sort(int arr[], int dim){
	void swap(int*,int*);
	int i,j;

	for(i=0;i<dim-1;i++){		//vale anche con n
		for(j=0;j<dim-i-1;j++){
			if(arr[j]<arr[j+1])
				swap(&arr[j],&arr[j+1]);
			}
		}
}

void swap(int *a,int *b){
	 int temp;
	 temp=*a;
	 *a=*b;
	 *b=temp;
}

void printArray(int arr[],int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d  ",arr[i]);
    printf("\n");
}
