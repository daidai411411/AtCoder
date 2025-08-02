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
	cin >> n >> m;
	vector<ll> a(n), b(m);
	for (ll& i : a) cin >> i;
	for (ll& i : b) cin >> i;

	multiset<ll> ans;
	for (ll i : a) ans.insert(i);
	for (ll i : b) {
		auto pos = ans.find(i);
		if (pos != ans.end()) ans.erase(pos);
	}

	for (ll i : ans) cout << i << ' ';
	cout << endl;

	return 0;
}
