
/* Pre: p.i. = C1, c = C2 */ 
/* Post: el p.i. passa a ser el resultat de trenar C1 i C2; c passa a ser buida */
void trenat(Cua &c) {
	//demanar_torn = push
	//avancar = pop
	//primer = front
	//es_buida = empty
	node_cua* prim = this->primer_node;
	node_cua* cnode = c.primer_node;
	if (prim == NULL) this->primer_node = cnode; //si el primer node del paràmetre implicit és nul, tota la cua serà c.
	if (this->longitud <= c.longitud) ultim_node = c.ultim_node;
	this->longitud += c.longitud;
   
	while (prim != NULL and cnode != NULL) {
			node_cua* auxprim = prim->seguent;
			node_cua* auxc = cnode->seguent;
			prim->seguent = cnode;
			if (auxprim != NULL) {
				cnode->seguent = auxprim;
			}
			prim = auxprim;
			cnode = auxc;
	}
}
