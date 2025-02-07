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

#define M (998244353ll)

using namespace std;
using ll = long long;

int main() {
	int n;
	cin >> n;
	n--;
	vector<ll> pre_x(9, 1), x(9);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++) {
			x[j] = 0;
			for (int k = j - 1; k <= j + 1; k += 1) {
				if (k < 0 or 9 <= k) continue;
				x[j] = (x[j] + pre_x[k]) % M;
			}
		}
		pre_x = x;
	}

	ll ans = 0;
	for (int i = 0; i < 9; i++) {
		ans = (ans + x[i]) % M;
	}

	cout << ans << endl;

	return 0;
}

/*

1 2 5 13 35
1 3 8 22 61
1 3 9 26 75
1 3 9 27 80
1 3 9 27 81
1 3 9 27 80
1 3 9 26 75
1 3 8 22 61
1 2 5 13 35

4+21=25
10+26+45=81
26+44+52+81=203

*/