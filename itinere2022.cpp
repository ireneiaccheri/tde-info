
#include <stdio.h>

#define N 100
#define M 8

typedef struct {int x,y;} Punto; 

typedef struct { int lunghezza; Punto coord[N]; }percorso;


typedef struct { int lunghezza;char stringa[N];
}parola;

//definisco tutte le strutture dati necessarie

void stampapercorso(percorso p);

percorso pulisci(percorso p,int num);

parola crea(percorso p, char mat[][M]);

int main(){
	percorso per1={8,{{0,0},{0,-4},{2,6},{4,5},{3,1},{7,2},{8,2},{2,-4}}};
	


	int lung1=8,lung2=0;
	char mat[M][M]={'B','R','S','P','E','E','F','A',
                    'Y','V','K','W','F','H','H','W',
                    'J','C','S','I','E','R','R','F',
                    'F','V','C','P','L','N','B','Q',
                    'P','C','D','F','Y','A','O','P',
                    'C','G','W','S','C','Q','O','O',
                    'D','H','H','S','L','L','U','I',
                    'X','R','O','L','E','N','T','Y'};
    
   	
   
	//scrivere qui le chiamate a funzione
	printf("\n\n");
	stampapercorso(per1);
	
   percorso per2=pulisci(per1, M);
	printf("\n\n");
	
	stampapercorso(per2);
	
parola	bravo=crea(per2,mat);
	
      int i;
	printf("\n\n");
	
	for(i=0;i<bravo.stringa[i]!='\0';i++){
		printf("%c",bravo.stringa[i]);
	}
	return 0;
}

//FINE MAIN


//prima funzione di stampa non deve restituire nulla;
void stampapercorso(percorso p){
	int i;	
	for(i=0;i<p.lunghezza;i++){
		printf("(%d,%d)\t",p.coord[i].x,p.coord[i].y);
	}
}

percorso pulisci(percorso p,int num){
	int i,numcord=0;
	percorso p2;
	for(i=0;i<p.lunghezza;i++){
		if(p.coord[i].x>=0 && p.coord[i].x<num && p.coord[i].y>=0 && p.coord[i].y<num){
		p2.coord[numcord].x=p.coord[i].x;
		p2.coord[numcord].y=p.coord[i].y;
		numcord++;
		p2.lunghezza++;}	}
			return p2;
}

parola crea(percorso p, char mat[][M]){
	int i,j=0;
parola word;
	for(i=0;i<p.lunghezza;i++){
		word.stringa[j]=mat[p.coord[i].x][p.coord[i].y];
		j++;
	}
	return word;
}


