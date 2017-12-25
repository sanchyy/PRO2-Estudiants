#include <iostream>
#include <list>
using namespace std;
 
struct Parell {
  int cod_op;
  int num;
};
 
void read (list < Parell > &l) {
  Parell p;
  cin >> p.cod_op>> p.num;
  list < Parell >::iterator it = l.begin ();
  while (p.cod_op != 0 and p.num != 0) {
      l.insert (it, p);
      cin >> p.cod_op >> p.num;
    }
}
 
void borra(list <Parell> &l, int n, double &elem, double &suma) {
  list < Parell >::iterator it;
  bool done = false;
  for (it = l.begin (); not done and it != l.end (); ++it)
    {
      Parell aux = *it;
      if (aux.cod_op == -1 and aux.num == n)
        {
          it = l.erase (it);
          --elem;
          suma -= aux.num;
          done = true;
        }
    }
}
 
void recalcula_maxmin (const list < Parell > &l, int &max, int &min) {
  max = 0;
  min = 9;
  list < Parell >::const_iterator it;
  bool hiha_valids = false;
  for (it = l.begin (); it != l.end (); ++it)
    {
      Parell aux = *it;
      if (aux.cod_op == -1)
        {
          if (max < aux.num)
            max = aux.num;
          if (min > aux.num)
            min = aux.num;
          hiha_valids = true;
        }
    }
  if (not hiha_valids)
    {
      max = min = 0;
    }
}
 
void solution (list < Parell > &l) {
  list <Parell>::iterator it;
  int min = 9, max = 0;
  double suma = 0, elem = 0;
  for (it = l.begin (); it != l.end (); ++it)
    {
      Parell aux = *it;
      if (aux.cod_op == -1)
        {
          if (max < aux.num)
            max = aux.num;
          if (min > aux.num)
            min = aux.num;
          ++elem;
          suma += aux.num;
          cout << min << ' ' << max << ' ' << suma / elem << endl;
        }
      else
        {
          borra(l, aux.num, elem, suma);
          if (max == aux.num or min == aux.num)
            recalcula_maxmin (l, max, min);
          if (max == 0 and min == 0)
            cout << 0 << endl;
          else
            cout << min << ' ' << max << ' ' << suma / elem << endl;
        }
    }
}
 
int main () {
  list <Parell> l;
  read(l);
  solution (l);
}