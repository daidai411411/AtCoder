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

int main(void) {
	ll n, q;
	cin >> n >> q;
	vector<ll> a(n), b(q);
	for (ll& ai : a) cin >> ai;
	for (ll& bi : b) cin >> bi;

	sort(a.rbegin(), a.rend());
	vector<ll> counts(a.front() + 1);
	for (ll i = 1, count = n; i <= a.front(); i++) {
		while (a[count - 1] < i) count--;
		counts[i] = count;
	}
	vector<ll> sum_counts(a.front() + 1);
	for (int i = 1; i <= a.front(); i++) sum_counts[i] = sum_counts[i - 1] + counts[i];

	for (ll bi : b) {
		if (bi > a.front()) cout << -1 << endl;
		else cout << (sum_counts[bi - 1] + 1) << endl;
	}

	return 0;
}
