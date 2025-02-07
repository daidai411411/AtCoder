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

int main() {
	ll n, m;
	cin >> n >> m;
	set<tuple<int, int, char>> xyc;
	for (int i = 0; i < m; i++) {
		int x, y;
		char c;
		cin >> x >> y >> c;
		xyc.emplace(x, y, c);
	}

	bool yes = true;
	int min_white_y = n + 1;
	for (auto [x, y, c] : xyc) {
		if (c == 'B') {
			if (min_white_y <= y) {
				yes = false;
				break;
			}
		} else {
			if (y < min_white_y) min_white_y = y;
		}
	}

	if (yes) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
