

/*  Pre: cert 
	Post: si m és NULL, el resultat és NULL; en cas contrari, el
	resultat apunta al primer node d'una cadena de nodes que són
	còpia de de la cadena que té el node apuntat per m com a primer */
node_pila* copia_node_pila_it(node_pila* m) {
	node_pila* aux; //node que anirà resseguint la pila
	node_pila* copy; //marca el primer node, que al ser igual que aux, serà la mateixa pila
	if (m == NULL) copy = NULL;
	else {
		aux = new node_pila;
		copy = aux;
		aux -> info = m -> info;
		m = m -> seguent;
		while (m != NULL) {
			aux -> seguent = new node_pila;
			aux = aux -> seguent;
			aux -> info = m -> info;
			m = m -> seguent;
		}
		aux->seguent = NULL;
	}
	return copy;
}

/*  Pre: cert 
	Post: El p.i. passa a ser una còpia d'original i qualsevol
	contingut anterior del p.i. ha estat esborrat (excepte si el
	p.i. i original ja eren el mateix objecte) */
Pila& operator=(const Pila& original) {
	if (this != &original) {
		altura = original.altura;
		esborra_node_pila(primer_node);
		primer_node = copia_node_pila_it(original.primer_node);
	}
	return *this;
}
