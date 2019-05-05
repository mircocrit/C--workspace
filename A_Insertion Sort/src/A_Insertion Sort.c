#include <stdio.h>
#include <stdlib.h>

void Insertion_sort(int[],int);
void printArray(int[],int);


int main() {
    int arr[]={12,11,13,5,6,10,4,1,20,3,14,2,7};
    int n=sizeof(arr)/sizeof(arr[0]);

    Insertion_sort(arr,n);
    printArray(arr,n);
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
    for(i=0;i<n;i++)
        printf("%d  ",arr[i]);
    printf("\n");

}
