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
	int n;
	cin >> n;
	vector<set<int>> adjacents(n + 1);
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adjacents[u].insert(v);
		adjacents[v].insert(u);
	}

	vector<int> group(n + 1, -1);
	for (int u = 1; u <= n; u++) {
		if (group[u] != -1) continue;
		group[u] = 0;
		stack<int> search_stack;
		search_stack.push(u);
		while (!search_stack.empty()) {
			int v = search_stack.top();
			search_stack.pop();
			for (int a : adjacents[v]) {
				if (group[a] != -1) continue;
				group[a] = !group[v];
				search_stack.push(a);
			}
		}
	}

	set<array<int, 2>> edges_to_add;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (adjacents[i].find(j) == adjacents[i].end() and group[i] != group[j]) {
				edges_to_add.insert({i, j});
			}
		}
	}

	if (edges_to_add.size() % 2 == 0) {
		cout << "Second" << endl;
		int i, j;
		cin >> i >> j;
		if (i == -1) return 0;
		edges_to_add.erase({i, j});
	} else cout << "First" << endl;

	while (!edges_to_add.empty()) {
		int i, j;
		i = (*edges_to_add.begin())[0];
		j = (*edges_to_add.begin())[1];
		edges_to_add.erase(edges_to_add.begin());
		cout << i << ' ' << j << endl;
		cin >> i >> j;
		if (i == -1) return 0;
		edges_to_add.erase({i, j});
	}

	return 0;
}
