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
	string s;
	cin >> s;
	int n = s.length();
	vector<int> alpha_count(26, 0);
	vector<vector<ll>> alpha_ans(26, vector<ll>(n + 1, 0));
	vector<int> alpha_last(26, -1);

	for (int i = 0; i < n; i++) {
		int c = s[i] - 'A';
		alpha_count[c]++;
		if (alpha_count[c] == 1) {
			alpha_ans[c][alpha_count[c]] = 0;
		} else if (alpha_count[c] >= 2) {
			alpha_ans[c][alpha_count[c]] = 2 * alpha_ans[c][alpha_count[c] - 1] - alpha_ans[c][alpha_count[c] - 2] + (alpha_count[c] - 1) * (i - alpha_last[c]) - 1;
		}
		alpha_last[c] = i;
	}

	ll ans = 0;
	for (int c = 0; c < 26; c++) {
		ans += alpha_ans[c][alpha_count[c]];
	}
	cout << ans << endl;

	return 0;
}