#include <algorithm>
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

int main(void) {
	int n, k;
	cin >> n >> k;
	vector<int> h(n);
	for (int& hi : h) cin >> hi;

	// dp[i] : 足場 i に辿り着くまでに支払うコストの総和の最小値
	vector<ll> dp(n, __LONG_LONG_MAX__);
	dp[0] = 0;

	for (int j = 1; j < n; j++) {
		ll minimum = __LONG_LONG_MAX__;
		for (int i = max(0, j - k); i < j; i++) {
			minimum = min(minimum, dp[i] + abs(h[i] - h[j]));
		}
		dp[j] = minimum;
	}

	cout << dp[n - 1] << endl;

	return 0;
}
