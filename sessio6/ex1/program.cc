#include "LlistaIOParInt.hh"
#include <iostream>
#include <list>
using namespace std;

int main() {
    list <ParInt> l;
    list <ParInt>::iterator it = l.begin();
    LlegirLlistaParInt(l);
    int n; cin >> n;
    int nrep = 0;
    int nsum = 0;
    for (it = l.begin(); it != l.end(); ++it) {
        if ((*it).primer() == n) {
            ++nrep;
            nsum += (*it).segon();
        }
        
    }
    cout <<n << ' ' << nrep << " " << nsum << endl;
}
