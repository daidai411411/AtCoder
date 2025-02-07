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

void atob(int n, int r, int x, int y, vector<string>& a, vector<string>& b) {
	int bx, by;
	if (r == 0) {
		bx = y;
		by = n - 1 - x;
	} else if (r == 1) {
		bx = n - 1 - x;
		by = n - 1 - y;
	} else if (r == 2) {
		bx = n - 1 - y;
		by = x;
	} else if (r == 3) {
		bx = x;
		by = y;
	}
	b[bx][by] = a[x][y];
}

int main() {
	int n;
	cin >> n;
	vector<string> a(n);
	vector<string> b(n, string(n, 0));

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i <= n / 2 - 1; i++) {
		int r = i % 4;
		for (int x = i; x <= n - i - 1; x++) {
			int y = i;
			atob(n, r, x, y, a, b);
			y = n - i - 1;
			atob(n, r, x, y, a, b);
		}
		for (int y = i + 1; y <= n - i - 2; y++) {
			int x = i;
			atob(n, r, x, y, a, b);
			x = n - i - 1;
			atob(n, r, x, y, a, b);
		}
	}

	for (int i = 0; i < n; i++) cout << b[i] << endl;

	return 0;
}
