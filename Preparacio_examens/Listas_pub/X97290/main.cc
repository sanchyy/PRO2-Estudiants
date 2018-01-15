#include "LlistaIOint.hh"

int main() {
  Llista<int> a, b;
  llegir_llista_int(a,0);
  llegir_llista_int(b,0);
  cout << endl;
  escriure_llista_int(a);
  cout << endl;
  escriure_llista_int(b);
  b = a;
  cout << endl;
  escriure_llista_int(a);
  cout << endl;
  escriure_llista_int(b);
  cout << endl << "al reves" << endl;
  cout << endl;
  escriure_llista_int_rev(b);
}
