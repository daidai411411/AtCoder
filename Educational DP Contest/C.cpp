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
	vector<vector<int>> a(n, vector<int>(3));
	for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];

	// dp[i][j] : i 日目に活動 a[i][j] を行うとき、i 日目までに太郎君が得る幸福度の総和の最大値
	vector<vector<ll>> dp(n, vector<ll>(3, 0));
	for (int j = 0; j < 3; j++) dp[0][j] = a[0][j];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int yesterday_j = 0; yesterday_j < 3; yesterday_j++) {
				if (j == yesterday_j) continue;
				dp[i][j] = max(dp[i][j], dp[i - 1][yesterday_j] + a[i][j]);
			}
		}
	}

	cout << *max_element(dp[n - 1].begin(), dp[n - 1].end()) << endl;

	return 0;
}
