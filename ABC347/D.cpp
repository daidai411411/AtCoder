#include <stdlib.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
	int a, b;
	long long C;
	cin >> a >> b >> C;

	vector<int> x_bin(60), y_bin(60), c_bin(60);
	int c = 0;

	for (int i = 0; i < 60; i++) {
		if (C & (1LL << i)) {
			c_bin[i] = 1;
			c++;
		}
	}

	if ((c % 2) == (abs(a - b) % 2) && (c >= abs(a - b)) && (c <= a + b)) {
		int x1y0, x0y1, x1y1;
		x1y0 = x0y1 = (c - abs(a - b)) / 2;
		if (a > b) {
			x1y0 += a - b;
		}
		x1y1 = a - x1y0;

		for (int i = 0; i < 60; i++) {
			if (c_bin[i] == 1) {
				if (x1y0 > 0) {
					x_bin[i] = 1;
					x1y0--;
				} else {
					y_bin[i] = 1;
				}
			} else if (x1y1 > 0) {
				x_bin[i] = y_bin[i] = 1;
				x1y1--;
			}
		}

		if (x1y1 > 0) {
			cout << -1 << endl;
			return 0;
		}

		long long x = 0, y = 0;
		for (int i = 0; i < 60; i++) {
			x += (1LL << i) * x_bin[i];
			y += (1LL << i) * y_bin[i];
		}

		cout << x << " " << y << endl;

	} else {
		cout << -1 << endl;
	}

	return 0;
}
