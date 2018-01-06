
int freq_imm(node_arbreGen* n, const T& x) {
	
	int count = 0;
	if (n != NULL) {

		if (n -> info == x)
			++count;

		for (int i = 0; i < int(n->seg.size()); ++i) {
			count += freq_imm(n -> seg[i], x);
		}

	}
	return count;
}

/* Pre: cert */
/* Post: el resultat indica el nombre d'aparicions de x en el p.i. */
int freq(const T& x) {
	return freq_imm(this -> primer_node, x);
}
