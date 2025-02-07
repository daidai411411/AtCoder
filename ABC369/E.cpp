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

class Bridge {
	public:
	int i, dst, time;
};

int main() {
	int n, m;
	vector<vector<Bridge>> bridges(n);
	for (int i = 0; i < m; i++) {
		int u, v, t;
		cin >> u >> v;
		u--;
		v--;
		bridges[u].emplace_back(i, v, t);
		bridges[v].emplace_back(i, u, t);
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {

	}

	return 0;
}
