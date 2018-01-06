 /* Pre: parametre implicit = P */
 /* Post: s'han eliminat del parametre implicit totes les aparicions d'x (la
    resta d'elements queda en el mateix ordre que a P); si el punt d'interes de P
    referenciava a una aparicio d'x, passa a referenciar al primer element
    diferent d'x posterior a aquesta (si no hi ha cap element diferent d'x, passa
    a la dreta el tot); en cas contrari, el punt d'interes no canvia */
void esborrar_tots(const T& x) {
	node_llista *node = primer_node;
	if (longitud == 1) {
		if (node == x){
			primer_node == NULL;
			--longitud;
		}
	}
	else {
		while (node != NULL) {
			if ()
		}
	}
}
