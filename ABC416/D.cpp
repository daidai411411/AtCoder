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

void Solve(void) {
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());

	ll sum = 0;
	for (int i = 0, j = 0; i < n or j < n;) {
		if (i == n) {
			sum += b[j];
			j++;
		} else if (j == n) {
			sum += a[i];
			i++;
		} else if (a[i] + b[j] < m) {
			sum += a[i];
			i++;
		} else {
			sum += a[i] + b[j] - m;
			i++;
			j++;
		}
	}

	cout << sum << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) Solve();
	return 0;
}
