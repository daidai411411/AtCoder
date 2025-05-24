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
using ull = unsigned long long;

int main() {
	string s;
	cin >> s;

	ll cntb = 0;
	for (int i = (int)s.size() - 1; i >= 0; i--) {
		ll num = ((s[i] - '0') - cntb + 1000000000) % 10;
		cntb += num;
	}
	ll ans = (ll)s.size() + cntb;

	cout << ans << endl;
	return 0;
}
