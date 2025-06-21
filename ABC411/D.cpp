#include <algorithm>
#include <array>
#include <climits>
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
	int n, q;
	cin >> n >> q;
	vector<int> t(q), p(q);
	map<int, string> s;
	for (int i = 0; i < q; i++) {
		cin >> t[i] >> p[i];
		if (t[i] == 2) cin >> s[i];
	}

	vector<string> server_rev;
	int target = -1;
	for (int i = q - 1; i >= 0; i--) {
		if (target == -1) {
			if (t[i] == 3) target = p[i];
		} else if (target == p[i]) {
			if (t[i] == 1) target = -1;
			else if (t[i] == 2) server_rev.push_back(s[i]);
		}
	}

	for (int i = server_rev.size() - 1; i >= 0; i--) cout << server_rev[i];
	cout << endl;

	return 0;
}
