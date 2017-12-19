#include "LlistaIOParInt.hh"
void LlegirLlistaParInt(list<ParInt>& l) {
    list<ParInt>::iterator it = l.begin();
    int a,b;
    cin >> a >> b;
    while (a != 0 and b != 0) {
        ParInt p = ParInt(a,b);
        l.insert(it,p);
        cin >> a >> b;
    }
}

