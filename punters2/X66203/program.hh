
static T maxim_imm(node_arbreNari* n, T &maxim) {
    
    if (n != NULL) {
        for (int i = 0; i < int(n->seg.size()); ++i) 
            maxim_imm(n->seg[i], maxim);
 
        if (maxim < n->info) maxim = n->info;
    }
 
    return maxim;
}
 
/* Pre: el p.i. no és buit */
/* Post: el resultat indica el valor més gran que conté el p.i. */
T maxim() const {
	
    T max = this->primer_node->info;
    return maxim_imm(this->primer_node, max);
}