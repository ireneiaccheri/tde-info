//// TDE 16/01/2023 //////////////////////////////////////////////////////////////////////////////////////////////////////////

/// ESERCIZIO 1 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Si una funzione riordina che prende in ingresso due vettori u e v (più eventuali variabili necessarie) e che riordina gli elementi del primo vettore passato in input 
(u nel nostro caso) nel seguente modo:
tutti gli elementi di u che non compaiono in v saranno nelle prime posizioni di u dopo l'invocazione
tutti gli elementi di u che compaiono in v saranno nelle ultime posizioni di u dopo l'invocazione
Si faccia riferimento all'esempio sotto per eventuali dubbi su come modificare u.

Si invochi quindi la funzione relativamente al seguente codice e si stampi il contenuto del vettore u a schermo.

N.B non è possibile stampare all'interno della funzione riordina
Risultato atteso

u = 4 1 3 7 0
v = 1 6 8 4
dopo invocazione u = 3 7 0 4 1*/



#include<stdio.h>
#define N 5
int trovati(int elem,int v[],int dim);
void riordina(int u[],int v[]);
int main()
{
    int u[N] = {4,1,3,7,0}, v[N] = {1,6,8,4,2};

    // TODO stampa u e v
     for(int i=0;i<N;i++){
     	printf("%d\t",u[i]);
	 }
    // TODO invocazione riordina
     riordina(u,v);
     printf("\n\n");
     for(int i=0;i<N;i++){
     	printf("%d\t",u[i]);
	 }
    // TODO stampa u dopo invocazione

    return 0;
}

int trovati(int elem,int v[],int dim){
	int i;
	for(i=0;i<dim;i++){
		if(v[i]== elem)
		return 1;
	} ////se lo trovi restituisci 1 //////////////////////////
	return 0;
}

void riordina(int u[],int v[]){
	//se non lo trovi lo metti subito
	int auxtrovati[N],auxnontrovati[N],countnontrovati=0,k=0,t=0;
	for(int i=0;i<N;i++){
		if(!trovati(u[i],v,N)){
			auxnontrovati[k]=u[i];
			k++;
			countnontrovati++;
		}
		if(trovati(u[i],v,N)){
			auxtrovati[t]=u[i];
			t++;
		}
	}
	int j=0;
	for(int i=0;i<countnontrovati;i++){
		u[i]=auxnontrovati[i];
	}
	for(int i=countnontrovati;i<N;i++){
		u[i]=auxtrovati[j];
		j++;
	}
}

////// ESERCIZIO 2 /////////////////////////////////////////////////////////////////////////////////////////////////////////77
/*Si considerino le seguente definizioni di lista rappresentante una linea spezzata aperta in un piano cartesiano 

typedef struct P {float x,y;
                          struct P * next; } Punto;
typedef Punto * ListaPunti;



typedef struct S {ListaPunti lisP;
                          struct S * next; } Spezzata;
typedef Spezzata * ListaSpezzate;

Si scriva una funzione lunghezza che riceve una variabile di tipo ListaPunti (e altre variabili se necessarie) e calcola la lunghezza della spezzata corrispondente ai punti.

Si scriva poi una funzione sistemaListaSpezzate che riceve una variabile di tipo ListaSpezzate e verifica che le s
pezzate contenute dentro la lista siano in ordine di lunghezza crescente e, se non lo sono, 
la funzione elimina quelle che violano l’ordine eliminando quelle che sono più corte di quella che le precedono. 
Per semplicità si ignori il possibile rischio che cancellando una lista si renda accettabile quella che la segue anche se non dovrebbe essere accettata.
 Nello scrivere la funzione si può sfruttare la funzione distanza già contenuta nel file.
  Con cancellare si intende cancellare dalla lista, è necessario eliminare dalla lista, 
  non farne una più corta e senza appoggiari a liste ausiliarie.

Si invochi quindi la funzione sistemaListaSpezzate nel main e si stampi la lista "sistemata".

Si parta dal file:
https://www.dropbox.com/s/du949la0rvoupyw/listeTesto.c?dl=0

Ecco il risultato atteso a partire dal codice sopra:

Lista di Spezzate Prima Dell'invocazione:
 (1.00,0.00) --->  (2.00,0.00) --->  (0.00,2.00) --->  (0.00,1.00) --->  ---|
 (1.00,6.00) --->  (9.00,1.00) --->  (5.00,5.00) --->  (9.00,0.00) --->  (1.00,1.00) --->  ---|
 (1.00,30.00) --->  (1.00,1.00) --->  (111.00,1.00) --->  (80.00,9.00) --->  (0.00,1.00) --->  ---|
 (1.00,3.00) --->  (2.00,4.00) --->  (0.00,1.00) --->  (1.00,7.00) --->  (8.00,2.00) --->  ---|
 (1.00,32.00) --->  (88.00,8.00) --->  (45.00,0.00) --->  (90.00,0.00) --->  (1000.00,1.00) --->  ---|

Lista di Spezzate Dopo l'invocazione:
(1.00,0.00) --->  (2.00,0.00) --->  (0.00,2.00) --->  (0.00,1.00) --->  ---|
 (1.00,6.00) --->  (9.00,1.00) --->  (5.00,5.00) --->  (9.00,0.00) --->  (1.00,1.00) --->  ---|
 (1.00,30.00) --->  (1.00,1.00) --->  (111.00,1.00) --->  (80.00,9.00) --->  (0.00,1.00) --->  ---|
 (1.00,32.00) --->  (88.00,8.00) --->  (45.00,0.00) --->  (90.00,0.00) --->  (1000.00,1.00) --->  ---|*/
 
 #include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct P {float x,y;
                  struct P * next; } Punto;
