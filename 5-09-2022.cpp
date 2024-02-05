//// TDE 5/09/2022 //////////////////////////////////////////////////////////////////////////////////////////////////////////

/////ESERCIZIO 1 ///////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Il grafico sotto mostra due grafici che rappresentano l’andamento nel tempo del segnale raccolto da due sensori.
 Nel main che segue i valori delle ordinate di questi grafici sono scritti in due vettori distinti, V1 e V2. 
 Si scriva una funzione trovaIncrocio che serve ad individuare la **prima volta** in cui i due grafici si intersecano. 
 In particolare, la funzione trovaIncrocio deve restituire un tipo di dato (che deve essere definito dallo studente) che permetta 
 di identificare quale dei due vettori ha un valore maggiore inizialmente e quale è la prima coppia di valori che inverte 
 questa tendenza. Per farlo la funzione trovaIncrocio prende in ingresso V1 e V2 (ed eventuali variabili aggiuntive) e 
 riporta al chiamante quattro valori che identificano le ordinate dei valori prima e dopo l’incrocio. Si assuma pure che i due vettori diano sempre luogo ad un incrocio e che la loro lunghezza effettiva sia definita in una variabile nel main. 
Si invochi la funzione trovaIncrocio nel main e si stampi il risultato nel seguito.

L’esempio di output
“Incrocio quando V1 prima vale 919 e poi 993, mentre V2 prima vale 1070 e poi 912”

La funzione trovaIncrocio non può stampare, la stampa deve avvenire nel main.*/

#include<stdio.h>
#define N 20

typedef struct{
	int v1iniz;
	int v1fin;
	int v2iniz;
	int v2fin;
}incrocio;
incrocio trovaincrocio(int v1[],int v2[],int n);
int main(){
    int v1[N] = {1122, 1123, 1177, 1083, 1050, 1010, 919, 993, 1076, 1205, 1325, 1393, 1399};
    int v2[N] =  {1322, 1318, 1316, 1166, 1096, 1112, 1070, 912, 1154, 1294, 1350, 1624, 1782};
    int n = 13; // dimensioni effettive;
    int i;
    incrocio rest=trovaincrocio(v1,v2,n);
    printf("\n v1 = [");
    for(i = 0; i < n; i++)
        printf("%d, ", v1[i]);

    printf("]\n v2 = [");
    for(i = 0; i < n; i++)
        printf("%d, ", v2[i]);
    printf("]\n");

    //INVOCARE QUI LA FUNZIONE E STAMPARE SOLO NEL MAIN
    printf("\n");
    printf("incrocio quando v1 prima vale %d e poi %d, mentre v2 prima vale %d e poi %d",rest.v1iniz,rest.v1fin,rest.v2iniz,rest.v2fin);
    
    return 0;

}

incrocio trovaincrocio(int v1[],int v2[],int n){
	incrocio ris;
	int i,index;
	for(i=0;i<n-1;i++){
		if(v1[i]<v2[i] && v1[i+1]>v2[i+1]){
		
		index=i;
		break;}
	}
	
	ris.v1iniz=v1[index];
	ris.v1fin=v1[index+1];
	ris.v2iniz=v2[index];
	ris.v2fin=v2[index+1];
	
	return ris;
}

////ESERCIZIO 2 /////////////////////////////////////////////////////////////////////////////////////////////////////////////7

