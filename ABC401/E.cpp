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

#define INF (1000000)

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
	int n, m;
	cin >> n >> m;
	vector<set<int>> adjs(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adjs[u].insert(v);
		adjs[v].insert(u);
	}

	vector<int> dist(n + 1, INF);
	dist[1] = 0;
	queue<int> sq;
	sq.push(1);
	while (!sq.empty()) {
		int c = sq.front();
		sq.pop();
		for (int a : adjs[c]) {
			if (dist[c] + 1 < dist[a]) {
				dist[a] = dist[c] + 1;
				sq.push(a);
			}
		}
	}
	vector<int> ans(n + 1, -1);
	int u;
	for (u = 1; u + 1 <= n and dist[u + 1] != INF; u++);
	ans[u] = 0;
	set<int> rm;
	for (; u >= 1; u--) {

	}


	return 0;
}
