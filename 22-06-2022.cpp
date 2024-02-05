///// TDE 22-06-2022 /////////////////////////////////////////////////////////////////////////////////////////////
///// ESERCIZIO 1 //////////////////////////////////////////////////////////////////////////////////////////////////
/*Si scriva una funzione che riceve una matrice di caratteri NxN e restituisce 1 
se la matrice contiene solo i caratteri B e W disposti a scacchiera. 
Se invece la matrice non è a scacchiera o non contiene solo i caratteri B e W la funzione restituisce 0 e 
riporta al chiamante il numero della prima riga che viola la proprietà.

B W B W B W B W
W B W B W B W B
B W B W B W B W
W B W B W B W B     —-> 1
B W B W B W B W
W B W B W B W B
B W B W B W B W
W B W B W B W B

B W B W B W B W
B W B W B W B W
W B W B W B W B
W B W B W B W B     —-> 0 (le prime due righe sono identiche, quindi non è una scacchiera)
B W B W B W B W
W B W B W B W B
B W B W B W B W
W B W B W B W B

B C B W B W B W
W B W B W B W B
B W B W B W B W
W B W B W B W B     —-> 0 (il secondo carattere della prima riga non è né B né W)
B W B W B W B W
W B W B W B W B
B W B W B W B W
W B W B W B W B*/
#include <stdio.h>
#define N 8
int uguale(char mat[][N]);
int scacchiera(char mat[][N]);
int check(char mat[][N]);
int main(){
	int i,k;
	char M1[N][N]={'B','W','B','W','B','W','B','W','W','B','W','B','W','B','W','B','B','W','B','W','B','W','B','W','W','B','W','B','W','B','W','B','B','W','B','W','B','W','B','W','W','B','W','B','W','B','W','B','B','W','B','W','B','W','B','W','W','B','W','B','W','B','W','B',};
	char M2[N][N]={'B','W','B','W','B','W','B','W','W','B','W','B','W','B','W','B','W','B','W','B','W','B','W','B','W','B','W','B','W','B','W','B','B','W','B','W','B','W','B','W','W','B','W','B','W','B','W','B','B','W','B','W','B','W','B','W','W','B','W','B','W','B','W','B',};
	char M3[N][N]={'B','C','B','W','B','W','B','W','W','B','W','B','W','B','W','B','B','W','B','W','B','W','B','W','W','B','W','B','W','B','W','B','B','W','B','W','B','W','B','W','W','B','W','B','W','B','W','B','B','W','B','W','B','W','B','W','W','B','W','B','W','B','W','B',};
	
	printf("M1\n");
	for(i=0;i<N;i++){for(k=0;k<N;k++){printf("%c ",M1[i][k]);}printf("\n");}
	printf("\nM2\n");
	for(i=0;i<N;i++){for(k=0;k<N;k++){printf("%c ",M2[i][k]);}printf("\n");}
	printf("\nM3\n");
	for(i=0;i<N;i++){for(k=0;k<N;k++){printf("%c ",M3[i][k]);}printf("\n");}
	

	//printf("\n%d",check(M1));
	return 0;
}

int uguale(char mat[][N]){
	///faccio restituire 1 se e tutto uguale
	int i,j,si=1;;
	for(i=0;i<N && si;i++){ //accorcio dal pov computazionale
		for(j=0;j<N && si;j++){
			if(mat[i][j]!='B' && mat[i][j]!='W')
			si=0;
		}
	}
	return si;
}

int scacchiera(char mat[][N]){
	int i,j,si=1;
	for(i=0;i<N-1 && si;i++){
		for(j=0;j<N-1 && si;j++){
			if(mat[i][j]==mat[i][j+1])
			si=0;
		}
		if(mat[i+1][0]!=mat[i][j]) //l'iniziale della riga successiva deve essere uguale al finale della precedente
		si=0;
	}
	return si;
}

int check(char mat[][N]){
	return scacchiera(mat) && uguale(mat);
	// mi ritorna 1 se verifico entrambe le condizioni

}


