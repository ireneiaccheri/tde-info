///// TDE 1 FEBBRAIO 2021////////////////////////////////////////////////////////////////////////////////////////////////////////
/////ESERCIZIO 1 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Si scriva una funzione "primaPosizioneConsonante" che prende in ingresso
- una stringa "txt" di massimo 100 caratteri, contenente del testo
e restituisce
- un vettore di interi "pos" che nella posizione i-sima contiene la posizione
della prima consonante all'interno dell'i-sima parola.

si completi quindi il seguente main con l'invocazione a "primaPosizioneConsonante" con la stampa del contentuto di "txt" e di "pos"

PS: se utile, è lecito assumere che
    - "txt" non termini con il carattere spazio
    - "txt" non contenga altro che caratteri minuscoli
    - tutte le parole di "txt" contengono almeno una consonante
    
    
	risultato atteso:

volo in aeroplano con la prima aurora:
->
0 1 2 0 0 0 2

mangio due uova nella aiuola:
->
 0 0 2 0 4*/
    
#include<stdio.h>
int lunghezza(char str[]);
void primaconsonante(char txt[],int v[]);
int main()
{
    char txt1[100] = "volo in aeroplano con la prima aurora";
    char txt2[100] = "mangio due uova nella aiuola";
    int len=lunghezza(txt2);
    int v1[len],i;
    // TODO: DEFINIZIONE VARIABILI AGGIUNTIVE
   for(i=0;i<len;i++){
   	v1[i]=0;}
   
   primaconsonante(txt1,v1);
 
    // TODO: INVOCAZIONE funzione su txt1
    // STAMPA tutta la *porzione utilizzata* del vettore "pos"

    // TODO: INVOCAZIONE funzione su txt2
    // STAMPA tutta la *porzione utilizzata* della stringa "pos"

}

int lunghezza(char str[]){
	int count=0,i;
	for(i=0;str[i]!='\0';i++){
		if(str[i]==' ')
		count++;	}
	return count+1;
}

void primaconsonante(char txt[],int v[]){
	int i,j=1;
	int iniziatori[lunghezza(txt)];
///mi creo vettore aux che mi dice dove iniziano le varie parole///
    iniziatori[0]=0;
	for(i=1;txt[i]!='\0';i++){
		if(txt[i-1]==' '){
			iniziatori[j]=i;
			j++;
		}
	}
	for(i=0;i<7;i++)
	printf("%d\t",iniziatori[i]);
	printf("\n\n");
	int k=0;
	
	for(i=0;txt[i]!='\0' && k<6 ;i++){
		if(txt[i]!='a' && txt[i]!='e' && txt[i]!='i' &&txt[i]!='o' &&txt[i]!='u' ){
			v[k]=i-iniziatori[k];
			i=iniziatori[k+1]-1; ///faccio partie il conteggio da dove iniziano le parole; non ho capito perch -1
			k++;
		}
		
	}
	printf("\n\n");
	for(int t=0;t<7;t++){
		printf("%d\t",v[t]);
	}
	
}

////ESERCIZIO 2 LISTE/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Si consideri una lista di conti correnti bancari così definita
typedef struct c {???????? char c;
struct c * next; }???????? Cifra;

typedef Cifra * NumTelefono;

typedef struct con {???????? char nome[1000];
char IBAN[1000];
NumTelefono numero;
struct con * next; }???????? Correntista;

typedef Correntista * ListaConti;

Si noti che ogni nodo contiene un nome e un numero costruito come una lista di caratteri 
(esempio di IBAN IT02L1234512345123456789012).

Con l’avvento dell’unione bancaria europea arrivano correntisti dall’estero e urge uniformare 
la gestione dei contatti telefonici
- Se il numero inizia con il carattere '+' resta inalterato
- Se inizia con due zeri, li sostituisce con un '+'
- Se inizia con un solo zero o con una cifra diversa da zero ('1','2', ... '9') 
vi aggiunge i caratteri ‘+’, ‘3’ e ‘9’ all'inizio

Si sviluppino le funzioni richeiste e le si invochi nel main sotto definito nel file:
https://www.dropbox.com/s/2rqserwcksiwrdy/lab7es4.c?dl=0

OUTPUT ATTESO:
Alessandro IBAN: IT020000000000000 Numero:333333333
Marco IBAN: IT020000000000000 Numero:+3956789
Giacomo IBAN: IT020000000000000 Numero:003956565656
Giovanni IBAN: IT020000000000000 Numero:03456678
Matteo IBAN: IT020000000000000 Numero:4444444

Alessandro IBAN: IT020000000000000 Numero:+39333333333
Marco IBAN: IT020000000000000 Numero:+3956789
Giacomo IBAN: IT020000000000000 Numero:+3956565656
Giovanni IBAN: IT020000000000000 Numero:+3903456678
Matteo IBAN: IT020000000000000 Numero:+394444444*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct c { char c;
                   struct c * next; } Cifra;
typedef function
typedef Cifra * NumTelefono;

typedef struct con { char nome[1000];
                     char IBAN[1000]; 
					 NumTelefono numero;
					 struct con * next; } Correntista;

typedef Correntista * ListaConti;

