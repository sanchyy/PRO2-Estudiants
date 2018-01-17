
static int rec_iguals (node_arbreNari* n) {

	int r = 0;
	int s = n->seg.size();
	for (int i = 0; i < s; ++i) {
		suma += rec_iguals(n->seg[i]);
		if (n->seg[i]->info == n->info)
			++r;
	}
	return r;	
}

int iguals () const {
		if (n == NULL)
		return 0;
	return rec_iguals(this->primer_node);
}