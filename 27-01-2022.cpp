///// TDE 27/01/2022////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// ESERCIZIO 1 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//non si capisce il testo cosa chiede ////////////////////


///// ESERCIZIO 2 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Si scriva una funzione che riceve in ingresso una lista di stringhe contenenti tre o più caratteri 
(escluso il terminatore di stringa) e modifica la lista eliminando le parole consecutive per cui 
le ultime due lettere della prima parola sono uguali alle prime due della seconda. 
Per semplicità, si supponga non esistano tre (o più) parole consecutive con questa proprietà.

Ad esempio, la lista:
casa -> sale -> postino -> rame -> meta -> sasso -> osteria -> salvia -> notare -> renna
diventa
postino -> sasso -> osteria -> salvia*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct EL {
	char info[100];
	struct EL * prox;
} ElemLista;

typedef ElemLista * Lista;


Lista InsInFondoStringa(Lista lista,const char elem[] );
void VisualizzaListaStringhe(Lista lista );
Lista costruisci();
int consecutive(char str1[],char str2[]);
Lista checker(Lista lis);
//
// TODO: PROTOTIPI DELLE FUNZIONI RICHIESTE
//


int main(){
	Lista lis;
	lis=costruisci();
	//VisualizzaListaStringhe(lis);

	//TODO: invocazione funzione
  

	VisualizzaListaStringhe(checker(lis));

	return 0;
}

//
// TODO: SVILUPPARE QUI LE FUNZIONI RICHIESTE
//


Lista costruisci(){
	Lista lis=NULL;
	lis=InsInFondoStringa(lis,"casa");lis=InsInFondoStringa(lis,"sale");lis=InsInFondoStringa(lis,"postino");
	lis=InsInFondoStringa(lis,"rame");lis=InsInFondoStringa(lis,"meta");lis=InsInFondoStringa(lis,"sasso");
	lis=InsInFondoStringa(lis,"osteria");lis=InsInFondoStringa(lis,"salvia");lis=InsInFondoStringa(lis,"notare");
	lis=InsInFondoStringa(lis,"renna");
	
	return lis;
}

Lista InsInFondoStringa(Lista lista,const char elem[]) {
    Lista punt;
    if(lista==NULL) { punt = (Lista)malloc( sizeof(ElemLista) );
                     punt->prox = NULL; strcpy(punt->info,elem); return  punt;
    }else{lista->prox = InsInFondoStringa(lista->prox,elem); return lista;}
}

void VisualizzaListaStringhe(Lista lista) {
    if (lista==NULL) printf(" ---| \n");
    else{printf(" %s ---> ", lista->info); VisualizzaListaStringhe( lista->prox );}
}

int consecutive(char str1[],char str2[]){
	int lun=strlen(str1); //str1 è la stringa di cui controllo le finali;
	
	if((str1[lun-2]==str2[0])&& (str1[lun-1]==str2[1])){
	
	return 1;}else return 0;
	
}


Lista checker(Lista lis) {
    Lista result = NULL;
    Lista current = lis;

    while (current != NULL && current->prox != NULL) {
        if (consecutive(current->info, current->prox->info)) {
            Lista temp = current;
            current = current->prox->prox;
             
            free(temp);
        } else {
            // Aggiungi la parola corrente alla lista risultante
            result = InsInFondoStringa(result, current->info);
            current = current->prox; // Passa all'elemento successivo
        }
    }

    // Aggiungi l'ultimo elemento se presente
    if (current != NULL) {
        result = InsInFondoStringa(result, current->info);
    }

    return result;
}


////// ESERCIZIO 3 ////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Si considerino due alberi TA e TB (alberi di esempio e chiamate di prova sono definiti nel codice C allegato). Si scriva una funzione f che prende in ingresso TA e TB e stampa a video per ogni elemento di TA quanti suoi divisori (propri o impropri) contiene TB.

File da cui partire: https://www.dropbox.com/s/555b41hg9lcy2ml/esAlberi.c?dl=0

Con gli alberi nel codice:

T1:  ( ( ( 9 )  3  ( 10 ) )  7  ( ( 5 )  8  ( ( 11 )  12  ( 9 ) ) ) )

T2:  ( ( ( ( 6 )  12  ( 11 ) )  7  ( 9 ) )  7  ( ( 10 )  7  ( 9 ) ) )

T3:  ( ( ( ( 6 )  12  ( 2 ) )  4  ( 3 ) )  3  ( ( 10 )  3  ( 9 ) ) )

l’output sarà:

T1 in T2
Il valore 7 ha 3 divisori
Il valore 9 ha 2 divisori
Il valore 10 ha 1 divisori
Il valore 12 ha 2 divisori
Il valore 11 ha 1 divisori
Il valore 9 ha 2 divisori

T2 in T1
Il valore 7 ha 1 divisori
Il valore 7 ha 1 divisori
Il valore 12 ha 2 divisori
Il valore 6 ha 1 divisori
Il valore 11 ha 1 divisori
Il valore 9 ha 3 divisori
Il valore 7 ha 1 divisori
Il valore 10 ha 2 divisori
Il valore 9 ha 3 divisori

T1 in T3
Il valore 3 ha 3 divisori
Il valore 9 ha 4 divisori
Il valore 10 ha 2 divisori
Il valore 8 ha 2 divisori
Il valore 12 ha 7 divisori
Il valore 9 ha 4 divisori

