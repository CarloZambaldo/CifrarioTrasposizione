/*
   Programma: Cifrario a Trasposizione
   
   Programmed by Carlo Zambaldo (carlo.zambaldo@gmail.com)

   Version: 1.0.0
   Last Update: 30 October 2018
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <iostream>
using namespace std;

# define L 10 // Lunghezza parola chiave
# define K 50 // Lunghezza massima della frase da crittografare

int main(){
	int i, LK=K/L+1; // LK e' l'altezza mazzima della matrice tras (+1 poiche' ci deve stare anche la chiave)
	char frase[K];
	int ordine[L];
	bool ck;
	srand(time(NULL));
	
	// genero numeri casuali ciascuno diverso dagli altri
	i=1;
	ordine[0]=rand()%L;
	while(i<L){
		ck=true;
		ordine[i]=rand()%L;
		for(int j=0; j<i; j++)
			if(ordine[j]==ordine[i])
				ck=false;
		if(ck)
			i++;
	}
	
	// stampo il vettore ordine[L]
	for(int j=0; j<L; j++)
		cout<<ordine[j]<<"\t";
		
	cout<<endl<<endl;
	
	// Inizializzo la frase a tutti spazi
	for(int j=0; j<K; j++)
		frase[i]=' ';
	
	// chiedo l'inserimento della frase da crittografare
	cout<<"Inserire una frase da crittografare: ";
	gets(frase);
	
	// ottengo la lunghezza reale della frase
	int k = strlen(frase); 
	
	// Inizializzo la matrice tras[LK][L] con spazi
	char tras[LK][L];
	for(int c=0; c<LK; c++)
		for(int j=0; j<L; j++)
			tras[c][j]=' ';
	
	// Trasporto la frase dentro alla matrice tras
	int y=0, z=0;
	i=0;
	while(y<k){
		z=0;
		while((z<L)&&(y<k)){
			tras[i][z]=frase[y];
			y++;
			z++;
		}
		i++;
	}
	
	// Stampo la matrice tras[LK][L]
	for(int c=0; c<LK; c++){
		for(int j=0; j<L; j++)
			cout<<tras[c][j]<<"\t";
		cout<<endl;
	}
	
	// Trascrivo il risultato in ris[L] 
	char ris[LK];
	y=0;
	for(int j=0; j<L; j++){
		for(int c=0; c<LK; c++){
			ris[y]=tras[c][ordine[j]];
			y++;
		}
	}

	// stampo ris
	cout<<"La parola crittografata e': ";
	puts(ris);
	
	cout<<endl<<endl;
		
	system("PAUSE");
	return 0;
}

