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

template <typename T>
bool ChMax(T& max, T val) {
	return (val > max) ? (max = val, true) : false;
}

void Solve() {
	int n;
	cin >> n;
	vector<ull> a(2 * n);
	for (ull& i : a) cin >> i;

	ull ans = 0;
	priority_queue<ull> pq;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			pq.push(a[2 * i]);
		} else {
			pq.push(a[2 * i - 1]);
			pq.push(a[2 * i]);
		}
		ans += pq.top();
		pq.pop();
	}

	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) Solve();
	return 0;
}
