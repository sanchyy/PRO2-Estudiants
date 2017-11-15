#include "BinTree.hh"
#include <iostream>
#include <stack>
using namespace std;

int n_elements (const BinTree<int>& a) {
  if (a.empty()) return 0;
  else return 1 + n_elements(a.left()) + n_elements(a.right());
}

void cami_preferent(const BinTree<int> &a, stack<int> &c) {
  if (a.empty()) return;
  else {
    c.push(a.value());
    if (n_elements(a.left()) >= n_elements(a.right())) cami_preferent(a.left(),c);
    else cami_preferent(a.right(),c);
  }
}
