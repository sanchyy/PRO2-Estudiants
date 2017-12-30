/* Pre: cert */
/* Post: asum és l'arbre suma del p.i. */

void arbsuma_imm(node_arbreNari* node, node_arbreNari* &n_asum, int &suma) {
	
	if (node == NULL) 
		suma = 0;

	if (node != NULL) {
		suma = node -> info;
		n_asum = new node_arbreNari;
		int size = int(node->seg.size());
		n_asum->seg = vector<node_arbreNari*>(size);
		for (int i = 0; i < size; ++i) {
			node_arbreNari* n_asum_iessim = NULL;
			int suma_aux;
			arbsuma_imm(node -> seg[i],n_asum_iessim, suma_aux);
			suma += suma_aux;
			n_asum -> seg[i] = n_asum_iessim;
		}
		n_asum->info = suma;
	}
}

void arbsuma(ArbreNari& asum) const {
	int suma;
	node_arbreNari* n_asum = NULL;
	arbsuma_imm(this -> primer_node, n_asum, suma);
	asum.primer_node = n_asum;
}
