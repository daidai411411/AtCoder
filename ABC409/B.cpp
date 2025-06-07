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

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a) cin >> i;

	sort(a.rbegin(), a.rend());
	ll ans = n;
	for (int i = 0; i < n; i++) {
		if (a[i] == i + 1) {
			ans = a[i];
			break;
		} else if (a[i] < i + 1) {
			ans = i;
			break;
		}
	}

	cout << ans << endl;

	return 0;
}
