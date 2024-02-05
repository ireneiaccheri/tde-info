//// TDE 13/02/2023 /////////////////////////////////////////////////////////////////////////////////////////////////////////////77

////ESERCIZIO 1 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////7
/*Si implementi una funzione verifica per controllare che un acronimo corrisponda ad un determinato testo. 
In particolare la funzione verifica prende in ingresso due stringhe acr e txt (oltre ad eventuali variabili necessarie) e 
controllerà che tutti e soli i caratteri di acr corrispondono all'iniziale di una parola in txt e che questi appaiano 
in ordine corretto.

In particolare:
Acronimi troppo lunghi o troppo corti rispetto al testo non sono considerati validi.
Si assuma pure che i caratteri in acr siano tutti maiuscoli, e che in in txt ogni parola inizi con lettera maiuscola
Si assuma che acr sia correttamente formattata e txt oltre a essere correttamente formattata contenga sempre un solo spazio prima di ogni parola e che non ci siano spazi prima del ‘\0’



    Stringa acr1="ATM", txt1 = "Azienda Trasporti Milanesi"; //SI
    Stringa acr2="AT", txt2 = "Azienda Trasporti Milanesi";  //NO
    Stringa acr3="ATM", txt3 = "Azienda Trasporti Lombardi"; //NO
    Stringa acr4="ATMK", txt4 = "Azienda Trasporti Milanesi";//NO
    Stringa acr5="ATM", txt5 = "Azienda Trasporti Milanesi Lombardi"; //NO*/
    


#include<stdio.h>
#include<string.h>
#define N 100

typedef char Stringa[N];

int verifica(char acr[],char txt[]);

int main(){

    Stringa acr1="ATM", txt1 = " Azienda Trasporti Milanesi"; //SI
    Stringa acr2="AT", txt2 = " Azienda Trasporti Milanesi";  //NO
    Stringa acr3="ATM", txt3 = " Azienda Trasporti Lombardi"; //NO
    Stringa acr4="ATMK", txt4 = " Azienda Trasporti Milanesi";//NO
    Stringa acr5="ATM", txt5 = " Azienda Trasporti Milanesi Lombardi"; //NO

    // TODO: invocazione della funzione e stampa risultato
    char testo[100],acronimo[100];
    
    
    
    
    if(verifica(acr4,txt4)){
    	printf("SI");
	}else printf("NO");
    

    
return 0;
}



int verifica(char acr[],char txt[]){
	int k,i,j=0,count=0;
	k=strlen(acr);
	
	for(i=0;txt[i]!='\0';i++){
		if(txt[i]==' '){
			count++;
		}	}
		
		if((count)!=k){
			return 0;}
			
	int contatore=0;		
	if((count)==k){
		for(i=1;txt[i]!='\0'&& j<k;i++){
			if(txt[i-1]==' '){
				if(txt[i]==acr[j]){
					contatore++;}
					 j++;}
					}	}
					
if(contatore==count){
	return 1;
}else return 0;
				
}

/////ESERCIZIO 2 //////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Si consideri una lista definita come sotto che contiene i punti ottenuti da clienti durante vari acquisti (ovviamente lo stesso cliente, quindi lo stesso codice, sarà presente più volte nella lista)
 
typedef struct nodo{
    char codice[100];
    int punteggio;
    struct nodo * next;
} nodo;
typedef nodo * Lista;
 
Scrivere una funzione aggrega che, data una lista di nodi, genera una nuova lista con la stessa struttura, ma in cui ogni codice appare una volta sola avendo come punteggio la somma dei punteggi dei nodi della lista di partenza.
 
Coi dati del main allegato verrà generata una lista contenente i seguenti elementi (non importa in che ordine)
(c1,764) --->  (c2,882) --->  (c3,834) --->  (c4,634) --->  (c5,661) --->  ---|*/


//nota che ogni codice e costituito da una c e da un numero di una cifra-->partirai dal numero uno e scorri fino a 5
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct n{
    char codice[100];
    int punteggio;
    struct n * next;
} nodo;
typedef nodo * Lista;