/*Si considerino i seguenti tipi di dato atti a rappresentare i prodotti di un supermercato:
typedef struct { int giorno, mese, anno; } data 
	typedef struct ELP {
    char nome[50];
    data giorno_scadenza;
    struct ELP * next;
	} NodoP;
	typedef NodoP * ListaP;	
	typedef struct ELS {
     ListaP prodotti;
     struct ELS * next;
	} NodoS;
	typedef NodoS * ListaS;
Un supermercato è rappresentato da una lista di scaffali (ListaS), ed ogni scaffale (NodoS) contiene a sua volta una lista 
di prodotti (ListaP). Un prodotto (NodoP) è caratterizzato da un nome e da un giorno di scadenza.

Si scriva una funzione eliminaScaduti che riceve in ingresso una lista di scaffali ed una data G rappresentante un giorno 
dell’anno e che modifica la lista in ingresso eliminando dagli scaffali tutti i prodotti il cui giorno di scadenza è 
antecedente al giorno G in ingresso (se una scaffale resta vuoto lo si lasci pure come lista vuota).

Per risolvere l'esercizio si sviluppi e si invochi la funzione ausiliaria
int primaDi(Data d1, Data d2) 
che restituisce 1 se d1 è una data antecedente alla data d2, 0 altrimenti. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int giorno, mese, anno;
} Data;
typedef struct ELP {
    char nome[50];
    Data giorno_scadenza;
    struct ELP * next;
} NodoP;

typedef NodoP * ListaP;

typedef struct ELS {
    ListaP prodotti;
    struct ELS * next;
} NodoS;

typedef NodoS * ListaS;

/// Funzioni implementate
ListaP aggiungiProdotto(ListaP prodotti, char nome[50], int giorno, int mese, int anno);
ListaS costruisci();
void stampaData(Data d);
void stampaProdotto(NodoP* prodotto);
void stampaProdotti(ListaP prodotti);
void stampaScaffale(NodoS* scaffale);
void stampaScaffali(ListaS scaffali);
/// -------------------------

/// INSERIRE QUI PROTOTIPI E IMPLEMENTAZIONI DELLE FUNZIONI RICHIESTE
// TODO
ListaS eliminaScaduti(ListaS lis,Data G);
int primaDi(Data d1, Data d2);
ListaP Cancella( ListaP lista, char elem[],Data D );
ListaP esploraECancellaProd(ListaP lis,Data G);
ListaP InsInFondo( ListaP lista,char *elem,Data G );
/// -------------------------------------------------------------------
int primaDi(Data d1, Data d2)
{
//    restituisce 1 se d1 è una data antecedente alla data d2, 0 altrimenti.
    if(d1.anno<d2.anno)
        return 1;
    if(d1.anno==d2.anno&&d1.mese<d2.mese)
        return 1;
    if(d1.anno==d2.anno&&d1.mese==d2.mese&&d1.giorno<d2.giorno)
        return 1;
    return 0;
}
ListaS eliminaScaduti(ListaS lis,Data G)
{
    if(lis==NULL)
        return lis;
    while (lis!=NULL) {
        lis->prodotti=esploraECancellaProd(lis->prodotti, G);
        lis=lis->next;
    }
    return lis;
}
ListaP esploraECancellaProd(ListaP lis,Data G)
{
    ListaP nuova=NULL;
    if(lis==NULL)
        return lis;
    while (lis!=NULL) {
        if(primaDi(lis->giorno_scadenza, G)==0)
            nuova=InsInFondo(nuova, lis->nome, lis->giorno_scadenza);
        lis=lis->next;
    }
    return nuova;
}
ListaP InsInFondo( ListaP lista,char *elem,Data G ) {
    ListaP punt;
    if( lista==NULL ) {
        punt = (ListaP)malloc( sizeof(NodoP) );
        punt->next = NULL;
        strcpy(punt->nome, elem);
        punt->giorno_scadenza=G;
        return punt;
    } else {
        lista->next = InsInFondo( lista->next, elem,G );
        return lista;
    }
}
/// MAIN ED ALTRE FUNZIONI
int main(){
    ListaS scaffali = costruisci();
    Data G = {5, 9, 2022};
    printf("Data di scadenza: "); stampaData(G); printf("\n\n");
    printf("Prima della rimozione dei prodotti scaduti:\n");
    stampaScaffali(scaffali);

    /// INSERIRE QUI LE CHIAMATE A FUNZIONE
    // TODO
    /// -----------------------------------
    eliminaScaduti(scaffali, G);
    printf("Dopo la rimozione dei prodotti scaduti:\n");
    stampaScaffali(scaffali);
    return 0;
}

ListaP aggiungiProdotto(ListaP prodotti, char nome[50], int giorno, int mese, int anno){
    if(prodotti == NULL){
        prodotti = (ListaP) malloc(sizeof(NodoP));
        Data scad = {giorno, mese, anno}; strcpy(prodotti->nome, nome); prodotti->giorno_scadenza = scad; prodotti->next = NULL;
        return prodotti;
    } else { prodotti->next = aggiungiProdotto(prodotti->next, nome, giorno, mese, anno); return prodotti;}
}
ListaS costruisci(){
    ListaS scaffali = NULL;
    scaffali = (ListaS) malloc(sizeof(NodoS));scaffali->prodotti = NULL; scaffali->next = NULL;
    scaffali->prodotti = aggiungiProdotto(scaffali->prodotti, "Pasta", 14, 7, 2027);scaffali->prodotti = aggiungiProdotto(scaffali->prodotti, "Riso", 8, 11, 2020);scaffali->prodotti = aggiungiProdotto(scaffali->prodotti, "Farro", 9, 3, 2029);
    scaffali->next = (ListaS) malloc(sizeof(NodoS));scaffali->next->prodotti = NULL; scaffali->next->next = NULL;
    scaffali->next->prodotti = aggiungiProdotto(scaffali->next->prodotti, "Biscotti", 4, 6, 2020);scaffali->next->prodotti = aggiungiProdotto(scaffali->next->prodotti, "Cereali", 2, 7, 2025);scaffali->next->prodotti = aggiungiProdotto(scaffali->next->prodotti, "Toast", 1, 3, 2018);
    scaffali->next->next = (ListaS) malloc(sizeof(NodoS));scaffali->next->next->prodotti = NULL; scaffali->next->next->next = NULL;
    scaffali->next->next->prodotti = aggiungiProdotto(scaffali->next->next->prodotti, "More", 7, 9, 2016);scaffali->next->next->prodotti = aggiungiProdotto(scaffali->next->next->prodotti, "Lamponi", 25, 12, 2017);scaffali->next->next->prodotti = aggiungiProdotto(scaffali->next->next->prodotti, "Ribes", 18, 5, 2010);
    return scaffali;
}
void stampaData(Data d){ printf("%d/%d/%d", d.giorno, d.mese, d.anno); }
void stampaProdotto(NodoP* prodotto){printf(" ~ %s in scadenza il ", prodotto->nome);stampaData(prodotto->giorno_scadenza);}
void stampaProdotti(ListaP prodotti){
    if(prodotti == NULL){ printf(" * \n"); return; }
    stampaProdotto(prodotti); printf("\n"); stampaProdotti(prodotti->next);
}
void stampaScaffale(NodoS* scaffale){printf("+ - - -\n"); stampaProdotti(scaffale->prodotti);}
void stampaScaffali(ListaS scaffali){
    if(scaffali == NULL){ printf("+ _ _ _\n\n"); return; }
    stampaScaffale(scaffali);stampaScaffali(scaffali->next);
}

/////////7ESERCIZIO 4 ////////////////////////////////////////////////////////////////////////////////////////////////////////

CLIENTE (CODCLI, Nome, Citta, LavaggiTotali) 
VEICOLO (TARGA, Tipo, CodCli)
IMPIANTO (LOCALITÀ, NumeroLavaggi, DataApertura) 
LAVAGGIO (TARGA, DATA, ORAMINUTO, LOCALITÀ, Costo)

Scrivere in SQL l’interrogazione che estrae il Nome dei clienti residenti a Bergamo che non hanno mai lavato un 
veicolo di Tipo ”Motociclo”.

SELECT C.Nome 
FROM Cliente C,Lavaggio L, Veicolo V
WHERE Citta='Bergamo'
AND C.codcli=V.Codcli AND V.targa=L.targa AND V.Tipo<>'Motociclo'


Scrivere in SQL l’interrogazione che estrae la Località dell’impianto che ha effettuato il maggior numero di lavaggi.

SELECT Località
FROM IMPIANTO
WHERE NumeroLavaggi>= ALL(SELECT NumeroLavaggi
                          FROM Impianto)


/////ESERCIZIO 3 //////////////////////////////////////////////////////////////////////////////////////////////////////////7//
/*Si consideri un albero i cui nodi contengono un intero positivo tra 1 e 10 (estremi inclusi). Vogliamo misurare le fluttuazioni di valori in ciascun percorso radice-foglia. Per farlo, definiamo il punteggio di un nodo come segue.

Il punteggio del nodo radice è 0
Il punteggio di un nodo non-radice dipende dalla differenza in valore assoluto ? tra il valore del nodo ed il valore contenuto nel nodo genitore. Più nello specifico, il punteggio di un nodo è così definito:
Se ?<=3, il punteggio è 1;
Se ? è compreso nell’intervallo (3,5], il punteggio è 2 punto;
Se ? è compreso nell’intervallo (5,8], il punteggio è 3 punti;
Se ?>8, il punteggio è 4 punti.

Esempio di albero in input:
            5
         /    \
      5         5
     / \       /  \
   3    0   9    1
 /  \              / \
0   2          7   10

- il punteggio del nodo-foglia 0 (a sinistra) è 1
- il punteggio del nodo-foglia 10 (a destra) è 4

Si scriva una funzione calcolaPunteggi che riceve in input un Albero t1 e un Albero t2 con la stessa struttura di t1, ma inizialmente con tutti i nodi contenenti il valore 0. La funzione dovrà inserire in t2 i punteggi dei corrispondenti nodi di t1.

Esempio di output corrispondente all'input dato sopra:
           0
         /    \
      1         1
     / \       /  \
   1    2   2    2
 /  \              / \
1   1          3    4

che sarà stampato dal programma così:
( ( ( ( 1 )  1  ( 1 ) )  1  ( 2 ) )  0  ( ( 2 )  1  ( ( 3 )  2  ( 4 ) ) ) )*/

