/// TDE 5/07/2023 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////7

///// ESERCIZIO 1 /////////////////////////////////////////////////////////////////////////////////////////////////////////////7///
/*Si scriva una funzione verificaCorrispondenza che prende in ingresso un vettore v di dimensione N e una matrice M di dimensione 
Nx4 e che verifica che ogni elemento di v corrisponde alla somma di una riga di M 
(non necessariamente il primo elemento è la somma della prima riga o il secondo elemento della seconda riga…). 
Se la proprietà è verificata la funzione verificaCorrispondenza restituisce 1, altrimenti 0. Nella funzione da implementare non 
è ammesso usare istruzioni di stampa, il risultato restituito sarà usato nel main per decidere cosa stampare. 
Si supponga per semplicità che non esistano due righe con la stessa somma. Si noti che (come anche negli esempi nel main) 
le dimensioni di vettori e matrici non sono tutti uguali, ma le matrici hanno sempre esattamente 4 colonne.

Si parta dal main nel file:
https://www.dropbox.com/s/veke23itldlxs1h/matriciTesto.c?dl=0 

Con file fornito l’output deve essere

Risultato 1: Corrisponde
Risultato 2: Corrisponde
Risultato 3: Corrisponde
Risultato 4: Non corrisponde
Risultato 5: Non corrisponde*/
#include <stdio.h>

void stampa(int N, int v[], int M[][4]);
int somma(int mat[][4],int quale);
int cerca(int elem,int v[],int dim);
int verifica(int mat[][4],int v[],int N);

int main() {
    int v1[] = {14, 6, 10, 8};
    int M1[][4] = {{1, 2, 3, 4},
                   {0, 1, 2, 3},
                   {4, 3, 6, 1},
                   {2, 2, 2, 2}};
    int v2[] = {4, 6, 8};
    int M2[][4] = {{1, 1, 1, 1},
                   {0, 2, 2, 2},
                   {1, 2, 3, 2}};
    int v3[] = {10, 20};
    int M3[][4] = {{1, 2, 3, 4},
                   {2, 4, 6, 8}};
    int v4[] = {3, 5, 9};
    int M4[][4] = {{1, 1, 1, 1},
                   {0, 2, 2, 2},
                   {1, 2, 7, 2}};
    int v5[] = {10, 6, 16, 8};
    int M5[][4] = {{1, 2, 3, 4},
                   {0, 1, 2, 3},
                   {5, 3, 2, 1},
                   {2, 2, 2, 2}};

	printf("%d",verifica(M5,v5,4));    
    
    return 0;
}

void stampa(int N, int v[], int M[][4]) {
	int i,j;
	printf("Vettore\n");
    for (i = 0; i < N; i++) {
    	printf("%d ",v[i]);
    }
    printf("\nMatrice\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ",M[i][j]);
        }
		printf("\n");
    }
    printf("\n\n");
}
///funzione per sommare quelli di una riga/////////
int somma(int mat[][4],int quale){
	int i,somma=0;
	for(i=0;i<4;i++){
		somma=somma+mat[quale][i];
	}
	return somma;
}

////funzione per verificare la presenza di un numero in un vettore////
int cerca(int elem,int v[],int dim){
	int i;
	for(i=0;i<dim;i++){
		if(v[i]==elem)
		return 1;//--->se lo trovo restituisco 1 
	}
	return 0;
}

//funzione finale per controllare--->se ne trovo uno che non corrisponde restiuisco 0;
int verifica(int mat[][4],int v[],int N){
	int i;
	for(i=0;i<N;i++){
		if(!cerca(somma(mat,i),v,N))
		return 0;
	}
	return 1;
}

//////ESERCIZIO 2 //////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Si considerino le seguente definizioni di lista rappresentante poligoni in un piano cartesiano

typedef struct P {float x,y;
                          Struct P * next; } Punto;
typedef Punto * Poligono;

typedef struct S {Poligono lisP;
                          Struct S * next; } Pol;
typedef Pol * ListaPoligoni;

Si scriva una funzione mediaListaPoligoni che riceve una ListaPoligoni, e calcola la media dei perimetri. 
Si scriva poi una funzione rimuoviPoligoniCorti che riceve una ListaPoligoni, oltre ad altri parametri se ritenuti necessari, 
e elimina tutti i poligoni con perimetro sotto la media calcolata prima di iniziare a cancellare.

