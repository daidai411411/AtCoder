#include <algorithm>
#include <atcoder/all>
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
	int n;
	cin >> n;
	vector<ll> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	ll count = n, l = 1, r = 1;
	while (l < n) {
		if (l == r or (r <= n and a[l + 1] - a[l] == a[r] - a[r - 1])) {
			r++;
		} else {
			ll n = r - l;
			count += n * (n - 1) / 2;
			r--;
			l = r;
		}
	}

	cout << count << endl;

	return 0;
}
