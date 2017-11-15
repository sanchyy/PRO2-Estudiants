#include "Estudiant.hh"
 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

Estudiant calcula_mitjana(int N, vector<int> assig) {
    int dni;
    cin >> dni;
    Estudiant est(dni);
    vector<double> notes(N);
    for (int i = 0; i < N; i++) {
        cin >> notes[i];
    }
    int tam = assig.size();
    double mitjana = 0;
    //No és necessari crear un vector de boleans per seleccionar les notes, crant un vector de notes
    // només cal agafar S notes en la posició A-1.
    for (int i = 0; i < tam; i++) {
        mitjana += notes[assig[i]-1];
    }
    mitjana /= tam;
    est.afegir_nota(mitjana);
    return est;
}

bool kompare (Estudiant& a, Estudiant& b){
    if (a.consultar_nota() != b.consultar_nota()) {
        return a.consultar_nota() > b.consultar_nota(); 
    }
    return a.consultar_DNI() < b.consultar_DNI();
}
 
int main() {
    int M, N, S;
    cin >> M >> N >> S;
    vector<int> assig(S);
    for (int i = 0; i < S; i++) {
        cin >> assig[i];
    }
    vector <Estudiant> est(M);
    // Com que tens M estudiants, reiteres el calcul i l'escriptura M cops.
    for (int i = 0; i < M; ++i) est[i] = calcula_mitjana(N, assig);
    sort(est.begin(),est.end(),kompare);
    for (int i = 0; i < M; ++i) est[i].escriure();
}
