

//C <-  segona cua; p.i. <- primera cua
void distribucio(Cua &c) {
	node *act = c.primer;
	c.primer = act->seg;
	act = act -> seg;
	c.primer -> seg = c.ultim = NULL;
	ult = ult -> seg = new node;
	longitud = c.longitud = 0;
	int sum_temps1 = 0;
	int sum_temps2 = 0;
	while (act != NULL) {
		if (sum1 > sum2) {
			c.ultim = act;
			sum_temps2 += a->temps;
			++c.longitud;
			c.ultim = c.ultim -> seg = NULL;
		}
		else{
			ultim = act;
			ultim = ultim->seg = NULL;
			sum_temps1 += act -> temps;
			++longitud;
		}

		act = act->seg;
	}

}