static node_arbre* sub_arrel_immersive(node_arbre *n, const T &x, int &depth)
{
    node_arbre* node = NULL;
    if (n != NULL) {
        if (n->info == x) {
            node = copia_node_arbre(n);
        }
        else {
            int depth_left, depth_right;
            depth_left = depth_right = depth + 1;
            node_arbre *aux = NULL;
            node = sub_arrel_immersive(n->segE, x, depth_left);
            aux = sub_arrel_immersive(n->segD, x, depth_right);
            if (node == NULL) {
                node = aux;
                depth += depth_right;
            }
            else if (node != NULL && aux != NULL) {
                if (depth_left > depth_right) {
                    node = aux;
                    depth += depth_right;
                }
            }
            else depth += depth_left;
        }
    }
    return node;
}
 
void sub_arrel(Arbre& asub, const T& x)
/* Pre: p.i. = A, asub es buit */
/* Post: si A conte x, asub es el subarbre d'A resultat de la cerca;
   si A no conte x, asub es buit */
{
    int depth = 0;
    asub.primer_node = sub_arrel_immersive(this->primer_node, x, depth);
 
}