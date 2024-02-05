

//////// ESERCIZIO 3 ///////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura Nodo
typedef struct N {
    int valore;
    struct N * left,* right;
} Nodo;
typedef Nodo * Albero;
int delta(int a,int b);
Albero nuovoNodo(int valore);
void stampaAlbero(Albero t);
void print(Albero t);
Albero costruisci1();
Albero costruisci2();
int varianza(Albero t);
int max(int a,int b);
int main() {
    // Creazione dell'albero
    Albero alb1 = costruisci1();
    Albero alb2 = costruisci2();

    // Stampa dell'albero
    printf("Stampa dell'albero in ordine (left, radice, right):\n");
    stampaAlbero(alb1);
    stampaAlbero(alb2);
    
    //stampe e invocazioni
    printf("Albero 1: %d\n",varianza(alb1));
    printf("Albero 2: %d\n",varianza(alb2));

    return 0;
}

//FUNZIONE DA COMPLETARE 
//(E SCRIVERE INSIEME AD ALTRE FUNZIONI AUSILIARIE CHE f INVOCA)
int f(Albero T){
	//FUNZIONE DA SCRIVERE
	return 0;
}

// Funzione per creare un nuovo nodo
Albero nN(int valore) {
    Albero nodo = (Albero) malloc(sizeof(Nodo));
    nodo->valore = valore;
    nodo->left = NULL;
    nodo->right = NULL;
    return nodo;
}

// Funzione per stampare l'albero
void stampaAlbero(Albero t){print(t);printf("\n");}
void print(Albero t){
    if(t==NULL)return;
    else{printf(" (");print(t->left);printf(" %d ", t->valore);print(t->right);printf(") ");}
}
Albero costruisci1(){
    Albero radice=nN(3);radice->left=nN(4);radice->right=nN(9);radice->left->left=nN(2);radice->left->right=nN(6);radice->right->left=nN(8);radice->left->left->left=nN(1);radice->left->left->right=nN(3);
    return radice;
}
Albero costruisci2(){
    Albero radice=nN(3);radice->left=nN(4);radice->right=nN(100);radice->left->left=nN(2);radice->left->right=nN(6);radice->right->left=nN(8);radice->right->right=nN(1);
    return radice;
}

int delta(int a,int b){
	if(a>b){
		return a-b;
	}else return b-a;
}

int varianza(Albero t){
	if(t==NULL) return 0;
	int d=delta(t->valore,t->right->valore);
	int s=delta(t->valore,t->left->valore);	
		
	if(d>s){
		return d;
	}else return s;

   return max(varianza(t->left),varianza(t->right));
}

int max(int a,int b){
if(a>b){return a;}
else return b; }

