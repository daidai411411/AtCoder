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

vector<array<int, 3>> GetAdjacents(int h, int w, int i, int j) {
	vector<array<int, 3>> adjs{{i - 1, j, 'v'}, {i, j - 1, '>'}, {i, j + 1, '<'}, {i + 1, j, '^'}};
	for (auto itr = adjs.begin(); itr != adjs.end(); itr++) {
		if (0 <= (*itr)[0] and (*itr)[0] < h and 0 <= (*itr)[1] and (*itr)[1] < w) continue;
		itr = adjs.erase(itr);
		itr--;
	}
	return adjs;
}

vector<vector<char>> CalcRoute(int h, int w, const vector<string>& s) {
	vector<vector<char>> t(h, vector<char>(w));

	vector<vector<int>> d(h, vector<int>(w, 10000000));
	vector<array<int, 2>> start;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (s[i][j] == '#') {
				d[i][j] = -1;
				t[i][j] = '#';
			} else if (s[i][j] == 'E') {
				start.push_back({i, j});
				t[i][j] = 'E';
			}
		}
	}

	if (start.empty()) return t;

	queue<array<int, 2>> search_queue;
	for (auto [si, sj] : start) {
		search_queue.push({si, sj});
		d[si][sj] = 0;
	}
	while (!search_queue.empty()) {
		auto [i, j] = search_queue.front();
		search_queue.pop();
		for (auto [ai, aj, r] : GetAdjacents(h, w, i, j)) {
			if (s[ai][aj] == '#') continue;
			if (d[ai][aj] <= d[i][j] + 1) continue;
			d[ai][aj] = d[i][j] + 1;
			t[ai][aj] = r;
			search_queue.push({ai, aj});
		}
	}

	return t;
}

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	for (string& i : s) cin >> i;

	vector<vector<char>> t = CalcRoute(h, w, s);

	for (vector<char>& i : t) {
		for (char& j : i) cout << j;
		cout << endl;
	}

	return 0;
}
