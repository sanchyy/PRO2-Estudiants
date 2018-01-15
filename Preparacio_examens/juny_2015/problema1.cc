#include <iostream>
using namespace std;

void extreure_max_subseq(const T elem, Cua& sub) {
	 /* Pre: el p.i. conte una cua C, sub es buida
	 Post: sub conte la subcua mes llarga entre dues aparicions d'elem
	 Al p.i. se l'ha eliminat la subcua mes llarga entre dues
	aparicions d'elem
	 */
	node_cua* p1 = primer_node;

	while (p1 != NULL and p1->info != elem)

	 	p1 = p1 -> seguent; //go to primer element igual a elem
	 
	if (p1 != NULL) {

		isub = p1; //isub apunta primer element
		p1 = p1 -> seguent;
		node_cua* isub_max = NULL;	//inici cua max
		node_cua* fsub_max = NULL;	//fi cua max
		node_cua* isub;				//inici ultima cua observada		
		node_cua* fsub;				//fi ultima cua observada
		int maxlen = 0;
		int len = 0;

		while (p1 != NULL) {
			while (p1 != NULL and p1->info != elem){
				fsub = p1;			//fi, es l'actual
				p1 = p1 -> seguent;
				++len;
			}

			if (p1 != NULL) {
				if (len >= maxlen) {
					isub_max = isub;
					fsub_max = fsub;
					maxlen = len;
			 	}

				isub = p1;
				p1 = p1->seguent;
				len = 0;
			}
		}
		if (maxlen != 0) {/* Hi ha alguna sequencia */
			sub.primer_node = isub_max->seguent; /* Inici la cua sub */
			sub.ultim_node = fsub_max; /* Final de la cua sub */
			isub_max -> seguent = fsub_max->seguent; /* treiem els elements del p.i.*/
			fsub_max -> seguent = NULL; /* NULL de fi de llista a la subcua */
			sub.longitud = maxlen; /* Longitud de la cua sub */
			longitud -= maxlen; /* Longitud de la nova cua */
		}
	}
} 