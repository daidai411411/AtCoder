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
	const ll M = 1000000000;

	ll n, k;
	cin >> n >> k;

	if (n < k) {
		cout << 1 << endl;
		return 0;
	}

	vector<ll> a(n + 1, 1);
	a[k] = k;
	for (int i = k + 1; i <= n; i++) {
		a[i] = (2 * a[i - 1] - a[i - k - 1] + M) % M;
	}

	cout << a[n] << endl;
	
	return 0;
}
