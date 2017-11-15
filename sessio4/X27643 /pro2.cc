#include <iostream>
#include "Cjt_estudiants.hh"

using namespace std;


int main() {
  Cjt_estudiants c;
  c.llegir();
  cout << "Hi ha " << c.bec_disp() << " beques disponibles per al conjunt" << endl << endl; 
  string op; 
  cin >> op;
  bool terminar = false;
  while (not terminar) {
    if (op == "posicio") {  
      int pos = c.pos_max_no_becat();
      if (pos != -1)  cout << "Millor candidat no becat " << c.consultar_iessim(pos).consultar_DNI() << endl << endl;
      else cout << "No hi ha candidats sense beca" << endl << endl;
    }
    else if (op == "escriure") {   
      cout << "Conjunt:" << endl;
      c.escriure();
      cout << endl;
    }
    else if (op == "esborrar") {  
      int dni; 
      cin >> dni;
      bool trobat; 
      c.esborrar_estudiant(dni,trobat);
      if (not trobat)  cout << "L'estudiant " << dni << " no s'ha esborrat" << endl << endl;
    }
    else if (op == "becas") {
      cout << "Estudiants amb beca: " << c.b_assignades() << endl << endl; 
    }
    else if (op == "consultar") {
      int dni; 
      cin >> dni; 
      Estudiant est; 
      bool trobat; 
      c.consultar_estudiant(dni,trobat,est); 
      if (not trobat)  {
          cout << "L'estudiant amb DNI " << dni << 
          " no hi es" << endl << endl;
      }
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
