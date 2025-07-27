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

template <typename T>
bool ChMin(T& min, T val) {
	return (val < min) ? (min = val, true) : false;
}

int main() {
	ll n, m, k, t_air, q;
	cin >> n >> m;
	vector<map<int, ll>> roads(n);
	for (int i = 0; i < n; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		if (roads[a].find(b) == roads[a].end()) {
			roads[a][b] = roads[b][a] = c;
		} else {
			ChMin(roads[a][b], c);
			ChMin(roads[b][a], c);
		}
	}
	cin >> k >> t_air;
	vector<int> d(k);
	vector<bool> has_airport(n, false);
	for (int i = 0; i < k; i++) {
		cin >> d[i];
		d[i]--;
		has_airport[d[i]] = true;
	}
	cin >> q;
	vector<array<ll, 4>> querys(q);
	for (array<ll, 4>& query : querys) {
		ll type = 0, x = 0, y = 0, t = 0;
		cin >> type;
		if (type == 1) {
			cin >> x >> y >> t;
			x--;
			y--;
		} else if (type == 2) {
			cin >> x;
			x--;
		} 
		query = {type, x, y, t};
	}

	return 0;
}
