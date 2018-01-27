#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Equip {
  int e;
  int ngols=0;
  int nrebuts=0;
  int punts=0;
};


void read (int n, vector<Equip>& v) {
  pair <int,int> p;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> p.first >> p.second;
      if (i != j) {
        if (p.first > p.second) v[i].punts+=3;
        else if (p.first < p.second) v[j].punts +=3;
        else {v[i].punts++; v[j].punts++;}
        v[i].ngols +=p.first;
        v[i].nrebuts += p.second;
        v[j].ngols +=p.second;
        v[j].nrebuts +=p.first;
      }
    }
  }
}

bool kompare (Equip& a, Equip& b) {
  if (a.punts == b.punts) {
    if ((a.ngols-a.nrebuts) == (b.ngols-b.nrebuts)) {
      return a.e < b.e;
    }
    else return (a.ngols-a.nrebuts) > (b.ngols-b.nrebuts);
  }
  return a.punts > b.punts;

  return a.e < b.e;
}




int main() {
  int n; cin >> n;
  vector <Equip> v(n);
  for (int i = 0; i < n; ++i) v[i].e = i+1;
  read(n,v);
  sort(v.begin(), v.end(),kompare);
  for (int i = 0; i < n; ++i) cout << v[i].e << ' ' << v[i].punts << ' ' << v[i].ngols << ' ' << v[i].nrebuts << endl;

}
