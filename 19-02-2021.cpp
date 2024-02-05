//// TDE 19-02-2021 ///
/// ESERCIZIO 1 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Scrivere una funzione "contaSottomatriciPari" che riceve una matrice M di interi, 
un intero h ed un intero k e restituisce il numero di sottomatrici di M di dimensione h x h contenenti esattamente k valori pari 
(date pure per scontato che nelle chiamate 1<h<N con N dimensione della matrice).

Si completi quindi il main sottostante invocando la funzione come da esempi riportati

1    2    0    1
0    3    0    2
0    3    1    2
1    1    2    4

In M ci sono 0 sottomatrici 3x3 aventi 2 numeri pari
In M ci sono 2 sottomatrici 2x2 aventi 2 numeri pari
In M ci sono 3 sottomatrici 2x2 aventi 1 numeri pari*/

#include<stdio.h>
#define N 4
int risultato(int mat[][N],int h,int k);
int aux(int mat[][N],int riga,int colonna,int h);
int main(){
	int M[N][N]={1,2,0,1,0,3,0,2,0,3,1,2,1,1,2,4};
	int h,k;
	//TODO: invocazioni funzioni
	printf("inserire dimensione sottomatrice:\t");
	scanf("%d",&h);
	printf("\ninserire quanti valori pari si vuole trovare:\t");
	scanf("%d",&k);
     printf("\n\n");
     printf("le sottomatrici di dimensione %d contenenti %d numeri pari sono %d",h,k,risultato(M,h,k));
	//TODO: STAMPA --> ATTENZIONE: STAMPA CONSENTITA SOLO QUI <--

	return 0;
}

int risultato(int mat[][N],int h,int k){
	int i,j,count=0;
	for(i=0;i<N-h+1;i++){
		for(j=0;j<N-h+1;j++){
			if(aux(mat,i,j,h)==k)// i numeri pari che contono devono essere uguali a k(richiesto da utente)///
			count++; // mi conta quante sottomatrici che rispettano la proprietà ho///
		}
	}
	return count;
}

int aux(int mat[][N],int colonna,int riga,int h){
	int i,j,contapari=0;
	for(i=colonna;i<colonna+h;i++){ //ogni volta gli passo una riga e colonna diversa da cui partire a scorrere e si muove di h///
		for(j=riga;j<riga+h;j++){
			if(mat[i][j]%2==0) ///restituisco quanti numeri pari ho trovato///
			contapari++;
		}
	}
	return contapari;
}

/////ESERCIZIO 2//////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Scrivere una funzione "pulisci" che, data una lista i cui elementi sono liste di interi, 
elimina tutte le sottoliste che non contengono valori ripetuti.


Scrivere le funzioni necessarie per svolgere l'esercizio subito dopo il main e prima delle funzioni fornite.

Output atteso:
Lista (ogni elemento in una riga)   
5 --->  4 --->  1 --->  5 --->  2 --->  7 --->  ---|   
1 --->  6 --->  9 --->  1 --->  5 --->  7 --->  9 --->  0 --->  ---|   
1 --->  5 --->  1 --->  1 --->  2 --->  8 --->  9 --->  0 --->  ---|   
1 --->  3 --->  2 --->  4 --->  0 --->  9 --->  8 --->  6 --->  ---|     
1 --->  2 --->  9 --->  8 --->  4 --->  0 --->  9 --->  0 --->  ---|     
1 --->  8 --->  7 --->  8 --->  3 --->  ---|                              
1 --->  3 --->  4 --->  2 --->  5 --->  7 --->  9 --->  0 --->  ---|     
7 --->  8 --->  9 --->  ---|                                                                                                 

Lista dopo pulizia
5 --->  4 --->  1 --->  5 --->  2 --->  7 --->  ---|   
1 --->  6 --->  9 --->  1 --->  5 --->  7 --->  9 --->  0 --->  ---|
1 --->  5 --->  1 --->  1 --->  2 --->  8 --->  9 --->  0 --->  ---|
1 --->  8 --->  7 --->  8 --->  3 --->  ---|                              
1 --->  2 --->  9 ---> 8 --->  4 --->  0 --->  9 --->  0 --->  ---|*/

#include<stdio.h>
#include<stdlib.h>

typedef struct EL {
	int info;
	struct EL * prox;
} ElemLista;

typedef ElemLista * SottoLista;

