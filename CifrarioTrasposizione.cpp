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
	char frase[K], ordine[L];
	bool ck;
	srand(time(NULL));
	
	// genero numeri casuali ciascuno diverso dagli altri
	i=1;
	ordine[0]=rand()%L+'A';
	while(i<L){
		ck=true;
		ordine[i]=rand()%L+'A';
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
	
	// Inizializzo la matrice tras[5][k] con spazi
	char tras[LK][L];
	for(int c=0; c<LK; c++)
		for(int j=0; j<L; j++)
			tras[c][j]=' ';
	
	// Inserisco la chiave (ordine[L]) generata in tras
	for(int j=0; j<L; j++)
		tras[0][j]=ordine[j];
	
	// Trasporto la frase dentro alla matrice tras
	int y=0, z=0;
	i=1;
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
	
	// Inizializzo la matrice crit[5][k] con spazi
	char crit[L][LK];
	for(int c=0; c<L; c++)
		for(int j=0; j<LK; j++)
			crit[c][j]=' ';
			
	// copio le colonne di tras nelle righe di crit: copio il trasposto di trans in crit
	for(int c=0; c<LK; c++){ 
		for(int z=0; z<L; z++){
			crit[z][c]=tras[c][z];
		}
	}
	
	// Stampo la matrice tras[LK][L]
	cout<<endl<<endl;
	for(int c=0; c<L; c++){
		for(int j=0; j<LK; j++)
			cout<<crit[c][j]<<"\t";
		cout<<endl;
	}
	
	// Riordino gli elementi rispetto alla chiave nella matrice crit
	i=0;
	char max, min;
	for(int c=0; c<L-1; c++){
		if(crit[0][c]>crit[0][c+1]){
			for(int j=0; j<L; j++){
				crit[c][j]=crit[];
				}
				
		}
	}
	
	system("PAUSE");
	return 0;
}

