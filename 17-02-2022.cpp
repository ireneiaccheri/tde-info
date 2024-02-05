//// TDE 17/02/2022 //////////////////////////////////////////////////////////////////////////////////////////////
//// ESERCIZIO 1 ////////////////////////////////////////////////////////////////////////////////////////////////////
/*Il tipo Inquinante definisce un prodotto chimico con nome e livello di pericolosità. 

typedef struct{
    char nome[N];
    int livello;
}Inquinante;

Si scriva una funzione analizzaInquinanti che prende in ingresso un array di elementi di tipo Inquinante -- 
ed ulteriori variabili aggiuntive se necessarie-- e riporta al chiamante il nome dell’inquinante meno pericoloso 
(che si può supporre essere unico) tra quelli contenuti nell’array ed il nome dell’inquinante con il livello più vicino 
alla media dei livelli dei vari inquinanti. Per identificare l’inquinante più vicino alla media, 
si consideri la differenza in valore assoluto.

Si invochi la funzione analizzaInquinanti nel main e si stampino i nomi dei due inquinanti selezionati. 

In riferimento all’array popolato nel main nel seguente codice (da utilizzare per sviluppare la soluzione)
https://www.dropbox.com/s/xeja2um71fulncj/inquinanti_TODO.c?dl=0
ci si aspetta la seguente stampa dal main:

Meno pericoloso: PM10, piu' vicino alla media: Benzene*/

#include<stdio.h>
#include<string.h>
#define N 20

typedef struct{
char nome[N];
int livello;
}Inquinante;

typedef struct{
	char menoper[N];
	char piuvicino[N];
}risultato;

risultato ris(Inquinante elementi[5]);
float media( Inquinante vett[5]);
int calcoladist(Inquinante elementi[],int quale);

int main()
{
Inquinante elementi[5];
// TODO aggiungere dichiarazione variabili aggiuntive

strcpy(elementi[0].nome, "PM10");
elementi[0].livello = 65;
strcpy(elementi[1].nome, "Benzene");
elementi[1].livello = 212;
strcpy(elementi[2].nome, "PM7");
elementi[2].livello = 352;
strcpy(elementi[3].nome, "PM5");
elementi[3].livello = 176;
strcpy(elementi[4].nome, "CO2");
elementi[4].livello = 451;
int i;
printf("l'inquinante meno pericoloso e:");
for(i=0;ris(elementi).menoper[i]!='\0';i++){
	printf("%c",ris(elementi).menoper[i]);
}

printf("\n\nl'inquinante piu vicino e:");
for(i=0;ris(elementi).piuvicino[i]!='\0';i++){
	printf("%c",ris(elementi).piuvicino[i]);
}

return 0;
}
//mi calclo la media dei livelli
float media( Inquinante vett[5]){
	int i;
	float somma=0;
	for(i=0;i<5;i++)
	somma=somma+vett[i].livello;
	
	return somma/5;
}
//definisco valore assoluto
int calcoladist(Inquinante elementi[],int quale){
	int dist,valass;
	dist=elementi[quale].livello-media(elementi);
	if(dist>0){
		valass=dist;
	}else valass=-dist;
	
	return valass;
}

risultato ris(Inquinante elementi[5]){
	risultato rest;
	int min=elementi[0].livello;
	int i,index;
	for(i=0;i<5;i++){
		if(elementi[i].livello<=min){
			min=elementi[i].livello;
			index=i;
		}
	}
	strcpy(rest.menoper,elementi[index].nome);
/////ho fatto il meno pericoloso/////////////////
   int meno=calcoladist(elementi,0),quale;
   for(int j=0;j<5;j++){
   	if(calcoladist(elementi,j)<=meno){
   		meno=calcoladist(elementi,j);
   		quale=j;
	   }
   }
   strcpy(rest.piuvicino,elementi[quale].nome);
   
   return rest;
	
}

