#include <stdio.h>
#include <stdlib.h>

void bubble_sort_1(int[],int);
void bubble_sort_2(int[],int);
void bubble_sort_3(int[],int);
void swap(int*,int*);
void printArray(int[],int);

int main() {
    int arr[]={12,11,13,5,6,10,4,1,20,3,14,2,7};
    int n=sizeof(arr)/sizeof(arr[0]);

    bubble_sort_3(arr,n);

    printArray(arr,n);
    system("pause");
    return 0;
}


void swap(int *a,int *b){
	 int temp;
	 temp=*a;
	 *a=*b;
	 *b=temp;
}

void bubble_sort_1(int arr[],int n){
	int i,p=0;

	p=p+1;
	while(p<n){
		for(i=0;i<n;i++){
			if(arr[i]>arr[i+1])
				swap(&arr[i],&arr[i+1]);
				}
			p++;
		}
}

void bubble_sort_2 (int arr[],int n){
	int i,flag=1,p=0;

	p=p+1;
	while(p<n && flag==1){
		flag=0;
		for(i=0;i==n-1;i++){
			if(arr[i]>arr[i+1]){
				swap(&arr[i],&arr[i+1]);
				flag=1;
			}
		p++;
		}
	}
}

void bubble_sort_3(int arr[], int n){
	int i,flag=1,k;

	k=n-1;
	while(flag==1){
		flag=0;
		for(i=0;i<k;i++)
			if(arr[i]>arr[i+1]){
				swap(&arr[i],&arr[i+1]);
				flag=1;
				}
		}
}


void printArray(int arr[],int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d  ",arr[i]);
    printf("\n");
}
