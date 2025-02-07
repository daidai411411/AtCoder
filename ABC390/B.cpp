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

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a) cin >> i;

	for (int i = 0; i <= n - 3; i++) {
		if (a[i] * a[i + 2] == a[i + 1] * a[i + 1]) continue;
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	return 0;
}
