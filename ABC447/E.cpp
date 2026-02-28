#include <algorithm>
#include <array>
#include <climits>
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

#define M (998244353LL)

using namespace std;
using ll = long long;
using ull = unsigned long long;

struct UnionFind {
   private:
	int n_;
	int numof_unions_;
	vector<int> parent_;
	vector<int> root_size_;

   public:
	UnionFind(const int n) : n_(n), numof_unions_(n), parent_(n), root_size_(n, 1) {
		iota(parent_.begin(), parent_.end(), 0);
	}

	int Root(const int u) {
		if (parent_[u] == u) return u;
		else {
			parent_[u] = Root(parent_[u]);
			return parent_[u];
		}
	}

	void Unite(const int u, const int v) {
		int root_u = Root(u), root_v = Root(v);
		if (root_u != root_v) {
			numof_unions_--;
			parent_[root_v] = root_u;
			root_size_[root_u] += root_size_[root_v];
		}
	}

	bool Same(const int u, const int v) {
		return (Root(u) == Root(v));
	}

	int NumofUnions(void) {
		return numof_unions_;
	}

	int UnionSize(const int u) {
		return root_size_[Root(u)];
	}

	vector<vector<int>> Unions(void) {
		vector<int> indices(n_, -1);
		vector<vector<int>> unions;
		for (int i = 0; i < n_; i++) {
			if (indices[Root(i)] == -1) {
				indices[Root(i)] = unions.size();
				unions.emplace_back(1, i);
			} else {
				unions[indices[Root(i)]].emplace_back(i);
			}
		}
		return unions;
	}
};

struct Edge {
	int u, v;
	int i;
};

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<Edge> edges(m);
	for (int i = 0; i < m; i++) {
		cin >> edges[i].u >> edges[i].v;
		edges[i].u--;
		edges[i].v--;
		edges[i].i = i + 1;
	}

	vector<ll> pow2mod(m + 1);
	pow2mod[0] = 1;
	for (int i = 1; i <= m; i++) pow2mod[i] = (pow2mod[i - 1] * 2) % M;

	reverse(edges.begin(), edges.end());
	UnionFind uf(n);
	ll ans = 0;
	for (Edge& e : edges) {
		// cout << "Unite (" + to_string(e.u) + ", " + to_string(e.v) + ") : ";

		int num_cc = uf.NumofUnions();
		bool is_same = uf.Same(e.u, e.v);
		// cout << to_string(num_cc) + " -> " + to_string(is_same ? num_cc : (num_cc - 1));

		if (num_cc == 2 and !is_same) {
			ans = (ans + pow2mod[e.i]) % M;
			// cout << "  Cancel" << endl;
		} else {
			uf.Unite(e.u, e.v);
			// cout << "  Unite" << endl;
		}
	}

	cout << ans << endl;

	return 0;
}
