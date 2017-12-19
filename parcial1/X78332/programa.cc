#include "BinTree.hh"
#include <iostream>
#include <stack>
using namespace std;


void i_cami_preferent(const BinTree<int> &a, stack<int> &c,int n) {
    if (a.left().empty() or a.right().empty()) return;
    else {
        int nl,nr;
        BinTree<int> left,right;
        
    }
    n = nl+nr+1;
    
}


void cami_preferent(BinTree<int> &a, stack<int> &c) {
    int n;
    i_cami_preferent(a,c,n);
}

