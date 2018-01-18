
void moure_punt_preu_just_imm(node_llista *n, const T &x) {
	if (n == NULL)
		return ;
	else {
		if (n->info < x)
			n = n->seg;
			moure_punt_preu_just_imm(n,x);
		}
}

void moure_punt_preu_just(const T &x) {
	moure_punt_preu_just_imm(prim,x);
}

void splice_imm(node *n,Llista &l) {
	//act es el punt de referència
	node *aux = act;
	act = l.prim;
	l.ult -> seg = aux;
	aux -> seg = NULL;
}

void splice (Llista &l) {
	splice_imm(act,l);
}