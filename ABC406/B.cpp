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

vector<int> product(vector<int> x, vector<int> y) {
	vector<int> z(x.size() + y.size(), 0);
	for (int i = 0; i < x.size(); i++) {
		for (int j = 0; j < y.size(); j++) {
			z[i + j] += x[i] * y[j];
		}
	}
	for (int i = 0; i < z.size() - 1; i++) {
		z[i + 1] += z[i] / 10;
		z[i] %= 10;
	}
	while (z.back() == 0) z.pop_back();
	return z;
}

string to_string(vector<int> x) {
	string s;
	for (int i = x.size() - 1; i >= 0; i--) s.push_back('0' + x[i]);
	return s;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> a(n);
	for (int i = 0; i < n; i++) {
		ll ai;
		cin >> ai;
		while (ai > 0) {
			a[i].push_back(ai % 10);
			ai /= 10;
		}
	}

	vector<int> disp{1};
	for (int i = 0; i < n; i++) {
		disp = product(disp, a[i]);
		if (disp.size() > k) disp = {1};
	}

	cout << to_string(disp) << endl;

	return 0;
}

/*
100 * 100 = 10000
999 * 999 = 998001

2 5
999 999

*/