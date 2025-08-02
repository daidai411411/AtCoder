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
	vector<int> a(n);
	for (int& i : a) cin >> i;

	map<int, ll> ipai_cnt, jmaj_cnt;
	for (int i = 1; i <= n; i++) {
		ipai_cnt[i + a[i - 1]]++;
		jmaj_cnt[i - a[i - 1]]++;
	}

	ll ans = 0;
	for (auto [ipai, cnt]: ipai_cnt) ans += cnt * jmaj_cnt[ipai];

	cout << ans << endl;

	return 0;
}

// i + ai = j - aj
/*

i   :  1  2  3  4  5  6  7  8  9
a   :  3  6  4  1  5  9  1  1  1
ipai:  4  8  7  5 10 15  8 14 10
jmaj: -2 -4 -1  3  0 -3  6  2  8

*/
