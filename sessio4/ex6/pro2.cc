#include <iostream>
#include "Cjt_estudiants.hh"

using namespace std;

int main() {
  Cjt_estudiants c;
  cout << "Hi ha " << c.places_disp() << " places disponibles per al curs de reavaluacio." << endl << endl; 
  string op; 
  cin >> op;
  bool terminar = false;
  while (not terminar) {
    if (op == "afegir") {  
      Estudiant est; 
      est.llegir();
      bool trobat; 
      c.afegir_estudiant(est,trobat);
      if (trobat)  cout << "L'estudiant " << est.consultar_DNI() << " ja hi era" << endl << endl;
    }
    else if (op == "escriure") {   
      cout << "Conjunt:" << endl;
      c.escriure();
      cout << endl;
    }
    else if (op == "posicio") {  
      int pos = c.pos_min_admes(); 
      if (pos != -1)  cout << "Admes amb nota i DNI mes petits: " << c.consultar_iessim(pos).consultar_DNI() << endl << endl;
      else cout << "No hi ha estudiants admesos" << endl << endl;
    }
    else if (op == "admesos") {
      cout << "Admesos al curs de reavaluacio: " << c.n_admesos() << endl << endl; 
    }
    else if (op == "consultar") {
      int dni; 
      cin >> dni; 
      Estudiant est; 
      bool trobat; 
      c.consultar_estudiant(dni,trobat,est); 
      if (not trobat)  cout << "L'estudiant amb DNI " << dni << " no hi es" << endl << endl;
      else { 
        cout << "Estudiant ";
        est.escriure();
        cout << endl; 
      }  
    }
    else terminar = true;
    cin >> op;
  }
}

