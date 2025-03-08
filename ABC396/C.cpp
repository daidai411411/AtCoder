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

void ChMax(ll& a, ll b) {
	if (a < b) a = b;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<ll> b(n), w(m);
	for (ll& i : b) cin >> i;
	for (ll& i : w) cin >> i;

	sort(b.rbegin(), b.rend());
	sort(w.rbegin(), w.rend());
	int nb = 0, nw = 0;
	while (true) {
		if (nb < n and nw < m) {
			if (b[nb] > 0) {
				nb++;
				if (w[nw] > 0) nw++;
			} else {
				if (b[nb] + w[nw] > 0) {
					nb++;
					nw++;
				} else break;
			}
		} else if (nb < n) {
			while (nb < n and b[nb] > 0) nb++;
			break;
		} else break;
	}
	ll sum = 0;
	for (int i = 0; i < nb; i++) sum += b[i];
	for (int i = 0; i < nw; i++) sum += w[i];

	cout << sum << endl;

	return 0;
}
