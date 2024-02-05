#include <stdio.h>
#include <stdlib.h>

typedef struct n {
        int val;
        struct n * left;
struct n * right;
} nodo;
typedef nodo * albero;

albero createVal(int val);
albero creaAlbero1(); albero creaAlbero2(); albero creaAlbero3();
void print(albero t);
void stampa(albero T);
int verifica(albero t, int elem);
int comuni(albero t1,albero t2);
int main(){
    int ris=0;
    albero T1,T2,T3;
    T1 = creaAlbero1(); T2 = creaAlbero2(); T3 = creaAlbero3();
    printf("\nT1: "); stampa(T1);
    printf("\nT2: "); stampa(T2);
    printf("\nT3: "); stampa(T3);
    ris=comuni(T2,T3);
   //LA FUNZIONE valoriInComune  VIENE INVOCATA QUI
   printf("gli alberi T1 E T2 hanno %d elementi comuni",ris);

   //VIENE STAMPATO IL RISULTATO DELLE INVOCAZIONI PER RESTITUIRE COME DA ESEMPIO 

    return 0;
}

//
// TODO: SVILUPPARE QUI valoriInComune 
//

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
    albero tmp = (albero)malloc(sizeof(nodo));
    tmp->val = val;    tmp->left = NULL;    tmp->right = NULL;
    return tmp;
}

int verifica(albero t, int elem){
	if(t==NULL) return 0;
	if(t->val==elem) return 1;
	return verifica(t->right,elem) || verifica(t->left,elem);
}

int comuni(albero t1,albero t2){
	int count=0;
	if(t1==NULL || t2==NULL) return 0;
	if(verifica(t1,t2->val)){
		return 1+comuni(t1,t2->left)+comuni(t1,t2->right); //se metti t->val li sommi
	}
	///se ce lo sommi ma poi devi dare questo risultato;il count è ricorsivo
	return comuni(t1,t2->left)+comuni(t1,t2->right);

}

