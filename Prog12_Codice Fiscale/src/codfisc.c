#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 16 caratteri (0 a 15):
 (0 1 2) Prime tre consonanti del cognome							rizzo -- rzz
-Se le consonanti sono meno di 3 prendo le vocali in ordine		riso -- rsi
-Se le lettere del cognome sono meno di 3 aggiungo 'x' 			fo -- fox
(3 4 5) Prime 3 consonanti del nome
Se sono piu di 4 prendo la 1, la 2, la 4
Se sono meno di 3 prendo in ordine le vocali
Se le lettere del nome sono meno di 3 aggiungo 'x'
(6 7) ultime 2 cifre dell'anno
(8) lettera identificatrice del mese
(9) giorno: se donna sommare +40 al giorno
(10..)comune...*/


void calcolaCognome(char cognome[],char risCognome[],int max,int n){
	char bufferC[n], bufferV[n];
	int contConsonanti=0,contVocali=0,i=0;
	if(strlen(cognome)<n){	//al-->lax
		if((cognome[0]=='a'|| cognome[0]=='e'|| cognome[0]=='i'|| cognome[0]=='o'|| cognome[0]=='u') &&(cognome[1]!='a' && cognome[1]!='e' && cognome[1]!='i' && cognome[1]!='o' && cognome[1]!='u')){
			risCognome[0]=cognome[1];
			risCognome[1]=cognome[0];
			risCognome[2]='x';
		}
		else{
			risCognome[0]=cognome[0];
			risCognome[1]=cognome[1];
			risCognome[2]='x';
		}
		if((cognome[0]=='a'|| cognome[0]=='e'|| cognome[0]=='i'|| cognome[0]=='o'|| cognome[0]=='u') &&(cognome[1]=='a' && cognome[1]=='e' && cognome[1]=='i' && cognome[1]=='o' && cognome[1]=='u')){
			risCognome[0]=cognome[0];	//aer->aex
			risCognome[1]=cognome[1];
			risCognome[2]='x';
		}
	}
	if(strlen(cognome)>=n){
		for(i=0;i<strlen(cognome)&&contConsonanti<n;i++){		//acquisiz conson
			if(cognome[i]!='a' && cognome[i]!='e' && cognome[i]!='i' && cognome[i]!='o' && cognome[i]!='u'){
				bufferC[contConsonanti]=cognome[i];
				contConsonanti++;
			}
			else{	//acquisiz vocali
				if(contVocali<2){
					bufferV[contVocali]=cognome[i];
					contVocali++;
				}
			}
			switch(contConsonanti){
			case 3: risCognome[0]=bufferC[0];
					risCognome[1]=bufferC[1];
					risCognome[2]=bufferC[2];
					break;
			case 2:	risCognome[0]=bufferC[0];
					risCognome[1]=bufferC[1];
					risCognome[2]=bufferV[0];
					break;
			case 1:	risCognome[0]=bufferC[0];
					risCognome[1]=bufferV[0];
					risCognome[2]=bufferV[1];
					break;
			case 0:	risCognome[0]=bufferV[0];
					risCognome[1]=bufferV[1];
					risCognome[2]=bufferV[2];
					break;
			}
		}
	}
}

void calcolaNome(char nome[],char risNome[],int max, int n){
	char bufferC[4],bufferV[2];
	int i,contV=0,contC=0;
	if(strlen(nome)<3){	//al->lax
		if((nome[0]=='a' || nome[0]=='e' || nome[0]=='i' || nome[0]=='o' || nome[0]=='u')&&(nome[1]!='a' && nome[1]!='e' && nome[1]!='i' && nome[1]!='o' && nome[1]!='u')){
			risNome[0]=nome[1];
			risNome[1]=nome[0];
			risNome[2]='x';
		}else{		//fo-->fox
			risNome[0]=nome[0];
			risNome[1]=nome[1];
			risNome[2]='x';
		}
	}else{
		if(strlen(nome)>=3){
			for(i=0;i<strlen(nome)&&contC<5;i++){
				if(nome[i]!='a'&& nome[i]!='e'&& nome[i]!='i'&& nome[i]!='o'&& nome[i]!='u'){
					bufferC[contC]=nome[i];
					contC++;
				}else	if(contV<2){
							bufferV[contV]=nome[i];
							contV++;
					}

				switch(contC){
				case 4: risNome[0]=bufferC[0];
						risNome[1]=bufferC[2];
						risNome[2]=bufferC[3];
						break;
				case 3: risNome[0]=bufferC[0];
						risNome[1]=bufferC[1];
						risNome[2]=bufferC[2];
						break;
				case 2: risNome[0]=bufferC[0];
						risNome[1]=bufferC[1];
						risNome[2]=bufferV[0];
						break;
				case 1: risNome[0]=bufferC[0];
						risNome[1]=bufferV[0];
						risNome[2]=bufferC[1];
						break;
					}
				}
			}
		}
}

void calcolaData(char anno[],char annoDiNascita[],int mese,int giorno, char sesso){
	annoDiNascita[0]=anno[2];
	annoDiNascita[1]=anno[3];
	if(mese==1) annoDiNascita[2]='A';
	if(mese==2) annoDiNascita[2]='B';
	if(mese==3) annoDiNascita[2]='C';
	if(mese==4) annoDiNascita[2]='D';
	if(mese==5) annoDiNascita[2]='E';
	if(mese==6) annoDiNascita[2]='H';
	if(mese==7) annoDiNascita[2]='L';
	if(mese==8) annoDiNascita[2]='M';
	if(mese==9) annoDiNascita[2]='P';
	if(mese==10) annoDiNascita[2]='R';
	if(mese==11) annoDiNascita[2]='S';
	if(mese==12) annoDiNascita[2]='T';
	if(sesso=='f')	giorno+=40;
}