typedef Punto * ListaPunti;

typedef struct S {ListaPunti lisP;
                  struct S * next; } Spezzata;
typedef Spezzata * ListaSpezzate;


ListaPunti InsInFondoPunto(ListaPunti lista,float x,float y);
ListaSpezzate InsInFondoSpezzata( ListaSpezzate lista,ListaPunti lis );
void VisualizzaListaPunti(ListaPunti lista );
void VisualizzaListaSpezzate(ListaSpezzate lista );
ListaSpezzate costruisci();
float distanza(Punto * p1,Punto * p2);
//
// TODO: PROTOTIPI DELLE FUNZIONI RICHIESTE
float lunghezza(ListaPunti lis);
void DistruggiListaRic ( ListaPunti lista );
ListaSpezzate modifica(ListaSpezzate lis);
//


int main(){
	ListaSpezzate lis;
	lis=costruisci();
	VisualizzaListaSpezzate(lis);
	
	VisualizzaListaSpezzate(modifica(lis));

	return 0;
}

//
// TODO: SVILUPPARE QUI LE FUNZIONI RICHIESTE
float lunghezza(ListaPunti lis){
	float dist=0;
	if(lis==NULL) return 0;
	while(lis->next!=NULL){
		dist=dist+distanza(lis,lis->next);
		lis=lis->next;
	}
	return dist;
}

ListaSpezzate modifica(ListaSpezzate lis) {
    if (lis == NULL || lis->next == NULL) {
        return lis;
    }

    if (lunghezza(lis->lisP) > lunghezza(lis->next->lisP)) {
        ListaSpezzate temp = lis->next;
        lis->next = lis->next->next;
        DistruggiListaRic(temp->lisP);
       
        return modifica(lis);
    } else {
        lis->next = modifica(lis->next);
        return lis;
    }
}

//


float distanza(Punto * p1,Punto * p2){
	return sqrt((p1->x-p2->x)*(p1->x-p2->x)+(p1->y-p2->y)*(p1->y-p2->y));
}

ListaSpezzate costruisci(){
	int M[5][10]={1,0,2,0,0,2,0,1,-1,-1,
	              1,6,9,1,5,5,9,0,1,1,
				  1,30,1,1,111,1,80,9,0,1,
				  1,3,2,4,0,1,1,7,8,2,
				  1,32,8,88,45,0,90,0,1000,1};
	int i,k;ListaSpezzate ris=NULL; ListaPunti temp=NULL;
	for(i=0;i<5;i++){
		temp=NULL;for(k=0;k<10;k=k+2)if(M[i][k]!=-1)temp=InsInFondoPunto(temp,M[i][k],M[i][k+1]);
		ris=InsInFondoSpezzata(ris,temp);}
	return ris;
}

ListaPunti InsInFondoPunto(ListaPunti lista,float x,float y) {
    ListaPunti punt;
    if(lista==NULL) { punt = (ListaPunti)malloc( sizeof(Punto) );
                     punt->next = NULL; punt->x = x; punt->y = y; return  punt;
    }else{lista->next = InsInFondoPunto(lista->next,x,y); return lista;}
}

