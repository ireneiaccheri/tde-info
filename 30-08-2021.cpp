/////TDE 30/08/2021/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////ESERCIZIO 1/////////////////////////////////////////////////////////////////////////////////////////////////////////////////7
/*Scrivere una funzione (e tutte le funzioni ausiliarie necessaire) che riceve in ingresso una stringa, parola, e un carattere c. La funzione cerca in parola il carattere c e lo rimuove. La funzione, oltre a modificare l’array parola, restituisce il numero di caratteri eliminati. Nell’eliminare caratteri non devono essere lasciati buchi, ma parola dev’essere ricompattata.

Esempio

parola: supercalifragilistichespiralidoso

c: a

dopo l’esecuzione parola diventa: superclifrgilistichespirlidoso

e la funzione restituisce 3*/
#include <stdio.h>
#include <string.h>

int rimuovi(char str[100], char x);

int main() {
    char str[100] = "supercalifragilistichespiralidoso";
    char x;
    int count = 0; // Inizializza count a zero
    //printf(" seleziona carattere da eliminare:\t");
    //scanf("%c", &x);
    count = rimuovi(str, 'a'); // Aggiorna count con il valore restituito dalla funzione
    int i = 0;
    for (i = 0; str[i] != '\0'; i++) {
        printf("%c", str[i]);
    }
    printf("\nla parola è stata rimossa %d volte ", count);

    return 0;
}

int rimuovi(char str[100], char x) {
    int i, t, count = 0; // Inizializza count a zero
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == x) {
            count = count + 1;
            for (t = i; str[t - 1] != '\0'; t++)
                str[t] = str[t + 1];

            t = i;
        }
    }
    return count;
}


////ESERCIZIO 2///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Si codifichi in C una funzione conteggiLista che riceve in ingresso una lista di interi e 
alloca e restituisce una lista di tipo ListaRisultato

La lista restituita contiene, per ogni valore distinto contenuto nella lista in input, 
un nodo che contiene il valore e il numero di volte che questo si presenta nella lista di input*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nd1{
    int valore;
    struct nd1* next;
} Nodo;
typedef Nodo* Lista;

typedef struct nd2{
    int valore;
    int quanteVolte;
    struct nd2* next;
} NodoRisultato;
typedef NodoRisultato* ListaRisultato;

Lista costruisci();
Lista InsInFondo(Lista lista, int elem);
void stampaLista(Lista lista);
void stampaListaRisultato(ListaRisultato risulato);
int contapresenze(Lista lista,int elem);
int controllasegiapresente(Lista lis,int elem);
ListaRisultato finale(Lista lis);
int main(){
    Lista lista;
    lista = costruisci();
    printf("Lista in input:\n");
    stampaLista(lista);


    // TODO: chiamata funzion
    printf("Lista corretta:\n");
    stampaListaRisultato(finale(lista));

    return 0;
}


ListaRisultato InsInFondoLisOfRis( ListaRisultato lista,int elem,int quanteVolte ) {
    ListaRisultato punt;
    if( lista==NULL ) {
        punt =(ListaRisultato) malloc( sizeof(NodoRisultato) );
        punt->next = NULL;
        punt->valore = elem;
        punt->quanteVolte=quanteVolte;
        return punt;
    } else {
        lista->next = InsInFondoLisOfRis( lista->next, elem,quanteVolte );
        return lista;
    }
}
Lista costruisci(){
    Lista lista = NULL;
    lista = InsInFondo(lista, 3);
    lista = InsInFondo(lista, 5);
    lista = InsInFondo(lista, 1);
    lista = InsInFondo(lista, 4);
    lista = InsInFondo(lista, 3);
    lista = InsInFondo(lista, 4);
    lista = InsInFondo(lista, 3);
    lista = InsInFondo(lista, 4);
    lista = InsInFondo(lista, 1);
    lista = InsInFondo(lista, 8);
    return lista;
}

Lista InsInFondo(Lista lista, int elem){
    if(lista==NULL){
        Nodo* punt;
        punt = (Nodo*) malloc(sizeof(Nodo));
        punt->valore = elem;
        punt->next   = NULL;
        return punt;
    } else {
        lista->next = InsInFondo(lista->next, elem);
        return lista;
    }
}

void stampaLista(Lista lista){
    if(lista == NULL){
        printf("=||\n");
        return;
    } else {
        printf("%d -> ", lista->valore);
        stampaLista(lista->next);
    }
}

void stampaListaRisultato(ListaRisultato risultato){
    if(risultato == NULL){
        printf("=||\n");
        return;
    } else {
        printf("[%d (%d)] -> ", risultato->valore, risultato->quanteVolte);
        stampaListaRisultato(risultato->next);
    }
}

int contapresenze(Lista lista,int elem){
	int count=0;
	if(lista==NULL) return 0;
	while(lista!=NULL){
		if(lista->valore==elem){
			count++;
		}
		lista=lista->next;
	}
	return count;
}

