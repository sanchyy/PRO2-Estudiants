

//exercici1
//----------------------------------------------------

node * i_cons_arbre_cerca(const vector <T> &v, int i, int j) {
	if (j < i)
		return NULL;
	else {
		int m = (i+j)/2;
		node* n = new node;
		n -> info = v[m];
		n -> segE = i_cons_arbre_cerca(v,i,m-1);
		n -> segD = i_cons_arbre_cerca(v,m+1,j);
		return n;
	}

}

void cons_arbre_cerca(vecotr <T> &v) {
	v.sort();
	primer = i_cons_arbre_cerca(v,0,v.size()-1);	
}

//exercici2
//----------------------------------------------------


static bool i_cerca(node* n, const T &x) {
	if (n == NULL)
		return false;
	else if (n -> info < x)
		return i_cerca(n->segE,x);
	else if (n->info > x)
		return i_cerca(n->segD,x);
	else
		return true;
}

bool cerca (const T& x) {
	return i_cerca(this->primer,x);
}