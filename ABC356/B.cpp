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
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int j = 0; j < m; j++) cin >> b[j];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	bool is_a = false;
	for (int i = 0, j = 0;;) {
		if (i < n && (j == m || a[i] < b[j])) {
			if (is_a) {
				cout << "Yes" << endl;
				return 0;
			}
			is_a = true;
			i++;
		} else if (j < m && (i == n || a[i] > b[j])) {
			is_a = false;
			j++;
		}

		if (i == n && j == m) break;
	}

	cout << "No" << endl;

	return 0;
}
