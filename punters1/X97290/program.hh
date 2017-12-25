/* Pre: cert */
/* Post: si m és NULL, el resultat, u i a són NULL; en cas
       contrari, el resultat apunta al primer node d'una cadena de
       nodes que són còpia de la cadena que té el node apuntat per m
       com a primer, u apunta a l'últim node, a és o bé NULL si oact
       no apunta a cap node de la cadena que comença amb m o bé apunta
       al node còpia del node apuntat per oact */
node_llista* copia_node_llista_it (node_llista* m, node_llista* oact, node_llista* &u, node_llista* &a) {
	if (m == NULL) {
		u = NULL;
		a = NULL;
		return NULL;
	}
	else {
		a = NULL;
		node_llista* primer_node_copia = NULL;
		bool primer = true;
		node_llista* aux = NULL;
		while (m != NULL) {
			node_llista* new_node = new node_llista;
			new_node -> info = m -> info;
			if (aux != NULL)
				aux -> seg = new_node;
			new_node -> ant = aux;
			if (primer) {
				primer = not primer;
				primer_node_copia = new_node;
			}
			if (oact == m)
				a = new_node;
			aux = new_node;
			m = m -> seg;
		}
		u = aux;
		return primer_node_copia;
	}
}

void borrar_llista(node_llista* n) {
  if (n != NULL) {
    borrar_llista(n->seg);
    delete n;
    n = NULL;
  }
}

/* Pre: cert */
/* Post: El p.i. passa a ser una còpia d'original i qualsevol
   contingut anterior del p.i. ha estat esborrat (excepte si el
   p.i. i original ja eren el mateix objecte) */
Llista& operator=(const Llista& original) {
	if (this != &original) {
	      longitud = original.longitud;
	      borrar_llista(this->primer_node);
	      primer_node = copia_node_llista_it(original.primer_node, original.act, ultim_node, act);
	   }
	   return *this;
}



