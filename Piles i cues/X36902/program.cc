#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack <char> s;
    char c;
    while (cin >> c and c != '.') {
        if (s.empty()) s.push(c);
        else {
            if (s.top() == '(') {
                if (c == ')') s.pop();
                else s.push(c);
            }
            else {
                if (s.top() == '[') {
                    if (c == ']') s.pop();
                else s.push(c);
                }
            }
        }
    }
    if (s.empty()) cout << "Correcte" << endl;
    else cout << "Incorrecte" << endl;
}