Si noti che i poligoni contenuti nelle variabili ListaPoligoni non sono chiusi. 
Il primo e l'ultimo punto non coincidono e per il calcolo del perimetro è necessario unirli.

Si parta dal file:
https://www.dropbox.com/s/xj2evk8pjpfoz5e/ListeTesto.c?dl=0

Coi dati del file fornito l’output deve essere
Lista iniziale:
 (0.00,0.00) --->  (1.00,0.00) --->  (2.00,2.00) --->  (1.00,1.00) --->  ---|
 (1.00,6.00) --->  (9.00,1.00) --->  (5.00,5.00) --->  (1.00,9.00) --->  (0.00,8.00) --->  ---|
 (1.00,3.00) --->  (1.00,4.00) --->  (4.00,4.00) --->  (4.00,2.00) --->  (3.00,1.00) --->  ---|
 (1.00,3.00) --->  (2.00,4.00) --->  (0.00,2.00) --->  (0.00,0.00) --->  ---|
 (1.00,32.00) --->  (8.00,8.00) --->  (5.00,0.00) --->  ---|

Media dei perimetri: 23.18
Lista dopo l'eliminazione dei poligoni con perimetro sotto la media:
 (1.00,6.00) --->  (9.00,1.00) --->  (5.00,5.00) --->  (1.00,9.00) --->  (0.00,8.00) --->  ---|
 (1.00,32.00) --->  (8.00,8.00) --->  (5.00,0.00) --->  ---|*/
 #include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct P {
    float x, y;
    struct P *next;
} Punto;

typedef Punto *Poligono;

typedef struct S {
    Poligono lisP;
    struct S *next;
} Pol;

typedef Pol *ListaPoligoni;

ListaPoligoni costruisci();
Poligono InsInFondoPunto(Poligono lista,float x,float y);
ListaPoligoni InsInFondoPoligono( ListaPoligoni lista,Poligono lis );
void VisualizzaPoligono(Poligono lista );
void VisualizzaListaPoligoni(ListaPoligoni lista );
float distanza(Punto * p1,Punto * p2);
float perimetro(Poligono pol);
float media(ListaPoligoni lis);
void DistruggiListaRic (Poligono lista );
ListaPoligoni finale(ListaPoligoni lis);
//AGGIUNGERE QUI PROTOTIPI


int main() {
    // Creazione di una lista di poligoni di esempio
    ListaPoligoni lista=costruisci();

    printf("Lista iniziale:\n");
    VisualizzaListaPoligoni(lista);

    //INSERIRE QUI INVOCAZIONI E STAMPA MEDIA PERIMETRI
printf("%f",media(lista));
    printf("Lista dopo l'eliminazione dei poligoni con perimetro sotto la media:\n");
    VisualizzaListaPoligoni(finale(lista));

    return 0;
}

//AGGIUNGERE QUI LE FUNZIONI

ListaPoligoni costruisci(){
	int M[5][10]={0,0,1,0,2,2,1,1,-1,-1,
	              1,6,9,1,5,5,1,9,0,8,
				  1,3,1,4,4,4,4,2,3,1,
				  1,3,2,4,0,2,0,0,-1,-1,
				  1,32,8,8,5,0,-1,-1,-1,-1};
	int i,k;ListaPoligoni ris=NULL; Poligono temp=NULL;
	for(i=0;i<5;i++){
		temp=NULL;for(k=0;k<10;k=k+2)if(M[i][k]!=-1)temp=InsInFondoPunto(temp,M[i][k],M[i][k+1]);
		ris=InsInFondoPoligono(ris,temp);}
	return ris;
}


Poligono InsInFondoPunto(Poligono lista,float x,float y) {
    Poligono punt;
    if(lista==NULL) { punt = (Poligono)malloc( sizeof(Punto) );
                     punt->next = NULL; punt->x = x; punt->y = y; return  punt;
    }else{lista->next = InsInFondoPunto(lista->next,x,y); return lista;}
}

ListaPoligoni InsInFondoPoligono( ListaPoligoni lista,Poligono lis ) {
   ListaPoligoni punt;
   if(lista==NULL) { punt = (ListaPoligoni)malloc( sizeof(Pol) );
                     punt->next=NULL; punt->lisP=lis; return  punt;
   }else{lista->next = InsInFondoPoligono(lista->next,lis); return lista;}
}

