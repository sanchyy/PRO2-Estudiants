#include <iostream>
#include <vector>
using namespace std;

struct Equip {
    int e;
    int ngols;
    int nrebuts;
    int punts;
};

struct Parell {
    int x;
    int y;
};

void read (vector <int>& v, int n) {
    Parell p;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
           cin >> p.x >> p.y;
           if (p.x > p.y) v[i].punts +=3;
           else if (p.x == p.y) {++v[i].punts; ++v[j].punts;}
           else (p.x < p.y) {v[j].punts +=3;}
           v[i].ngols += p.x;
           v[j].ngols += p.y;
           v[i].nrebuts += p.y;
           v[j].nrebuts += p.x;
           
        }
    }
}

bool kompare (Equip& a, Equip& b) {
    
}

int main() {
    int n; cin >> n;
    vector <Equip> v(n);
    for (int i = 0; i < n; ++i)v[i].e = i+1;
    read(v,n);
    
    
}
