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

void ChMin(ll& a, ll b) {
	if (a > b) a = b;
}

void Dfs(ll& min_xor, int current, int n, const vector<map<int, ll>>& edges, int visited = 0, ll current_xor = 0) {
	if (current == n) {
		ChMin(min_xor, current_xor);
		return;
	}
	visited |= 1 << current;
	for (auto [adjacent, w] : edges[current]) {
		if (visited & (1 << adjacent)) continue;
		Dfs(min_xor, adjacent, n, edges, visited, current_xor ^ w);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<map<int, ll>> edges(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		edges[u][v] = w;
		edges[v][u] = w;
	}

	ll min_xor = __LONG_LONG_MAX__;
	Dfs(min_xor, 1, n, edges);

	cout << min_xor << endl;

	return 0;
}