ListaSpezzate InsInFondoSpezzata( ListaSpezzate lista,ListaPunti lis ) {
   ListaSpezzate punt;
   if(lista==NULL) { punt = (ListaSpezzate)malloc( sizeof(Spezzata) );
                     punt->next=NULL; punt->lisP=lis; return  punt;
   }else{lista->next = InsInFondoSpezzata(lista->next,lis); return lista;}
}

void VisualizzaListaPunti(ListaPunti lista ){
    if (lista==NULL) printf(" ---| \n");
    else{printf(" (%.2f,%.2f) ---> ", lista->x, lista->y); VisualizzaListaPunti( lista->next );}
}

void VisualizzaListaSpezzate(ListaSpezzate lista ) {
    if(lista==NULL) printf("\n");
    else{VisualizzaListaPunti(lista->lisP); VisualizzaListaSpezzate(lista->next);}
}

void DistruggiListaRic ( ListaPunti lista ) {
    if ( lista!=NULL ) {
	    DistruggiListaRic( lista->next ); free( lista );
	}
}

//////ESERCIZIO 3 //////////////////////////////////////////////////////////////////////////////////////////////////////////7
/*Sia data la seguente definizione di un albero contenente un carattere in ogni nodo.

typedef struct El{
char c;
struct El *left, *right;
}Nodo;

typedef Nodo *Tree;

Si scriva una funzione cerca che prende in ingresso un albero binario (si assuma pure questo contenga solo lettere minuscole) 
ed una stringa e 
- restituisce 1 se tutti cammini dalla radice alle foglie contengono esattamente 2 lettere della stringa, 
- 0 altrimenti.

Si consiglia molto fortemente l’uso di funzioni ausiliarie con parametri aggiuntivi che “trasportino” nelle chiamate informazioni utili.

Se la funzione cerca sarà scritta correttamente (insieme alle funzioni ausiliarie) il programma stamperà il seguente risultato 
a partire dal codice fornito

T1:  ( ( ( o )  c  ( b ) )  a  ( ( c )  d  ( ( c )  r  ( a ) ) ) )

T2:  ( ( ( o )  c  ( b ) )  a  ( ( c )  d  ( ( c )  a  ( a ) ) ) )

T3:  ( ( ( o )  c  ( b ) )  s  ( ( c )  d  ( ( c )  r  ( a ) ) ) )

1
1
0
0
0
1*/

#include <stdio.h>
#include <stdlib.h>

typedef struct n {
        char val;
        struct n * left;
		struct n * right;
} nodo;
typedef nodo * albero;

albero createVal(char val);
albero creaAlbero1();albero creaAlbero2();albero creaAlbero3();
void print(albero t);
void stampa(albero T);
int f(albero t,char str[]);
int trovato(char str[],char x);
int foglie(albero t);
void aux(albero t,int v[], char str[],int *index, int count);
int main(){
    int ris=0;
    char str1[100]="acacia",str2[100]="sacca";
    albero T1,T2,T3;
    T1 = creaAlbero1(); T2 = creaAlbero2(); T3 = creaAlbero3();
    printf("\nT1: "); stampa(T1);
    printf("\nT2: "); stampa(T2);
    printf("\nT3: "); stampa(T3);
    printf("\n");

   //LA FUNZIONE DA SVILUPPARE VIENE USATA QUI


   printf("%d\n",f(T1,str1));
   printf("%d\n",f(T1,str2));
   printf("%d\n",f(T2,str1));
   printf("%d\n",f(T2,str2));
   printf("%d\n",f(T3,str1));
   printf("%d\n",f(T3,str2));
   
   return 0;
}

//
// TODO: SVILUPPARE QUI DENTRO QUANTO RICHIESTO
//
int f(albero t,char str[]){
    int v[foglie(t)];
///le dimensioni del vettore sono il numero dei cammini possibili, quindi il numero di foglie////
    for(int i=0;i<foglie(t);i++){
    	v[i]=0;
	}
	int index=0;
	//funzione ausiliaria che mette a 1 i cammini che rispettano la condizione
	aux(t,v,str,&index,0);
	// se tutti sono a 1 posso restituire 1, altrimenti 0///
	int j;
	for(j=0;j<foglie(t);j++){
		if(v[j]==0)
		return 0;
	}
	return 1;
}
int trovato(char str[],char x){
	for(int i=0;str[i]!='\0';i++){
		if(x==str[i])
		return 1;
	}
	return 0;
}

