
static T max_suma_cami_imm(node_arbreGen *n, bool& valid) {
    T suma = 0;
    if (n != NULL) {
        valid = true;
        suma = n->info;
        T max = 0;
        for (int i = 0; i < n->seg.size(); ++i) {
            bool valid_aux = false;
            T aux = max_suma_cami_imm(n->seg[i], valid_aux);
            if (valid_aux && aux > max)
                max = aux;
        }
        if (n->seg.size() > 0) suma += max;
    }
    return suma;
}
 
T max_suma_cami() const
/* Pre: el parametre implicit no es buit */
/* Post: el resultat es la suma del cami de suma maxima del parametre implicit */
{
    bool valid;
    return max_suma_cami_imm(this->primer_node, valid);
}
