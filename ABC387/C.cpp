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
using ull = unsigned long long;

ull Dfs(const ull& l, const ull& r, ull i, ull h, ull n) {
	ull max = 0ULL;
	for (int j = i - 1; j >= 0; j--) max = max * 10 + h - 1;
	max += n;
	if (max < l or r < n) return 0;
	if (i == 0) return 1;
	if (l <= n and max <= r) return powl(h, i);
	ull ans = 0;
	for (int j = 0; j < h; j++) {
		ull next_h;
		if (h != 10) next_h = h;
		else if (j == 0) next_h = 10;
		else next_h = j;
		ans += Dfs(l, r, i - 1, next_h, n + j * powl(10, i - 1));
	}
	return ans;
}

int main() {
	ull l, r;
	cin >> l >> r;

	ull ans = Dfs(l, r, 19, 10, 0);

	cout << ans << endl;

	return 0;
}
