#include "Estudiant.hh"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector <Estudiant> e(n);
    int count = 0;
    for (int i = 0; i < n; ++i) {
        e[i].llegir(); 
        if (i != 0 and e[i].dni != e[i-1].dni) ++count;
    }
    vector<Estudiant> aux(count);
    int j = 0; 
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            aux[0] = e[0];
        }
    }
    
    
}
