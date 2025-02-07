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

	// dp[i][j] : i 個目までの品物から重さ j を超えないように選んだときの、品物の価値の総和の最大値
	vector<vector<ll>> dp(N + 1, vector<ll>(W + 1, 0));

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= W; j++) {
			// 品物 i を追加する場合
			if (j - w[i] >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
			}

			// 品物 i を追加しない場合
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}

	cout << dp[N][W] << endl;

	return 0;
}
