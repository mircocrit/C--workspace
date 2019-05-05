#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#include <stdio.h>


void acquisizone(int vett[MAX],int n){
    for(int i=0;i<n;i++){
        printf("Inserire elem  num %d   ",i+1);
        scanf("%d",&vett[i]);
    }
}

void mem_file(int vett[MAX],int n,FILE *fp,int *k){
    if(*k==0)        fp=fopen("file.txt","w+");
    else if(*k==1)   fp=fopen("file2.txt","w+");
    else            fp=fopen("file3.txt","w+");
    if(fp==NULL)    printf("Apertura file non riuscita\n");
    else{
        for(int i=0;i<n;i++)
            fprintf(fp, "%d  ",vett[i]);
        printf("Scrittura completata\n");
        *k=*k+1;
        fclose(fp);
    }
}

void inserction_sort(int vett[MAX],int n){
    int i,key,j;
    for(i=1;i<n;i++){
        key=vett[i];
        j=i-1;
        while(j>=0 && vett[j]>key){
            vett[j+1]=vett[j];
            j=j-1;
        }
        vett[j+1]=key;
    }
}

void ricerca_magg(int vett[MAX],int n,int search,FILE* fp3,int *k){
    int i,j=0;
    int temp[MAX];
    for(i=0;i<n;i++){
        if(vett[i]>search){
            temp[j]=vett[i];
            j++;
            
        }
    }
    mem_file(temp,j,fp3,k);
}

void leggi_file(FILE *fp){
    int temp[MAX],j=0;
    while(!feof(fp)){
        fscanf(fp,"%d   ",&temp[j]);
        printf("%d  ",temp[j]);
        j++;
    }
    printf("\n");
}

