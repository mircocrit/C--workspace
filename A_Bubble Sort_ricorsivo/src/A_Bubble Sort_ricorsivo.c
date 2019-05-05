#include <stdio.h>
#include <stdlib.h>

void bubble_sort_ricorsivo(int[],int);
void printArray(int[],int);
void swap(int*,int*);

int main() {
    int arr[]={12,11,13,5,6,10,4,1,20,3,14,2,7};
    int n=sizeof(arr)/sizeof(arr[0]);

    bubble_sort_ricorsivo(arr,n);
    printArray(arr,n);
    system("pause");
    return 0;
}

void bubble_sort_ricorsivo(int arr[], int n){
	void swap(int*,int*);
	if(n==1)		return;
	for(int i=0;i<n-1;i++){
		if(arr[i]>arr[i+1]){
			swap(&arr[i],&arr[i+1]);
		}
	}
	bubble_sort_ricorsivo(arr,n-1);
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
        printf("%d ",arr[i]);
    printf("\n");
}
