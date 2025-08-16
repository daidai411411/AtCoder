#include <algorithm>
#include <array>
#include <climits>
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

int main(void) {
	int n;
	cin >> n;
	vector<ll> r(n), c(n);
	for (int i = 0; i < n; i++) cin >> r[i] >> c[i];

	ll min_r = *(min_element(r.begin(), r.end()));
	ll max_r = *(max_element(r.begin(), r.end()));
	ll min_c = *(min_element(c.begin(), c.end()));
	ll max_c = *(max_element(c.begin(), c.end()));
	ll ans = max((max_r - min_r + 1) / 2, (max_c - min_c + 1) / 2);

	cout << ans << endl;

	return 0;
}
