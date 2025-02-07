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
	int n;
	cin >> n;
	vector<int> a(n), b(n - 1);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n - 1; i++) cin >> b[i];
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());

	bool can = true;
	int size = 0;
	int i = 0, j = 0;
	while (i < n) {
		if (a[i] > b[j]) {
			if (size == 0) {
				size = a[i];
				j--;
			} else {
				can = false;
				break;
			}
		}
		i++;
		j++;
	}

	if (can) cout << size << endl;
	else cout << -1 << endl;

	return 0;
}
