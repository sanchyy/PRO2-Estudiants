#include <iostream>
#include <vector>
using namespace std;

int comptatge_frontisses(const vector<int>& v) {
  int count = 0;
  int l = v.size();
  int sumaesquerra = 0, sumadreta = 0;

  for (int aux = 0; aux < l; ++ aux) {
          sumadreta += v [aux];
  }

  int num = 0;

  for (int aux = 0; aux < l; ++ aux) {
          sumaesquerra += num;
          num = v [aux];
          sumadreta -= num;

          if (sumadreta - sumaesquerra == num) count ++;
  }

  return count;
  }
