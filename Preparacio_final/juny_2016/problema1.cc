

void subintervals (int dif) {
	node_pila* api;
	node_pila* apf;
	if (primer != NULL) {
		api = primer;
		apf = primer;
		while (apf != NULL) {
			if (api != apf and api->seg != apf) {
				node_pila* aptmp;
				aptmp = api->seg;
				api -> seg = apf
				delete aptmp;
				--longitud;
			}
			if (apf -> seg == NULL or (apf->seg->info - apf->info)>dif)
			api = apf->seg;
		}
		apf = apf -> seg;
	}
}