#include <stdio.h>
#include <stdlib.h>

typedef struct n {
        int val;
        struct n * left;
		struct n * right;
} nodo;
typedef nodo * albero;

albero createVal(int val);
albero creaAlbero1();albero creaAlbero2();
void print(albero t);
void stampa(albero T);
void f(albero input,albero risultato);
int depth(albero t);
int max(int a,int b);
void inizializza(albero t,int v[],int liv);
void verifica(albero t,int elem[],int v[],int liv);
int valass(int a,int b);
int delta(int a,int b);
int main(){
    int ris=0;
    albero input,risultato;
    input = creaAlbero1(); risultato = creaAlbero2(); 
    printf("\nalberi in input: "); stampa(input);
    printf("\nalbero risultato con solo 0: "); stampa(risultato);

   //LA FUNZIONE DA SVILUPPARE VIENE USATA QUI
   f(input,risultato);

   printf("\nalbero risultato dopo esecuzione della funzione\n");stampa(risultato);
   
   return 0;
}

//
// TODO: SVILUPPARE QUI DENTRO QUANTO RICHIESTO
//
void f(albero input,albero risultato){
      ///gli passi l albero di cui calcolare punteggi e un albero di solo 0 da modificare
      if(input==NULL) return;
      
     //confronti ogni nodo con il suo precedente e il delta lo metti nell albero
      if(input->left!=NULL && input->right!=NULL){
      	risultato->left->val=delta(input->val,input->left->val);
      	risultato->right->val=delta(input->val,input->right->val);
	  }
	  
	  f(input->right,risultato->right);
	  f(input->left,risultato->left);

}

