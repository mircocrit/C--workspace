#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct{
	char cogn_resp[20];
	char nome_resp[20];
	char via_sup[20];
	char citta_sup[20];
	int num_dip;
	float fat;
}supermercato;

typedef	enum
{false,true}
bool;

supermercato inserimento_supermercato(void);
void ricerca_supermercato(supermercato sup[], int num_sup, char cogn_resp_ric[], char nome_resp_ric[]);
int conta_supermercati(supermercato sup[], int num_sup, char citta_ric[]);
int ricerca_max(supermercato sup[], int num_sup);
void stampa_num_dip(supermercato sup[], int num_sup, int max);
void ordina_stampa(supermercato sup[], int num_sup);
void ordina_cognome_stampa(supermercato sup[], int num_sup);

int main(){
	int num_sup, i, tot_sup_citta, max;
	supermercato sup[MAX];
	char cogn_resp_ric[20], nome_resp_ric[20];
	char citta_ric[20];

	printf("NUMERO DI SUPERMERCATI DA INSERIRE: ");
	scanf("%d", &num_sup);
	for(i=0; i<num_sup; i++)
	{
		sup[i]=inserimento_supermercato();
	}

	printf("\n\nInserire Cognome del responsabile da ricercare: ");
	scanf("%s", cogn_resp_ric);
	printf("Inserire Nome del responsabile da ricercare: ");
	scanf("%s", nome_resp_ric);

	printf("\nLISTA SUPERMERCATI RICERCATI:\n");
	ricerca_supermercato(sup, num_sup, cogn_resp_ric, nome_resp_ric);

	printf("\nInserire citt‡ da ricercare: ");
	scanf("%s", citta_ric);
	tot_sup_citta=conta_supermercati(sup, num_sup, citta_ric);
	if(tot_sup_citta==0)
	{
		printf("**NELLA CITTA' RICERCATA NON CI SONO SUPERMERCATI**\n");
	}
	else
	{
		printf("NELLA CITTA' RICERCATA CI SONO %d SUPERMERCATI\n", tot_sup_citta);
	}

	max=ricerca_max(sup, num_sup);
	printf("\nLISTA SUPERMERCATI CON NUMERO MASSIMO DI DIPENDENTI:\n");

	stampa_num_dip(sup, num_sup, max);
	system("pause");


	printf("\n\nLISTA DEI SUPERMERCATI ORDINATI IN BASE AL NUMERO DEI DIPENDENTI:\n");
	ordina_stampa(sup, num_sup);
	system("pause");


	printf("\n\nLISTA DEI SUPERMERCATI ORDINATI IN BASE AL COGNOME");
	ordina_cognome_stampa(sup, num_sup);
	system("pause");

}


supermercato inserimento_supermercato(void)
{
	supermercato dati;
	printf("Cognome del responsabile: ");
	scanf("%s", dati.cogn_resp);
	printf("Nome del responsabile: ");
	scanf("%s", dati.nome_resp);
	printf("Via del supermercato: ");
	scanf("%s", dati.via_sup);
	printf("Citta' del supermercato: ");
	scanf("%s", dati.citta_sup);
	printf("Numero dei dipendenti: ");
	scanf("%d", &dati.num_dip);
	printf("Fatturato: ");
	scanf("%f", &dati.fat);
	return dati;
}

void ricerca_supermercato(supermercato sup[], int num_sup, char cogn_resp_ric[], char nome_resp_ric[])
{
	bool flag;
	int i;

	flag=false;
	for(i=0; i<num_sup; i++)
	{
		if((strcmp(sup[i].cogn_resp,cogn_resp_ric)==0) && (strcmp(sup[i].nome_resp,nome_resp_ric)==0))//CONFRONTO
		{
			flag=true;
			printf("\nVia del supermercato: %s", sup[i].via_sup);
			printf("\nCitta' del supermercato: %s", sup[i].citta_sup);
			printf("\nNumero dei dipendenti: %d", sup[i].num_dip);
			printf("\nFatturato: %f\n", sup[i].fat);
		}
	}
	if(flag==false)
	{
		printf("**IL NOMINATIVO INSERITO NON E' RESPONSABILE DI NESSUN SUPERMERCATO**\n");
	}

}

int conta_supermercati(supermercato sup[], int num_sup, char citta_ric[])
{
	int numero_supermercati, i;

	numero_supermercati=0;
	for(i=0; i<num_sup; i++)
	{
		if(strcmp(sup[i].citta_sup,citta_ric)==0)
		{
			numero_supermercati++;
		}
	}
	return numero_supermercati;
}

int ricerca_max(supermercato sup[], int num_sup)
{
	int massimo=0, i;

	for(i=0; i<num_sup; i++)
	{
		if(sup[i].num_dip>massimo)
		{
			massimo=sup[i].num_dip;
		}
	}

	return massimo;
}

void stampa_num_dip(supermercato sup[], int num_sup, int max)
{
	int i;

	for(i=0; i<num_sup; i++)
	{
		if(sup[i].num_dip==max)
		{
			printf("\nCognome del responsabile: %s", sup[i].cogn_resp);
			printf("\nNome del responsabile: %s", sup[i].nome_resp);
			printf("\nVia del supermercato: %s", sup[i].via_sup);
			printf("\nCitta' del supermercato: %s", sup[i].citta_sup);
			printf("\nNumero dei dipendenti: %d", sup[i].num_dip);
			printf("\nFatturato: %f\n", sup[i].fat);
		}
	}
}

void ordina_stampa(supermercato sup[], int num_sup)
{
	int i, passo=0;
	bool flag=true;
	supermercato scambio;

	do{
		flag=false;
		for(i=0; i<num_sup-1; i++)
		{
			if(sup[i].num_dip>sup[i+1].num_dip)
			{
				scambio=sup[i];
				sup[i]=sup[i+1];
				sup[i+1]=scambio;
				flag=true;
			}
		}
		passo++;
	}while(passo<num_sup-1 && flag==true);

	for(i=0; i<num_sup; i++)
	{
		printf("\nCognome del responsabile: %s", sup[i].cogn_resp);
		printf("\nNome del responsabile: %s", sup[i].nome_resp);
		printf("\nVia del supermercato: %s", sup[i].via_sup);
		printf("\nCitta' del supermercato: %s", sup[i].citta_sup);
		printf("\nNumero dei dipendenti: %d", sup[i].num_dip);
		printf("\nFatturato: %f\n\n", sup[i].fat);
	}
}

void ordina_cognome_stampa(supermercato sup[], int num_sup)
{
	int i, passo=0;
	bool flag=true;
	supermercato scambio;

	do{
		flag=false;
		for(i=0; i<num_sup-1; i++)
		{
			if(strcmp(sup[i].cogn_resp,sup[i+1].cogn_resp)>0)
			{
				scambio=sup[i];
				sup[i]=sup[i+1];
				sup[i+1]=scambio;
				flag=true;
			}
		}
		passo++;
	}while(passo<num_sup-1 && flag==true);

	for(i=0; i<num_sup; i++)
	{
		printf("\nCognome del responsabile: %s", sup[i].cogn_resp);
		printf("\nNome del responsabile: %s", sup[i].nome_resp);
		printf("\nVia del supermercato: %s", sup[i].via_sup);
		printf("\nCitta' del supermercato: %s", sup[i].citta_sup);
		printf("\nNumero dei dipendenti: %d", sup[i].num_dip);
		printf("\nFatturato: %f\n\n", sup[i].fat);
	}

}
