#include <iostream>
#include "BinTreeIOParInt.hh"

bool profunditat (BinTree<ParInt>& a, int& n, int& count, int& parell) {
  if (a.value() == n){
    parell = n.segon();
    return true;
  }
  else {
    profunditat(a.left(), n, count, parell);
    profunditat(a.right(), n, count, parell);
  }
}

int main() {
  BinTree <ParInt> a;
  read_bintree_parint(a);
  int n;
  while (cin >> n) {
    int count = 0;
    int parell;
    if (!profunditat(a,n,count,parell)) cout << '-1' << endl;
    else cout << n << ' ' << parell << ' ' << count << endl;
  }
}