albero creaAlbero1() {
    albero tmp = createVal(5);
    tmp->left = createVal(5);tmp->left->left = createVal(3);tmp->left->right = createVal(0);
    tmp->right = createVal(5);tmp->right->left = createVal(9);tmp->right->right = createVal(1);
    tmp->right->right->left = createVal(7); tmp->right->right->right = createVal(10);
    tmp->left->left->left = createVal(0); tmp->left->left->right = createVal(2);
    return tmp;
}

albero creaAlbero2() {
    albero tmp = createVal(0);
    tmp->left = createVal(0);tmp->left->left = createVal(0);tmp->left->right = createVal(0);
    tmp->right = createVal(0);tmp->right->left = createVal(0);tmp->right->right = createVal(0);
    tmp->right->right->left = createVal(0); tmp->right->right->right = createVal(0);
    tmp->left->left->left = createVal(0); tmp->left->left->right = createVal(0);
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

int delta(int a, int b){
	if(valass(b,a)>8) return 4;
	if(valass(b,a)<=3) return 1;
	if(valass(b,a)>3 && valass(b,a)<=5) return 2;
	if(valass(b,a)>5 && valass(b,a)<=8) return 3;
}

int valass(int a,int b){
	if(a-b>=0){
		return a-b;
	}else return b-a;
}
