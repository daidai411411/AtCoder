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
	vector<int> p(n);
	for (int& i : p) cin >> i;

	vector<ull> up(0);
	for (int i = 0; i < n - 1; i++) {
		// cout << i << ' ' << flush;
		if (p[i] > p[i + 1]) continue;
		up.push_back(0);
		while (i < n - 1 and p[i] < p[i + 1]) {
			up.back()++;
			i++;
		}
	}

	// cout << "up.size() = " << up.size() << endl;
	// for (ll i : up) cout << i << ' ';
	// cout << endl;

	ull ans = 0;
	for (int i = 0; i < (int)up.size() - 1; i++) {
		// cout << i << ' ' << flush;
		ans += up[i] * up[i + 1];
	}

	cout << ans << endl;

	return 0;
}
