#include <queue>
#include <iostream>
#include "CuaIOParInt.hh"
using namespace std;

void distribucio_en_cues (queue <ParInt> &a, queue <ParInt> &b, queue <ParInt> &c) {
	int count_primer = 0;
	int count_segon = 0;
	while (not a.empty()) {
		ParInt aux = a.front();
		if (count_segon < count_primer) {
			c.push(aux);
			count_segon += aux.segon();
		}
		else {
			b.push(aux);
			count_primer += aux.segon();
		}
		a.pop();
	}
}

int main() {
	queue <ParInt> cua_par;
	llegirCuaParInt(cua_par);
	queue <ParInt> primera_cua,segona_cua;
	distribucio_en_cues(cua_par,primera_cua,segona_cua);
	escriureCuaParInt(primera_cua);
	cout << endl;
	escriureCuaParInt(segona_cua);
}
