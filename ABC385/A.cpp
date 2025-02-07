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

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  if ((a == b and b == c) or (a + b == c) or (b + c == a) or (c + a == b)) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
