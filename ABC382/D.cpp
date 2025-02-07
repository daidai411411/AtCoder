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

bool Next(int n, int max, vector<int>& ans) {
	ans[n - 1]++;
	int i;
	for (i = n - 1; i >= 0; i--) {
		if (ans[i] <= max) break;
		if (i == 0) return false;
		ans[i - 1]++;
	}
	for (int j = i + 1; j < n; j++) {
		ans[j] = ans[i];
	}
	return true;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> ans_list;
	vector<int> ans(n, 0);

	do {
		ans_list.push_back(ans);
	} while (Next(n, m - 10 * (n - 1) - 1, ans));

	cout << ans_list.size() << endl;
	for (vector<int> a : ans_list) {
		for (int i = 0; i < n; i++) cout << (10 * i + 1 + a[i]) << ' ';
		cout << endl;
	}

	return 0;
}

/*
n = 3, m = 23

0 : 1  m-20 3
1 : 11 m-10 13
2 : 21 m    23

0 0 0
0 0 1
0 0 2
0 1 1
0 1 2
0 2 2
1 1 1
1 1 2
1 2 2
2 2 2

*/