Lista InsInFondo(Lista lista,char c[],int p);
void VisualizzaLista(Lista lista );
Lista costruisci();
Lista caux(Lista lista,int i);
//
// TODO: PROTOTIPI DELLE FUNZIONI RICHIESTE
//
int sommasimili(Lista lis, char c[]){ 
	int somma=0;
	while(lis!=NULL){
	
		if(!strcmp(c,lis->codice)){ //restituisce 0 se sono uguali---> mi serve per sommare quelli con lo stesso codice
		somma=somma+lis->punteggio;
		}
		lis=lis->next;
	}
	return somma;
}

Lista aggrega(Lista lis){
	Lista fin=NULL;
     Lista cur=lis;
     char boh[3]="  ";
	char i='1';
	for(i='1';i<='5';i++){
         boh[0]='c'; //codice sempre fatto da c e un numero
         boh[1]=i;  //metto in ordine crescente,parto da c1, poi c2...
		fin=InsInFondo(fin,boh,sommasimili(lis,boh));}
	
	return fin;
}

 Lista InsInFondo(Lista lista,char c[],int p){
    Lista punt;
	if( lista==NULL ) {
	    punt= (Lista)malloc( sizeof(nodo) );
		punt->next = NULL;
		punt->punteggio=p;
		strcpy(punt->codice,c);
		return punt;
	} else { 
	    lista->next = InsInFondo( lista->next,c,p );
		return lista; 
	}
}


int main(){
	Lista lis,risultato;
	lis=costruisci();
	VisualizzaLista(lis);
	printf("\n\n");

	//TODO: invocazione funzione e visualizzazione risultato
	VisualizzaLista(aggrega(lis));
	return 0;
}

//
// TODO: SVILUPPARE QUI LE FUNZIONI RICHIESTE
//



Lista costruisci(){ return caux(NULL,0);}
Lista caux(Lista lista,int i){
	int p[50]={57, 63, 70, 88, 91, 97, 57, 59, 66, 88, 94, 92, 77, 61, 68, 75, 85, 94, 68, 77, 63, 89, 85, 100, 57, 77, 59, 97, 68, 60, 87, 92, 94, 66, 61, 68, 75, 63, 89, 68, 75, 94, 57, 63, 75, 66, 92, 61, 77, 70};
	char c[50][20]={"c2", "c1", "c3", "c1", "c5", "c2", "c5", "c4", "c5", "c1", "c3", "c4", "c4", "c5", "c1", "c5", "c2", "c2", "c5", "c2", "c3", "c1", "c5", "c3", "c1", "c3", "c3", "c2", "c2", "c1", "c3", "c3", "c1", "c4", "c3", "c4", "c4", "c4", "c1", "c1", "c2", "c2", "c4", "c2", "c2", "c5", "c5", "c3", "c4", "c3"};
	if(i==50) return NULL;
	lista= (Lista)malloc( sizeof(nodo) );	lista->codice[0]=c[i][0]; lista->codice[1]=c[i][1]; lista->codice[2]=c[i][2]; lista->punteggio = p[i];    lista->next = caux(lista->next,i+1); return lista;
}

void VisualizzaLista(Lista lista ){
    if (lista==NULL) printf(" ---| \n");
    else{printf(" (%s,%i) ---> ", lista->codice, lista->punteggio); VisualizzaLista( lista->next );}
}

///////ESERCIZIO 3 /////////////////////////////////////////////////////////////////////////////////////////////////////////7
/*Si consideri la seguente definizione di un albero binario

typedef struct t { 
    int val;
    struct t * left, *right; 
} Nodo;

typedef Nodo * Tree;
 
Scrivere una funzione percorsoMediaMinima che prende in ingresso un albero binario e calcolando, per ogni percorso dalla radice alle foglie, la media dei valori (nei nodi) che compongono il percorso restituisce un unico valore che rappresenta il minimo tra le medie dei valori di ciascun percorso. 
 
Si consiglia molto fortemente l’uso di funzioni ausiliarie con parametri aggiuntivi che “trasportino” nelle chiamate informazioni utili.
 
Con gli alberi di esempio del codice fornito l’output deve essere:
Il percorso in T1 con media di valori minima ha media: 6.333333
Il percorso in T2 con media di valori minima ha media: 6.500000
Il percorso in T3 con media di valori minima ha media: 3.000000*/

#include <stdio.h>
#include <stdlib.h>

typedef struct n {
    int val;
    struct n *left;
    struct n *right;
} nodo;
typedef nodo *albero;

