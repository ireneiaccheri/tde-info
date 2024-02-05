//// TDE 16-06-2023 ///////////////////////////////////////////////////////////////////////////////////////////////////////7

//////// ESERCIZIO 1 /////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Si consideri una matrice NxN di interi. Una matrice quadrata si dice "a diagonale massima" se ciascun elemento sulla diagonale 
è il massimo elemento della sotto-matrice quadrata che parte da quell'elemento. Ad esempio, la seguente matrice è a diagonale massima:

9 3 4 5
1 7 5 2
8 1 5 3
4 2 4 4

Infatti 9 è il massimo elemento della matrice completa, 7 è il massimo elemento della sottomatrice
7 5 2
1 5 3
2 4 4
5 è il massimo elemento della sottomatrice
5 3
4 4
e 4 è il massimo elemento della matrice formata dal solo 4 

Si scriva una funzione diagonaleMassima che restituisce 1 se la matrice che riceve è a diagonale massima, 0 altrimenti. 
Inoltre, la funzione diagonaleMassima riporta al chiamante un vettore grande come il numero di elementi della diagonale, 
dove compare un 1 se l’elemento corrispondente sulla diagonale è il massimo della sotto-matrice quadrata che parte
 da quell'elemento, zero altrimenti. Con la matrice mostrata sopra il vettore conterrebbe quattro 1.

Altro esempio, con la matrice

9 3 4 5
1 1 5 2
8 1 3 3
4 2 4 4

Restituirebbe 0, infatti 9 è il massimo elemento della matrice completa, ma 1 non è il massimo elemento della sottomatrice
1 5 2 
1 3 3 
2 4 4 

3 non è il massimo elemento della sottomatrice
3 3
4 4

4 è il massimo elemento della sottomatrice contenente solo il 4

Con questa matrice nel vettore verrebbero inseriti 1 0 0 1

Il main contenuto nel file 
https://www.dropbox.com/s/r9915po05hhvq3x/matrici.c?dl=0 
deve essere modificato in modo da stampare 
Per la matrice
9 3 4 5
1 7 5 2
8 1 5 3
4 2 4 4
Il risultato è 1 e il vettore contiene 1 1 1 1
Per la matrice
9 3 4 5
1 1 5 2
8 1 3 3
4 2 4 4
Il risultato è 0 e il vettore contiene 1 0 0 1
Le stampe sono ammesse solo nel main (stampe in altre funzioni comporteranno penalizzazioni molto forti del punteggio). 
Non è ammesso modificare le librerie importate.*/
#include <stdio.h>

#define N 4

void stampaMatrice(int m[][N]);
int check(int mat[][N],int v[]);
int aux(int mat[][N],int riga, int colonna,int elem);
int main() {
    int matrice1[N][N] = { {9, 3, 4, 5}, {1, 7, 5, 2}, {8, 1, 5, 3}, {4, 2, 4, 4} };
    int matrice2[N][N] = { {9, 3, 4, 5}, {1, 1, 5, 2}, {8, 1, 3, 3}, {4, 2, 4, 4} };
	//spazio per variabili aggiuntive
	
	stampaMatrice(matrice1);
	//invocazione funzione scritta dallo studente
	
	//stampa output per matrice1
    
    printf("\n\n");
	stampaMatrice(matrice2);
	//invocazione funzione scritta dallo studente
	int v[N]={0,0,0,0};
	//stampa output per matrice2
    printf("\n%d",check(matrice2,v));
    printf("\n");
    for(int i=0;i<N;i++) 
	printf("%d",v[i]);
    
    return 0;
}

void stampaMatrice(int m[][N]){
	int i,k;
	for(i=0;i<N;i++){
		for(k=0;k<N;k++){
			printf("%d ",m[i][k]);
		}
		printf("\n");
	}
}

int check(int mat[][N],int v[]){
	int si=1,i,j,k=0;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(i==j){
				if(aux(mat,i,j,mat[i][j])){ //controlla che primo elem sia maggiore di tutti
					v[i]=1;
					
				} //ricordati che comunque il k deve essere incrementato--> e piu comodo se usi direttamente i come indice
			}
		}
	}
	
	for(i=0;i<N;i++){
		if(v[i]==0) return 0;
	}
	
	return 1;
}

