/**
 *@file header.h
 *@authors matr 683254.
 *@date 24 lug 2018.
 */
/**
 * massimo caratteri ammissibili.
 */
#define MAX_CHAR 20
/**
 * percorso file che contiene le auto parcheggiate
 */
#define PATH "D:\\C-workspace\\Lab 9.3 Auto\\Debug\\auto.txt"
/**
 * percorso file che contiene le auto ordinate
 */
#define PATH_ORDINATE "D:\\C-workspace\\Lab 9.3 Auto\\Debug\\auto_ord.txt"
/**
 * costo parcheggio in euro ad ogni ora
 */
#define PRICE 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struttura di tipo orario.
 */
typedef struct{
	int ora;
	int minuti;
}orario;

/**
 * struttura di tipo automobile.
 */
typedef struct{
	char marca[MAX_CHAR];///marca autovettura
	char modello[MAX_CHAR];///modello auto.
	int cilidrata;///cilindrata auto.
	char colore[MAX_CHAR];///colore auto.
	orario orario_ingr;/// orario di ingresso.
	int posteggio;///postazione che occupa nel parcheggio.
	float costo;///tarriffa totale calcolata all uscita.
}automobile;

/**
 * apre un file in lettura per essere acquisiti
 * @pre il file deve esistere
 * @post la stuttura conterrà i dati del file
 * @post  restituira un valore >= 0
 */

int leggi_auto(automobile a[]){
	void rimuovi_cancell(char[]);
	FILE *fp;
	int i=0;
	char string[50];
	fp=fopen(PATH,"r");
	if(fp==NULL)
		printf("Errore, percorso non valido\n");
	else{
		while(!feof(fp)){
			fscanf(fp,"%s\n",string);
			rimuovi_cancell(string);
			sscanf(string," %s %s %d %s %d:%d %d",a[i].marca,a[i].modello,&a[i].cilidrata,a[i].colore,&a[i].orario_ingr.ora,&a[i].orario_ingr.minuti,&a[i].posteggio);
			a[i].costo=0;
			i++;
		}
	}
	return i;
}
/**
 * procedura che rimuove il simbolo '#' da una stringa data,sostituendolo con ' '
 * @post la stringa non deve avere # al suo interno
 */
void rimuovi_cancell(char string[]){
	int j=0;
	while((string[j])!='\0'){
		if(string[j]=='#'){
			string[j]=' ';
		}
		j++;
	}
	string[j]='\0';
}

void visual_auto(automobile a[],int dim){
	printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", "Marca", "Modello","Cilindr","Colore","Ora ingr", "Posteggio","Costo");
	for(int i=0;i<dim;i++)
		printf("%-10s%-10s%-10d%-10s%-2d:%-8.2d%-10d%-10.2f\n",a[i].marca,a[i].modello,a[i].cilidrata,a[i].colore,a[i].orario_ingr.ora,a[i].orario_ingr.minuti,a[i].posteggio,a[i].costo);
}
/**
 * acquisisce l'ora e ne controlla la correttezza.
 * @post l'ora andra da 0 e 23 e i minuti da 0 a 59.
 */
orario get_orario(){
	int controlla_ora(orario);
	int flag=0;
	orario ora;
	do{
		printf("Inserire ora in formato HH:MM\n");
		scanf("%d:%d",&ora.ora,&ora.minuti);
		flag=controlla_ora(ora);
	}while(flag==0);	//0=ora sbagliata
	return ora;
}
/**
 * controlla l'ora passata come parametro.
 * @pre l'ora deve essere nel formato orario
 * @post il valore restituito piuo' essere o 0, o 1.
 */
int controlla_ora(orario time){
	int flag=1;
	if((time.ora<0 || time.ora>=24)||(time.minuti<0 ||time.minuti>=60))
		flag=0;
	return flag;
}
/**
 * calcola la tariffa da pagare.
 * @pre car deve contenere dati.
 * @pre dim >= 1.
 * @post il campo costo dei record modificato.
 */
void calcola_costo(automobile a[],int dim ,orario orario_uscita){
	int i;
	for(i=0;i<dim;i++){
		if(orario_uscita.ora<a[i].orario_ingr.ora ||((orario_uscita.ora==a[i].orario_ingr.ora)&&(orario_uscita.minuti <a[i].orario_ingr.minuti)))
			printf("Errore\n");
		else
			a[i].costo=(orario_uscita.ora-a[i].orario_ingr.ora )*PRICE;
	}
}
/**
 *visualizza il prezzo del parcheggio da pagare.
 * @pre car deve contenere dati.
 * @pre dim >= 1.
 */

void visual_prezzo(automobile a[],int dim,int id){
	int i=0;
	for(i=0;i<dim;i++)
		if(a[i].posteggio==id)
			printf("La tariffa dell'auto al posteggio %d e' %.2f\n\n",a[i].posteggio,a[i].costo);
}
/**
 * rimuove l'auto in uscita dal parcheggio.
 * @pre a deve contenere dati.
 * @pre dim >= 1.
 * @post non ci saranno piu auto con l'identificativo id nella tabella
 */

