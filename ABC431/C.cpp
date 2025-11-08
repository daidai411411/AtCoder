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
	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> h(n), b(m);
	for (auto& i : h) cin >> i;
	for (auto& i : b) cin >> i;

	sort(h.begin(), h.end());
	sort(b.begin(), b.end());
	int count = 0;
	for (int i = 0, j = 0; i < n and j < m;) {
		if (h[i] <= b[j]) {
			count++;
			i++;
			j++;
		} else {
			j++;
		}
	}

	cout << ((count >= k) ? "Yes" : "No") << endl;

	return 0;
}