typedef struct ELL {
	SottoLista lista;
	struct ELL * prox;
} NodoLista;
typedef NodoLista * ListaDiListe;

SottoLista InsInFondoInt(SottoLista lista,int elem );
ListaDiListe InsInFondoLista( ListaDiListe lista,SottoLista lis );
void VisualizzaListaInt(SottoLista lista );
void VisualizzaListaDiListe(ListaDiListe lista );
ListaDiListe costruisci();
////funz che mi cerca se ci sono duplicati////
int duplicati(SottoLista lis);
ListaDiListe checker(ListaDiListe lis );

int main(){
	ListaDiListe lis;
	lis=costruisci();
	printf("Lista (ogni elemento in una riga)\n");
	VisualizzaListaDiListe(lis);

	//TODO: invocazione funzione
    
    printf("Lista dopo pulizia\n");
	VisualizzaListaDiListe(checker(lis));

	return 0;
}

//
// TODO: SVILUPPARE QUI LE FUNZIONI RICHIESTE
//


ListaDiListe costruisci(){
	int M[8][10]={5,4,1,5,2,7,-1,-1,-1,-1,1,6,9,1,5,7,9,0,-1,-1,1,5,1,1,2,8,9,0,-1,-1,
				  1,3,2,4,0,9,8,6,-1,-1,1,2,9,8,4,0,9,0,-1,-1,1,8,7,8,3,-1,-1,-1,-1,-1,
				  1,3,4,2,5,7,9,0,-1,-1,7,8,9,-1,-1,-1,-1,-1,-1,-1};
	int i,k;ListaDiListe ris=NULL; SottoLista temp=NULL;
	for(i=0;i<8;i++){
		temp=NULL;for(k=0;k<10;k++)if(M[i][k]!=-1)temp=InsInFondoInt(temp,M[i][k]);
		ris=InsInFondoLista(ris,temp);}
	return ris;
}

SottoLista InsInFondoInt(SottoLista lista,int elem ) {
    SottoLista punt;
    if(lista==NULL) { punt = (SottoLista)malloc( sizeof(ElemLista) );
                     punt->prox = NULL; punt->info = elem; return  punt;
    }else{lista->prox = InsInFondoInt(lista->prox,elem); return lista;}
}

ListaDiListe InsInFondoLista(ListaDiListe lista,SottoLista lis ) {
   ListaDiListe punt;
   if(lista==NULL) { punt = (ListaDiListe)malloc( sizeof(NodoLista) );
                     punt->prox=NULL; punt->lista=lis; return  punt;
   }else{lista->prox = InsInFondoLista(lista->prox,lis); return lista;}
}

void VisualizzaListaInt(SottoLista lista) {
    if (lista==NULL) printf(" ---| \n");
    else{printf(" %d ---> ", lista->info); VisualizzaListaInt( lista->prox );}
}
void VisualizzaListaDiListe( ListaDiListe lista ) {
    if(lista==NULL) printf("\n");
    else{VisualizzaListaInt(lista->lista); VisualizzaListaDiListe(lista->prox);}
}
///funz 1///
int duplicati(SottoLista lis){
	SottoLista cur=lis;
	while(lis!=NULL){
		while(cur!=NULL){
			if(cur->info==lis->info && cur!=lis)
			return 1;
			cur=cur->prox;
		}
		lis=lis->prox;
	}
	return 0;
}

////funz 2/////
ListaDiListe checker(ListaDiListe lis){
	int q;
	if(lis->prox!=NULL)
		lis->prox=checker(lis->prox);

	if(duplicati(lis->lista))
		return lis->prox;
	else 
		return lis;
	
}  //eventualmente da modificare con funzioni di cancellazione//    


////////// ESERCIZIO 3 /////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Si scriva una funzione “simmetrici” che dati due alberi binari restituisce 1 se i due alberi sono simmetrici, 0 altrimenti. 

Esempio:
T1:  ( ( ( 9 )  3  ( 10 ) )  7  ( ( 5 )  8  ( ( 11 )  12  ( 6 ) ) ) )
T2:  ( ( ( ( 6 )  12  ( 11 ) )  8  ( 5 ) )  7  ( ( 10 )  3  ( 9 ) ) )
T3:  ( ( ( ( 6 )  12  ( 11 ) )  4  ( 5 ) )  7  ( ( 10 )  3  ( 9 ) ) ) 