int rimuovi_auto(automobile a[],int dim ,int id){
	void copy_field(automobile *,automobile);
	int i,k;
	k=0;
	for(i=0;i<dim;i++){
		if(a[i].posteggio!=id){
		  	copy_field(&a[k],a[i]);
		  	k++;
		}
	}
	return k;
}
/**
 * rimuove i duplicati di auto dalla tabella.
 * @pre a deve contenere dati.
 * @pre dim >= 1.
 * @post non ci saranno piu auto con l'identificativo id uguale nella tabella
 */

int rimozione_duplicati(automobile a[],int dim){
	void copy_field(automobile*,automobile);
	int i,j,k=0;
	int dup;
	for(i=1;i<dim;i++){
		dup=0;
		for(j=0;j<i;j++){
			if(a[j].posteggio==a[i].posteggio)
			   dup=1;

		}
		if(!dup){
			copy_field(&a[k],a[i]);
			k++;
			}
	}
	return k-1;
}

/**
 *  copia tutti i campi da una stuttura A ad una B.
 *  @pre auto che riceve dati deve essere passata per riferimento
 */
void copy_field(automobile *a1,automobile a2){
	*a1=a2;
}

/**
 * scrive su un file in scrittura i dati ricevuti
 * @pre il file deve esistere
 * @post la stuttura conterrà i dati del file
 * @post  restituira un valore >= 0
 * @post  i cmpi devono essere separati da un #, anziche' da uno spazio
 */

void scrivi_auto(automobile a[],int dim){
	FILE *fp;
	int i=0;
	char string[40];
	fp=fopen(PATH,"w");
	if(fp==NULL)
		printf("Errore, percorso non valido\n");
	else{
		for(i=0;i<dim;i++){
			sprintf(string,"#%s#%s#%d#%s#%d:%d#%d",a[i].marca,a[i].modello,a[i].cilidrata,a[i].colore,a[i].orario_ingr.ora,a[i].orario_ingr.minuti,a[i].posteggio);
			fprintf(fp,"%s\n",string);
		}
	fclose(fp);
	}
}
/**
 * ordina la tabella auto in base al costo del parcheggio in maniera crescente
 * @pre costo non nullo
 * @post la stuttura conterrà i dati della tabella ordinati per prezzo
 */

void insertion_sort(automobile a[],int dim){
	automobile key;
	int i,j=0;
	for(i=1;i<dim;i++){
		copy_field(&key,a[i]);
		j=i-1;
		while(j>=0 &&(a[j].costo>key.costo)){
			copy_field(&a[j+1],a[j]);
			j=j-1;
		}
		copy_field(&a[j+1],key);
	}
}
/**
 * ordina la tabella auto in base al costo del parcheggio in maniera crescente
 * @pre costo non nullo
 * @post la stuttura conterrà i dati della tabella ordinati per prezzo
 */

void bubble_sort(automobile a[],int dim){
	void swap(automobile*,automobile*);
	int i,j;
	for(i=0;i<dim-1;i++)
		for(j=0;j<dim-i-1;j++)
			if(a[j].costo>a[j+1].costo)
				swap(&a[j],&a[j+1]);

}
/**
 * ordina la tabella auto in base al costo del parcheggio in maniera crescente
 * @pre costo non nullo
 * @post la stuttura conterrà i dati della tabella ordinati per prezzo
 */

void selection_sort(automobile a[],int dim){
	void swap(automobile*,automobile*);
	int i,j,iMin;
	for(j=0;j<dim-1;j++){
		iMin=j;
		for(i=j+1;i<dim;i++){
			if(a[i].costo<a[iMin].costo)
				iMin=i;
		}
		if(iMin!=j){
			swap(&a[j],&a[iMin]);
		}
	}
}
/**
 * scambia tutti i campi della stuttura a1 con quelli della struttura a2
 */
void swap(automobile *a1,automobile *a2){
	automobile temp;
	temp=*a1;
	*a1=*a2;
	*a2=temp;
}
/**
 * scrive su un file in scrittura il singolo record autovettura
 * @pre il file deve esistere
 * @pre l'autovettura deve contenere dati
 * @pre percorso esistente
 */

void scrivi_record_auto(automobile a){
	FILE *fp;
	fp=fopen(PATH_ORDINATE,"a");
	if(fp==NULL)
		printf("Errore, percorso non valido\n");
	else{
			fprintf(fp,"%s %s %d %s %d:%d %d\n",a.marca,a.modello,a.cilidrata,a.colore,a.orario_ingr.ora,a.orario_ingr.minuti,a.posteggio);
			printf("%-10s%-10s%-10d%-10s%-3d:%-3d%-10d%-10.2f\n",a.marca,a.modello,a.cilidrata,a.colore,a.orario_ingr.ora,a.orario_ingr.minuti,a.posteggio,a.costo);

		}
	fclose(fp);
	}

