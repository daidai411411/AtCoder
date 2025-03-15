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
	ll n;
	cin >> n;

	ll y = 1, x = cbrt(n + 1);
	while (3 * y * y + 3 * y + 1 <= n) {
		while (x * x * x - y * y * y < n) x++;
		if (x * x * x - y * y * y == n) {
			cout << x << ' ' << y << endl;
			return 0;
		}
		x--;
		y++;
	}

	cout << -1 << endl;

	return 0;
}
