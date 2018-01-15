

void i_suma_max_subarbre(node *n, int &count, int &max) const {
	if (n != NULL) {
		if (n->seg.size() == 0) {
			count = n -> info;
			max = n -> info;
		}
		for (int i = 0; i < n->seg.size(); ++i) {
			int count_aux;
			int max_aux;
			i_suma_max_subarbre(n->seg[i],count_aux,max_aux);
			count += count_aux;		
			if (max_aux > max)
				max = max_aux;

		}
		if (max < count)
			max = count;
	}
}


/* pre: primer_node conté un punter a l'arrel del subarbre a analitzar
 * count conté la sumà del subarbre
 * post: retornarà el valor de la suma maxima que es pot aconseguir, primer node i count seguiran igual*/
int suma_max_subarbre() const {
	int count = 0;
	int max = 0;
	i_suma_max_subarbre(this->primer_node,count,max);
	return max;
}