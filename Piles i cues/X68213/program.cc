#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//moviments:
    //-1: retornar un llibre a la pila de devolucions;
    //-2: personal de la biblioteca retira llibre
    //-3: escriure contingut d'una de les piles del mostrador 
    //-4: acabar programa

int main() {
    int n; cin >> n;
    int x;
    vector <stack<string> > s(n);
    string nom;
    int  categoria;
    while (cin >> x and x != -4) {
        if (x == -1) {
            cin >> nom >> categoria;
            s[categoria-1].push(nom); 
        }
        else if (x == -2) {
            int a,b; cin >> a >> b;
            for (int i = 0; i < a; ++i) s[b-1].pop();
        }
        else if (x == -3) {
            int c; cin >> c;
            cout << "Pila de la categoria " << c << endl;
            stack<string> aux(s[c-1]);
            while (!aux.empty()) {
               cout << aux.top() << endl;
               aux.pop();
            }
            cout << endl;
        }
        
    }
}
