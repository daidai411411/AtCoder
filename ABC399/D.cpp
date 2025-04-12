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

void Solve() {
	int n;
	cin >> n;
	vector<int> a(2 * n);
	for (int& i : a) cin >> i;

	int ans = 0;
	set<set<int>> pairs;
	map<set<int>, int> pos;
	for (int i = 0; i < 2 * n - 1; i++) {
		if (pairs.find({a[i], a[i + 1]}) == pairs.end()) {
			pairs.insert({a[i], a[i + 1]});
			pos[{a[i], a[i + 1]}] = i;
		} else if (i - pos[{a[i], a[i + 1]}] >= 2 and pairs.find({a[i]}) == pairs.end() and pairs.find({a[i + 1]}) == pairs.end() ) {
			ans++;
		}
	}

	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) Solve();
	return 0;
}