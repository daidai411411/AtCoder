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

int main() {
	int n, q;
	cin >> n >> q;

	int l = 1, r = 2, total = 0;
	for (int i = 0; i < q; i++) {
		char h;
		int t;
		cin >> h >> t;
		string order;
		if (l < r) {
			if (t < l) order = "tlr";
			else if (t < r) order = "ltr";
			else order = "lrt";
		} else {
			if (t < r) order = "trl";
			else if (t < l) order = "rtl";
			else order = "rlt";
		}

		if (h == 'L') {
			if (order == "tlr") total += l - t;
			else if (order == "ltr") total += t - l;
			else if (order == "lrt") total += n + l - t;
			else if (order == "trl") total += n + t - l;
			else if (order == "rtl") total += l - t;
			else if (order == "rlt") total += t - l;
			l = t;
		} else if (h == 'R') {
			if (order == "tlr") total += n + t - r;
			else if (order == "ltr") total += r - t;
			else if (order == "lrt") total += t - r;
			else if (order == "trl") total += r - t;
			else if (order == "rtl") total += t - r;
			else if (order == "rlt") total += n + r - t;
			r = t;
		}
	}

	cout << total << endl;

	return 0;
}
