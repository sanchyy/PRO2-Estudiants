#include <iostream>
#include <vector>
using namespace std;

void arbre_max_min_imm(node* n_arbre_pi, node* n_arbre_max, node* n_arbre_min T &min, T &max) {
	n_arbre_max = new node_arbreGen;
	n_arbre_min = new node_arbreGen;

	if (n_arbre_pi -> seg.size() == 0) {
		min = max = n->seg->info;
		n_arbre_max -> info = max;
		n_arbre_min -> info = min;
	}
	else {
		T min_aux;
		T max_aux;

		min = max = n->info;

		n_arbre_max -> seg = vector <node_arbreGen> (n_arbre_pi -> seg.size());
		n_arbre_min->seg = vector <node_arbreGen*> (n_arbre_pi -> seg.size());

		for (int i = 0; i < n_arbre_pi->seg.size();++i) {

			arbre_max_min_imm(n_arbre_pi->seg[i],n_arbre_max,n_arbre_min,min_aux,max_aux);

			if (min > min_aux)
				min = min_aux;

			if (max < max_aux)
				max = max_aux;
		}

		n_arbre_max -> info = max;
		n_arbre_min -> info = min;

	}
}

void arbre_max_min(ArbreGen<T>& amax, ArbreGen <T> & amin) const {

	T min = 0;
	T max = 0;

	arbre_max_min_imm(this->primer, amax -> primer, amin -> primer, min,max);
}