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

ll Max(ll i, ll h, ll n) {
	for (int j = i - 1; j >= 0; j--) n += (h - 1) * pow(10, j);
	return n;
}

ll Dfs(const ll& l, const ll& r, ll i, ll h, ll n) {
	cout << i << " " << h << " " << n << endl;
	if (Max(i, h, n) < l or r < n) return 0;
	if (i == 0) {cout << "found 1" << endl; return 1;}
	if (l <= n and Max(i, h, n) <= r) {cout << "found 10^" << i << endl; return pow(10, i);}
	ll ans = 0;
	for (int j = 0; j < h; j++) ans += Dfs(l, r, i - 1, j == 0 ? 10 : j, n + j * pow(10, i - 1));
	return ans;
}

int main() {
	ll l, r;
	cin >> l >> r;

	ll ans = Dfs(l, r, 18, 10, 0) + Dfs(l, r, 18, 1, pow(10, 18));

	cout << ans << endl;

	return 0;
}
