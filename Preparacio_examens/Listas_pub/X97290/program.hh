#ifndef _EJERCICIO_13_3_
#define _EJERCICIO_13_3_


private:

static node_llista* copia_node_llista_it(node_llista* m, 
					 node_llista* oact, 
					 node_llista* &u,
                                         node_llista* &a) {
  node_llista* n; 
  if (m == NULL) n = a = u = NULL;
  else {  // cadena no vacía
      n = new node_llista; 
      n->info = m->info;  // copio el primer nodo
      n->ant = NULL;  
      if (oact == m) a = n;
      node_llista* c_act = n; // puntero para moverme por la cadena copia
      while (m->seg != NULL) {
	  m = m->seg; 
          c_act->seg = new node_llista; 
          (c_act->seg)->ant = c_act;
          c_act = c_act->seg; 
          c_act->info = m->info;
          if (m == oact) a = c_act;  
      }
      c_act->seg = NULL; // enlace de la copia del último nodo
      u = c_act; // c_act es el último de la cadena copia
      if (oact == NULL) a = NULL;
  }
  return n; 
}


public:

Llista& operator=(const Llista& original) {
  if (this != &original) {
     esborra_node_llista(primer_node);
     primer_node = copia_node_llista_it(original.primer_node, original.act, ultim_node, act);
     longitud = original.longitud;
  }
  return *this;
}

#endif
