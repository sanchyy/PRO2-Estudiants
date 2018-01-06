#ifndef LLISTA
#define LLISTA

#include "utils.PRO2"

template <class T> class Llista {
private:
  struct node_llista {
    T info;
    node_llista* seg;
    node_llista* ant;
  }; 
  int longitud;
  node_llista* primer_node;
  node_llista* ultim_node;
  node_llista* act;
  // especificaci� operacions privades

static node_llista* copia_node_llista(node_llista* m, node_llista* oact,
				 node_llista* &u, node_llista* &a)
    /* Pre: cert */
    /* Post: si m �s NULL, el resultat, u i a s�n NULL; en cas
       contrari, el resultat apunta al primer node d'una cadena de
       nodes que s�n c�pia de la cadena que t� el node apuntat per m
       com a primer, u apunta a l'�ltim node, a �s o b� NULL si oact
       no apunta a cap node de la cadena que comen�a amb m o b� apunta
       al node c�pia del node apuntat per oact */
  { 
  	node_llista* n;
  	if (m==NULL) {n=NULL; u=NULL; a=NULL;}
  	else {
  		a = NULL;
	    node_llista* aux = m;
	    node_llista* old = NULL;
	    while (aux != NULL){
	    	node_llista* n2 = new node_llista;
	    	n2->info = aux->info;
	    	n2->ant = old;
	    	n2->seg = NULL;
	    	if (n2->ant != NULL) n2->ant->seg = n2;
	    	else n = n2; 
	    	if (aux == oact) a = n2;
	    	old = n2;
	    	aux = aux->seg;
	    }
	    u = old;
	}
	return n;
  }


static void esborra_node_llista(node_llista* m) 
    /* Pre: cert */
    /* Post: no fa res si m �s NULL, en cas contrari, allibera espai dels 
       nodes de la cadena que t� el node apuntat per m com a primer */
  {  
  	
  	while (m != NULL)    {
  		node_llista * aux = m->seg;
  		delete m;
  		m = aux;
  	}
  }


public:
  //  operacions p�bliques

  // Constructora

  Llista() 
    /* Pre: cert */
    /* Post: el resultat �s una llista buida */
  {
    longitud= 0;
    primer_node= NULL;
    ultim_node= NULL;
    act= NULL;
  }

  Llista(const Llista &original) 
    /* Pre: cert */
    /* Post: El resultat �s una c�pia d'original */
  {
    longitud= original.longitud;
    primer_node = copia_node_llista(original.primer_node, original.act,
				       ultim_node, act);  
  }

  // Destructora

  ~Llista() 
    // Destructora: Esborra autom�ticament els objectes locals en
    // sortir d'un �mbit de visibilitat
  {
    esborra_node_llista(primer_node);
  }

  // Redefinici� de la asignaci�

  Llista& operator=(const Llista& original) 
    /* Pre: cert */
    /* Post: El p.i. passa a ser una c�pia d'original i qualsevol
       contingut anterior del p.i. ha estat esborrat 
       (excepte si el p.i. i original ja eren el mateix objecte) */
  {
    if (this != &original) {
      longitud= original.longitud;
      esborra_node_llista(primer_node);
      primer_node = copia_node_llista(original.primer_node, original.act,
					 ultim_node, act);
    }
    return *this;
  }

  // Modificadores

  void l_buida() 
    /* Pre: cert */
    /* Post: El p.i. passa a ser una llista sense elements i qualsevol
       contingut anterior del p.i. ha estat esborrat */
  {
    esborra_node_llista(primer_node);
    longitud= 0;
    primer_node= NULL;
    ultim_node= NULL;
    act= NULL;
  }
        
  void afegir (const T& x) 
    /* Pre: cert */
    /* Post: el p.i. �s com el seu valor original, per� amb x
       afegit a l'esquerra del punt d'inter�s */
  {
    node_llista* aux;
    aux= new node_llista; // reserva espai pel nou element
    aux->info= x;
    aux->seg= act;
    if (longitud==0) {
      aux->ant= NULL;
      primer_node= aux;
      ultim_node= aux;
    }
    else if (act==NULL) {
      aux->ant= ultim_node;
      ultim_node->seg= aux;
      ultim_node= aux;
    }
    else if (act==primer_node) {
      aux->ant= NULL;
      act->ant= aux;
      primer_node= aux;
    }
    else {
      aux->ant= act->ant;
      (act->ant)->seg= aux;
      act->ant= aux;
    }
    ++longitud;
  }

  void eliminar()
    /* Pre: el p.i. �s una llista no buida i el seu punt d'inter�s no est� a la dreta de tot */ 
    /* Post: El p.i. �s com el p.i. original sense l'element on estava el punt d'inter�s 
       i amb el nou punt d'inter�s avan�at una posici� a la dreta */
  {
    node_llista* aux;
    aux= act; // conserva l'acc�s al node actual
    if (longitud==1) {
      primer_node= NULL;
      ultim_node= NULL;
    }
    else if (act==primer_node) {
      primer_node= act->seg;
      primer_node->ant= NULL;
    }
    else if (act==ultim_node) {
      ultim_node= act->ant;
      ultim_node->seg= NULL;
    }
    else {
      (act->ant)->seg= act->seg;
      (act->seg)->ant= act->ant;
    }
    act= act->seg; // avan�a el punt d'inter�s
    delete aux; // allibera l'espai de l'element esborrat
    --longitud;
  }

  void concat(Llista& l) 
    /* Pre: l=L */
    /* Post: el p.i. t� els seus elements originals seguits pels de
       L, l �s buida i el punt d'interes del p.i. queda situat a l�inici */
  {
    if (l.longitud>0) {  // si la llista l �s buida no cal fer res
      if (longitud==0) {
	primer_node= l.primer_node;
	ultim_node= l.ultim_node;
	longitud= l.longitud;
      }
      else {
	ultim_node->seg= l.primer_node;
	(l.primer_node)->ant= ultim_node;
	ultim_node= l.ultim_node;
	longitud+= l.longitud;
      }
      l.primer_node= NULL;
      l.ultim_node= NULL;
      l.act= NULL;
      l.longitud= 0;  
    }    
    act= primer_node;

  }

  // Consultores 

  bool es_buida() const 
    /* Pre: cert */
    /* Post: El resultat indica si el p.i. �s una llista buida o no */
  {
    return primer_node==NULL;
  }

  int mida() const 
    /* Pre: cert */
    /* Post: El resultat �s el nombre d'elements de la llista p.i. */
  {
    return longitud;
  }

  // Noves operacions per a consultar i modificar l'element actual 
 
  T actual() const
    /* Pre: el p.i. �s una llista no buida i el seu punt d'inter�s no est� a la dreta de tot */
    /* Post: el resultat �s l'element actual del p.i. */ 
  { 
    return act->info;// equival a consultar *it si it es un iterador a l'actual
  }

  void modifica_actual(const T &x) 
    /* Pre: el p.i. �s una llista no buida i el seu punt d'inter�s no est� a la dreta de tot */
    /* Post: el p.i. �s com el seu valor original, per� amb x reempla�ant l'element actual */ 
  {
    act->info= x; // equival a fer *it=x; si it is un iterador
  }

  // Noves operacions per a moure el punt d'inter�s

  void inici()
    /* Pre: cert */
    /* Post: el punt d'inter�s del p.i. est� situat a sobre del primer element de la llista
       o a la dreta de tot si la llista �s buida */
  {
    act= primer_node; // equival a fer it=l.begin(); si it es un iterador a l'actual
  }

  void fi()
    /* Pre: cert */
    /* Post: el punt d'inter�s del p.i. est� situat a la dreta del tot */
  {
    act= NULL;  // equival a fer it=l.end(); si it es un iterador a l'actual
  }

  void avanca() 
    /* Pre: el punt d'inter�s del p.i. no est� a la dreta de tot */
    /* Post: el punt d'inter�s del p.i. est� situat una posici� m�s a la dreta que al 
       valor original del p.i. */ 
  { 
    act= act->seg; // equival a fer ++it; si it es un iterador a l'actual
  }

  void retrocedeix() 
    /* Pre: el punt d'inter�s del p.i. no est� a sobre del primer element de la llista*/
    /* Post: el punt d'inter�s del p.i. est� situat una posici� m�s a l'esquerra que 
       al valor original del p.i. */ 
  {
    if (act==NULL) act=ultim_node;  
    else act= act->ant; // equival a fer --it; si it es un iterador a l'actual
  }

  bool dreta_de_tot() const
    /* Pre: cert */
    /* Post: el resultat indica si el punt d'inter�s del p.i. est� a la dreta de tot */
  {
    return act==NULL; // equival a comparar it==l.end() si it es un iterador a l'actual
  }

  bool sobre_el_primer() const 
    /* Pre: cert */
    /* Post: el resultat indica si el punt d'inter�s del p.i. est� a sobre del 
       primer element del p.i. o est� a la dreta de tot si la llista �s buida */
  {
    return act==primer_node; // equival a comparar it==l.begin() si it es un iterador a l'actual
  }

  // Extensi�n ------------------------------------------------
  void invertir ()
    /* Pre: cert */ 
    /* Post: el p.i. t� els mateixos elements que a l'inici per� amb l'ordre invertit
       i el seu punt d'inter�s no s'ha mogut */
  {
    node_llista* n = primer_node;
    while (n != ultim_node) {
      /* Inv: els nodes anteriors al que apunta n en la cadena que comen�a a primer_node
	 han intercanviat els seus punters a l'anterior i al seg�ent node */
      node_llista* aux = n->seg;
      n->seg = n->ant;
      n->ant = aux;
      n = aux;
    }
    if (n!=NULL and n!=primer_node) {
      n->seg = n->ant;
      n->ant = NULL;
      ultim_node = primer_node;
      primer_node = n;
    }
  }


  #include "program.hh"

};

#endif