int controllasegiapresente(ListaRisultato lis,int elem){
	if(lis==NULL) return 0;
	while(lis!=NULL){
		if(lis->valore==elem)
		return 1; //vuol dire che lo hai gia messo
		lis=lis->next;
	}

}

ListaRisultato finale(Lista lis){
	ListaRisultato fin=NULL;
	while(lis!=NULL){ ///deve esserci un tot di volte e non devo averlo gia messo
		if(contapresenze(lis,lis->valore)!=0 && !controllasegiapresente(fin,lis->valore)){
			fin=InsInFondoLisOfRis( fin,lis->valore,contapresenze(lis,lis->valore) );
		}
		lis=lis->next;
	}
	return fin;
}

///// ESERCIZIO 3 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Si scriva una funzione profonditaMassimaRipetizione che prende in ingresso un albero definito come sopra e restituisce
// la profondità massima alla quale compare un nodo contenente un valore uguale a quello contenuto nella radice. 
#include <stdio.h>
#include <stdlib.h>

typedef struct s_nodo {
        int val;
        struct s_nodo *left;
        struct s_nodo *right;
} nodo;
typedef nodo *albero;


albero creaAlbero();
albero createVal(int val);

void print(albero t);
void printConLivello(albero t,int liv);
int depth(albero t) ;
int max(int a,int b);
int f(albero t);

int main(){
  int ris=0;  
  albero alb = creaAlbero();
  print(alb);
  printf("\n");
  printConLivello(alb,1);
  printf("\n");
  
  //chiamata alla funzione da scrivere
  ris=f(alb);
  
  printf("la profodnita piu in giu in cui trovi 7 e %d", ris);
  fflush(stdin);
  return 0;
}
int depth(albero t) {
    
     //funzione da scrivere
     	if(t==NULL) return 0;////mi scrivo una funzione ausiliaria che mi dia il massimo
	return 1+max(depth(t->left),depth(t->right));
}

int max(int a,int b){
	if(a>b){
		return a;
	}else return b;
}

void verifica(albero T,int k,int liv,int v[]){
    if(T==NULL)
        return;
        
    if(T->val==k)
        v[liv]=1;
            
    verifica(T->left,k,liv+1,v);
    verifica(T->right,k,liv+1,v);
}


int f(albero T){
	int livelli,tutti=1,*v,i;
	
	livelli=depth(T);
	v=(int*)malloc(sizeof(int)*livelli);
	for(i=0;i<livelli;i++)
	    v[i]=0;
	    
   int k=T->val;
	verifica(T,k,0,v);
	
	for(i=livelli;i>0;i--){
               if(v[i]==1){
			   
                 return i;
                 break;}
           } 
           free(v);    
    
        
}


albero creaAlbero() {
       albero tmp = createVal(7);
       tmp->left = createVal(7);
       tmp->left->left = createVal(9);
       tmp->left->right = createVal(10);
       tmp->right = createVal(8);
       tmp->right->left = createVal(5);
       tmp->right->right = createVal(7);
       tmp->right->right->left = createVal(11);
       tmp->right->right->right = createVal(7);

       return tmp;
}

albero createVal(int val) {
       albero tmp = (albero)malloc(sizeof(nodo));
       tmp->val = val;
       tmp->left = NULL;
       tmp->right = NULL;
       return tmp;
}

void print(albero t){
       if(t==NULL)
           return;       
       printf(" (");
       print(t->left);
       printf(" %d ",t->val);      
       print(t->right);
       printf(") ");       
}

void printConLivello(albero t,int liv){
       if(t==NULL)
           return;       
       printf(" (");
       printConLivello(t->left,liv+1);
       printf("(v: %d, l: %d)",t->val,liv);      
       printConLivello(t->right,liv+1);
       printf(") ");       
}

//////ESERCIZIO 4 SQL//////////////////////////////////////////////////////////////////////////////////////////////
Il seguente database è utilizzato da negozio (per nostalgici) che consente di noleggiare CD
  
CD(CODICE, Autore, Titolo, Genere, Durata)
Noleggio(CODCD, CFCLIENTE, DATAINIZIO, DataRestituzione)
Cliente(CODICEFISCALE, Nome, Città)

Scrivere in SQL l’interrogazione che estrae il cliente che ha noleggiato più CD

SELECT cfcliente
FROM noleggio
GROUP BY  cfcliente
HAVING COUNT(*)>=ALL(SELECT COUNT(CFCLIENTE)
                     FROM Noleggio
					 GROUP BY cfcliente)


Scrivere in SQL l’interrogazione che estrae per ogni CD la prima prenotazione

SELECT (*)
FROM Noleggio N1
GROUP BY CODCD
HAVING DATAINIZIO<=ALL( SELECT DataInizio
                        FROM Noleggio N2
						WHERE N1.CODCD=N2.CODCD)
