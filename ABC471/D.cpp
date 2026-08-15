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
	ll q, v;
	cin >> q >> v;

	multiset<ll> w_on_zero;

	for (int i = 0; i < q; i++) {
		ll type, t, w;
		cin >> type;
		if (type == 1) {
			cin >> t >> w;
			w_on_zero.insert(w - t);
		} else {
			cin >> t;
			if (w_on_zero.empty()) cout << -1 << endl;
			else {
				auto max_batteery = w_on_zero.end();
				max_batteery--;
				cout << min(v, *max_batteery + t) << endl;
				w_on_zero.erase(max_batteery);
			}
		}
	}

	return 0;
}
