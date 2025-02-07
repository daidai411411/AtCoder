#include <stdlib.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

int main() {
	int h, w, n;
	cin >> h >> w >> n;
	string t;
	cin >> t;
	vector<string> s(h);
	for (int r = 0; r < h; r++) cin >> s[r];

	vector<int> route_r(n + 1, 0), route_c(n + 1, 0);
	for (int i = 0; i < n; i++) {
		if (t[i] == 'L') {
			route_r[i + 1] = route_r[i];
			route_c[i + 1] = route_c[i] - 1;
		} else if (t[i] == 'R') {
			route_r[i + 1] = route_r[i];
			route_c[i + 1] = route_c[i] + 1;
		} else if (t[i] == 'U') {
			route_r[i + 1] = route_r[i] - 1;
			route_c[i + 1] = route_c[i];
		} else {
			route_r[i + 1] = route_r[i] + 1;
			route_c[i + 1] = route_c[i];
		}
	}

	int count = 0;
	for (int r = 1; r < h - 1; r++) {
		for (int c = 1; c < w - 1; c++) {
			bool all_land = true;
			for (int i = 0; i < n + 1; i++) {
				if (s[r + route_r[i]][c + route_c[i]] == '#') {
					all_land = false;
					break;
				}
			}

			if (all_land) count++;
		}
	}

	cout << count << endl;

	return 0;
}
