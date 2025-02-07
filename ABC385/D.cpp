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
  ll n, m, sx, sy;
  cin >> n >> m >> sx >> sy;
  unordered_map<ll, set<ll>> x2y, y2x;
  for (int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    x2y[x].insert(y);
    y2x[y].insert(x);
  }

  int hc = 0;
  for (int i = 0; i < m; i++) {
    char d;
    ll c;
    cin >> d >> c;

    if (d == 'U') {
      auto hy_begin = x2y[sx].upper_bound(sy);
      for (auto hy = hy_begin; hy != x2y[sx].end() and *hy <= sy + c;) {
        y2x[*hy].erase(sx);
        hy = x2y[sx].erase(hy);
        hc++;
      }
      sy += c;
    } else if (d == 'D') {
      auto hy_begin = x2y[sx].lower_bound(sy - c);
      for (auto hy = hy_begin; hy != x2y[sx].end() and *hy < sy;) {
        y2x[*hy].erase(sx);
        hy = x2y[sx].erase(hy);
        hc++;
      }
      sy -= c;
    } else if (d == 'L') {
      auto hx_begin = y2x[sy].lower_bound(sx - c);
      for (auto hx = hx_begin; hx != y2x[sy].end() and *hx < sx;) {
        x2y[*hx].erase(sy);
        hx = y2x[sy].erase(hx);
        hc++;
      }
      sx -= c;
    } else {
      auto hx_begin = y2x[sy].upper_bound(sx);
      for (auto hx = hx_begin; hx != y2x[sy].end() and *hx <= sx + c;) {
        x2y[*hx].erase(sy);
        hx = y2x[sy].erase(hx);
        hc++;
      }
      sx += c;
    }
  }

  cout << sx << ' ' << sy << ' ' << hc << endl;

  return 0;
}
