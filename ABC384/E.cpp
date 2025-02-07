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
#include <unordered_set>
#include <vector>
#include <tuple>

using namespace std;
using ll = long long;

int main() {
	int h, w, p, q;
	double x;
	cin >> h >> w >> x >> p >> q;
	p--;
	q--;
	vector<vector<ll>> s(h, vector<ll>(w));
	for (auto& i : s) {
		for (ll& j : i) cin >> j;
	}

	ll strength = s[p][q];
	s[p][q] = 0;
	set<tuple<ll, int, int>> adj;
	adj.insert({s[p][q], p, q});

	bool updated = true;
	while (true) {
		updated = false;
		set<tuple<ll, int, int>> new_adj;
		for (auto itr = adj.begin(); itr != adj.end();) {
			auto [_, r, c] = *itr;
			if (s[r][c] < strength / x) {
				strength += s[r][c];
				s[r][c] = 0;
				updated = true;
				itr = adj.erase(itr);
				if (r - 1 >= 0 and s[r - 1][c] != 0) new_adj.insert({r - 1, c});
				if (r + 1 < h and s[r + 1][c] != 0) new_adj.insert({r + 1, c});
				if (c - 1 >= 0 and s[r][c - 1] != 0) new_adj.insert({r, c - 1});
				if (c + 1 < w and s[r][c + 1] != 0) new_adj.insert({r, c + 1});
			} else itr++;
		}

		if (!updated) break;
		adj.merge(new_adj);
	}

	cout << strength << endl;

	return 0;
}
