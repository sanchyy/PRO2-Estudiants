#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b) {
  b = 0;
  int dni = est.consultar_DNI();
  int i = cerca_dicot(vest, 0, nest-1, dni);
  if (vest[i].consultar_DNI() == dni) b = 1;
  else {
    int j = nest;
    ++nest;
    while (j > i) {
      vest[j] = vest[j-1];
      --j;
    }
    vest[j] = est;
    recalcular_posicio_imax();
  }

}

void Cjt_estudiants::eliminar_estudiants_sense_nota() {
  int count = 0;
  for (int i = 0; i < nest; ++i) {
    if (!vest[i].te_nota()) ++count;
    else vest[i-count] = vest[i];
  }
  nest -= count;
  recalcular_posicio_imax();
}
