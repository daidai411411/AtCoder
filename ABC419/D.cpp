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
	int n, m;
	string s, t;
	cin >> n >> m >> s >> t;
	vector<int> l(m), r(m);
	for (int i = 0; i < m; i++) {
		cin >> l[i] >> r[i];
		l[i]--;
		r[i]--;
	}

	vector<bool> change(n + 1, false);
	for (int i = 0; i < m; i++) {
		change[l[i]] = !change[l[i]];
		change[r[i] + 1] = !change[r[i] + 1];
	}
	string ans = s;
	bool is_s = true;
	for (int i = 0; i < n; i++) {
		if (change[i]) is_s = !is_s;
		if (!is_s) ans[i] = t[i];
	}

	cout << ans << endl;

	return 0;
}
