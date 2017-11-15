#include "LlistaIOEstudiant.hh"

void LlegirLlistaEstudiant(list<Estudiant>& l) {
    list<Estudiant>::iterator it = l.begin();
    Estudiant e;
    e.llegir();
    while (e.consultar_nota() != 0 and e.consultar_DNI() != 0) {
        l.insert(it,e);
        e.llegir();
    }
}

void EscriureLlistaEstudiant(list<Estudiant>& l) {
    list<Estudiant>::iterator it;
    for (it = l.begin(); it != l.end(); ++it) it -> escriure();
}
