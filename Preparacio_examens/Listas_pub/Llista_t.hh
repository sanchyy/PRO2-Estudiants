#ifndef LLISTA_HH
#define LLISTA_HH

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
node2* primer_node;
node2* ultim_node;
node2* act; // punto de interés

// No implementamos iteradores
// - sólo un punto de interés por lista
// - una Llista no se puede pasar por referencia constante  
//   en operaciones de búsqueda o recorrido.


static node2* copia_cadena(node2* m, node2* oact,
				    node2*& u, node2*& a) { 
/* Pre: cert */
/* Post: si m és NULL, el resultat, u i a són NULL; en cas contrari,
 el resultat apunta al primer node d'una cadena de nodes que és 
 còpia de la cadena que té el node apuntat per m com a primer, u
 apunta a l'últim node, a és o bé NULL si oact no apunta a cap
 node de la cadena que comenca amb m o bé apunta al node còpia del
 node apuntat per oact */
/* Cost temporal: proporcional al nombre de nodes que penjen d'm; cada
 node copiat aporta el cost de copiar la seva info */
node2* n;
if (m==NULL) {n=NULL; u=NULL; a=NULL;}
else {
  n = new node2;
  n->info = m->info;
  n->ant = NULL;
  n->seg = copia_cadena(m->seg, oact, u, a);
  // Explicar excepción
  if (n->seg == NULL) u = n; 
  else (n->seg)->ant = n;
  if (m == oact) a = n;
}
return n;
}

/*
            ->     ->    -> NULL
         1      2      3
NULL <-     <-     <-
         |      |      |
        p_n     a     u_n
*/


static void esborra_cadena(node2* m) 
/* Pre: cert */
/* Post: No fa res si m és NULL; en cas contrari, allibera espai dels
 nodes de la cadena que té el node apuntat per m com a primer. */
/* Cost temporal: proporcional al nombre de nodes que penjen d'm */
{     
if (m != NULL) {
  esborra_cadena(m->seg);
  delete m;
}
}


public:


Llista() 
/* Pre: cert */
/* Post: el resultat es una llista buida */
{
longitud = 0;
primer_node = NULL;
ultim_node = NULL;
act = NULL; // apunta a un elemento ficticio 
            // detrás del último
}


Llista(const Llista &original) 
/* Pre: cert */
/* Post: El resultat és una còpia d'original */
{
longitud = original.longitud;
primer_node = copia_cadena(original.primer_node, original.act,
				ultim_node, act);  
}

/*
1. ¿Dónde se asignan los tres punteros del p.i.?
*/


~Llista() 
// Destructora: Esborra automaticament els objectes locals en
// sortir d'un ambit de visibilitat
{
esborra_cadena(primer_node);
}


Llista& operator=(const Llista& original) 
/* Pre: cert */
/* Post: El p.i. passa a ser una copia d'original i qualsevol contingut
 anterior del p.i. ha estat esborrat (excepte si el p.i. i original ja
 eren el mateix objecte) */
{
if (this != &original) {
  longitud = original.longitud;
  esborra_cadena(primer_node);
  primer_node = copia_cadena(original.primer_node, original.act,
				  ultim_node, act);
}
return *this;
}


// ¿Cómo se llama en la clase list de STL?
void l_buida() 
/* Pre: cert */
/* Post: El p.i. passa a ser una llista sense elements i qualsevol
 contingut anterior del p.i. ha estat esborrat */
{
esborra_cadena(primer_node);
longitud = 0;
primer_node = NULL;
ultim_node = NULL;
act = NULL;
}


// ¿A qué corresponde en la clase list de STL?
void afegir(const T& x) 
/* Pre: cert */
/* Post: el p.i. és com el seu valor original, però amb x afegit a
 l'esquerra del punt d'interès */
{
node2* aux = new node2; 
aux->info = x;
aux->seg = act;
// Falta asignar aux->ant
// ¿A qué componentes del p.i afecta?
if (longitud==0) {
  aux->ant = NULL;
  primer_node = aux;
  ultim_node = aux;
}
else if (act==NULL) {// ¿Dónde  insertamos?
  aux->ant = ultim_node;
  ultim_node->seg = aux;
  ultim_node = aux;
}
else if (act==primer_node) {
  aux->ant = NULL;
  primer_node->ant = aux; 
  primer_node = aux;
}
else {
  aux->ant = act->ant;
  (act->ant)->seg = aux;
  act->ant = aux;
}
++longitud;
}


