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

void Dfs(int n, vector<set<int>>& adj, int c, set<int>& visited) {
	visited.insert(c);
	for (int a : adj[c]) {
		if (visited.find(a) != visited.end()) continue;
		Dfs(n, adj, a, visited);
	}
}

bool IsCycleGraph(int n, vector<set<int>>& adj) {
	for (int i = 1; i <= n; i++) {
		if (adj[i].size() != 2) return false;
	}
	set<int> visited;
	Dfs(n, adj, 1, visited);
	return (visited.size() == n);
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<set<int>> adj(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].insert(b);
		adj[b].insert(a);
	}

	if (IsCycleGraph(n, adj)) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}
