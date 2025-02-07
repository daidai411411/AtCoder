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

int main() {
	int n;
	cin >> n;
	vector<ll> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	// dp[i][0] : i 匹目のモンスターを奇数回目に倒す時の経験値の合計の最大値
	// dp[i][1] : i 匹目のモンスターを偶数回目に倒す時の経験値の合計の最大値
	vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
	dp[1][0] = a[1];

	for (int i = 2; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][1], dp[i - 2][1]) + a[i];
		dp[i][1] = max(dp[i - 1][0], dp[i - 2][0]) + a[i] * 2ll;
	}

	cout << max(dp[n][0], dp[n][1]) << endl;

	return 0;
}
