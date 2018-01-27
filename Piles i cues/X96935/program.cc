#include <iostream>
#include <stack>
using namespace std;


bool es_palindrom(stack<int>& s, int n) {
    int x;
    if (n%2 != 0) cin >> x;
    for (int i = 0; i < n/2; ++i) {
        cin >> x;
        if (s.top() != x) return false;
        s.pop();
    }
    return true;
}

int main() {
    int n; cin >> n;
    stack <int> s;
    for (int i = 0; i < n/2; ++i) {
        int x; cin >> x;
        s.push(x);
    }
    if (es_palindrom(s,n)) cout << "SI" << endl;
    else cout << "NO" << endl;
    
}
