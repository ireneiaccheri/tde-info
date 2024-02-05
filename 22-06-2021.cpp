////TDE 22/06/2021/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////ESERCIIO 1 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Si scriva una funzione che riceve in ingresso una matrice M quadrata NxN di interi e due indici di posizione r e c 
che rappresentano, rispettivamente, una riga e una colonna della matrice. La funzione restituisce 1 se tutti gli elementi 
posizionati sulla stessa riga o sulla stessa colonna dell’elemento in (r, c) sono maggiori di M[r][c], 0 altrimenti.

Si completi quindi il main sottostante invocando la funzione come da esempi riportati

    1   12    2    7
    4    3    5    5
    6    4    3    8
    7    5    2    4

 f invocata su M in posizioni r = 1, c = 1 restituisce 1
 f invocata su M in posizioni r = 1, c = 2 restituisce 0
 f invocata su M in posizioni r = 2, c = 3 restituisce 0*/

#include<stdio.h>
#define N 4
int checkriga(int mat[][N],int riga,int elem);
int checkcolonna(int mat[][N],int col,int elem);
int ris(int mat[][N],int r,int c);
int main(){
	int M[N][N]={1,12,2,7,4,3,5,5,6,4,3,8,7,5,2,4};

	//TODO: invocazioni funzioni
printf("%d",ris(M,1,1));
	//TODO: STAMPA --> ATTENZIONE: STAMPA CONSENTITA SOLO QUI <--

	return 0;
}
/// devono essere tutti maggiori;
///se ne trovi uno minore hai finito
int checkriga(int mat[][N],int riga,int elem){
	int si=1,i;
	for(i=0;i<N;i++ && si){
		if(mat[riga][i]<elem)
		si=0;
	}
	
	return si;
}

int checkcolonna(int mat[][N],int col,int elem){
	int si=1,i;
	for(i=0;i<N;i++ && si){
		if(mat[i][col]<elem)
		si=0;
	}
	
	return si;
}

int ris(int mat[][N],int r,int c){
	/// devono essere 1 sia la riga che la colonna
	if(checkcolonna(mat,c,mat[r][c]) && checkriga(mat,r,mat[r][c])){
		return 1;
	}
	return 0;

}

////ESERCIZIO 2 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////77
/*Scrivere una funzione "aggrega" che, data una lista i cui elementi sono liste di interi,
 restituisce una nuova lista di double i cui nodi contengono ognuno la media di una delle sottoliste.

Si consiglia di utilizzare funzioni ausiliarie per trattare e costruire liste, 
come illustrato a lezione e nella dispensa. Tutte le funzioni devono essere sviluppate subito dopo il main e 
prima delle funzioni fornite.

Output atteso:
Lista (ogni elemento in una riga)
5 ---> 4 ---> 6 ---> 5 ---> 3 ---> 7 ---> ---|
1 ---> 6 ---> 9 ---> 1 ---> 5 ---> 5 ---> 8 ---> 1 ---> ---|
1 ---> 5 ---> 1 ---> 1 ---> 1 ---> 1 ---> 8 ---> 7 ---> 2 ---> ---|
1 ---> 3 ---> 2 ---> 4 ---> 0 ---> ---|
1 ---> 2 ---> 8 ---> 8 ---> 4 ---> 0 ---> 9 ---> 0 ---> ---|

Lista delle medie
5 ---> 4.5 ---> 3 ---> 2 ---> 4 ---> ---|*/
#include<stdio.h>
#include<stdlib.h>

typedef struct EL {
	int info;
	struct EL * prox;
} ElemLista;

typedef ElemLista * SottoLista;

typedef struct ELD {
	double info;
	struct ELD * prox;
} ElemListaDouble;

typedef ElemListaDouble * ListaDouble;

typedef struct ELL {
	SottoLista lista;
	struct ELL * prox;
} NodoLista;
typedef NodoLista * ListaDiListe;

