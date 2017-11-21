#include <iostream>
#include <list>
using namespace std;

struct Parell {
  int cod_op;
    //cod_op == -1 --> enter és vàlid
    //cod_op == -2 --> invalides tots els cops que surt "enter"
  int enter;
};

void eliminar_enter(list<Parell>& l, int a) {
  list<Parell>::iterator it;
  bool borrat =0;
  for (it = l.begin(); it != l.end() and !borrat; ++it) if (it->enter == a) {
    l.erase(it);
    --it;
    borrat = 1;
  }
}

void cosa (list <Parell>& l) {
  list<Parell>::iterator it = l.begin();
  int min = it->enter;
  int max = it->enter;
  double mitjana = 0;
  int n = 1;
  for (it = l.begin(); it != l.end(); ++it) {
    if (it->enter < min) min = it->enter;
    if (it->enter > max) max = it->enter;
    mitjana += it->enter;
    ++n;
  }
  if (min == 0 and max == 0 and mitjana == 0) cout << '0' << endl;
  else {
    cout << min << ' ' << max << ' ';
    if (n > 1) cout << mitjana/(n-1) << endl;
    else cout << mitjana << endl;
  }
}

int main() {
  Parell a;
  list <Parell> l;
  list<Parell>::iterator it = l.begin();
  cin >> a.cod_op >> a.enter;
  while (a.cod_op != 0 and a.enter != 0) {
    if (a.cod_op == -1)
      l.insert(it,a);
    else if (a.cod_op == -2)
      eliminar_enter(l,a.enter);
    cosa(l);
    cin >> a.cod_op >> a.enter;
  }
}
