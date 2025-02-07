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
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	for (string& i : s) cin >> i;

	int top = h, bottom = 0, left = w, right = 0;
	for (int r = 0; r < h; r++) {
		for (int c = 0; c < w; c++) {
			if (s[r][c] == '#') {
				top = min(top, r);
				bottom = max(bottom, r);
				left = min(left, c);
				right = max(right, c);
			}
		}
	}
	for (int r = top; r <= bottom; r++) {
		for (int c = left; c <= right; c++) {
			if (s[r][c] == '.') {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}
