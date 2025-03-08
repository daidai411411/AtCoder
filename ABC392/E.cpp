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

using Edge = array<int, 2>;

struct ConnectedConponents {
	int representative;
	set<Edge> redundant_Edges;
	void Merge(ConnectedConponents other) {
		this->redundant_Edges.merge(other.redundant_Edges);
	}
};

vector<ConnectedConponents> IntoVecOfCC(const int n, const vector<set<Edge>>& edges) {
	vector<ConnectedConponents> vec_of_cc;
	vector<bool> visited(n, false);

	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		ConnectedConponents cc;
		cc.representative = i;
		stack<int> search_stack;
		search_stack.push(cc.representative);
		while (!search_stack.empty()) {
			int current = search_stack.top();
			search_stack.pop();
			visited[current] = true;
			for (Edge e : edges[current]) {
				if (visited[e[1]]) cc.redundant_Edges.insert(e);
				else search_stack.push(e[1]);
			}
		}
		vec_of_cc.push_back(cc);
	}
	return vec_of_cc;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<set<Edge>> edges(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		edges[a].insert({i, b});
		edges[b].insert({i, a});
	}

	vector<array<int, 3>> operations;
	vector<ConnectedConponents> vec_of_cc = IntoVecOfCC(n, edges);
	int k = vec_of_cc.size() - 1;
	cout << k << endl;

	sort(vec_of_cc.begin(), vec_of_cc.end(), [](const ConnectedConponents& l, const ConnectedConponents& r) { return l.redundant_Edges.size() < r.redundant_Edges.size(); });	
	for (int i = k; i >= 1; i--) {
		Edge target = *(vec_of_cc[i].redundant_Edges.begin());
		vec_of_cc[i].redundant_Edges.erase(vec_of_cc[i].redundant_Edges.begin());
		int change_to = vec_of_cc[i - 1].representative;
		vec_of_cc[i - 1].Merge(vec_of_cc[i]);
		operations.push_back({target[0], target[1], change_to});
	}

	for (auto [edge_number, from, to] : operations) cout << edge_number + 1 << " " << from + 1 << " " << to + 1 << endl;

	return 0;
}
