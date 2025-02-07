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

int BinarySearch(const deque<array<int, 2>>& a, int l, int r, int b) {
	if (r < l) {
		if (r == -1) return -1;
		else return a[r][0];
	}
	int m = (l + r) / 2;
	if (a[m][1] == b) return a[m][0];
	else if (a[m][1] < b) return BinarySearch(a, m + 1, r, b);
	else return BinarySearch(a, l, m - 1, b);
}

int main() {
	int n, m;
	cin >> n >> m;
	deque<array<int, 2>> a;
	for (int min_a = 1000000, i = 1; i <= n; i++) {
		int ai;
		cin >> ai;
		if (ai < min_a) {
			a.push_front({i, ai});
			min_a = ai;
		}
	}
	for (int b, i = 0; i < m; i++) {
		cin >> b;
		cout << BinarySearch(a, 0, a.size() - 1, b) << endl;
	}

	return 0;
}
