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

int main() {
	int n, h, m;
	cin >> n >> h >> m;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

	int max_win = 0;
	map<int, int> search;
	search[h] = m;
	for (int i = 0; i < n; i++) {
		map<int, int> next_search;

		int max_rm = -1;
		for (auto itr = search.rbegin(); itr != search.rend(); itr++) {
			auto [rh, rm] = *itr;
			if (!ChMax(max_rm, rm)) continue;
			if (rh >= a[i]) ChMax(next_search[rh - a[i]], rm);
			if (rm >= b[i]) ChMax(next_search[rh], rm - b[i]);
		}

		if (next_search.empty()) break;
		search = next_search;
		max_win = i + 1;
	}

	cout << max_win << endl;
	return 0;
}
