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
#include <vector>

using namespace std;
using ll = long long;

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ans += a[i];
	}
	ans *= n - 1;

	sort(a.begin(), a.end());
	ll count = 0;
	for (int i = 0, j = n; i < n; i++) {
		if (i == j) j++;
		while (i < j - 1 and a[i] + a[j - 1] >= 100000000) j--;
		count += n - j;
	}

	ans -= count * 100000000;
	cout << ans << endl;

	return 0;
}
