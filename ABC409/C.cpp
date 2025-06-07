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

int main() {
	int n, l;
	cin >> n >> l;
	vector<int> d(n - 1);
	for (int& di : d) cin >> di;

	if (l % 3 != 0) {
		cout << 0 << endl;
		return 0;
	}

	vector<ll> pos_count(l, 0);
	int pos = 0;
	pos_count[pos]++;
	for (int di : d) {
		pos = (pos + di) % l;
		pos_count[pos]++;
	}

	ll ans = 0;
	int offset = l / 3;
	for (int i = 0; i < offset; i++) {
		ans += pos_count[i] * pos_count[i + offset] * pos_count[i + offset * 2];
	}

	cout << ans << endl;

	return 0;
}
