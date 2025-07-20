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

bool Dfs(const int& n, const string& s, int state, vector<bool>& seen) {
	seen[state] = true;
	if (state == ((1 << n) - 1)) return true;

	bool all_contained = false;
	for (int med = 0; med < n; med++) {
		if (state & (1 << med)) continue;
		int next_state = state | (1 << med);
		if (s[next_state - 1] == '1') continue;
		if (seen[next_state]) continue;
		if (Dfs(n, s, next_state, seen)) {
			all_contained = true;
			break;
		}
	}

	return all_contained;
}

void Solve(void) {
	int n;
	string s;
	cin >> n >> s;

	vector<bool> seen((1 << n), false);
	if (Dfs(n, s, 0, seen)) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) Solve();
	return 0;
}