T1 e T2 sono simmetrici   
T1 e T3 non sono simmetrici  */

#include <stdio.h>
#include <stdlib.h>

typedef struct n {
        int val;
        struct n * left;
		struct n * right;
} nodo;
typedef nodo * albero;

albero createVal(int val);
albero creaAlbero1();albero creaAlbero2();albero creaAlbero3();
void print(albero t);
void stampa(albero T);
int f(albero t1,albero t2);

int main(){
    int ris=0;
    albero T1,T2,T3;
    T1 = creaAlbero1(); T2 = creaAlbero2(); T3 = creaAlbero3();
    printf("\nT1: "); stampa(T1);
    printf("\nT2: "); stampa(T2);
    printf("\nT3: "); stampa(T3);

   //LA FUNZIONE DA SVILUPPARE VIENE USATA QUI
   if(f(T1,T2)==1)
        printf("T1 e T2 sono simmetrici\n");
    else printf("T1 e T2 non sono simmetrici\n");

    if(f(T1,T3)==1)
        printf("T1 e T3 sono simmetrici\n");
    else printf("T1 e T3 non sono simmetrici\n");
   
    return 0;
}

//
// TODO: SVILUPPARE QUI DENTRO QUANTO RICHIESTO
//
int f(albero t1,albero t2){
    int ris;
   if(t1==NULL && t2==NULL) return 1;
   if(t1==NULL || t2==NULL) return 0;
   return ((t1->val== t2->val) && f(t1->right,t2->left) && f(t1->left,t2->right));
    
}

albero creaAlbero1() {
    albero tmp = createVal(7);
    tmp->left = createVal(3);tmp->left->left = createVal(9);tmp->left->right = createVal(10);
    tmp->right = createVal(8);tmp->right->left = createVal(5);tmp->right->right = createVal(12);
    tmp->right->right->left = createVal(11); tmp->right->right->right = createVal(6);
    return tmp;
}

albero creaAlbero2() {
    albero tmp = createVal(7);
    tmp->right = createVal(3);tmp->right->right = createVal(9);tmp->right->left = createVal(10);
    tmp->left = createVal(8);tmp->left->right = createVal(5);tmp->left->left = createVal(12);
    tmp->left->left->right = createVal(11);tmp->left->left->left = createVal(6);
    return tmp;
}

albero creaAlbero3() {
    albero tmp = createVal(7);
    tmp->right = createVal(3);tmp->right->right = createVal(9);tmp->right->left = createVal(10);
    tmp->left = createVal(4);tmp->left->right = createVal(5);tmp->left->left = createVal(12);
    tmp->left->left->right = createVal(11);tmp->left->left->left = createVal(6);
    return tmp;
}

void print(albero t){
       if(t==NULL)return;       
       else{printf(" (");print(t->left);printf(" %d ",t->val);print(t->right);printf(") ");}       
}

void stampa(albero T){print(T);printf("\n");}

albero createVal(int val) {
    albero tmp = (albero)malloc(sizeof(nodo));
    tmp->val = val;    tmp->left = NULL;    tmp->right = NULL;
    return tmp;
}


///// ESERCIZIO 4 SQL/////////////////////////////////////////////////////////////////////////////////////////////////////////////

Il seguente schema rappresenta le informazioni riguardo al noleggio di automobili 
(gli attributi scritti interamente in maiuscolo sono chiavi):
Auto ( TARGA, Modello, Marca )
Cliente ( CF, Nome, Cognome, Indirizzo, Telefono, Convenzione )
Noleggio ( CF, TARGA, DATAINIZIO, DataFine, CostoAlGiorno, Giorni, Km )

Scrivere una query che estrae per ogni auto il numero totale di noleggi.

SELECT count(*) ///di ogni gruppetto di targhe conto quante righe ci sono---> ho estratto il numero di noleggi///
FROM Noleggio
GROUP BY Targa /// non ho nessuna condizione aggiuntiva da limitare nel where--->raggruppo semplicemente per targa///

Scrivere una query che estrae i clienti che non hanno mai noleggiato auto che costano meno di 500 euro al giorno.

SELECT CF //estraggo codice fiscale
FROM Cliente
WHERE CF NOT IN ( SELECT CF //elenco clienti che prendono macchine <500----> non ci deve essere in mezzo
                  FROM Noleggio
				  WHERE Costoalgiorno< 500)

