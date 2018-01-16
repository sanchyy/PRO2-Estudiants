//cadena imparell va al p.i.
//cadena parell va a l

void split (Llista <int> &l) {
	node_llista *ant;
	bool creixent = true;
	int cont = 0;
	//insert here
	ant = primer;
	act = primer -> seg;
	while (act != NULL and creixent) {
		if (act -> info < ant -> info)
			creixent = false;
		else {
			ant = act;
			act = act -> seg;
		}
		++cont;
	}

	if (act != NULL) {
		l.primer = l.ultim = ant = act;
		ult = ant;
		l.prim -> ant = NULL; //X
		act = act -> seg;
		longitud = cont;
		l.longitud = 1;
		bool senar = false;
	}

	while (act != NULL) {
		if (senar) {
			if (act -> info < ant -> info) { //act i ant pertanyen a la mateixa escala
				//senar -> parell
				ult = act;	//ultim de llista imparell serà el primer de la nova llista
				++longitud;

			}
			else { //don't
				l.ult -> seg = act;
				act -> ant = l.ult;
				l.ult = act;
				++l.longitud;
				senar = false;

			}
		}
		else {
			if (act -> info < ant -> info) { //act i ant pertanyen a la mateixa escala
				//parell -> senar
				l.ult = act;
				++l.longitud;
			}
			else { //don't

				ult -> seg = act;
				act -> ant = ult;
				ult = act;
				++longitud;
				senar = true;
			}
		}
		//code here
		ult -> seg = l.ult->seg = NULL;
		l.act = l.prim;
	}

	act = pim;
}