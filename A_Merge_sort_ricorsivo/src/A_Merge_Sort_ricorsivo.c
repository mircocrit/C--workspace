#include<stdlib.h>
#include<stdio.h>

void merge(int[],int,int,int);
void merge_Sort(int[],int,int);
void printArray(int[],int);

int main()
{
    int arr[] ={12,11,13,5,6,7,1,4,3,6,8,3,18,19,4,33,23,45,32,32,23};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    merge_Sort(arr,0,arr_size-1);

    printArray(arr, arr_size);
    system("pause");
    return 0;
}

void merge_Sort(int arr[], int l, int r){
    if(l<r){
        int m=l+(r-l)/2;

        merge_Sort(arr, l, m);
        merge_Sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m-l+1;
    int n2 = r-m;

    int L[n1], R[n2];


    for(i=0;i<n1;i++)
        L[i] = arr[l+i];
    for (j=0;j<n2;j++)
        R[j] = arr[m+1+j];

    i = 0;
    j = 0;
    k = l;

    while (i<n1 && j<n2){
        if(L[i]<= R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void printArray(int A[], int size){
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
