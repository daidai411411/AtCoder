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

ll ClacSlope(ll n, ll a, ll b) {
	ll diff = b - a;
	a += (diff - 1) / 2;
	b -= (diff - 1) / 2;

	if (n % 2 == 0) {
		if (b - a == 1) {
			return a % (n / 2);
		} else {
			return a % (n / 2) + n / 2;
		}
	} else {
		if (b - a == 1) {
			return a;
		} else {
			return (a - n / 2 + n) % n;
		}
	}
}

int main() {
	ll n, m;
	cin >> n >> m;
	vector<ll> slopes(n, 0);
	for (int i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		slopes[ClacSlope(n, a, b)]++;
	}

	ll lines = 0, count = 0;
	for (ll s : slopes) {
		count += lines * s;
		lines += s;
	}

	cout << count << endl;

	return 0;
}
