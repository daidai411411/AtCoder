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

void Solve(void) {
	int n;
	cin >> n;
	string s;
	cin >> s;

	int l = 0;
	while (l < n - 1 and s[l] <= s[l + 1]) l++;
	int r = l;
	while (r < n - 1 and s[r + 1] <= s[l]) r++;

	for (int i = 0; i < l; i++) cout << s[i];
	for (int i = l + 1; i <= r; i++) cout << s[i];
	cout << s[l];
	for (int i = r + 1; i < n; i++) cout << s[i];
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) Solve();
	return 0;
}
