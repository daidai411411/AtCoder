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

void Solve() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for (ll& ai : a) cin >> ai;

	bool all_same = true;
	int sign_count[]{0, 0};
	for (int i = 0; i < n; i++) {
		if (abs(a[i]) != abs(a[0])) {
			all_same = false;
			break;
		}
		sign_count[a[i] > 0]++;
	}
	if (all_same) {
		cout << sign_count[0] << ' ' << sign_count[1] << endl;
		if (abs(sign_count[0] - sign_count[1]) <= 1) cout << "Yes" << endl;
		else cout << "No" << endl;
		return;
	}

	sort(a.begin(), a.end(), [](ll l, ll r) { return abs(l) < abs(r); });
	bool yes = true;
	if (n > 2) {
		for (int i = 1; i < n - 1; i++) {
			if (a[i] * a[i] == a[i - 1] * a[i + 1]) continue;
			yes = false;
			break;
		}
	}

	if (yes) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) Solve();
	return 0;
}
