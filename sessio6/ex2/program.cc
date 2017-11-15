#include "LlistaIOEstudiant.hh"
#include "Estudiant.hh"
#include <list>
#include <iostream>
using namespace std;

int main() {
    list <Estudiant> l;

    LlegirLlistaEstudiant(l);
    int n; cin >> n;
    cout << n << ' ';
    int count = 0;
    list <Estudiant>::iterator it = l.begin();
    while (it != l.end()) {
        if (it->consultar_DNI() == n) ++count;
        ++it;
    }
    cout << count << endl;
}
