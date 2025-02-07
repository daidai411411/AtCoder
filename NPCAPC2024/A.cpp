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

#define MOD (998244353)

using namespace std;
using namespace atcoder;
using ll = long long;

ll FactorialMod(ll n, ll m) {
	ll result = 1;

	for (ll i = n; i >= 2; i--) result = (result * i) % m;

	return result;
}

int main() {
	int T, N;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;

		if (N < 12) {
			cout << 0 << endl;
			continue;
		}

		ll result = 0;

		for (int big = 6; big <= N; big++) {
			for (int small = 6; big + small <= N; small++) {
				ll res = pow_mod(44, N - big - small, MOD);
			}
		}

		cout << result << endl;
	}

	return 0;
}
