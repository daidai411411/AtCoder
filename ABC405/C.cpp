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

	ll ans = 0;
	ll tmp = 0;
	for (int j = 1; j < n; j++) {
		tmp += a[j - 1];
		ans += tmp * a[j];
	}
	
	cout << ans << endl;

	return 0;
}
