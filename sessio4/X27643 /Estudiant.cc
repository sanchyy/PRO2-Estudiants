#include "Estudiant.hh"


/* Constants */

const char *ER1 = "No te nota";
const char *ER2 = "Valor de la nota entre 0 a 10";
const char *ER3 = "Ja te nota";
const char *ER4 = "El DNI es incorrecte";


Estudiant::Estudiant() {
  dni = 0;
  amb_nota = false;
  amb_beca = false;
}

Estudiant::Estudiant(int x) {
  if (x < 0) throw PRO2Excepcio(ER4);
  dni = x;
  amb_nota = false;
  amb_beca = false;
}

Estudiant::~Estudiant() {}

void Estudiant::afegir_nota(double n) {
  if (amb_nota) 
    throw PRO2Excepcio(ER3);
  if (n < 0 or n > MAX_NOTA)
    throw PRO2Excepcio(ER2); 
  
  nota = n; 
  amb_nota = true;
}

void Estudiant::modificar_nota(double n) { 				
  if (not amb_nota) 
    throw PRO2Excepcio(ER1);
  if (n < 0 or n > MAX_NOTA)
    throw PRO2Excepcio(ER2);
  nota = n;
}

void Estudiant::modificar_beca(bool v) { 				
  amb_beca = v;
}

bool Estudiant::te_nota() const {
  return amb_nota;
}

bool Estudiant::te_beca() const {
  return amb_beca;
}

double Estudiant::consultar_nota() const {
  if (not amb_nota) throw PRO2Excepcio(ER1);
  return nota;
}

int Estudiant::consultar_DNI() const {
  return dni;
}

double Estudiant::nota_maxima() {
  return MAX_NOTA;
}


bool Estudiant::aprovat() const {
  return amb_nota and nota >= MIN_APR;
}

bool Estudiant::menor_dni(const Estudiant& e1, const Estudiant& e2) {
  return e1.dni < e2.dni;
}

bool Estudiant::major_nota_dni(const Estudiant& e1, const Estudiant& e2) {
  if (e1.amb_nota and e2.amb_nota) {
    if (e1.nota != e2.nota) return e1.nota > e2.nota;
    else return e1.dni > e2.dni;
  } 
  if (e1.amb_nota != e2.amb_nota) return e1.amb_nota; 
  return e1.dni > e2.dni;
}

void Estudiant::llegir() {
  cin >> dni;
  if (dni < 0) throw PRO2Excepcio(ER4);
  double x;
  cin >> x;
  if (x >= 0 and x <= MAX_NOTA) {
    nota = x; 
    amb_nota = true;
  }
  else amb_nota = false;
  amb_beca = false;
}

void Estudiant::escriure() const {
  cout << dni; 
  if (amb_nota) cout << ": nota " << nota;
  else cout << ": NP";
  if (amb_beca) cout << ", amb beca"; 
  cout << endl;
}
