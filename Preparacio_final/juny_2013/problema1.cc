

void trenat (Cua &c) {
	//code here
	node_cua* node = primer_node;
	node_cua* cnode = c.primer_node;
	if (node == NULL)
		primer_node = c.primer_node
	if (longitud <= c.longitud)
		ultim_node = c.ultim_node;
	longitud += c.longitud;

	while (node != NULL and cnode != NULL) {
		node_cua* auxnode = prim -> seguent;
		node_cua* auxcnode = cnode -> seguent;
		node -> seguent = cnode;
		if (auxnode != NULL)
			cnode -> seguent = auxnode;
		node = auxnode;
		cnode = auxcnode;
	}
}