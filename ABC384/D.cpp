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
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;

int main() {
	ll n, s;
	cin >> n >> s;
	vector<ll> a(n);
	for (ll& i : a) cin >> i;
	ll sum_one_cycle = reduce(a.begin(), a.end(), 0ll);
	s %= sum_one_cycle;

	bool yes = false;
	ll l = 0, r = 0, sum = 0;
	while (l < n) {
		if (sum == s) {
			yes = true;
			break;
		} else if (sum < s) {
			sum += a[r % n];
			r++;
		} else {
			sum -= a[l];
			l++;
		}
	}

	if (yes) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
