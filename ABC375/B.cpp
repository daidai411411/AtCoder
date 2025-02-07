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
	vector<ll> x(n + 2, 0), y(n + 2, 0);
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}

	double ans = 0.0;
	for (int i = 0; i <= n; i++) {
		ll dx = x[i] - x[i + 1], dy = y[i] - y[i + 1];
		ans += sqrt(dx * dx + dy * dy);
	}

	printf("%f\n", ans);

	return 0;
}
