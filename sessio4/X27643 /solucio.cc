#include "Cjt_estudiants.hh"

//candidat a beca si té un 5 o més
// e1.nota > e2.nota o si e1 == e2, dni(e1) > dni(e2)

void Cjt_estudiants::recalcular_pos_max_no_becat() {
  i_max_no_becat = -1;
  for (int i = 0; i < nest; ++i) {
    if (vest[i].te_nota() and vest[i].aprovat() and !vest[i].te_beca()) {
      if (i_max_no_becat == -1) i_max_no_becat = i;
      else if (Estudiant::major_nota_dni(vest[i],vest[i_max_no_becat])){i_max_no_becat = i;};
    }
  }
}

void Cjt_estudiants::esborrar_estudiant(int x, bool& trobat) {
  trobat = 0;
  int pos = cerca_dicot(vest,0,nest-1,x);
  if (vest[pos].consultar_DNI() == x) {
    trobat = 1;
    if (vest[pos].te_beca()) {
      if (i_max_no_becat != -1)
        vest[i_max_no_becat].modificar_beca(1);
      else if (n_bec >= 1) --n_bec;
    }
    for (int i = pos; i < nest-1; ++i) vest[i] = vest[i+1];
      --nest;
      recalcular_pos_max_no_becat();
  }
}
