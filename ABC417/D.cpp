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

int main(void) {
	unsigned n, q;
	cin >> n;
	vector<unsigned> p(n), a(n), b(n);
	for (unsigned i = 0; i < n; i++) cin >> p[i] >> a[i] >> b[i];
	cin >> q;
	vector<unsigned> x(q);
	for (auto& xi : x) cin >> xi;

	// "プレゼントを受け取った直後のテンション" の最大値
	unsigned m = 0;
	for (unsigned i = 0; i < n; i++) ChMax(m, p[i] + a[i]);

	// 0 <= i <= n. 0 <= j <= m.
	// dp[i][j] := i 番目のプレゼントを受け取った直後(i = 0 のとき、初めのプレゼントを受け取る前)のテンションが j であるときの、最終的なテンション
	vector<vector<unsigned>> dp(n + 1, vector<unsigned>(m + 1));

	// 全てのプレゼント受けとった後のテンションが j であるとき、最終的なテンションは j
	iota(dp.back().begin(), dp.back().end(), 0);

	// 後ろからdpテーブルを埋めていく
	for (unsigned i = n; i--;) {
		for (unsigned j = 0; j <= m; j++) {
			dp[i][j] = (j <= p[i]) ? dp[i + 1][j + a[i]] : dp[i + 1][j - min(j, b[i])];
		}
	}

	// b の累積和
	vector<unsigned> sum_b(n);
	for (unsigned i = 0; i < n; i++) sum_b[i] = (i == 0) ? b[0] : (sum_b[i - 1] + b[i]);

	// 始めのテンションが xi だったときの、最終的なテンション
	const auto ans{[&](unsigned xi) -> unsigned {
		// dpテーブル内
		if (xi <= m) return dp[0][xi];
		// dpテーブル外
		// テンションがdpテーブル内に到達するか、最後のプレゼントを受け取るまでテンションを下げ続ける
		const auto down_last = lower_bound(sum_b.begin(), sum_b.end(), xi - m);
		// n 最後のプレゼントを受け取ってもdpテーブルないに到達しないなら、そのときのテンションが最終的なテンション
		if (down_last == sum_b.end()) return xi - sum_b.back();
		// 全部受け取る前にdpテーブルの範囲内に入ったら、その途中からdpテーブルを参照
		return dp[down_last - sum_b.begin() + 1][xi - min(xi, *down_last)];
	}};

	for (auto& xi : x) cout << ans(xi) << endl;

	return 0;
}