T3 in T1
Il valore 3 ha 1 divisori
Il valore 12 ha 2 divisori
Il valore 6 ha 1 divisori
Il valore 3 ha 1 divisori
Il valore 3 ha 1 divisori
Il valore 10 ha 2 divisori
Il valore 9 ha 3 divisori

T2 in T3
Il valore 12 ha 7 divisori
Il valore 6 ha 5 divisori
Il valore 9 ha 4 divisori
Il valore 10 ha 2 divisori
Il valore 9 ha 4 divisori

T3 in T2
Il valore 12 ha 2 divisori
Il valore 6 ha 1 divisori
Il valore 10 ha 1 divisori
Il valore 9 ha 2 divisori*/

#include <stdio.h>
#include <stdlib.h>

typedef struct n {
        int val;
        struct n * left, * right;
} nodo;
typedef nodo * Albero;

Albero createVal(int val);
Albero creaAlbero1();Albero creaAlbero2();Albero creaAlbero3();
void print(Albero t);
void stampa(Albero T);
void f(Albero T1, Albero T2);
int verifica(Albero t, int elem);
int divisori(Albero t1,int elemt2);
int main(){
    int ris=0, valore = -1;
    Albero T1,T2,T3;
    T1 = creaAlbero1(); T2 = creaAlbero2(); T3 = creaAlbero3();
    //printf("\nT1: "); stampa(T1);
    //printf("\nT2: "); stampa(T2);
    //printf("\nT3: "); stampa(T3);

    //
    // TODO: CHIAMATE DI TEST
    //
    printf("\nT1 in T2\n");f(T1,T2);
    //printf("\nT2 in T1\n");f(T2,T1);
    //printf("\nT1 in T3\n");f(T1,T3);
    //printf("\nT3 in T1\n");f(T3,T1);
    //printf("\nT2 in T3\n");f(T2,T3);
    //printf("\nT3 in T2\n");f(T3,T2);

 	//FUNZIONI AUSILIARIE CON PARAMETRI DIVERSI SONO MOLTO CONSIGLIATE

    return 0;
}


Albero creaAlbero1() {
    Albero tmp = createVal(7);
    tmp->left = createVal(3);tmp->left->left = createVal(9);tmp->left->right = createVal(10);
    tmp->right = createVal(8);tmp->right->left = createVal(5);tmp->right->right = createVal(12);
    tmp->right->right->left = createVal(11); tmp->right->right->right = createVal(9);
    return tmp;
}

Albero creaAlbero2() {
    Albero tmp = createVal(7);
    tmp->right = createVal(7);tmp->right->right = createVal(9);tmp->right->left = createVal(10);
    tmp->left = createVal(7);tmp->left->right = createVal(9);tmp->left->left = createVal(12);
    tmp->left->left->right = createVal(11);tmp->left->left->left = createVal(6);
    return tmp;
}

Albero creaAlbero3() {
    Albero tmp = createVal(3);
    tmp->right = createVal(3);tmp->right->right = createVal(9);tmp->right->left = createVal(10);
    tmp->left = createVal(4);tmp->left->right = createVal(3);tmp->left->left = createVal(12);
    tmp->left->left->right = createVal(2);tmp->left->left->left = createVal(6);
    return tmp;
}

void print(Albero t){
       if(t==NULL)return;
       else{printf(" (");print(t->left);printf(" %d ",t->val);print(t->right);printf(") ");}
}

void stampa(Albero T){print(T);printf("\n");}

Albero createVal(int val) {
    Albero tmp = (Albero)malloc(sizeof(nodo));
    tmp->val = val;    tmp->left = NULL;    tmp->right = NULL;
    return tmp;
}


//conto quanti divisori ci sono in totale
int divisori(Albero t1,int elemt2){
	int count=0;
	if(t1==NULL) return 0;
	if(elemt2%t1->val==0){
		return 1+divisori(t1->right,elemt2)+divisori(t1->left,elemt2); //se metti t->val li sommi
	}
	///se ce lo sommi ma poi devi dare questo risultato;il count è ricorsivo
	return divisori(t1->right,elemt2)+divisori(t1->left,elemt2);

}
void f(Albero T1,Albero T2){
	if(T2==NULL) return;
	printf("il valore %d ha %d divisori\n",T2->val,divisori(T1,T2->val));
	f(T1,T2->right);
	f(T1,T2->left);
}

//// ESERCIZIO 4 SQL /////////////////////////////////////////////////////////////////////////////////////////////////////////77
Dato il seguente schema (chiave primaria tutta in maiuscolo):
CLIENTE(CODCLIENTE, Nome, Indirizzo, SecondiTotali)
TELEFONATA(CODCLIENTE, DATAINIZIO, ORAINIZIO, DurataInSecondi, TipoTariffa)
TARIFFA(TIPOTARIFFA, CostoAlSecondo)

Scrivere la query che estrae il codice dei clienti che non hanno mai effettuato telefonate dopo le 22:00
SELECT CODCLIENTE
FROM TELEFONATA
WHERE CODLICENTE NOT IN (SELECT CODCLIENTE
                         FROM TELEFONATA
						 WHERE ORARIOINIZIO>='22:00')
						 
Scrivere in SQL la query che estrae per ogni cliente la media della durata delle telefonate del 2021
SELECT CODCLIENTE,AVG(DURATA IN SECONDI)
FROM TELEFONATA
WHERE DATAINIZIO>='1/1/2021' AND DATAINIZIO<='31/12/2021'
GROUP BY CODCLLIENTE
