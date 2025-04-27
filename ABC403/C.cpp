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

int main() {
	int n, m, q;
	cin >> n >> m >> q;

	vector<set<int>> has_auth(n + 1);
	vector<bool> has_admin(n + 1, false);

	int type, x, y;
	for (int i = 0; i < q; i++) {
		cin >> type;
		if (type == 1) {
			cin >> x >> y;
			has_auth[x].insert(y);
		} else if (type == 2) {
			cin >> x;
			has_admin[x] = true;
		} else {
			cin >> x >> y;
			if (has_admin[x] || (has_auth[x].find(y) != has_auth[x].end())) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}

	return 0;
}
