void Llista<T>::transferir (Llista <T> & dest) {
	//pre: p.i. té un elem x i una llista L; dest = D;
	//post: p.i. conté L; dest conté D + x;

	node_llista *aux = primer_node;
	if (act == primer_node)
		act = primer_node -> seg;
	primer_node = primer_node -> seg;
	primer_node -> ant = NULL;
	--longitud;

	if (dest.primer == NULL)
		dest.primer = aux;
	else {
	des.ultim_node -> seg = aux;
	dest.ultim_node = dest.ultim_node -> seg;
	}
	++dest.longitud;
}

void Llista <T>:: concat_per_nivells ( vector<Llista<T> >& v) {
	bool alguna_no_buida = true;
	while (alguna_no_buida) { 
		alguna_no_buida = false;
		for (int i = 0; i < v.size(); ++i) {
			v[i].transferir(*this);
			if (v[i].longitud > 0)
				alguna_no_buida = true;
		}
		//code here
	}
}