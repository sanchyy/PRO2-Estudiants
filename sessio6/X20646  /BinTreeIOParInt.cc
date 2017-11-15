#include "BinTreeIOParInt.hh"
using namespace std;

void read_bintree_parint(BinTree<ParInt>& a) {
  BinTree<ParInt> left,right;
  ParInt p;
  p.llegir();
  if (p.primer() == 0 and p.segon() == 0) return;
  read_bintree_parint(left);
  read_bintree_parint(right);
  BinTree(p,left,right);
}
