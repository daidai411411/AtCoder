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

using namespace std;
using ll = long long;
using ull = unsigned long long;

struct UnionFind {
   private:
	int n_;
	int numof_unions_;
	vector<int> parent_;
	vector<bool> is_black_;
	vector<int> root_size_;
	vector<int> root_numof_blacks_;

   public:
	UnionFind(const int n) : n_(n), numof_unions_(n), parent_(n), is_black_(n, false), root_size_(n, 1), root_numof_blacks_(n, false) {
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
			root_numof_blacks_[root_u] += root_numof_blacks_[root_v];
		}
	}

	void Change(const int u) {
		if (is_black_[u]) {
			is_black_[u] = false;
			root_numof_blacks_[Root(u)]--;
		} else {
			is_black_[u] = true;
			root_numof_blacks_[Root(u)]++;
		}
	}

	int NumofBlacks(const int u) {
		return root_numof_blacks_[Root(u)];
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

int main(void) {
	int n, q;
	cin >> n >> q;
	vector<int> t(q), u(q), v(q);
	for (int i = 0; i < q; i++) {
		cin >> t[i];
		if (t[i] == 1) cin >> u[i] >> v[i];
		else cin >> v[i];
		u[i]--;
		v[i]--;
	}

	UnionFind uf(n);
	for (int i = 0; i < q; i++) {
		if (t[i] == 1) uf.Unite(u[i], v[i]);
		else if (t[i] == 2) uf.Change(v[i]);
		else cout << ((uf.NumofBlacks(v[i]) > 0) ? "Yes" : "No") << endl;
	}

	return 0;
}
