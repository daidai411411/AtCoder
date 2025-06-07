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
	int n;
	string t, a;
	cin >> n >> t >> a;

	bool ans = false;
	for (int i = 0; i < n; i++) {
		if (t[i] == 'o' and a[i] == 'o') {
			ans = true;
			break;
		}
	}

	if (ans) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
