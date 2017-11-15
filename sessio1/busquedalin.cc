#include <iostream>
using namespace std;

#include "vectorIOint.hh"

/* Buscar  */    
bool busqueda_lin(const vector<int>& v, int x, int& i)
/* Pre: cierto */
/* Post: el resultado indica si x está en v */
{
  int tam = v.size();
  i = 0;
  bool b = false;
  while (i<tam and not b) {
    if (v[i]==x) b=true; 
    else ++i;
  }
  return b;
}

int main()
{
  vector<int> v;
  leer_vector_int(v); 
  cout << "Escribe el elemento a buscar: " << endl;
  int i;
  int x;
  cin >> x; 
  bool b = busqueda_lin(v,x,i);
  if (b)  cout << "El elemento " << x << " esta en la posicion: " << i << endl << endl;
  else cout << "El elemento " << x << " no esta en el vector." << endl << endl;
  cout << "Escribimos el vector para que se vea que no ha cambiado:" << endl;
  escribir_vector_int(v);
}
