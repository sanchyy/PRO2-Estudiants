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
    } vest[j] = est;
    if (est.te_nota()) incrementar_interval(est.consultar_nota());
  }
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b) {
  b = 0;
    int j = 0;
    while (not b and j < nest) {
        if (vest[j].consultar_DNI() == dni) b = 1;
        ++j;
    }
    if (b) {
        if (vest[j-1].te_nota()) {
            int a = vest[j-1].consultar_nota();
            if (a == 10) a = 9;
            if (a < 10) --intervals[a];
        }
        for (int i = j; i < nest; ++i) vest[i-1] = vest[i];
        --nest;
    }
}
