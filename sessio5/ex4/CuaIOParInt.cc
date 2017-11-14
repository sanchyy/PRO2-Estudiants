#include "cuaIOparInt.hh"
#include <queue>
using namespace std;

void cuaIOparInt::llegirCuaParInt(queue<ParInt>& c) {
  ParInt aux();
  parInt comp();
  comp.llegir();
  int i = 0;
  if (!comp.empty()){
    while (comp != aux) {
      c.push(comp);
      c[i].llegir();
      comp = c[i];
      ++i;
    }
  }
}

void cuaIOparInt::escriureCuaParInt(queue<ParInt> c) {
  int n = c.size();
  for (int i = 0; i < n; ++i) {
    c[i].escriure();
  }
}
