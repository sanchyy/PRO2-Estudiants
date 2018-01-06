static bool buscar_imm(node_arbreGen* n, const T& x) {
    if (n != NULL) {
        bool found = n->info == x;
        int i = 0;
        while (i < int(n->seg.size()) and not found) {
            found = buscar_imm(n->seg[i], x);
            ++i;
        }
 
        return found;
    }
    return false;
}
 
 
/* Pre: cert */
/* Post: el resultat indica si x es troba al p.i. o no */
bool buscar(const T& x) const {
    return buscar_imm(this->primer_node, x);
}