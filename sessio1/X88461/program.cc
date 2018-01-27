#include <iostream>
#include <vector>
using namespace std;


void read (vector <int>& v, int n, int&max, int&min) {
    cin >> v[0];
    min = v[0];
    max = v[0];
    for (int i = 1; i < n; ++i) {
        cin >> v[i];
        if (v[i] < min) min = v[i];
        if (v[i] > max) max = v[i];
    }
}

int main() {
    int n;
    cin >> n;
    int max, min;
    vector <int> v(n);
    read(v,n,max,min);
    
    cout << max << ' ' << min << endl;
    
}
