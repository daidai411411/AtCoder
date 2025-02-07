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

bool increment(vector<int>& a, const vector<int>& r) {
	a[a.size() - 1]++;
	for (int i = a.size() - 1; i >= 0; i--) {
		if (r[i] < a[i]) {
			if (i == 0) return false;
			a[i - 1]++;
			a[i] = 1;
		}
	}
	return true;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> r(n);
	for (int i = 0; i < n; i++) cin >> r[i];

	vector<int> a(n, 1);
	do {
		if (reduce(a.begin(), a.end()) % k == 0) {
			for (int i : a) cout << i << " ";
			cout << endl;
		}
	} while (increment(a, r));

	return 0;
}
