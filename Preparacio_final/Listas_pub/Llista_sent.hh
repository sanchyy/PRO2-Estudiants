#ifndef LLISTA_SENT_HH
#define LLISTA_SENT_HH

#include <iostream> 
using namespace std;


template <class T> class Llista {

private:

struct node2 {
  T info;
  node2* seg;
  node2* ant;
}; 

int longitud;
node2* sent; // sentinella
node2* act; // punto de interés

// Ver figura 10.1 de los apuntes, página 24.

/*
sent es un puntero a un nodo extra que no contiene ningún elemento. 

El primer nodo de la lista es el siguiente del nodo al que apunta sent. 

El punto de interés act puede apuntar a sent, pero sent no se puede
consultar, modificar o borrar. Si act apunta a sent, se interpreta que
el punto de interés apunta a end().

El último nodo de la lista es el anterior del nodo al que apunta sent.

sent es también el ant del primer nodo y el seg del último nodo de la
lista. 

Si la lista es vacía, los campos seg y ant de sent apuntan a sent, 
es decir a sí mismo. 
*/


static node2* copia_cadena_sent(node2* m, node2* s, 
     node2* oact, node2* &ns, node2* &a)
/* Pre: s apunta a un sentinella, m apunta al primer node de la cadena
   que acaba en s. */
/* Post: si m apunta a s, el resultat, ns i a apunten a una còpia del
sentinella; en cas contrari, el resultat apunta al primer node d'una
cadena de nodes que és copia de la cadena que té el node apuntat per m
com a primer i acaba en s, ns apunta a la còpia del sentinella s, i a
apunta al nod còpia del node apuntat per oact. */
{ 
node2* n = new node2;
if (m==s) {ns = n; a = ns; ns->seg = ns; ns->ant = ns;}
else {
  n->info = m->info;
  n->seg = copia_cadena_sent(m->seg, s, oact, ns, a);
  (n->seg)->ant = n;
  ns->seg = n;
  n->ant = ns;
  if (m == oact) a = n;
}
return n;
}

/*
Caso base: 

Caso recursivo: 

HI: 

Terminación:
*/


static void esborra_cadena_sent(node2* m, node2* s) 
/* Pre: s apunta al centinela de una cadena de nodos, m apunta al
   primer nodo de dicha cadena si contiene más nodos que s, en otro
   caso m apunta a s. */
/* Post: si m apunta a s, borra el centinela; en otro caso, libera el
   espacio de la cadena que tiene al nodo apuntado por m como
   primero y que termina en s. */
{     
if (m != s) {
  esborra_cadena_sent(m->seg,s);
}
delete m;
}

/*
¿Por qué esborra_cadena_sent necesita el segundo parámetro s?  
*/


public:


Llista() 
/* Pre: cert */
/* Post: el resultat es una llista buida */
{
longitud = 0;
sent = new node2;
sent->seg = sent; 
sent->ant = sent; 
act = sent;
}


Llista(const Llista &original) 
/* Pre: cert */
/* Post: El resultat es una copia d'original */
{
longitud = original.longitud;
 node2* aux;
 aux = copia_cadena_sent((original.sent)->seg, original.sent, 
                         original.act, sent, act);  
}

/*
1. ¿Dónde se asignan los dos punteros del p.i.?
*/


~Llista() 
// Destructora: Esborra automaticament els objectes locals en
// sortir d'un ambit de visibilitat
{
  esborra_cadena_sent(sent->seg, sent);
}


Llista& operator=(const Llista& original) 
/* Pre: cert */
/* Post: El p.i. passa a ser una copia d'original i qualsevol contingut
 anterior del p.i. ha estat esborrat (excepte si el p.i. i original ja
 eren el mateix objecte) */
{
if (this != &original) {
  longitud = original.longitud;
  esborra_cadena_sent(sent->seg, sent);
  node2* aux;
  aux = copia_cadena_sent((original.sent)->seg, original.sent, 
                         original.act, sent, act);  
}
return *this;
}


void l_buida() 
/* Pre: cert */
/* Post: El p.i. passa a ser una llista sense elements i qualsevol
 contingut anterior del p.i. ha estat esborrat */
{
esborra_cadena_sent(sent->seg, sent);
longitud = 0;
sent = new node2;
sent->seg = sent; 
sent->ant = sent; 
act = sent;
}


void afegir(const T& x) 
/* Pre: cert */
/* Post: el p.i. és com el seu valor original, però amb x afegit a
 l'esquerra del punt d'interès */
{
node2* aux = new node2; 
aux->info = x;
aux->seg = act;
/* ¿Podríamos hacer 
 act->ant = aux; 
aqui? */
aux->ant = act->ant;
(act->ant)->seg = aux;

act->ant = aux;
++longitud;
}


void eliminar()
/* Pre: el p.i. és una llista no buida i el seu punt d'interès no està a
 la dreta de tot */
/* Post: El p.i. és com el p.i. original sense l'element on estava el
 punt d'interès i amb el nou punt d'interès avançat una posició a la
 dreta */
{
node2* aux = act; 
// Dibujar e identificar los tres nodos
(act->ant)->seg = act->seg;
(act->seg)->ant = act->ant;
act = act->seg; // avanca el punt d'interes
delete aux; // allibera l'espai de l'element esborrat
--longitud;
}


void concat(Llista& l) 
/* Pre: l = L; l no és el mateix objecte que el p.i. */
/* Post: el p.i. té els seus elements originals seguits pels de L, l és
 buida i el punt d'interès del p.i. queda situat a l'inici */
{
if (this != &l) { // Les dues llistes han de ser objectes diferents.
  if (l.longitud > 0) { // Si la llista l és buida no cal fer res.
    if (longitud == 0) swap(sent, l.sent);
    else {
      //ultim_node->seg = l.primer_node;
      (sent->ant)->seg = (l.sent)->seg;
      //(l.primer_node)->ant = ultim_node;
      ((l.sent)->seg)->ant = sent->ant;
      //ultim_node = l.ultim_node;
      sent->ant = (l.sent)->ant;
      ((l.sent)->ant)->seg = sent;

      // Después de conectar el p.i. con l, 
      // hacemos que l pase a ser vacía,  
      // i.e. l.sent se apunta a sí mismo.
      (l.sent)->seg = l.sent; 
      (l.sent)->ant = l.sent;
    }
    longitud += l.longitud;
    // Hacemos que l pase a ser vacía. 
    l.act = l.sent;
    l.longitud = 0;  
  }    
  act = sent->seg;
}
}


bool es_buida() const 
/* Pre: cert */
/* Post: El resultat indica si el p.i. és una llista buida o no */
{
return longitud == 0;
}


int mida() const 
/* Pre: cert */
/* Post: El resultat és el nombre d'elements de la llista p.i. */
{
return longitud;
}


T actual() const
/* Pre: el p.i. és una llista no buida i el seu punt d'interès no
 està a la dreta de tot */
/* Post: el resultat és l'element actual del p.i. */
{ 
return act->info;
}


void modifica_actual(const T &x) 
/* Pre: el p.i. és una llista no buida i el seu punt d'interès no
 està a la dreta de tot */
/* Post: el p.i. és com el seu valor original, pero amb x
 reemplaçant l'element actual */
{
act->info = x; 
}


// ¿A qué corresponden en STL? 
void inici()
/* Pre: cert */
/* Post: el punt d'interès del p.i. està situat a sobre del primer
 element de la llista o a la dreta de tot si la llista és buida */
{
act = sent->seg; 
}


void fi()
/* Pre: cert */
/* Post: el punt d'interes del p.i. esta situat a la dreta del tot */
{
act = sent; 
}


void avanca() 
/* Pre: el punt d'interes del p.i. no estó a la dreta de tot */
/* Post: el punt d'interes del p.i. esta situat una posicio mes a la
 dreta que al valor original del p.i. */ 
{ 
act = act->seg; 
}


void retrocedeix() 
/* Pre: el punt d'interes del p.i. no està a sobre del primer
 element de la llista */
/* Post: el punt d'interes del p.i. esta situat una posicio mes a
 l'esquerra que al valor original del p.i. */ 
{
act = act->ant; 
}


bool dreta_de_tot() const
/* Pre: cert */
/* Post: el resultat indica si el punt d'interes del p.i. esta a la
 dreta de tot */
{
return act == sent; 
}


bool sobre_el_primer() const 
/* Pre: cert */
/* Post: el resultat indica si el punt d'interós del p.i. esta a sobre del
primer element del p.i. o esta a la dreta de tot si la llista es buida */
{
  return act == (sent->seg); 
}

};
#endif
