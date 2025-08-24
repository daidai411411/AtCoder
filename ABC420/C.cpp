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
	int n, q;
	cin >> n >> q;
	vector<ll> a(n), b(n), x(q), v(q);
	vector<char> c(q);
	for (auto& i : a) cin >> i;
	for (auto& i : b) cin >> i;
	for (int i = 0; i < q; i++) {
		cin >> c[i] >> x[i] >> v[i];
		x[i]--;
	}

	ll sum = 0;
	for (int i = 0; i < n; i++) sum += min(a[i], b[i]);
	for (int i = 0; i < q; i++) {
		if (c[i] == 'A') {
			ll diff = min(v[i], b[x[i]]) - min(a[x[i]], b[x[i]]);
			a[x[i]] = v[i];
			sum += diff;
			cout << sum << endl;
		} else {
			ll diff = min(a[x[i]], v[i]) - min(a[x[i]], b[x[i]]);
			b[x[i]] = v[i];
			sum += diff;
			cout << sum << endl;
		}
	}
	return 0;
}
