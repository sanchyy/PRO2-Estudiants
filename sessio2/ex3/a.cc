#include "Cjt_estudiants.hh"
#include <iostream>
#include <vector>
using namespace std;


void modificar(Cjt_estudiants& a, const Cjt_estudiants& b) {
    for (int i = 0; i < a.mida(); ++i) {
        Estudiant e1 = a.consultar_iessim(i+1);
        Estudiant e2 = b.consultar_iessim(i+1);
        
        if (e1.te_nota()) {
            if (e2.te_nota() && e2.consultar_nota() > e1.consultar_nota()) a.modificar_iessim(i+1,e2);
        }
        else if (e2.te_nota()) a.modificar_iessim(i+1,e2);
    }
}


int main() {
    Cjt_estudiants a = Cjt_estudiants();
    a.llegir();
    Cjt_estudiants b = Cjt_estudiants();
    b.llegir();
    modificar(a,b);
    a.escriure();
}