albero createVal(int val);
albero creaAlbero1();
albero creaAlbero2();
albero creaAlbero3();

void print(albero t);
void stampa(albero T);
float costoMinimoMedio(albero T);
float calcolamedia(albero t,float somma,float count);
int main() {
    albero T1, T2, T3;
    T1 = creaAlbero1();
    T2 = creaAlbero2();
    T3 = creaAlbero3();

    printf("\nT1: ");
    stampa(T1);
    printf("\nT2: ");
    stampa(T2);
    printf("\nT3: ");
    stampa(T3);

    // visualizzazione risultati e invocazione funzione 
    printf("Il percorso di T1 con media di valori minima ha media: %f\n", costoMinimoMedio(T1));
    printf("Il percorso di T2 con media di valori minima ha media: %f\n", costoMinimoMedio(T2));
    printf("Il percorso di T3 con media di valori minima ha media: %f\n", costoMinimoMedio(T3));

    return 0;
}

float costoMinimoMedio(albero T){
	
	return calcolamedia(T,0,0);
}

float calcolamedia(albero t,float somma,float count){
	if(t==NULL) return somma/count;
	float d=calcolamedia(t->right,somma+t->val,count+1);
		float s=calcolamedia(t->left,somma+t->val,count+1);
		
	if(d<s){
		return d;
	}else return s;

}

albero creaAlbero1() {
    albero tmp = createVal(7);
    tmp->left = createVal(3);
    tmp->left->left = createVal(9);
    tmp->left->right = createVal(10);
    tmp->right = createVal(8);
    tmp->right->left = createVal(5);
    tmp->right->right = createVal(12);
    tmp->right->right->left = createVal(11);
    tmp->right->right->right = createVal(6);
    return tmp;
}

albero creaAlbero2() {
    albero tmp = createVal(8);
    tmp->left = createVal(5);
    tmp->right = createVal(12);
    tmp->right->left = createVal(11);
    tmp->right->right = createVal(6);
    return tmp;
}

albero creaAlbero3() {
    albero tmp = createVal(8);
    tmp->left = createVal(5);
    tmp->right = createVal(0);
    tmp->right->left = createVal(1);
    tmp->right->right = createVal(5);
    return tmp;
}

void print(albero t) {
    if (t == NULL)return;
    else {
        printf(" (");
        print(t->left);
        printf(" %d ", t->val);
        print(t->right);
        printf(") ");
    }
}

void stampa(albero T) {
    print(T);
    printf("\n");
}

albero createVal(int val) {
    albero tmp = (albero)malloc(sizeof(nodo));
    tmp->val = val;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

////// ESERCIZIO 4 /////////////////////////////////////////////////////////////////////////////////////////////////////////////

Si consideri il seguente schema, relativo ad una catena di piscine pubbliche (i campi tutto maiuscolo sono le chiavi delle tabelle).

CLIENTE (CFCLIENTE, Nome, Cognome, Città, Data_Nascita)
PISCINA (IDPISCINA, Nome, Indirizzo, Città, Data_Inaugurazione)
BIGLIETTO (CFCLIENTE, IDPISCINA, DATAINGRESSO)

Scrivere una query in SQL che estrae CF, Nome e Cognome dei clienti che non sono mai andati in piscine della loro città.
SELECT C.CFCliente,C.Nome,C.Cognome
 FROM Cliente as C,Piscina as P,Biglietto as B
 WHERE C.CfCliente=B.CfCliente AND
             P.IdPiscina=B.IdPiscina AND
             B.IdPiscina NOT IN (SELECT P2.IdPiscina
                                    FROM Piscina as P2
                                    WHERE P2.Città=C.Città)
 GROUP BY C.CFCliente

Scrivere una query in SQL che estrae CF, Nome e Cognome dei clienti di Milano che hanno frequentato almeno una volta tutte le piscine di Milano.
 SELECT C.CFCliente,C.Nome,C.Cognome
 FROM Cliente as C,Biglietto as B,Piscina as P
 WHERE C.CFCliente=B.CFCliente AND
            B.IdPiscina=P.IdPiscina AND
            C.Città='Milano' AND
            P.Città='Milano
 GROUP BY C.CFCliente
 HAVING count(*)=(SELECT Count(IdPiscina)//essendo una chiave non ho messo Distinct.
                             FROM Piscina
                             WHERE Città='Milano')