int foglie(albero t){
	if(t==NULL) return 0;
	if(t->right==NULL && t->left==NULL  ) return 1;
	return foglie(t->right)+foglie(t->left);
}

void aux(albero t,int v[], char str[],int *index, int count){
	if(t==NULL) return;
	if(trovato(str,t->val)) count++; //se il valore e nella stringa incremento un contatore
	if(t->left==NULL && t->right==NULL ){ //arrivo ai nodi foglia
		if(count==2){ //se il contatore è 2, posso mettere a 1 la casella index del vettore
		    v[*index]=1;}
		(*index)++;	} //in ogni caso devo incrementare l'indice quando passo ad analizzare il cammino successivo
		
		aux(t->left,v,str,index,count); //non devo cambiare l'indice come quando mi sposto di livello
		aux(t->right,v,str,index,count);
}

albero creaAlbero1() {
    albero tmp = createVal('a');
    tmp->left = createVal('c');tmp->left->left = createVal('o');tmp->left->right = createVal('b');
    tmp->right = createVal('d');tmp->right->left = createVal('c');tmp->right->right = createVal('r');
    tmp->right->right->left = createVal('c'); tmp->right->right->right = createVal('a');
    return tmp;
}

albero creaAlbero2() {
    albero tmp = createVal('a');
    tmp->left = createVal('c');tmp->left->left = createVal('o');tmp->left->right = createVal('b');
    tmp->right = createVal('d');tmp->right->left = createVal('c');tmp->right->right = createVal('a');
    tmp->right->right->left = createVal('c'); tmp->right->right->right = createVal('a');
    return tmp;
}

albero creaAlbero3() {
    albero tmp = createVal('s');
    tmp->left = createVal('c');tmp->left->left = createVal('o');tmp->left->right = createVal('b');
    tmp->right = createVal('d');tmp->right->left = createVal('c');tmp->right->right = createVal('r');
    tmp->right->right->left = createVal('c'); tmp->right->right->right = createVal('a');
    return tmp;
}

void print(albero t){
       if(t==NULL)return;       
       else{printf(" (");print(t->left);printf(" %c ",t->val);print(t->right);printf(") ");}       
}

void stampa(albero T){print(T);printf("\n");}

albero createVal(char val) {
    albero tmp =(albero) malloc(sizeof(nodo));
    tmp->val = val;    tmp->left = NULL;    tmp->right = NULL;
    return tmp;
}

///// ESERCIZIO 4 ////////////////////////////////////////////////////////////////////////////////////////////////////////////

Il seguente schema è relativo alla base di dati di un’agenzia immobiliare. I valori possibili dell'attributo TIPO sono: Appartamento, Villetta, Box, ....

CLIENTE (CF, Nome, Cognome)
AFFITTO (CF_Cliente, ID_Immobile, Data_Inizio, Data_Fine, Costo_Totale)
IMMOBILE (ID, mq, Città, CF_Proprietario, Tipo)
PROPRIETARIO (CF, Nome, Cognome, Città)

Scrivere in SQL l’interrogazione che estrae CF, nome e cognome dei proprietari degli immobili che non sono mai stati affittati da nessuno.
SELECT P.Nome,P.CF,P.Cognome
FROM PROPRIETARIO P,IMMOBILE I
WHERE P.CF=I.CF_Propiretario AND ID NOT IN( SELECT ID_Immobile
                                            FROM AFFITTO)
				 
Scrivere in SQL l’interrogazione che estrae per ogni città l’immobile che ha generato i maggiori guadagni.
//per ogni immobile devi sommare i guadagni che ha generato
// devi raggruppare questi immobili per citta e trovare quello che ha il numero piu alto
SELECT Città, ID
FROM IMMOBILE I,AFFITTO A
GROUP BY I.CITTA,A.IDIMMOBILE
WHERE  I.ID=A.IDIMMOBILE AND SUM(A.CostoTotale)>=ALL (SELECT(SUM(COSTOTOTALE))
                              FROM AFFITT
	                  GROUP BY IDIMMOBILE)