//////// ESERCIZIO 2 ////////////////////////////////////////////////////////////////////////////////////////77
/*

Nel seguente main viene popolata la lista ordini contenente tutti i piatti che sono
stati ordinati al ristorante.

Si definisca un nuovo tipo Tavolo per gestire una lista di tavoli, ciascuno contenente
l'identificativo del tavolo ed una lista di piatti ordinati a quel tavolo.
----------> Tavolo sara una struct contenente ID e listapiatti ordinati
----------> di questo a sua volta ne avro una lista

Si scriva quindi una funzione organizzaPerTavoli che prende in ingresso la lista ordini
e popola una lista di tavoli dove ogni nodo contiene una sottolista di piatti ordinati
per quel tavolo.

Si sviluppi e si invochi nel main una funzione VisualizzaTavoli che stampa il contenuto
della lista tavoli come da esempio.

Stampa contenuto di oridni

 nome:Karelian Pie, tav:1 (10.50) --->
 nome:Makkara, tav:1 (8.00) --->
 nome:Musta Makkara, tav:1 (12.00) --->
 nome:Baltic Herrings, tav:2 (20.00) --->
 nome:Pasta all'Amatriciana, tav:2 (20.00) --->
 nome:Herrings, tav:1 (20.00) --->
 nome:Sgombro al Limone, tav:4 (20.00) --->
 nome:Tiramisu', tav:4 (20.00) --->  ---|


 --- TAVOLO ID: 1 ---
 nome:Karelian Pie, tav:1 (10.50) --->
 nome:Makkara, tav:1 (8.00) --->
 nome:Musta Makkara, tav:1 (12.00) --->
 nome:Herrings, tav:1 (20.00) --->  ---|
 --- TAVOLO ID: 2 ---
 nome:Baltic Herrings, tav:2 (20.00) --->
 nome:Pasta all'Amatriciana, tav:2 (20.00) --->  ---|
 --- TAVOLO ID: 4 ---
 nome:Sgombro al Limone, tav:4 (20.00) --->
 nome:Tiramisu', tav:4 (20.00) --->  ---|*/
 
 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
typedef char Tipo[N];

typedef struct ndP{
    float costo;
    int tavolo;
    Tipo nome;
    struct ndP* next;
} Piatto;

typedef Piatto* ListaP;

typedef struct ndT{
    int tavolo;
    ListaP ordiniTavolo;
    struct ndT* next;
} Tavolo;
typedef Tavolo* ListaT;
void visualizza(ListaT lis);
ListaP InsInFondoPiatto(ListaP lista, float costo, int tavolo, Tipo nome);
void VisualizzaListaP(ListaP lista);
ListaP costruisci();
ListaT organizza(ListaP lista);
int main()
{
    ListaP ordini = costruisci();
    ListaP temp;
    ListaT tavoli = NULL;
    ///VisualizzaListaP(ordini);
    //printf("\n\n");
    visualizza(organizza(ordini));
    return 0;
}

// Sviluppare qui le funzioni richieste
ListaP costruisci()
{
ListaP lista = NULL;
lista = InsInFondoPiatto(lista, 10.5, 1, "Karelian Pie"); lista = InsInFondoPiatto(lista, 8.0, 1, "Makkara");lista = InsInFondoPiatto(lista, 12.0, 1, "Musta Makkara");lista = InsInFondoPiatto(lista, 20, 2, "Baltic Herrings");lista = InsInFondoPiatto(lista, 20, 2, "Pasta all'Amatriciana");lista = InsInFondoPiatto(lista, 20, 1, "Herrings");lista = InsInFondoPiatto(lista, 20, 4, "Sgombro al Limone");lista = InsInFondoPiatto(lista, 20, 4, "Tiramisu'");return lista;
}

ListaP InsInFondoPiatto(ListaP lista, float costo, int tavolo, Tipo nome)
{
    ListaP punt;
        if(lista==NULL) { punt =(ListaP) malloc( sizeof(Piatto) );
                     punt->next = NULL; punt->costo = costo; punt->tavolo = tavolo; strcpy(punt->nome,nome);return punt;
    }else{lista->next = InsInFondoPiatto(lista->next,costo, tavolo, nome); return lista;}
}

void VisualizzaListaP(ListaP lista)
{
  if (lista==NULL) printf(" ---| \n");
    else{printf("\n nome:%s, tav:%d (%.2f) ---> ", lista->nome, lista->tavolo, lista->costo);
     VisualizzaListaP(lista->next);}
}

