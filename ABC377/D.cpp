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
	int N, M;
	cin >> N >> M;
	set<int> Rs;
	vector<int> R_to_L(M + 1, 0);
	for (int i = 0; i < N; i++) {
		int L, R;
		cin >> L >> R;
		Rs.insert(R);
		if (R_to_L[R] < L) R_to_L[R] = L;
	}

	cout << endl;

	ll count = 0;
	int l = 1, r = 1;
	for (int R : Rs) {
		if (l < R_to_L[R] + 1) {
			r = R - 1;
			ll n = (r - l + 1);
			cout << l << " " << r << " " << n << endl;
			count += ((n + 1) * n) / 2;
			l = R_to_L[R] + 1;
		}
	}

	r = M;
	ll n = (r - l + 1);
	cout << l << " " << r << " " << n << endl;
	count += ((n + 1) * n) / 2;

	cout << endl;

	cout << count << endl;

	return 0;
}

/*

1-----6
  4-------11
		8----12
		  11----13
	5-----------------19
				   14----20

*/