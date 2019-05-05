/*
 * main.c
 *
 *  Created on: 09 giu 2018
 *      Author: Ninny
 */
#include <stdio.h>
#include <string.h>
#include "function.h"

int main()
{
 int scelta,chiudi = 0, risp = 0;




 do
 {
	 puts("\t0-Esci");
	 puts("\t1-Inserire parole");
	 puts("\t2-Ordina parole");
	 puts("\t3-Parole palindrome");
	 printf("\tscelta : ");
	 scanf("%d",&scelta);

	 switch(scelta)
	 {
	 case 0: chiudi = 1;
	  break;
	 case 1:

		     do
		     {

		       inserimento();

		       printf("\tAltre ? (1-si / 0-no) -- >  ");
		       scanf("%d",&risp);

		     }while(risp == 1);
	  break;

	 case 2: leggi_file();
	  break;
	 }

 }while(scelta > 0 && scelta < 4 && chiudi == 0);
 system("pause");
  return 0;
}
