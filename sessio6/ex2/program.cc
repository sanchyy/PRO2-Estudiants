#include <iostream>
#include <list>
#include "LlistaIOEstudiant.hh"

int main() {
  list<Estudiant> l;
  list<Estudiant>::iterator it = l.begin();
  LlegirLlistaEstudiant(l);
  int n; cin >> n;
  int count = 0;
  for (it = l.begin(); it != l.end(); ++it) {
    if ((*it).consultar_DNI() == n) ++count;
  }

  cout << n << ' ' << count << endl;
}