void VisualizzaPoligono(Poligono lista ){
    if (lista==NULL) printf(" ---| \n");
    else{printf(" (%.2f,%.2f) ---> ", lista->x, lista->y); VisualizzaPoligono( lista->next );}
}

void VisualizzaListaPoligoni(ListaPoligoni lista ) {
    if(lista==NULL) printf("\n");
    else{VisualizzaPoligono(lista->lisP); VisualizzaListaPoligoni(lista->next);}
}

float distanza(Punto * p1,Punto * p2){
	return sqrt((p1->x-p2->x)*(p1->x-p2->x)+(p1->y-p2->y)*(p1->y-p2->y));
}


float perimetro(Poligono pol){
	Poligono testa=pol;
	float per;
	while(pol!=NULL && pol->next!=NULL){
		per=per+distanza(pol,pol->next);
		pol=pol->next;
	}
	
	per=per+distanza(testa,pol);
	return per;	
}

float media(ListaPoligoni lis){
	float somma=0;
	int count=0;
	while(lis!=NULL){
		somma=somma+perimetro(lis->lisP);
		count++;
		lis=lis->next;
	}
		return somma/count;
}

void DistruggiListaRic (Poligono lista ) {
    if ( lista!=NULL ) {
	    DistruggiListaRic( lista->next ); free( lista );
	}
}

ListaPoligoni Cancella( ListaPoligoni lista,float d ) {
	ListaPoligoni cur=lista;
 
    ListaPoligoni puntTemp;
	if( lista!=NULL)
	    if( perimetro(lista->lisP)<d) {
		    puntTemp = lista->next;
			free( lista );
			return Cancella(puntTemp,d);; // per cancellare tutte le istanze: return 
        }
		else
		    lista->next= Cancella( lista->next,d);
		return lista;
}
////se io metto un d variabile mi si aggiorna al modificarsi della lista--->devo passarlo come "costante"


///// ESERCIZIO 3 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Sia data la seguente definizione di un albero contenente un carattere in ogni nodo.

typedef struct El{
char c;
struct El *left, *right;
}Nodo;

typedef Nodo *Tree;


Un albero si dice ordinato se ogni nodo soddisfa le seguenti condizione:
- il figlio di sinistra (se esiste) contiene un carattere che precede il carattere nel nodo
- il figlio di destra (se esiste) contiene un carattere che segue il carattere nel nodo
si assuma che l'albero non abbia caratteri replicati.

Si scriva una funzione verifica che controlla se un albero è ordinato o meno.

Ecco due esempi di invocazione della funzione

( ( ( b )  d )  k  ( ( p )  q  ( z ) ) )  
albero ordinato   

( ( ( b )  w )  k  ( ( p )  q  ( z ) ) )    
albero NON ordinato  */
#include <stdio.h>
#include <stdlib.h>
typedef struct El {
    char c;
    struct El * left, * right;
} Nodo;

typedef Nodo* Tree;
int precede(char a, char b);
int f(Tree albero);
Tree costruisci1();
Tree costruisci2();
void visualizzaAlbero(Tree albero);

int main() {
    int risultato1,risultato2;
	Tree albero1,albero2;
    albero1=costruisci1();
    albero2=costruisci2();
    visualizzaAlbero(albero1);
    printf("\n");
    visualizzaAlbero(albero2);
    printf("\n");
    risultato1 = f(albero1);
    risultato2 = f(albero2);

    if (risultato1) {
        printf("Albero 1: albero ordinato\n");
    } else {
        printf("Albero 1: albero NON ordinato\n");
    }

    if (risultato2) {
        printf("Albero 2: albero ordinato\n");
    } else {
        printf("Albero 2: albero NON ordinato\n");
    }

    return 0;
}

int check(Tree t) {
    if (t == NULL) return 1;
//////DEVI CONSIDERARE TUTTI I CASI//////////
///HO SOLO FIGLIO SINISTRO ED E MAGGIORE------->RETURN 0
    if (t->left != NULL && t->left->c >= t->c) return 0;

////HO SOLO FIGLIO DESTRO ED E MINORE----------->RETURN 0
    if (t->right != NULL && t->right->c <= t->c) return 0;

/////SE ANCHE SOLO UNO DEI DUE MI DA 0----------->RETURN 0
    if (!check(t->left) || !check(t->right)) return 0;

    return 1;
}

