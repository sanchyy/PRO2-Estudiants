//aquesta ja està implementada
void string_a_enter (const string& s, bool& es enter, int& result );

void avalua_imm(node *n, bool& def, int& result) {
	bool es_nombre;
	string_a_enter(n->info,es_nombre,result);
	if (es_nobmre) 
		def = true;
	else {
		string op = n->info;
		if (not (op == "+" or op == "-" or op == "*" or op == "/" or op == "==" or op == "<" or op == "abs" or op == "if"))
			def = false;
		else {
			int size = n->seg.size();
			if (op == "abs" and size != 1)
				def = false;
			//ja que abs va acompanyat d'un nombre o d'un nombre produit en una op
			else if (op == "if" and ari != 3)
				def = false;
			else if (op != "abs" and op != "if" and ari != 2)
				def = false;

			else {
				if (op == "if") {
					bool def_aux;
					int res_aux;
					avalua_imm(n->seg[0],def_aux,res_aux);
					if (not def_aux)
						def = false;
					else {
						if (res_aux == 1)
							avalua_imm(n->seg[1],def,result);
						else if (res_aux == 0)
							avalua_imm(n->seg[2],def,result);
						else def = false;
					}
				}

				else {
					vector <int> r(size);
					bool d = true;
					for (int i = 0; i < size and d; ++i)
						avalua_imm(n->seg[i],d,r[i]);
					if (d) {
						def = true;
						if (op == "+") result = r[0] + r[1]; 
		                else if (op == "-") result = r[0] - r[1];
		                else if (op == "*") result = r[0] * r[1];
		                else if (op == "abs") result = abs(r[0]);  
		                else if (op == "<") result = r[0] < r[1];  
		                else if (op == "==") result = r[0] == r[1];  
		                else {
		                    if (r[1] != 0) result = r[0]/r[1]; 
		                	else definit = false;
		                }
			     	}
		            
		            else definit = false;
				}
			}
		}
	}
}

void avalua(bool& def, int& result ) const {
	avalua_imm(primer_node,def,result);
}


