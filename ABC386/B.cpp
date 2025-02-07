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
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;

  int count = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != '0') {
      count++;
    } else if (i != s.size() - 1 and s[i + 1] == '0') {
      count++;
      i++;
    } else {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}