NumTelefono InsInTestaCifra( NumTelefono lista, char elem );
NumTelefono InsInFondoCifra( NumTelefono lista,char elem );
ListaConti costruisciListaConti();
NumTelefono costruisciNumero(char * telefono);
ListaConti InsInFondoCorrentista( ListaConti lista, char * nome, char * IBAN, char * telefono );
void stampa(ListaConti lista);
void modifica(ListaConti lista);
NumTelefono Cancella( NumTelefono lista,char num );
int main(){
    ListaConti conti;
	conti=costruisciListaConti();
	// TODO stampa contenuto conti
	// TODO correggi i conti
	// TODO stampa contenuto conti corretti
	//stampa(conti);
	modifica(conti);
	//printf("\n\n");
	stampa(conti);
	
	
	
	
	return 0;
}
ListaConti costruisciListaConti(){
    ListaConti lis=NULL;
	int i=0;
	char nomi[5][20]={"Alessandro","Marco","Giacomo","Giovanni","Matteo"};
	char IBAN[5][20]={"IT020000000000000","IT020000000000000","IT020000000000000","IT020000000000000","IT020000000000000"};
	char telefoni[5][20]={"333333333","+3956789","003956565656","03456678","4444444"};
	
	for(i=0;i<5;i++)
	    lis=InsInFondoCorrentista(lis,nomi[i],IBAN[i],telefoni[i]);
		
	return lis;
}

NumTelefono InsInTestaCifra ( NumTelefono lista, char elem ) {
    NumTelefono punt;
	punt = (NumTelefono) malloc(sizeof(Cifra));
	punt->c = elem; punt->next = lista;
	return punt;
}

NumTelefono InsInFondoCifra( NumTelefono lista,char elem ) {
	NumTelefono punt;
	if( lista==NULL ) {
		punt = (NumTelefono)malloc( sizeof(Cifra) );
		punt->next = NULL; punt->c = elem;
		return punt;
	} else { 
		lista->next = InsInFondoCifra( lista->next, elem );
		return lista;
	}
}

NumTelefono costruisciNumero(char * telefono){
	int i;
	NumTelefono lis=NULL;
	for(i=0;telefono[i]!='\0';i++)
		lis=InsInFondoCifra(lis,telefono[i]);
	return lis;
}

ListaConti InsInFondoCorrentista( ListaConti lista, char * nome, char * IBAN, char * telefono ) {
	ListaConti punt;
	if( lista==NULL ) {
		punt = (ListaConti)malloc( sizeof(Correntista) );
		punt->next = NULL;
		strcpy(punt->nome, nome);
		strcpy(punt->IBAN, IBAN);
		punt->numero=costruisciNumero(telefono);
		return punt;
	} else {
		lista->next = InsInFondoCorrentista( lista->next, nome, IBAN, telefono );
		return lista;
	}
}

void stampa(ListaConti lista){
	while(lista!=NULL){
		 printf("%s,   IBAN:%s, ",lista->nome,lista->IBAN);
		 while(lista->numero!=NULL ){
		 	printf("%c",lista.numero->c);
		 	lista->numero=lista->numero->next;
		 }
		 printf("\n");
		lista=lista->next;
	}
	
}

NumTelefono Cancella( NumTelefono lista,char num ) {
    NumTelefono puntTemp;
	if( lista!=NULL){
		if(lista->c==num){
		
		    puntTemp = lista->next;
			free( lista );
			return puntTemp;} }// per cancellare tutte le istanze: return Cancella(PuntTemp, Elem); }
		else
		    lista->next = Cancella( lista->next,num);
		return lista;
}
void modifica(ListaConti lista){
	while(lista!=NULL){
		
		if(lista->numero->c=='0' && lista->numero->next->c=='0'){
			lista->numero=Cancella(lista->numero,'0');
			lista->numero=Cancella(lista->numero,'0');
			lista->numero=InsInTestaCifra(lista->numero,'+');
			
		}else{
		if((lista->numero->c=='0' && lista->numero->next->c!='0') || (lista->numero->c!='\0' && lista->numero->c!='+')){
				lista->numero=InsInTestaCifra(lista->numero,'9');
				lista->numero=InsInTestaCifra(lista->numero,'3');
				lista->numero=InsInTestaCifra(lista->numero,'+');
			
		}}
		lista=lista->next;
	}
}

///ESERCIZIO 3 SQL///////////////////////////////////////////////////////////////////////////////////////////////////////////////
Lo schema seguente è utilizzato per gestire l’acquisto di biglietti per i voli di una compagnia aerea. Capienza indica il numero massimo di posti disponibili su un determinato volo. Le chiavi sono gli attributi scritti interamente in maiuscolo.
- VOLO (NUMERO, DATA, Ora, AeroportoPartenza, AeroportoDestinazione, Capienza, TipoAeromobile)
- BIGLIETTO (NUMEROPOSTO, NUMEROVOLO, DATA, CFCliente, Prezzo)
- CLIENTE (CF, Nome, Cognome, Indirizzo, Città, Nazione)

Scrivere la query SQL che, per ciascun giorno, trova la media dei prezzi dei biglietti venduti.

SELECT avg(prezzo)
FROM Biglietto
GROUP BY Data 
// non ho condizioni sul where, e devo scegliere di cosa fare la media///


Scrivere la query SQL che estrae i voli per cui sono stati venduti solo biglietti più costosi di 2000 euro
SELECT (*)
FROM Volo
WHERE Numero NOT IN (SELECT Numerovolo
                     FROM Biglietto
					 WHERE Prezzo<2000) 

///prendo i voli per cui i biglietti costano meno di 2000--->devo prendere tuttti gli altri///////////

