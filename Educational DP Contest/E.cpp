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
	int N, W;
	cin >> N >> W;
	vector<int> w(N + 1), v(N + 1);
	for (int i = 1; i <= N; i++) cin >> w[i] >> v[i];

	int max_v = *max_element(v.begin(), v.end());
	// dp[i][j] : i 個までの品物から価値が j 以上になるように選んだ時の、品物の重さの総和の最小値
	vector<vector<ll>> dp(N + 1, vector<ll>(N * max_v + 1, __LONG_LONG_MAX__ / 2));
	dp[0][0] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= N * max_v; j++) {
			// 品物 i を追加する場合
			if (j - v[i] >= 0) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
			}
			// 品物 i を追加しない場合
			dp[i][j] = min(dp[i][j], dp[i - 1][j]);
		}
	}

	int ans;
	for (int j = 0; j <= N * max_v; j++) {
		if (dp[N][j] <= W) ans = j;
	}

	cout << ans << endl;

	return 0;
}
