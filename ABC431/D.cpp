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
bool ChMax(T& max, T val) {
	return (val > max) ? (max = val, true) : false;
}

template <typename T>
bool ChMin(T& min, T val) {
	return (val < min) ? (min = val, true) : false;
}

int main(void) {
	int n;
	cin >> n;
	vector<ll> w(n), h(n), b(n);
	for (int i = 0; i < n; i++) cin >> w[i] >> h[i] >> b[i];

	// dp[i][j]: パーツ i までで頭に移すパーツを選んで頭の重さが j となったときの、パーツ i までの嬉しさの合計の最大値
	vector<vector<ll>> dp(n + 1);
	dp[0] = {0};
	for (int i = 0; i < n; i++) {
		int m = dp[i].size();
		dp[i + 1].resize(m + w[i]);
		for (int j = 0; j < m; j++) {
			ChMax(dp[i + 1][j + w[i]], dp[i][j] + h[i]); // 頭に移したとき
			ChMax(dp[i + 1][j], dp[i][j] + b[i]);		 // 頭に移さなかったとき
		}
	}
	ll ans = *max_element(dp[n].begin(), dp[n].begin() + (dp[n].size() + 1) / 2);

	cout << ans << endl;

	return 0;
}