int aux(int mat[][N],int riga,int colonna,int elem){
	int i,j,si=1;
	for(i=riga;i<N;i++){
		for(j=colonna;j<N;j++){
			if(mat[i][j]>elem)
			si=0;
		}
	}
	
	return si;
}

//// ESERCIZIO 2 ///////////////////////////////////////////////////////////////////////////////////////////////////////////77
/*Sia data una lista contenente almeno due numeri interi in ordine crescente i cui record sono definiti 
tramite la seguente struttura C:
 
typedef struct nodo{
    int valore;
    struct nodo* next;
} nodo;
 
Scrivere una funzione riempiLista che, data una lista di numeri interi in ordine crescente, 
inserisce nella posizione corretta all'interno della lista tutti i numeri mancanti. 

Per esempio, se la lista in ingresso è
1 -> 2 -> 5 -> 7 -> 8
la lista restituita dalla funzione conterrà:
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8

Per la risoluzione di questo esercizio non è consentito usare array, 
liste o altre strutture dati ausiliarie ad eccezione della lista in ingresso. 
Non è consentito importare librerie aggiuntive a quelle già presenti nel file fornito.*/
 
#include <stdlib.h>
#include <stdio.h>

typedef struct nodo {
    int valore;
    struct nodo *next;
} nodo;

typedef nodo *lista;

lista InsInFondo(lista lis, int elem);
void VisualizzaLista(lista lis);
lista costruisci();
int mancanti(int a,int b);
lista completa(lista lis);
int main() {
    lista lis = costruisci();
    VisualizzaLista(lis);
	 printf("\n\n");
	 VisualizzaLista(completa(lis));
    // TODO: invocazione funzione
    // TODO: visualizzazione lista output

    return 0;
}

lista InsInFondo(lista lis, int elem) {
    lista punt;
    if (lis == NULL) {
        punt = (lista)malloc(sizeof(nodo));
        punt->next = NULL;
        punt->valore = elem;
        return punt;
    } else {
        lis->next = InsInFondo(lis->next, elem);
        return lis;
    }
}

void VisualizzaLista(lista lis) {
    if (lis == NULL)
        printf(" ---| \n");
    else {
        printf(" %d ---> ", lis->valore);
        VisualizzaLista(lis->next);
    }
}

lista costruisci() {
    // 1 -> 2 -> 5 -> 7 -> 8
    lista lis = NULL;
    lis = InsInFondo(lis, 1);
    lis = InsInFondo(lis, 3);
    lis = InsInFondo(lis, 5);
    lis = InsInFondo(lis, 7);
    lis = InsInFondo(lis, 8);

    return lis;
}

int mancanti(int a,int b){
	if(a==b-1){
		return 0;
	}else return 1;
}

lista completa(lista lis){
	lista tmp;
	lista nuovonodo;
	lista testa=lis;
	while(lis!=NULL && lis->next!=NULL){
		if(mancanti(lis->valore,lis->next->valore)){
		    tmp=lis;
			nuovonodo=(lista)malloc(sizeof(nodo));
			nuovonodo->valore=lis->valore+1;
			nuovonodo->next=lis->next;
			tmp->next=nuovonodo;
		}
		lis=lis->next;
	}
	
	return testa;
}

///////ESERCIZIO 3 /////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Sia data la seguente definizione di un albero binario contenente un intero in ogni nodo.

typedef struct N{
int c;
struct El *left, *right;
}Nodo;

typedef Nodo *Tree;

Si scriva una funzione sommaPercorsi che alloca un vettore di interi con tante caselle quante sono le foglie dell’albero e 
inserisce in ognuna la somma di tutti gli elementi dei percorsi dalla radice alle foglie.

Ad esempio, quando la funzione sommaPercorsi viene invocata su questo albero

               3
       4              9
   2      7       8 
1   3

questa restituisce un vettore contenente i numeri
10  12  14  20

