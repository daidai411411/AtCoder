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
	int n;
	cin >> n;
	vector<int> colors(n + 1);
	iota(colors.begin(), colors.end(), 0);
	vector<int> count(n + 1, 1);
	vector<int> l(n + 1), r(n + 1);
	iota(l.begin(), l.end(), 0);
	iota(r.begin(), r.end(), 0);

	int q;
	cin >> q;
	int q, x, c;
	for (int i = 0; i < q; i++) {
		cin >> q;
		if (q == 1) {
			cin >> x >> c;
			int new_l, new_r;
			new_l = l[x];
			while(new_l >= 0 and colors[])

		} else {
			cin >> c;
			cout << count[c] << endl;
		}
	}

	return 0;
}
