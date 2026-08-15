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
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a) cin >> i;
	sort(a.begin(), a.end());
	ll min_idx = 0, min = abs(a[0]);
	for (int i = 0; i < n; i++) {
		ll dist = abs(a[i]);
		if (min > dist) {
			min = dist;
			min_idx = i;
		}
	}
	ll current = a[min_idx];
	ll total = min;
	ll left = min_idx;
	ll right = min_idx;
	for (int i = 0; i < n - 1; i++) {
		ll left_dist = __LONG_LONG_MAX__, right_dist = __LONG_LONG_MAX__;
		if (left > 0) {
			left_dist = abs(current - a[left - 1]);
		}
		if (right < n - 1) {
			right_dist = abs(current - a[right + 1]);
		}
		if (left_dist <= right_dist) {
			total += left_dist;
			left--;
			current = a[left];
		} else {
			total += right_dist;
			right++;
			current = a[right];
		}
	}

	cout << total << endl;

	return 0;
}
