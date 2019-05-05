#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int scan(char*);

int main(int argc, char* argv[])
{
 char buffer[MAX_LENGTH+1];

 FILE* p;

 if((p=fopen("test.txt","r"))==NULL)
 puts("File inesistente");
 else
 {
 	while (!feof(p))
 	{
 		fscanf(p,"%s",buffer);
 		if(scan(buffer))
 		 printf(" riconosciuto %-13s \n",buffer);
 		else
 		 printf(" non riconosciuto %-13s \n", buffer);
 	 /*if (fgets(buffer,MAX_LENGTH,p))
     if (scan(buffer))
     printf("%s RICONOSCIUTO\n", buffer);
     else
     printf("%s NON RICONOSCIUTO\n", buffer);
	 */
	}
	fclose(p);

 }
 	system("pause");
 	return 0;
 }

int scan(char* s)
{
	int i = 0;
	enum{ S,B,C,D,E,F,POZZA } current_state = S;

	while(s[i]!='\0' && s[i]!='\n' && current_state != POZZA)
	{
		switch(current_state)
		{
			case S:
				if(s[i] >= 97 && s[i] <= 122)
				current_state = B;
				else
				current_state = POZZA;
		    	break;
			case B:
				if(s[i] == 64)
				current_state = C;
				else if( (s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57) || s[i] == 46 || s[i] == 95 )
				current_state = B;
				else
				current_state = POZZA;
				break;
			case C:
				if(s[i] >= 97 && s[i] <= 122)
				current_state = D;
				else
				current_state = POZZA;
				break;
			case D:
				if(s[i] == 46)
				current_state = E;
				else if(s[i] >= 97 && s[i] <= 122)
				current_state=D;
				else
				current_state = POZZA;
				break;
			case E:
			    if(s[i] >= 97 && s[i] <= 122)
				current_state = F;
				else
				current_state = POZZA;
				break;
			case F:
				if(s[i] >= 97 && s[i] <= 122)
				current_state = F;
				else
				current_state = POZZA;
				break;
		}
		i++;
	}
	return (current_state == F);
}

