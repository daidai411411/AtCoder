#include <algorithm>
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
	int n, t;
	cin >> n >> t;
	vector<int> count_row(n, 0), count_col(n, 0);
	int count_up{0}, count_down{0};
	for (int k = 1; k <= t; k++) {
		int a;
		cin >> a;
		int i = (a - 1) / n, j = ((a - 1) % n);

		count_row[i]++;
		if (count_row[i] == n) {
			cout << k << endl;
			return 0;
		}
		count_col[j]++;
		if (count_col[j] == n) {
			cout << k << endl;
			return 0;
		}

		if (i + j == n - 1) {
			count_up++;
			if (count_up == n) {
				cout << k << endl;
				return 0;
			}
		}

		if (i == j) {
			count_down++;
			if (count_down == n) {
				cout << k << endl;
				return 0;
			}
		}
	}

	cout << -1 << endl;

	return 0;
}
