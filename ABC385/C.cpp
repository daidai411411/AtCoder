#include <algorithm>
#include <array>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;

void ChMax(int& a, int b) {
  if (a < b) a = b;
}

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; i++) cin >> h[i];

  int m = 1;
  for (int d = 1; d < n; d++) {
    for (int b = 0; b < d; b++) {
      int c = 1;
      for (int i = b + d; i < n; i += d) {
        if (h[i - d] == h[i]) c++;
        else {
          ChMax(m, c);
          c = 1;
        }
      }
      ChMax(m, c);
    }
  }

  cout << m << endl;

  return 0;
}
