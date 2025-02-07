#include <algorithm>
#include <atcoder/all>
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
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;

int CalcArea(int h, int w, int d, vector<string>& office, int r1, int c1, int r2, int c2) {
	int area = 0;
	vector<vector<bool>> is_humid(h, vector<bool>(w, false));
	int rs[2]{r1, r2}, cs[2]{c1, c2};
	for (int i = 0; i <= 1; i++) {
		for (int r = rs[i] - d; r <= rs[i] + d; r++) {
			for (int c = cs[i] - d + abs(r - rs[i]); c <= cs[i] + d - abs(r - rs[i]); c++) {
				if (not(0 <= r and r < h and 0 <= c and c < w)) continue;
				if (office[r][c] == '#') continue;
				if (is_humid[r][c]) continue;
				is_humid[r][c] = true;
				area++;
			}
		}
	}

	return area;
}

int main() {
	int h, w, d;
	cin >> h >> w >> d;
	vector<string> office(h);
	for (string& i : office) cin >> i;

	int max_area = 0;
	for (int r1 = 0; r1 < h; r1++) {
		for (int c1 = 0; c1 < w; c1++) {
			if (office[r1][c1] == '#') continue;
			for (int r2 = 0; r2 < h; r2++) {
				for (int c2 = 0; c2 < w; c2++) {
					if (r1 == r2 and c1 == c2) continue;
					if (office[r2][c2] == '#') continue;
					int area = CalcArea(h, w, d, office, r1, c1, r2, c2);
					if (max_area < area) max_area = area;
				}
			}
		}
	}

	cout << max_area << endl;

	return 0;
}
