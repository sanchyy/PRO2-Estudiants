// Pre: el p.i. és una pila P
// Post: el p.i. conté els mateixos elements de P, però ordenats
// del més petit (al cim) al més gran (al fons)
void ordena() {
	node* nova = NULL;
	while (CONDICIO_1) {

		node* p = primer;
		node* max = primer;
		node* ant_max = NULL;

		while (p -> seg != NULL) {
			if (p -> seg -> info > max -> info){
				max = p -> seg;
				ant_max = p
			}
			p = p -> seg;
					
		}
		ant_max -> seg = max -> seg;
		max -> seg = nova;
		nova = max;
	}
	primer = nova;
}
