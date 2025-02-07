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
	int n, m;
	cin >> n >> m;
	vector<set<int>> friends(n + 1);
	for (int i = 0; i < m; i++) {
		int pre_a, a;
		cin >> pre_a;
		for (int j = 1; j < n; j++) {
			cin >> a;
			friends[a].insert(pre_a);
			friends[pre_a].insert(a);
			pre_a = a;
		}
	}

	ll count = 0;
	for (int i = 1; i <= n; i++) {
		count += n - 1 - friends[i].size();
	}
	count /= 2;

	cout << count << endl;

	return 0;
}
