
void arb_sumes_immersive(node_arbre *n, node_arbre* &m, int &suma) {

	if (n == NULL) 
		suma = 0;
	else {
		suma = n -> info;
		int suma_left, suma_right;
		node_arbre* m_left = NULL;
		node_arbre* m_right = NULL;
		arb_sumes_immersive(n->segE,m_left,suma_left);
		arb_sumes_immersive(n->segD,m_right,suma_right);
		suma += suma_left + suma_right;
		m = new node_arbre;
		m -> info = suma;
		m -> segE = m_left;
		m -> segD = m_right;
	}
  
}

/* Pre: cert */
/* Post: l'arbre asum és l'arbre suma del p.i. */
void arb_sumes(Arbre<int> &asum)  {
    int suma;
    node_arbre* m = NULL;
    arb_sumes_immersive(this->primer_node, m, suma); 
    asum.primer_node = m; 
}


