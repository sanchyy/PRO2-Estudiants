
void trams(vector <Llista<T> > & v) {
	node *p = primer;
	node *u = primer->seg;
	int i = 0;
	while (u != NULL) {
		if (u -> ant ->info > u -> info) {
			v.push_back();
			v[i].primer = p;
			v[i].ultim = u -> ant;
			++i;
		}
		else 
			u = u -> seg;
	}
}