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
	int n, l, r;
	string s;
	cin >> n >> l >> r >> s;

	bool yes = true;
	for (int i = l - 1; i <= r - 1; i++) {
		if (s[i] == 'o') continue;
		yes = false;
		break;
	}

	if (yes) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
