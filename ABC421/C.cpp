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

int main(void) {
	int n;
	string s;
	cin >> n >> s;

	vector<int> a_pos;
	for (int i = 0; i < 2 * n; i++) {
		if (s[i] == 'A') a_pos.push_back(i);
	}
	ll ans_ab = 0;
	for (int i = 0; i < n; i++) ans_ab += abs(a_pos[i] - 2 * i);
	ll ans_ba = 0;
	for (int i = 0; i < n; i++) ans_ba += abs(a_pos[i] - (2 * i + 1));
	ll ans = min(ans_ab, ans_ba);

	cout << ans << endl;

	return 0;
}
