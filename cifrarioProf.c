// Cifrario per trasposizione 
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <time.h>
# include <stdbool.h>

#define t 10 // t lunghezza parola chiave
main()
{
	int i=1, j;
	int ordine[t];
	bool ck;
	srand(time(NULL));
	// genero numeri casuali tutti diversi
	ordine[0]=rand()%t;
	while(i<t){
		ordine[i]=rand()%t;
		ck=true;
		for(j=0; j<i; j++)
			if(ordine[i]==ordine[j])
				ck=false; // se trovo un valore uguale
		if(ck) i++;
	}
	
	for(i=0; i<t; i++)
	 printf("%d\t", ordine[i]);
	
// inseriamo una frase da crittografare 
char parola[50];
printf("\n\n");
printf ("inserisci una frase: ");
gets(parola);
int k=strlen(parola);
// trasformo frase da crittografare in lettere maiuscole
//tolgo caratteri diversi da lettere 
i=0;
while(i<k)
{
if (parola[i]>'Z')parola[i]-=32;
if ((parola[i]<'A')||(parola[i]>'Z'))
	{int j;
	for (j=i;j<k;j++)parola[j]=parola[j+1];
	parola[k]=' ';k--;}//k=lunghezza della parola da crittografare
else i++;
}
printf("\n\n");
puts(parola);
	
char tras[5][k];
// inizializzo a spazi la matrice di trasposizione
for(i=0;i<5;i++)
	for(j=0;j<k;j++)
		tras[i][j]=' ';
		
int z=0;
i=0;

while(z<k){
	j=0;
	while(z<k){
		tras[i][j]=parola[z];
		z++;
		j++;
	}
	i++;
}
	
	for(i=0;i<5;i++){
		printf("\n\n");
	
		for(j=0;j<k;j++)
			printf("%c\t",tras[i][j]);}
	
int righe;
if(k%10==0)
	righe=k/10;
else
	righe=k/10+1;
	
char risultato[50];
int u;
for(u=0; u<50; u++) // INIZIALIZZO RISULTATO CON TUTTI SPAZI
	risultato[u]=' ';
int y=0;

for(j=0;j<10;j++)
	for(i=0;i<righe;i++)
		{
			if(tras[i][ordine[j]]!=' ') // ALTRIMENTI METTE ANCHE GLI SPAZI
			{
				risultato[y]=tras[i][ordine[j]];
				printf("\n%d %c",y,risultato[y]);
				y++;
			}
		}
printf("\n\n");
for(j=0;j<10;j++)
	printf("%d\t",ordine[j]);		
printf("la parola crittografata e': ");
puts(risultato);
	
	printf("\n\n");
	system("PAUSE");
}

