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
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	iota(a.begin(), a.end(), 1);

	ll base = 0, k;
	int t, p, x;
	for (int i = 0; i < q; i++) {
		cin >> t;
		if (t == 1) {
			cin >> p >> x;
			p--;
			a[(base + p) % n] = x;
		} else if (t == 2) {
			cin >> p;
			p--;
			cout << a[(base + p) % n] << endl;
		} else {
			cin >> k;
			base += k;
		}
	}
	return 0;
}
