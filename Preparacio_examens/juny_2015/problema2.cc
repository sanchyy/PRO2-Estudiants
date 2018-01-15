

bool es_complet_imm(node *n, int &h) {
	bool aux;
	if (n == NULL){
		h = 0;
		return false;
	}
	else {
		aux = es_complet_imm(n -> seg[0],h);
		int i = 0;
		while (i < n -> seg.size() and aux) {
			aux = es_compet_imm(n->seg[i],h_aux);
			aux = (h == h_aux and aux);
			++i;
		}
		h = h + 1;
	}
	return aux;
}

bool es_complet() const {
	return es_complet_imm(this->primer, int & h);
}