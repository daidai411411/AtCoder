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
	int n, m;
	cin >> n >> m;
	vector<set<int>> adjacents(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adjacents[u].insert(v);
		adjacents[v].insert(u);
	}

	int ans = 0;
	vector<bool> visited(n + 1, false);
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		stack<array<int, 2>> search_stack;
		search_stack.push({-1, i});
		while (!search_stack.empty()) {
			auto [parent, current] = search_stack.top();
			search_stack.pop();
			if (visited[current]) continue;
			visited[current] = true;
			if (parent != -1) adjacents[parent].erase(current);
			adjacents[current].erase(parent);
			for (int adjacent : adjacents[current]) {
				if (visited[adjacent]) {
					ans++;
				} else {
					search_stack.push({current, adjacent});
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}
