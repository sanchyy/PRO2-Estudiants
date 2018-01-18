
void antecessor_comu_mes_proper_imm(node_arbreNari *n,const T& y, const T& z,T&x, bool& b, bool &a, bool&c) {
	bool y_search_aux = false;
	bool z_search_aux = false;
	if (n == NULL) {
		x = NULL;
		y_search_aux = b = z_search_aux = false;
	}

	if (n -> info  == y)
		y_search = true

	if (n -> info == z)
		z_search = true;

	for (int i = 0; i < N; ++i) {
		antecessor_comu_mes_proper_imm(n->seg[i],y,z,x,b,y_search_aux,z_search_aux);
		//el moment que li arriben els dos true, vol dir que és pare dels dos nodes.
		if (y_search_aux and z_search_aux){
			x = n->info;
			b = true;
			y_search_aux = false; 
			z_search_aux = false;
		}
	}
}


void antecessor_comu_mes_proper(const T& y, const T& z,T&x, bool& b) {
	bool a,c;
	antecessor_comu_mes_proper_imm(this->primer_node,y,z,x,b,a,c);
}