int f(Tree t) {
    
     //funzione da scrivere
     	if(t==NULL) return 1;
	if(check(t))return 1;
	int si=1;
	if(!(check(t->left) && check(t->right))) si=0;
	return si;
     
}


void visualizzaAlbero(Tree albero) {
    if (albero == NULL) {
        return;
    }

    printf("(", albero->c);
    visualizzaAlbero(albero->left);

    printf("(%c)", albero->c);

    // Stampa i sottoalberi
    visualizzaAlbero(albero->right);
    printf(")", albero->c);

} 

Tree costruisci1(){
    Tree albero1;
    albero1 = (Tree)malloc(sizeof(Nodo));
    albero1->c = 'k';    albero1->left = (Tree)malloc(sizeof(Nodo));    albero1->left->c = 'd';    albero1->left->left = (Tree)malloc(sizeof(Nodo));    albero1->left->left->c = 'b';    albero1->left->left->left = NULL;    albero1->left->left->right = NULL;    albero1->left->right = NULL;    albero1->right = (Tree)malloc(sizeof(Nodo));    albero1->right->c = 'r';    albero1->right->left = (Tree)malloc(sizeof(Nodo));    albero1->right->left->c = 'q';    albero1->right->left->left = NULL;    albero1->right->left->right = NULL;    albero1->right->right = (Tree)malloc(sizeof(Nodo));    albero1->right->right->c = 'z';    albero1->right->right->left = NULL;    albero1->right->right->right = NULL;
	return albero1;
}

Tree costruisci2(){
    Tree albero2;
    albero2 = (Tree)malloc(sizeof(Nodo));
    albero2->c = 'k';    albero2->left =(Tree) malloc(sizeof(Nodo));    albero2->left->c = 'w';    albero2->left->left =(Tree) malloc(sizeof(Nodo));    albero2->left->left->c = 'b';    albero2->left->left->left = NULL;    albero2->left->left->right = NULL;    albero2->left->right = NULL;    albero2->right =(Tree) malloc(sizeof(Nodo));    albero2->right->c = 'p';    albero2->right->left = (Tree)malloc(sizeof(Nodo));    albero2->right->left->c = 'q';    albero2->right->left->left = NULL;    albero2->right->left->right = NULL;    albero2->right->right = (Tree)malloc(sizeof(Nodo));    albero2->right->right->c = 'z';    albero2->right->right->left = NULL;    albero2->right->right->right = NULL;
    return albero2;
}

int precede(char a, char b){
	if(a<b){
		return 1;
	}else return 0;
}

///// ESERCIZIO 4 /////////////////////////////////////////////////////////////////////////////////////////////////////////////77
Si consideri il seguente schema di base di dati che vuole tenere traccia dei lavori di muratura effettuati 
da una ditta che ha diverse sedi dislocate in Italia. Il campo TempoImpiegato è in ore.

MURATORE (CF, Nome, Cognome, Qualifica, CittàSede)
SEDE (CITTA, Zona, Indirizzo, Telefono, Manager)
CLIENTE (CF, Nome, Cognome, ContattoTelefonico, Azienda)
PROPRIETÀ (CODICE, Città, Indirizzo, Tipo, MetriCubi)
LAVORO (CFMURATORE, CFCLIENTE, CODPROPRIETA, DATA, TempoImpiegato, Compenso)

Scrivere in SQL l’interrogazione che estrae tutti i muratori con Qualifica di Apprendista 
che hanno lavorato in città diverse da quella della propria Sede.

SELECT CF 
FROM Muratore
WHERE Qualifica=Apprendista
AND CF NOT IN (SELECT CFMURATORE
                FROM LAVORO L,MURATORE M,PROPRIETA P
				WHERE L.CFMURATORE=M.CF
				AND P.CODICE=L.CODPROPRIETA 
				AND P.Citta=M.CittaSede)


Scrivere in SQL l’interrogazione che estrae per ogni muratore la durata media dei suoi lavori.
SELECT CF, avg(TempoImpiegato)
FROM LAVORO L,MURATORE M
WHERE L.CFMURATORE=M.CF 
GROUP BY L.CFMURATORE

