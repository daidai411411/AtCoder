#include <algorithm>
#include <atcoder/all>
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
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;

int main() {
	int n, m;
	cin >> n >> m;
	vector<set<int>> adj(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].insert(b);
	}

	vector<int> dist(n + 1, -1);
	dist[1] = 0;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int c = q.front();
		q.pop();

		for (int a : adj[c]) {
			if (a == 1) {
				cout << dist[c] + 1 << endl;
				return 0;
			}
			else if (dist[a] == -1) {
				dist[a] = dist[c] + 1;
				q.push(a);
			}
		}
	}

	cout << -1 << endl;

	return 0;
}
