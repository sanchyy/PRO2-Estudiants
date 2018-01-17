
//1r apartat

//--------------------------------------------------------------

pair <bool,int>distancia_imm(Node *n, string omega) {
	pair <bool,int> aux;
	if (n == NULL) {
		aux.first = false;

	else if (n->info.ciutat == omega){
		aux.first = true;
		aux.second = n->info.kms_recorridos;
	}
	aux.first = false;
	for (int i = 0; i < n->seg.size(); ++i) {
		pair<bool,int>aux_aux = distancia_imm(n->seg[i],omega);
		if (aux_aux.first) {
			if (not aux.first or aux_aux.second < aux.second)
				aux = aux_aux;
		}
	}
	return aux;
}

pair<bool,int> distancia(string omega) const {
	return distancia_imm(this->primer_node,string omega);
}

//2n apartat

//--------------------------------------------------------------------
pair <bool,int>distancia_imm(Node *n, string omega, stack<Etapa> &ruta) {
	pair <bool,int> aux;
	if (n == NULL) {
		aux.first = false;

	else if (n->info.ciutat == omega){
		aux.first = true;
		aux.second = n->info.kms_recorridos;
		ruta.push(n->info);
	}
	aux.first = false;
	for (int i = 0; i < n->seg.size(); ++i) {
		stack <Etapa> stack_aux;
		pair<bool,int>aux_aux = distancia_imm(n->seg[i],omega,stack_aux);
		if (aux_aux.first) {
			if (not aux.first or aux_aux.second < aux.second) {
				aux = aux_aux;
				ruta.swap(stack_aux);
			}

		}
		if (aux.first) ruta.push(n->info);
	}
	return aux;
}

pair<bool,int> distancia(string omega,stack<Etapa> &ruta) const {
	return distancia_imm(this->primer_node,string omega,ruta);
}
