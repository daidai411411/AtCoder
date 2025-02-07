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
	int n;
	cin >> n;
	vector<int> h(n);
	for (int& hi : h) cin >> hi;

	// dp[i] : 足場 i に辿り着くまでに支払うコストの総和の最小値
	vector<ll> dp(n, __LONG_LONG_MAX__);
	dp[0] = 0;
	dp[1] = abs(h[0] - h[1]);

	for (int j = 2; j < n; j++) {
		dp[j] = min(dp[j - 2] + abs(h[j - 2] - h[j]), dp[j - 1] + abs(h[j - 1] - h[j]));
	}

	cout << dp[n - 1] << endl;

	return 0;
}
