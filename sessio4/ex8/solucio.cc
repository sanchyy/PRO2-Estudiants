#include "ListaPalabras.hh"

void ListaPalabras::anadir_palabra(const Palabra &p) {
  int pos;
  bool b;
  buscar_palabra_posicion(p,b,pos);
  if (paraules[pos].iguales(p)) {
    ++suma_frec_long[p.long_pal()];
  }
  else {
    int j = nparaules;
    ++nparaules;
    while (j > pos) {
      paraules[j] = paraules[j-1];
      --j;
    }
    paraules[pos] = p;
  }
}

void ListaPalabras::borrar_palabra(const Palabra &p) {
  
}

void ListaPalabras::buscar_palabra_posicion(const Palabra &p, bool &b, int &i) const {
  ... // codi de la implementació
}