/////// ESERCIZIO 2 /////////////////////////////////////////////////////////////////////////////////////////////////
/*Si scriva una funzione che riceve un vettore di liste di interi positivi e la sua dimensione, e 
restituisce la somma delle medie di tutte le liste.
Si supponga per semplicità che non esistano liste vuote e che il vettore sia correttamente definito.
Con le liste dell'esempio:

 3 --->  7 --->  1 --->  8 --->  3 --->  1 --->  9 --->  1 --->  ---|

 1 --->  4 --->  2 --->  4 --->  8 --->  2 --->  0 --->  8 --->  2 --->  7 --->  ---|

 2 --->  4 --->  6 --->  8 --->  3 --->  ---|

 1 --->  6 --->  8 --->  3 --->  8 --->  9 --->  3 --->  ---|

 4 --->  4 --->  8 --->  1 --->  1 --->  6 --->  ---|

Somma medie: 21.953571*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 5



typedef struct EL {
	int info;
	struct EL * prox;
} ElemLista;

typedef ElemLista * Lista;
typedef Lista VettLista[5];

Lista InsInFondoInt(Lista lista,int elem);
void VisualizzaListaInt(Lista lista);
void VisualizzaVettListaInt(VettLista vett);

void costruisciVett(VettLista v);
Lista costruisciLista(int v[],int lun);
float f(VettLista v,int lun);
float media(Lista lis);
//
// TODO: PROTOTIPI DELLA FUNZIONE RICHIESTA E EVENTUALI FUNZIONI AUSILIARIE
//

int main(){
	float ris;
	VettLista vet;
	costruisciVett(vet);
	VisualizzaVettListaInt(vet);

	//TODO: invocazione funzione e stampa 
	//(in questo esercizio voi dovete stampare solo nel main)
    ris=f(vet,5);    
    printf("%f",ris);

	return 0;
}

//
// TODO: SVILUPPARE QUI LA FUNZIONI RICHIESTA ED EVENTUALI FUNZIONI RICHIESTE
//
float media(Lista lis){
	int somma=0,cont=0;
	for(;lis!=NULL;lis=lis->prox){
		somma=somma+lis->info;
		cont++;
	}
	return (float)somma/cont;
}

float f(VettLista v,int lun){
    int i;
    float somma;
    somma=media(v[0]);
    for(i=1;i<lun;i++){
    	somma=somma+media(v[i]);
	}
	return somma;
}


void costruisciVett(VettLista v){
	int m[N][N*2]={3,7,1,8,3,1,9,1,0,0,
	              1,4,2,4,8,2,0,8,2,7,
	              2,4,6,8,3,0,0,0,0,0,
	              1,6,8,3,8,9,3,0,0,0,
	              4,4,8,1,1,6,0,0,0,0};
	int i,lung[N]={8,10,5,7,6};
	
	for(i=0;i<N;i++)           
	    v[i]=costruisciLista(m[i],lung[i]);   
}

Lista costruisciLista(int v[],int lun){
	Lista lis=NULL;	int i=0;
    for(i=0;i<lun;i++)
	    lis=InsInFondoInt(lis,v[i]);
	return lis;
}

Lista InsInFondoInt(Lista lista,int elem){
    Lista punt;
    if(lista==NULL) { punt = (Lista)malloc( sizeof(ElemLista) );
                      punt->prox = NULL; punt->info=elem; return  punt;
    }else{lista->prox = InsInFondoInt(lista->prox,elem); return lista;}
}

void VisualizzaListaInt(Lista lista) {
    if (lista==NULL) printf(" ---| \n");
    else{printf(" %d ---> ", lista->info); VisualizzaListaInt( lista->prox );}
}

void VisualizzaVettListaInt(VettLista vett){
	int i;
	for(i=0;i<N;i++){
		VisualizzaListaInt(vett[i]);
		printf("\n");
	}
}

////// ESERCIZIO 3 ///////////////////////////////////////////////////////////////////////////////////////////////7
/*Si scriva una funzione che riceve in ingresso un albero binario di caratteri e 
restituisce al chiamante 1 se l’albero è tale per cui ogni nodo interno (cioè ogni nodo che non è una foglia) 
che contiene una vocale ha tra i suoi discendenti solo foglie che contengono consonanti.

File da cui partire: https://www.dropbox.com/s/svunjvqyl5vuo8i/alberiL.c?dl=0

Con gli alberi nel codice fornito stampa:

T1:  ( ( ( b )  e  ( z ) )  a  ( ( f )  o  ( ( g )  e  ( t ) ) ) )

T2:  ( ( ( ( a )  e  ( p ) )  s  ( l ) )  h  ( ( a )  r  ( b ) ) )

T3:  ( ( ( ( o )  i  ( a ) )  e  ( c ) )  b  ( ( a )  c  ( t ) ) )
T1 ok
T2 non ok
T3 non ok*/
#include <stdio.h>
#include <stdlib.h>

typedef struct n {
        char val;
        struct n * left;
		struct n * right;
} nodo;
typedef nodo * albero;

albero createVal(int val);
albero creaAlbero1();albero creaAlbero2();albero creaAlbero3();
void print(albero t);
void stampa(albero T);
int f(albero t);
int vocale(char c);
int precdoppiafoglia(albero t);
int precfogliadx(albero t);
int precfogliasx(albero t);

int main(){
    int ris=0;
    albero T1,T2,T3;
    T1 = creaAlbero1(); T2 = creaAlbero2(); T3 = creaAlbero3();
   // printf("\nT1: "); stampa(T1);
    //printf("\nT2: "); stampa(T2);
    //printf("\nT3: "); stampa(T3);

   //LA FUNZIONE DA SVILUPPARE VIENE USATA QUI
  

   if(f(T1)==1)
        printf("T1 ok\n");
    else printf("T1 non ok\n");

   if(f(T2)==1)
        printf("T2 ok\n");
    else printf("T2 non ok\n");

   if(f(T3)==1)
        printf("T3 ok\n");
    else printf("T3 non ok\n");

    return 0;
}

//
// TODO: SVILUPPARE QUI DENTRO QUANTO RICHIESTO
//


