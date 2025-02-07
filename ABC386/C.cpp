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
  int k;
  string s, t;
  cin >> k >> s >> t;

  if (s == t) {
    cout << "Yes" << endl;
    return 0;
  }

  bool yes = true;
  if (s.size() == t.size() - 1) {
    s += ' ';
    bool done = false;
    for (int i = 0; i < t.size(); i++) {
      if (s[i - done] == t[i])
        continue;
      else if (done == false) {
        done = true;
      } else {
        yes = false;
        break;
      }
    }
  } else if (s.size() == t.size() + 1) {
    bool done = false;
    for (int i = 0; i < t.size(); i++) {
      if (s[i + done] == t[i])
        continue;
      else if (done == false) {
        i--;
        done = true;
      } else {
        yes = false;
        break;
      }
    }
  } else if (s.size() == t.size()) {
    bool done = false;
    for (int i = 0; i < t.size(); i++) {
      if (s[i] == t[i])
        continue;
      else if (done == false)
        done = true;
      else {
        yes = false;
        break;
      }
    }
  } else {
    yes = false;
  }

  if (yes)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
