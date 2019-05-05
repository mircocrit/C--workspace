#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int n;
	int p;
}array2;


int inserimento(){
	int elem;
	printf("Inserire l'elemento:		");
	scanf("%d",&elem);
	return elem;
}

void print_array(int arr[],int n){
	int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
        printf("\n");
     }
}

int ricerca_flag(int arr[],int n,int search){
	int i=0;
	int flag=0;

	for(i=0;i<n && flag==0;i++){
		if(arr[i]==search)
			flag=1;
		}
	if(flag==0)		i=-1;
	return i;
}

int conteggio(int arr[],int n,int search){
	int i=0;
	int cont=0;

	for(i=0;i<n;i++){
		if(arr[i]==search)
			cont++;

		}
	return cont;
}

float media(int arr[],int n){
	int somma=0,i,k=0;

	for(i=0;i<n;i++){
		//if(arr[i]==search){
		somma+=arr[i];
		k++;
		}
	return somma/k;
}


int minimo(int arr[],int dim){//massimo: maggiore di max
	int i;
	int min,imin;

	min=arr[0];
	for(i=0;i<dim;i++)
		//if(arr[i].n==search){
		if(arr[i]<min){
			min=arr[i];
			imin=i;
		}
	return imin;
}


void swap(int *arr1, int *arr2){
	int temp;

	temp=*arr2;
	*arr2=*arr1;
	*arr1=temp;
}

void prenotazione(array2 arr[],array2 arr2[],int n,int dim){
	int i,j;

	for(i=0;i<n;i++){
		for(j=0;j<dim;j++){
			if(arr[i].n==arr2[j].n){
				if(arr2[j].p>arr[i].p)
					arr2[j].p-=arr[i].p;
				}
			}
	}
}

void bubble_sort(int arr[], int dim){
	void swap(int*,int*);
	int i,j;

	for(i=0;i<dim-1;i++){		//vale anche con n
		for(j=0;j<dim-i-1;j++){
			if(arr[j]>arr[j+1])
				swap(&arr[j],&arr[j+1]);
			}
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