// ¿A qué corresponde en la clase list de STL?
void eliminar()
/* Pre: el p.i. és una llista no buida i el seu punt d'interès no està a
 la dreta de tot */
/* Post: El p.i. és com el p.i. original sense l'element on estava el
 punt d'interès i amb el nou punt d'interès avançat una posició a la
 dreta */
{
node2* aux = act; 
// ¿Podríamos hacer  delete aux;  aquí?
if (longitud==1) {
  primer_node = NULL;
  ultim_node = NULL;
}
else if (act==primer_node) {
  primer_node = primer_node->seg;
  primer_node->ant = NULL;
}
else if (act==ultim_node) {
  ultim_node = ultim_node->ant;
  ultim_node->seg = NULL;
}
else {
// Dibujar e identificar los tres nodos
  (act->ant)->seg = act->seg;
  (act->seg)->ant = act->ant;
}
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
  if (l.longitud>0) { // Si la llista l és buida no cal fer res.
    if (longitud==0) {
      primer_node = l.primer_node;
      ultim_node = l.ultim_node;
      longitud = l.longitud;
    }
    else {
      ultim_node->seg = l.primer_node;
      (l.primer_node)->ant = ultim_node;
      ultim_node = l.ultim_node;
      longitud += l.longitud;
    }
    l.primer_node = NULL;
    l.ultim_node = NULL;
    l.act = NULL;
    l.longitud = 0;  
  }    
  act = primer_node;
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


// ¿A qué corresponde en STL? 
T actual() const
/* Pre: el p.i. és una llista no buida i el seu punt d'interès no
 està a la dreta de tot */
/* Post: el resultat és l'element actual del p.i. */
{ 
return act->info;
}


// ¿A qué corresponde en STL? 
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
act = primer_node; 
}


void fi()
/* Pre: cert */
/* Post: el punt d'interes del p.i. esta situat a la dreta del tot */
{
act = NULL; 
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
if (act == NULL) act = ultim_node;  
else act = act->ant; 
}


bool dreta_de_tot() const
/* Pre: cert */
/* Post: el resultat indica si el punt d'interes del p.i. esta a la
 dreta de tot */
{
return act == NULL; 
}


bool sobre_el_primer() const 
/* Pre: cert */
/* Post: el resultat indica si el punt d'interós del p.i. esta a sobre del
primer element del p.i. o esta a la dreta de tot si la llista es buida */
{
return act == primer_node; 
}


// Extensio ------------------------------------------------

//------- Invertir el orden de los elementos de una lista ----- 
// Usamos la idea de intercambiar los punteros anterior y siguiente en
// cada nodo.

void invertir ()
/* Pre: cert */ 
/* Post: el p.i. té els mateixos elements que a l'inici però amb
 l'ordre invertit i el seu punt d'interès no s'ha mogut */
{ // c = C es la cadena de nodos enlazados a la que apunta n. 
node2* n = primer_node;
/* Inv: c es una cadena de nodos enlazados con los mismos elementos
que C, excepto que se han intercambiado los punteros ant y seg de los
nodos anteriores en C al nodo al que apunta n. */    
while (n != ultim_node) {
  node2* aux = n->seg;
  n->seg = n->ant;
  n->ant = aux;

  n = aux; // avanza n, aux es el seg de n en C
/* ¿Que nodo es n->seg en este momento? */
}
/* ¿Por qué es preciso comprobar las siguientes 
   condiciones?  */
if (n != NULL and n != primer_node) {
  n->seg = n->ant; // tratamos el último nodo
  n->ant = NULL;
  ultim_node = primer_node; // intercambiamos primer_node
  primer_node = n;          // y ultim_node
}
}

// include "invertir_s.hh"
};
#endif
