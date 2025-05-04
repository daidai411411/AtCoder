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

void ChMin(ll& a, ll b) {
	if (a > b) a = b;
}

void Dfs(int n, int m, vector<vector<int>>& animals, vector<ll>& c, int i, vector<char> seen, ll cost, ll& ans) {
	if (i == n) return;
	for (int j = 0; j <= 2; j++) {
		vector<char> new_seen(seen);
		for (int a : animals[i]) new_seen[a] += j;
		ll new_cost = cost + c[i] * j;
		bool all_two = true;
		for (int s : new_seen) {
			if (s < 2) {
				all_two = false;
				break;
			}
		}
		if (all_two) {
			ChMin(ans, new_cost);
		} else if (new_cost < ans) {
			Dfs(n, m, animals, c, i + 1, new_seen, new_cost, ans);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<ll> c(n);
	for (ll& i : c) cin >> i;
	vector<vector<int>> animals(n);
	for (int i = 0; i < m; i++) {
		int k, a;
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> a;
			a--;
			animals[a].emplace_back(i);
		}
	}
	
	ll ans = __LONG_LONG_MAX__;
	vector<char> seen(m, 0);
	Dfs(n, m, animals, c, 0, seen, 0, ans);

	cout << ans << endl;

	return 0;
}
