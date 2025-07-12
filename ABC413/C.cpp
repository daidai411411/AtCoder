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

int main() {
	int q;
	cin >> q;

	deque<pair<ll, ll>> seq;
	for (int i = 0; i < q; i++) {
		ll t, c, x, k;
		cin >> t;
		if (t == 1) {
			cin >> c >> x;
			seq.push_back({c, x});
		} else {
			cin >> k;
			ll sum = 0;
			while (k > 0) {
				if (k >= seq[0].first) {
					sum += seq[0].first * seq[0].second;
					k -= seq[0].first;
					seq.pop_front();
				} else {
					sum += k * seq[0].second;
					seq[0].first -= k;
					k = 0;
				}
			}
			cout << sum << endl;
		}
		// for (auto s : seq) cout << '{' <<  s.first << ' ' << s.second << '}';
		// cout << endl;
	}
	return 0;
}
