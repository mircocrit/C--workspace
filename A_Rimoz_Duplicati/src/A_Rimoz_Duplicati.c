#include <stdio.h>
#include <stdlib.h>


int rimozione_duplicati(int[],int);
void printArray(int[],int);

int main() {
	int dim=0;
	int arr[]={12,11,13,11,6,10,13,11,6,10,14,2,2,12,6,7,4,1,5,6,1,5};
	int n=sizeof(arr)/sizeof(arr[0]);

	dim=rimozione_duplicati(arr,n);
	printArray(arr,dim);

	system("pause");
	return 0;
	}


int rimozione_duplicati(int arr[],int dim){
	int i,j,k=0;
	int dup;
	for(i=1;i<dim;i++){
		dup=0;
		for(j=0;j<i;j++){
			if(arr[j]==arr[i])
			   dup=1;

		}
			if(!dup){
				arr[k]=arr[i];
				k++;
			}
	}
	return k-1;
}

void printArray(int arr[],int n){
      int i;
      for(i=0;i<n;i++){
          printf("%d\n",arr[i]);
      }
 }

