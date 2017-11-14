#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b) {
  b = 0;
  int i = cerca_dicot(vest,0,nest-1,est.consultar_DNI());
  if (vest[i].consultar_DNI() == est.consultar_DNI()) b = 1;
  else {
    int j = nest;
    ++nest;
    while (j > i) {
      vest[j] = vest[j-1];
      --j;
    }
    vest[j] = est;
      //canviar la nota general (mitjana)
    if (est.te_nota()) {
      if (nest_amb_nota == 0) suma_notes = est.consultar_nota();
      else suma_notes += est.consultar_nota();
      ++nest_amb_nota;
    }
  }
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b) {
    b = false;
    int i = 0;
    while (!b and i < nest) {
        if (vest[i].consultar_DNI() == dni) b = true;
        ++i;
    }
    if (b) {
        if (vest[i-1].te_nota()){
            //no cal if
            suma_notes -= vest[i-1].consultar_nota();
            --nest_amb_nota;
        }
        for (int j = i; j < nest; ++j) {
            vest[j-1] = vest[j];
        } --nest;
    }
}
