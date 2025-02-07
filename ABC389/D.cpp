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

int main() {
	ll r;
	cin >> r;

	ll ans = 0;

	// 中心・軸上以外
	for (int x = 1; x < r; x++) {
		ans += floor(sqrt(r * r - (x + 0.5) * (x + 0.5)) - 0.5);
	}
	ans *= 4;

	ans += 1;			// 中心
	ans += 4 * (r - 1); // 軸上
	cout << ans << endl;

	return 0;
}
