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
using ull = unsigned long long;

int main() {
	int h, w, n;
	cin >> h >> w >> n;
	vector<array<int, 2>> g(n);
	vector<set<int>> xg(h + 1), yg(w + 1);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		g[i] = {x, y};
		xg[x].insert(i);
		yg[y].insert(i);
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int t, x, y;
		cin >> t;
		if (t == 1) {
			cin >> x;
			cout << xg[x].size() << endl;
			for (int j : xg[x]) {
				y = g[j][1];
				yg[y].erase(j);
			}
			xg[x].clear();
		} else {
			cin >> y;
			cout << yg[y].size() << endl;
			for (int j : yg[y]) {
				x = g[j][0];
				xg[x].erase(j);
			}
			yg[y].clear();
		}
	}

	return 0;
}