int f(albero t){
    //SVILUPPARE QUI QUANTO RICHIESTO 
	//FUNZIONI AUSILIARIE CON PARAMETRI AGGIUNTIVI SONO MOLTO CONSIGLIATE
   if(t==NULL) return 1;
   if( precdoppiafoglia(t) && vocale(t->val)){
   	if(!vocale(t->left->val) && !vocale(t->right->val)){
   	return 1;}else return 0;}

   
   if(vocale(t->val) && precfogliasx(t)){
   	if(!vocale(t->left->val))
   	return 1;
   }
   
   if(vocale(t->val) && precfogliadx(t)){
   	if(!vocale(t->right->val))
   	return 1;
   }
   
    return f(t->right) && f(t->left);
}

albero creaAlbero1() {
    albero tmp = createVal('a');
    tmp->left = createVal('e');tmp->left->left = createVal('b');tmp->left->right = createVal('z');
    tmp->right = createVal('o');tmp->right->left = createVal('f');tmp->right->right = createVal('e');
    tmp->right->right->left = createVal('g'); tmp->right->right->right = createVal('y');
    return tmp;
}

albero creaAlbero2() {
    albero tmp = createVal('h');
    tmp->right = createVal('r');tmp->right->right = createVal('b');tmp->right->left = createVal('t');
    tmp->left = createVal('s');tmp->left->right = createVal('l');tmp->left->left = createVal('e');
    tmp->left->left->right = createVal('p');tmp->left->left->left = createVal('l');
    return tmp;
}

albero creaAlbero3() {
    albero tmp = createVal('b');
    tmp->right = createVal('c');tmp->right->right = createVal('t');tmp->right->left = createVal('a');
    tmp->left = createVal('e');tmp->left->right = createVal('c');tmp->left->left = createVal('i');
    tmp->left->left->right = createVal('a');tmp->left->left->left = createVal('o');
    return tmp;
}

void print(albero t){
       if(t==NULL)return;       
       else{printf(" (");print(t->left);printf(" %c ",t->val);print(t->right);printf(") ");}       
}

void stampa(albero T){print(T);printf("\n");}

albero createVal(int val) {
    albero tmp = (albero)malloc(sizeof(nodo));
    tmp->val = val;    tmp->left = NULL;    tmp->right = NULL;
    return tmp;
}

int precdoppiafoglia(albero t){
	if(t==NULL) return 0;
	if(t->left!=NULL && t->right!=NULL){
		if(t->left->left ==NULL &&t->left->right ==NULL &&t->right->left ==NULL &&t->right->left ==NULL){
		
		return 1;}else return 0;
	}
}

int precfogliasx(albero t) {
    if (t == NULL) return 0;

    if (t->left != NULL && t->right == NULL) {
        if (t->left->left == NULL && t->left->right == NULL) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;  // Aggiunta questa riga per gestire il caso in cui la condizione nell'if esterno non è soddisfatta
    }
}


int precfogliadx(albero t) {
    if (t == NULL) return 0;

    if (t->left == NULL && t->right != NULL) {
        if (t->right->left == NULL && t->right->right == NULL) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;  // Aggiunta questa riga per gestire il caso in cui la condizione nell'if esterno non è soddisfatta
    }
}


int vocale(char c){
	if(c=='a' ||c=='e' ||c=='i' ||c=='o' ||c=='u'){
		return 1;
	}else return 0;
}
//ho controllato la condizione che sia un nodo interno a cui seguono foglie
//ricorsione finche non ne trovo uno; ricordati i casi in cui hai solo una foglia dx o sx
// se il nodo corrente(nonche precedente di una foglia e vocale e il seguente(nonche foglia e consonante,allora posso restituire uno
//deve essere verificata sia per i sottoalberi dx e sx (&&)


/////ESERCIZIO 4 SQL //////////////////////////////////////////////////////////////////////////////////////////
Il seguente schema rappresenta i dati relativi ai campionati mondiali di calcio (le chiavi sono scritte tutto maiuscolo). 
SQUADRA(NAZIONE, Anno, Allenatore, PosizioneInClassifica, NumeroGiocatori)
ORGANIZZAZIONE(ANNO, Nazione)
GIOCATORE(ID, Nome)
PARTECIPAZIONE(IDGIOCATORE, ANNO, NAZIONE, Ruolo, GoalSegnati)

Scrivere in SQL la query che estrae i nomi dei Giocatori che hanno segnato zero goal in tutti i campionati mondiali a cui hanno partecipato.

SELECT Nome
FROM GIOCATORE
WHERE ID NOT IN SELECT (ID GIOCATORE
                        FROM PARTECIPAZIONE
						WHERE GOALSEGNATI<>'0'
						GROUP BY IDGIOCATORE)
						
Scrivere in SQL la query che estrae per ogni giocatore il numero dei mondiali a cui ha partecipato.
SELECT IDGIOCATORE,COUNT(*)
FROM PARTECIPAZIONE
GROUP BY IDGIOCATORE