SottoLista InsInFondoInt(SottoLista lista,int elem );
ListaDouble InsInFondoDouble(ListaDouble lista,double elem );
ListaDiListe InsInFondoLista( ListaDiListe lista,SottoLista lis );
void VisualizzaListaDouble(ListaDouble lista );
void VisualizzaListaInt(SottoLista lista );
void VisualizzaListaDiListe(ListaDiListe lista );
ListaDiListe costruisci();
double calcolamedia(SottoLista lista);
ListaDouble risult(ListaDiListe lis);
//
// TODO: PROTOTIPI DELLE FUNZIONI RICHIESTE
//
int main(){
	ListaDiListe lis;
	ListaDouble ris=NULL;
	lis=costruisci();
	printf("Lista (ogni elemento in una riga)\n");
	VisualizzaListaDiListe(lis);

	//TODO: invocazione funzione

    printf("Lista delle medie\n");
	VisualizzaListaDouble(risult(lis));

	return 0;
}
//
// TODO: SVILUPPARE QUI LE FUNZIONI RICHIESTE
//
ListaDiListe costruisci(){
	int M[5][10]={5,4,6,5,3,7,-1,-1,-1,-1,
	              1,6,9,1,5,5,9,0,-1,-1,
				  1,5,1,1,1,1,8,9,0,-1,
				  1,3,2,4,0,-1,-1,-1,-1,-1,
				  1,2,8,8,4,0,9,0,-1,-1};
	int i,k;ListaDiListe ris=NULL; SottoLista temp=NULL;
	for(i=0;i<5;i++){
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

ListaDouble InsInFondoDouble(ListaDouble lista,double elem ) {
    ListaDouble punt;
    if(lista==NULL) { punt = (ListaDouble)malloc( sizeof(ElemLista) );
                     punt->prox = NULL; punt->info = elem; return  punt;
    }else{lista->prox = InsInFondoDouble(lista->prox,elem); return lista;}
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
void VisualizzaListaDouble(ListaDouble lista) {
    if (lista==NULL) printf(" ---| \n");
    else{printf(" %lf ---> ", lista->info); VisualizzaListaDouble( lista->prox );}
}
void VisualizzaListaDiListe( ListaDiListe lista ) {
    if(lista==NULL) printf("\n");
    else{VisualizzaListaInt(lista->lista); VisualizzaListaDiListe(lista->prox);}
}
///FUNZIONE PER CALCOLARE LA MEDIA DI UNA LISTA
double calcolamedia(SottoLista lis){
	if(lis==NULL) return 0;
	double somma=0;
	int cont;
	while(lis!=NULL){
		somma=somma+lis->info;
		cont++;
		lis=lis->prox;
	}
		return somma/cont;
}

///FUNZIONE PER CREARE NUOVA LISTA
ListaDouble risult(ListaDiListe lis){
	ListaDouble rest=NULL;
	while(lis!=NULL){
		rest=InsInFondoDouble(rest,calcolamedia(lis->lista));
		lis=lis->prox;
	}
	return rest;
}

//// ESRCIZIO 3 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Si scriva una funzione che riceve in ingresso un albero T e verifica se tutti gli elementi dell’albero 
hanno un valore superiore al livello dell’albero in cui sono, 0 altrimenti.

Dati gli alberi e le stampe nel alberi.c l'output atteso è:
T1: ( ( ( 9 ) 3 ( 10 ) ) 7 ( ( 5 ) 8 ( ( 11 ) 12 ( 6 ) ) ) )
T2: ( ( ( ( 6 ) 12 ( 11 ) ) 1 ( 5 ) ) 7 ( ( 10 ) 3 ( 9 ) ) )
T3: ( ( ( ( 6 ) 12 ( 2 ) ) 4 ( 5 ) ) 7 ( ( 10 ) 3 ( 9 ) ) )
T1 ok
T2 non ok
T3 non ok*/
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
int check(albero t);
void aux(albero t, int *v,int livello);
int main(){
    int ris=0;
    albero T1,T2,T3;
    T1 = creaAlbero1(); T2 = creaAlbero2(); T3 = creaAlbero3();
    printf("\nT1: "); stampa(T1);
    printf("\nT2: "); stampa(T2);
    printf("\nT3: "); stampa(T3);

   //LA FUNZIONE DA SVILUPPARE VIENE USATA QUI


   if(check(T1)==1)
        printf("T1 ok\n");
    else printf("T1 non ok\n");

   if(check(T2)==1)
        printf("T2 ok\n");
    else printf("T2 non ok\n");

   if(check(T3)==1)
        printf("T3 ok\n");
    else printf("T3 non ok\n");

    return 0;
}

//
// TODO: SVILUPPARE QUI DENTRO QUANTO RICHIESTO
//
int depth(albero t ){
	if(t==NULL) return 0;
	int s=depth(t->left);
	int d=depth(t->right);
	if(s>d){
	return 1+s;}else return 1+d;
	
}
int check(albero t){
    int ris=0,*v;
    int livelli=depth(t);
	v=(int*)malloc(sizeof(int)*livelli);
    //SVILUPPARE QUI QUANTO RICHIESTO 
	//FUNZIONI AUSILIARIE CON PARAMETRI AGGIUNTIVI SONO MOLTO CONSIGLIATE
	
    int i;
    for(i=0;i<livelli;i++){
    	v[i]=1;
	}
	//inizializzi tutti a 1, se ne trovi anche solo uno ch e stato messo a 0, la proprieta non e verficata e quindi ritorni 0
	aux(t,v,0); // se ne trovi uno piu piccolo lo metti a 0
	for(i=0;i<livelli;i++){
		if(v[i]==0) return 0;
	}

    return 1;
}

void aux(albero t, int *v,int livello){
	if(t==NULL) return;
	if(t->val<=livello) v[livello]=0;
	aux(t->left,v,livello+1);
	aux(t->right,v,livello+1);

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
    tmp->left = createVal(1);tmp->left->right = createVal(5);tmp->left->left = createVal(12);
    tmp->left->left->right = createVal(11);tmp->left->left->left = createVal(6);
    return tmp;
}

albero creaAlbero3() {
    albero tmp = createVal(7);
    tmp->right = createVal(3);tmp->right->right = createVal(9);tmp->right->left = createVal(10);
    tmp->left = createVal(4);tmp->left->right = createVal(5);tmp->left->left = createVal(12);
    tmp->left->left->right = createVal(2);tmp->left->left->left = createVal(6);
    return tmp;
}

void print(albero t){
       if(t==NULL)return;       
       else{printf(" (");print(t->left);printf(" %d ",t->val);print(t->right);printf(") ");}       
}

void stampa(albero T){print(T);printf("\n");}

albero createVal(int val) {
    albero tmp =(albero) malloc(sizeof(nodo));
    tmp->val = val;    tmp->left = NULL;    tmp->right = NULL;
    return tmp;
}

///// ESERCIIO 4 SQL//////////////////////////////////////////////////////////////////////////////////////////////////////////////

DIPENDENTE(MATRICOLA, nome, qualifica, settore)
VIAGGIO(CODICE, matrDipendente, citta, data, km, targaAuto)
AUTO(TARGA, modello, costo-km)
DESTINAZIONE(NOME, stato)



Query 1: Esprimere in SQL l’interrogazione che estrae il nome dei dipendenti che non hanno mai fatto un viaggio più lungo di 95 km
SELECT nome 
FROM Dipendente
WHERE Matricola NOT IN( SELECT matrDipendente
                        FROM VIAGGIO
						WHERE km>95)

Query 2: Esprimere in SQL l’interrogazione che, per ogni settore riporta tutte le destinazioni
 in cui un dipendente si è recato in viaggio almeno una volta e quanti viaggi sono stati fatti verso quella meta.
 
SELECT DI.settore,Citta,count(*)
 FROM Viaggio V,Destinazione D,Dipendente DI
 GROUP BY MatrDipendente,Città
 

 

