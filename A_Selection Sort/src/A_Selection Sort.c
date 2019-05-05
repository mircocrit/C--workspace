#include <stdio.h>
#include <stdlib.h>

void Selection_sort(int[],int);
void swap(int*,int*);
void printArray(int[],int);

int main() {
    int arr[]={12,11,13,5,6,10,4,1,20,3,14,2,7};
    int n=sizeof(arr)/sizeof(arr[0]);

    Selection_sort(arr,n);
    printArray(arr,n);
    system("pause");
    return 0;
}

void Selection_sort(int arr[],int n){
	int i,j;
	for(j=0;j<n-1;j++){
		int iMin=j;
		for(i=j+1;i<n;i++){
			if(arr[i]<arr[iMin])
				iMin=i;
		}
		if(iMin!=j){
			swap(&arr[j],&arr[iMin]);
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
      for(i=0;i<n;i++){
          printf("%d ",arr[i]);
          printf("\n");
      }
 }
