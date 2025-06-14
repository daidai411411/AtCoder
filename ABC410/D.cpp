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

template <typename T>
bool ChMin(T& min, T val) {
	return (val < min) ? (min = val, true) : false;
}

void Dfs(const int n, const vector<vector<pair<int, ll>>>& edges, const int c, vector<set<ll>>& hist, ll x, ll& minx) {
	if (c == n) ChMin(minx, x);

	hist[c].insert(x);

	for (auto [a, w] : edges[c]) {
		if (hist[a].find(x ^ w) != hist[a].end()) continue;
		Dfs(n, edges, a, hist, x ^ w, minx);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, ll>>> edges(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		ll w;
		cin >> a >> b >> w;
		edges[a].push_back({b, w});
	}

	vector<set<ll>> hist(n + 1);
	ll minx = 1 << 10;
	Dfs(n, edges, 1, hist, 0, minx);

	if (minx < 1 << 10) cout << minx << endl;
	else cout << -1 << endl;

	return 0;
}
