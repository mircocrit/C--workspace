#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 50
#define PATH "D:\\C-workspace\\Lab 9.4 Olimpiadi\\Debug\\calendario.txt"
//

typedef struct{
	int gg;
	char sport[MAX_CHAR];
	int finale;
}disciplina;

void copy_field(disciplina *, disciplina);
int acquisiz_lista(disciplina d[]){
	FILE *fp;
	int i=0;
	char name [MAX_CHAR],buffer[MAX_CHAR];
	disciplina temp;
	/*printf("Nome file classifica:---->");
	scanf("%s",name);
	strcpy(buffer,PATH);
	strcat(buffer,name);
	printf("%s\n",buffer);*/
	fp=fopen(PATH,"r");
	if(fp==NULL)	printf("Errore\n");
	else
		while(!feof(fp)){
			fscanf(fp,"%d %s %d",&temp.gg,temp.sport,&temp.finale);
			if(temp.gg>=10 && temp.gg <=26){
				copy_field(&d[i],temp);
				i++;
		}
	}
	fclose(fp);
	return i-1;
}

void visual_classifica(disciplina d[],int dim){
	printf("%-10s%-15s%-10s\n","Giorno","Gara","Finale");
	for(int i=0;i<dim;i++){
		printf("%-10d%-15s%-10d\n",d[i].gg,d[i].sport,d[i].finale);
	}
}

void copy_field(disciplina *a, disciplina b){
	*a=b;
	/*a->gg=b.gg;
	strcpy(a->sport,b.sport);
	a->finale=b.finale;*/
}

void ordina_lista(disciplina d[],int dim){
    int i,j=0;
    disciplina key;
    for(i=1;i<dim;i++){
        copy_field(&key,d[i]);
        j=i-1;
        while(j>=0 && d[j].gg>key.gg){
        	copy_field(&d[j+1],d[j]);
            j=j-1;
        }
        copy_field(&d[j+1],key);
    }
}


void consiglia_gara(disciplina d[],int dim){
	int i,j;
	int flag=0;
	i=0;
	for(j=10;j<25;j++){
		flag=0;
		if(d[i].gg==j){
			do{
				if(d[i].gg!=d[i+1].gg){
					flag=1;
					printf("Vedere %s nel giorno %d\n",d[i].sport,j);
					}
				i++;
			}while(flag==0);
		}
		else{
			printf("Nulla d interessante nel giorno %d\n",j);
		}
	}
}
