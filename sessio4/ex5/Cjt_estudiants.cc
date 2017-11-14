#include "Cjt_estudiants.hh"
#include <algorithm>


void Cjt_estudiants::ordenar_cjt_estudiants() {
  sort(vest.begin(), vest.begin() + nest, Estudiant::menor_dni);
}

int Cjt_estudiants::cerca_dicot(const vector<Estudiant>& vest, int left, 
                                int right, int x) {
  int i;
  bool found = false;
  while (not found and left <= right) { 
    i = (left + right)/2;
    if (x < vest[i].consultar_DNI()) right = i - 1;
    else if (x > vest[i].consultar_DNI()) left = i + 1; 
    else found = true;
  }
  if (found) return i; 
  else return left;  
}  


Cjt_estudiants::Cjt_estudiants() {
  nest = 0;
  vest = vector<Estudiant>(MAX_NEST);
  n_bec = 0;
  i_max_no_becat = -1; 
}
  
Cjt_estudiants::~Cjt_estudiants() {}
 
  
int Cjt_estudiants::mida() const {
  return nest;
}

int Cjt_estudiants::mida_maxima() {
  return MAX_NEST;
}

int Cjt_estudiants::b_assignades() const {
  return n_bec;
}
  
int Cjt_estudiants::bec_disp() {
  return MAX_BEC;
}

int Cjt_estudiants::pos_max_no_becat() const {
  if (i_max_no_becat == -1) return i_max_no_becat;
  else return i_max_no_becat + 1;
}

void Cjt_estudiants::consultar_estudiant(int dni, bool& trobat, Estudiant& e) const {
  int i = cerca_dicot(vest,0,nest-1,dni);
  trobat = i < nest and vest[i].consultar_DNI() == dni;
  if (trobat) e = vest[i];
}
 
Estudiant Cjt_estudiants::consultar_iessim(int i) const {
 if (i < 1 or i > nest) throw PRO2Excepcio("Index no valid per a consultar_iessim");
  return vest[i-1];
}

void Cjt_estudiants::escriure() const {
  for (int i = 0; i < nest; ++i) vest[i].escriure();
}

// Implementació deliberadament ineficient
void Cjt_estudiants::llegir() {
  cin >> nest;
  if (nest > MAX_NEST) throw PRO2Excepcio("El conjunt no pot ser mes gran que la mida maxima");
  for (int i = 0; i < nest; ++i) vest[i].llegir();
  sort(vest.begin(), vest.begin() + nest, Estudiant::major_nota_dni);
  for (int i = 0; i < MAX_BEC; ++i) {
    if (vest[i].aprovat()) { 
       vest[i].modificar_beca(true);
       ++n_bec;
    }
  }
  ordenar_cjt_estudiants();
  recalcular_pos_max_no_becat();
}


