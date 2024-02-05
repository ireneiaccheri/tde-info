/*  Definiamo percorso all'interno di una matrice una sequenza di lunghezza nota di coordinate (x,y) 
in cui x indica la riga e y la colonna. Gli indici del percorso partono da 0.

Per rappresentare il percorso si utilizzi la seguente definizione:
typedef struct {int x,y;} Punto;

e due variabili:
- un vettore di Punti
- una variabile intera che ne indica le dimensioni effettive

Si chiede di:

1=scrivere una funzione stampaPercorso che ricevuto in ingresso un percoso e 
la sua lunghezza stampa le sue coordinate.
 Ad esempio, se invocata avendo come parametro per1 e lung1 stamperà 
 (0,0) (0,-4) (2,6) (4,5) (3,1) (7,2) (8,2) (2,-4)
 
 
2=scrivere una funzione pulisci che ricevendo in ingresso e restituendo gli opportuni parametri 
riporta al chiamante e faccia in modo che siano contenuti in per2 i punti del percorso con le sole 
coordinate ammissibili per una matrice 8x8 e che lung2 contenga la lunghezza di tale percorso. 
Si invocherà poi stampaPercorso anche per per2 e verrà stampato (0,0) (2,6) (4,5) (3,1) (7,2)




3=infine si scriva una funzione che, usando un percorso e una matrice, 
inserisce in una stringa (che dovrà essere ben formata) i caratteri della matrice contenuti nelle caselle 
indicate dal percorso. La funzione dovrà essere usata per inserire in str il risultato della sua esecuzione 
usando il percorso in per2 e mat. Nel main si dovrà poi stampare la stringa str e con i valori nel file fornito 
verrà stampato BRAVO.   */


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

//scrivere qui i prototipi delle funzioni richieste;potrei anche usare stampaparola
//ma chiede di stampare nel main

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
	//posso creare un vettore char, passarlo come parametro alla struct e poi stamparlo. ovvio che glielo
	//devo passare vuoto e non crearlo all inetro della funz; potrebbe anche essere un void che mi modifica chill il vettore
	//oppure returno una struct di cui ho modifiato il campo vettore
	
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

//funzione che mi pulisce:ci metto anche un p2 vuoto dal main cosi che lo riempia
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

//una funzione non puo restituire un vettore!! lo devo mettere all'interno di una struct
//della lunghezza non mi interessa nulla:mi creo una nuova parola word che andro a restituire
parola crea(percorso p, char mat[][M]){
	int i,j=0;
parola word;
	for(i=0;i<p.lunghezza;i++){
		word.stringa[j]=mat[p.coord[i].x][p.coord[i].y];
		j++;
	}
	return word;
}


//scrivere qui le funzioni richieste