N.B La funzione deve stampare il vettore e lo deve deallocare.

Si consiglia molto fortemente l’uso di funzioni ausiliarie con parametri aggiuntivi che “trasportino” nelle 
chiamate informazioni utili.*/

#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura Nodo
typedef struct N {
    int valore;
    struct N * left;
    struct N * right;
} Nodo;
typedef Nodo * Albero;

Albero nuovoNodo(int valore);
void stampaAlbero(Albero t);
void print(Albero t);
void stampavettore(Albero t ); 
void aux(Albero t,int v[],int *index,int somma);
int contafoglie(Albero t);
int main() {
    // Creazione dell'albero
    Albero radice = nuovoNodo(3);
    radice->left = nuovoNodo(4);
    radice->right = nuovoNodo(9);
    radice->left->left = nuovoNodo(2);
    radice->left->right = nuovoNodo(7);
    radice->right->left = nuovoNodo(8);
    radice->left->left->left = nuovoNodo(1);
    radice->left->left->right = nuovoNodo(3);

    // Stampa dell'albero
    printf("Stampa dell'albero in ordine antecedente (radice, left, right):\n");
    stampaAlbero(radice);
     printf("\n\n");
     
     stampavettore(radice);
    return 0;
}

// Funzione per creare un nuovo nodo
Albero nuovoNodo(int valore) {
    Albero nodo = (Albero) malloc(sizeof(Nodo));
    nodo->valore = valore;
    nodo->left = NULL;
    nodo->right = NULL;
    return nodo;
}

// Funzione per stampare l'albero
void stampaAlbero(Albero t) { print(t); printf("\n");}
void print(Albero t) {
    if (t == NULL)return;
    else {
        printf(" (");
        print(t->left);
        printf(" %d ", t->valore);
        print(t->right);
        printf(") ");
    }
}

void stampavettore(Albero t ){
	int d=contafoglie(t); // La dimensione del vettore
    int *v;

    v = (int *)malloc(d * sizeof(int));
    for(int i=0;i<d;i++){
    	v[i]=0;
	}
	int index=0;
	aux(t,v,&index,0);
	 //albero,vettore,indice,somma;
	for(int i=d-1;i>=0;i--)
	printf("%d\t",v[i]);
	//lo stampo al contrario ma non dovrebbe essere un problema.
	free(v); //mi chiede esplicitamente di deallocare
}

int contafoglie(Albero t){
	if(t==NULL) return 0;
	if(t->left==NULL && t->right==NULL) return 1;
	return contafoglie(t->left)+contafoglie(t->right);
}

void aux(Albero t,int v[],int *index,int somma){
	if(t==NULL) return;
	somma=somma+t->valore;
	if(t->left==NULL && t->right==NULL){
		v[*index]=somma;
		(*index)++;
	}
	
	aux(t->right,v,index,somma);
	aux(t->left,v,index,somma);
}

////// ESERCIZIO 4 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ATLETA (CF_ATLETA, Nome, Cognome, Nazione, Data_Nascita, Specialista)
GARA (ID_GARA, Disciplina, Data, Finale)
PARTECIPAZIONE (CF_ATLETA, ID_GARA, Tempo)

Finale è un booleano uguale a TRUE se la gara è una finale

Scrivere una query in SQL che estrae CF, Nome e Cognome degli atleti che hanno partecipato ad almeno due gare.
//devi ordinare le partecipazioni per cfatleta e contare idgara e questo count deve essere>=2
SELECT CF_ATLETA, A.NOME, A.COGNOME
FROM PARTECIPAZIONE P ,ATLETA A 
WHERE A.CF_ATLETA=P.CF_ATLETA
GROUP BY CF_ATLETA
HAVING COUNT(ID_GARA)>=2

Scrivere una query in SQL che estrae gli atleti mai arrivati a una finale
SELECT CF_ATLETA
FROM PARTECIPAZIONE P ,GARA G
WHERE P.ID_GARA=G.GARA_ID AND P.ID_GARA NOT IN (SELECT ID_GARA
                                                FROM GARA
												WHERE Finale=TRUE)

