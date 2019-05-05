#include <stdio.h>
#include <stdlib.h>

void quick_Sort(int[],int,int);
int partition(int[],int,int);
void printArray(int[],int);
void swap(int*, int*);


int main(){
    int arr[] = {10,7,8,9,1,5,3,6,1,4,6,8,4,6,5,4,1,0,-1,-5,-9,-0};
    int n = sizeof(arr)/sizeof(arr[0]);
    quick_Sort(arr,0,n-1);
    printArray(arr,n);
    system("pause");
    return 0;
}

void quick_Sort(int arr[],int low,int high){
    if (low<high){
        int pi =partition(arr,low,high);
        quick_Sort(arr,low,pi - 1);
        quick_Sort(arr,pi + 1,high);
    }
}

int partition(int arr[],int low,int high){
    int pivot = arr[high];
    int i = (low - 1);

    for (int j=low; j<=high-1; j++){
        if (arr[j]<=pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

void printArray(int arr[],int size){
    int i;
    for (i=0; i < size; i++)
        printf("%d\n", arr[i]);
    printf("\n");
}

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
