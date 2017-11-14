#include "LlistaIOEstudiant.hh"
#include "Estudiant.hh"

void LlegirLlistaEstudiant(list<Estudiant>& l) {
  list<Estudiant>::iterator it = l.begin();
  Estudiant e = Estudiant();
  e.llegir();
  while (e.consultar_nota() != 0 and e.consultar_DNI() != 0) {
    l.insert(it,e);
    e.llegir();
  }
}
