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
  int h, w, x, y;
  cin >> h >> w >> x >> y;
  x--;
  y--;
  vector<string> s(h);
  for (string& i : s) cin >> i;
  string t;
  cin >> t;

  int c = 0;
  for (char ti : t) {
    int nx = x, ny = y;
    if (ti == 'U') nx--;
    else if (ti == 'D') nx++;
    else if (ti == 'L') ny--;
    else ny++;

    if (!(0 <= nx and nx < h and 0 <= ny and ny < w)) continue;
    if (s[nx][ny] == '#') continue;

    x = nx;
    y = ny;
    if (s[x][y] == '@') {
      c++;
      s[x][y] = '.';
    }
  }

  cout << (x + 1) << ' ' << (y + 1) << ' ' << c << endl;

  return 0;
}
