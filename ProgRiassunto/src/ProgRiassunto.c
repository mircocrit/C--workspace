#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#define MAX 20

int main(){
	int arr[]={12,11,13,5,6,10,4,1,11,3,14,2,7,4,12,13,8,1,2,3,16,7,5,9,4,3,2,2,8,3,};
	int dim=sizeof(arr)/sizeof(arr[0]);
	int scelta,chiudi=0;
	int search,min,pos,i=0,cont=0;
	float med;

	do{
		printf("Inserire scelta:	");
		scanf("%d",&scelta);
		switch(scelta){
			default:
				printf("Errore!\n");
				break;
			case 0:
				chiudi=1;
				break;
			case 1:
				dim=7;
				for(i=0;i<dim;i++)
					arr[i]=inserimento();
				break;
			case 2:
				print_array(arr,dim);
				break;
			case 3:
				printf("Campo:	");
				scanf("%d",&search);

				ricerca_flag(arr,dim,search);
				printf("Elem trovato in posiz %d",i-1);
				break;
			case 4:
				printf("Campo:	");
				scanf("%d",&search);

				cont=conteggio(arr,dim,search);
				printf("Ho trovato %d corrispondenze\n",cont);
				break;
			case 5:
				med=media(arr,dim);
				printf("Media: %f",med);
				break;
			case 6:
				 min=minimo(arr,dim);
				 printf("%d",min);
				 break;
			case 7:
				bubble_sort(arr,dim);
				print_array(arr,dim);
				break;
			case 8:
				printf("Campo:	");
				scanf("%d",&search);

				pos= ricerca_binaria(arr,dim,search);
				printf("posizone: %d",pos);
				break;

			}
		}while(scelta>0 && scelta<10 && chiudi==0);
	system("pause");
	return 0;
		}
