#include "Cjt_estudiants.hh"

void Cjt_estudiants::recalcular_pos_min_admes() {
  i_min_admes = -1;
  for (int i = 0; i < nest; ++i) {
    if (vest[i].te_nota() and vest[i].admes_reaval()) {
      if (i_min_admes == -1) i_min_admes = i;
      else if (Estudiant::major_nota_dni(vest[i_min_admes],vest[i])) i_min_admes = i;
    }
  }
}

void Cjt_estudiants::afegir_estudiant(const Estudiant& est, bool& trobat) {
  trobat = 0;
  int pos = cerca_dicot(vest,0,nest-1,est.consultar_DNI());
  if (vest[pos].consultar_DNI() == est.consultar_DNI()) trobat = true;
  else {
    ++nest;
    for (int i = nest-1; i > pos; --i) vest[i] = vest[i-1];
    vest[pos] = est;
    if (vest[pos].cond_reaval()){
      if (n_admes < MAX_PLA) {
        vest[pos].modificar_reaval(1);
        ++n_admes;
      }
      else {
        if (pos <= i_min_admes) ++i_min_admes;
        if (Estudiant::major_nota_dni(vest[pos],vest[i_min_admes])) {
          vest[i_min_admes].modificar_reaval(0);
          vest[pos].modificar_reaval(1);
        }
      }

    }
  }
  recalcular_pos_min_admes();
}
