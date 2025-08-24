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

template <typename T>
bool ChMin(T& min, T val) {
	return (val < min) ? (min = val, true) : false;
}

int main(void) {
	int h, w;
	cin >> h >> w;
	vector<vector<char>> a(h, vector<char>(w));
	int si, sj;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'S') {
				si = i;
				sj = j;
			}
		}
	}

	int ans = -1;
	vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(2, 1'000'000'000)));
	queue<array<int, 3>> search;
	dist[si][sj][0] = 0;
	search.push({si, sj, 0});
	while (!search.empty()) {
		auto [i, j, p] = search.front();
		search.pop();
		for (auto [ai, aj] : vector<array<int, 2>>{{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}}) {
			if (ai < 0 or ai >= h or aj < 0 or aj >= w) continue;
			if (a[ai][aj] == '#' or (p == 0 and a[ai][aj] == 'x') or (p == 1 and a[ai][aj] == 'o')) continue;
			if (a[ai][aj] == 'G') {
				ans = dist[i][j][p] + 1;
				search = {};
				break;
			}
			bool ap = (a[ai][aj] == '?') ? !p : p;
			if (ChMin(dist[ai][aj][ap], dist[i][j][p] + 1)) search.push({ai, aj, ap});
		}
	}

	cout << ans << endl;

	return 0;
}
