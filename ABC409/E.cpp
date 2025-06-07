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

void Dfs(const int n, vector<ll>& x, const vector<map<int, ll>>& edges, int parent, int current, ll& energy) {
	for (auto [adjacent, weight] : edges[current]) {
		if (adjacent == parent) continue;
		Dfs(n, x, edges, current, adjacent, energy);
	}
	if (parent == -1) return;
	energy += abs(x[current]) * edges[current].at(parent);
	x[parent] += x[current];
}

int main() {
	int n;
	cin >> n;
	vector<ll> x(n);
	for (ll& xi : x) cin >> xi;
	vector<map<int, ll>> edges(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		u--;
		v--;
		edges[u][v] = edges[v][u] = w;
	}

	ll energy = 0;
	Dfs(n, x, edges, -1, 0, energy);

	cout << energy << endl;

	return 0;
}
