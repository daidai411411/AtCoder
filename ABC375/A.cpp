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
	string s;
	cin >> n >> s;
	ll ans = 0;
	for (int i = 0; i < n - 2; i++) {
		if (s[i] == '#' and s[i + 1] == '.' and s[i + 2] == '#') ans++;
	}

	cout << ans << endl;

	return 0;
}
