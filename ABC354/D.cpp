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
#include <vector>

using namespace std;
using ll = long long;

constexpr int mass[2][4] = {
	{2, 1, 0, 1},
	{1, 2, 1, 0},
};
// mass[i][j] : 長方形 [[j, j + 1], [i, i + 1]] の面積 x 2

constexpr ll inf = 4000000000ll;
int main() {
	// 入力
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	// 計算
	ll ans = 0;
	for (int fy = 0; fy < 2; ++fy) {
		for (int fx = 0; fx < 4; ++fx) {
			const ll x1 = (a - fx + 3 + inf) / 4, x2 = (c - fx + 3 + inf) / 4;
			const ll count_x = x2 - x1; // x 方向の個数
			const ll y1 = (b - fy + 1 + inf) / 2, y2 = (d - fy + 1 + inf) / 2;
			const ll count_y = y2 - y1; // y 方向の個数
			ans += count_x * count_y * mass[fy][fx];
		}
	}
	// 出力
	cout << ans << endl;
}
