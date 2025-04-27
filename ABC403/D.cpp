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
	ll n, d;
	cin >> n >> d;
	vector<ll> a(n);
	for (ll& i : a) cin >> i;

	if (d == 0) {
		ll ans = 0;
		vector<bool> seen(1000000 + 1, false);
		for (ll i : a) {
			if (seen[i]) ans++;
			else seen[i] = true;
		}
		cout << ans << endl;
		return 0;
	}

	vector<vector<ll>> counts_mod(d, vector<ll>(1000000 / d + 1, 0));
	for (ll i : a) {
		counts_mod[i % d][i / d]++;
	}

	ll ans = 0;
	for (const vector<ll>& counts : counts_mod) {
		vector<ll> cnt_rm(2, 0);
		for (ll i = 0; i < (ll)counts.size(); i++) {
			if (counts[i] == 0) continue;
			cnt_rm[i % 2] += counts[i];
			if (i == (ll)counts.size() - 1 || counts[i + 1] == 0) {
				ans += min(cnt_rm[0], cnt_rm[1]);
				cnt_rm[0] = cnt_rm[1] = 0;
			}
		}
	}

	cout << ans << endl;

	return 0;
}