ListaT organizza(ListaP lista) {
    ListaT ris = NULL; // Inizializza la lista di tavoli

    while (lista != NULL) {
        int ID = lista->tavolo;
        ListaT tavoloAttuale = ris;

        // Cerca se esiste già un tavolo con lo stesso numero
        while (tavoloAttuale != NULL && tavoloAttuale->tavolo != ID) {
            tavoloAttuale = tavoloAttuale->next;
        }

        // Se il tavolo non esiste, creane uno nuovo
        if (tavoloAttuale == NULL) {
            tavoloAttuale = (ListaT)malloc(sizeof(Tavolo));
            tavoloAttuale->tavolo = ID;
            tavoloAttuale->ordiniTavolo = NULL;
            tavoloAttuale->next = ris;
            ris = tavoloAttuale;
        }

        // Aggiungi l'ordine al tavolo corrente
        tavoloAttuale->ordiniTavolo = InsInFondoPiatto(tavoloAttuale->ordiniTavolo, lista->costo, lista->tavolo, lista->nome);

        lista = lista->next;
    }

    return ris;
}

void visualizza(ListaT lis) {
    while (lis != NULL) {
        printf("\n --- TAVOLO ID: %d ---", lis->tavolo);
        VisualizzaListaP(lis->ordiniTavolo);
        lis = lis->next;
    }
}*/


//////ESERCIZIO 3 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Si scriva una funzione f che riceve un albero e stampa la media degli elementi di ogni livello dell’albero. 
Si consiglia fortemente di utilizzare uno o più array grandi come la profondità dell’albero, allocati dinamicamente.
------>devo calcolarmi la somma di ogni livello e salvarla in un vettore e dividere per la profondita*/

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
void f(albero t);
int depth(albero t);
void somma(albero t, int *v,int cur);
void quanti(albero t, int *v,int cur);
int main(){
    int ris=0;
    albero T1,T2,T3;
    T1 = creaAlbero1(); T2 = creaAlbero2(); T3 = creaAlbero3();
    printf("\nT1: "); stampa(T1);
    //printf("\nT2: "); stampa(T2);
    //printf("\nT3: "); stampa(T3);

   //LA FUNZIONE DA SVILUPPARE VIENE USATA QUI


   f(T1);
   //f(T2);
   //f(T3);
   
   return 0;
}

//
// TODO: SVILUPPARE QUI DENTRO QUANTO RICHIESTO
//
void f(albero t){
    //SVILUPPARE QUI QUANTO RICHIESTO 
	//FUNZIONI AUSILIARIE CON PARAMETRI AGGIUNTIVI SONO MOLTO CONSIGLIATE
	///per ogni livello devi stampare la media
	int i,*v,*cont,livelli=depth(t);
	v=(int*)malloc(sizeof(int)*livelli);
	cont=(int*)malloc(sizeof(int)*livelli);
	for(i=0;i<livelli;i++){
		v[i]=0;
		cont[i]=0;
	}
	somma(t,v,0);
	for(i=0;i<livelli;i++){
	printf("\t%d",v[i]);
	}
	printf("\n\n");
	quanti(t,cont,0); // devi capire quanti nodi hai per livello;
	for(i=0;i<livelli;i++){
	printf("\t%d",cont[i]);
	}
	
	printf("\n\n");

	for(i=0;i<livelli;i++){
	printf("\t%f",float(v[i])/cont[i]);
	}


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
    albero tmp = (albero)malloc(sizeof(nodo));
    tmp->val = val;    tmp->left = NULL;    tmp->right = NULL;
    return tmp;
}

int depth(albero t){
	if(t==NULL) return 0;
	int s=depth(t->left);
	int d=depth(t->right);
	if(s>d){
		return 1+s;
	}else return 1+d;
}


void somma(albero t, int *v, int cur){
    if (t == NULL) {
        return;
    }

    v[cur] += t->val;  // Aggiungi il valore del nodo corrente al livello corrente
    somma(t->left, v, cur + 1);
    somma(t->right, v, cur + 1);
}


void quanti(albero t, int *vett, int cur){
    if (t == NULL) {
        return;
    }

    vett[cur] += 1;  // conta quanti nodi per ogni livello
    quanti(t->left, vett, cur + 1);
    quanti(t->right, vett, cur + 1);
}


