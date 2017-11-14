#include "Cjt_estudiants.hh"

int Cjt_estudiants::posicio_nota(double nota_b) const {
  for (int i=primer_est_amb_nota;i<nest;i++){
    if (vest[i].consultar_nota() >= nota_b) return i;
  }
  return nest;
}

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool &trobat) {
trobat = vest[cerca_lineal_per_dni(vest,0,nest-1,est.consultar_DNI())].consultar_DNI()== est.consultar_DNI();
if (!trobat){
    int x;
    if(est.te_nota()) x = cerca_dicot_per_nota_dni(vest,primer_est_amb_nota,nest-1,est);

    else {
        x = cerca_dicot_per_dni(vest,0,primer_est_amb_nota-1,est.consultar_DNI());
        ++primer_est_amb_nota;
    }
    int j = nest;
    ++nest;
    while (j > x) {vest[j]=vest[j-1];--j;}
    vest[j]=est;
 }
}

void Cjt_estudiants::escriure_i(double nota_i, double nota_s) const {
  for (int i= primer_est_amb_nota; i<nest; ++i)
        if (vest[i].consultar_nota() >= nota_i and vest[i].consultar_nota() <= nota_s) vest[i].escriure();
}
