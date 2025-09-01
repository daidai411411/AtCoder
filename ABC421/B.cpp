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
	ll x, y;
	cin >> x >> y;

	vector<ll> a(10);
	for (int i = 0; i < 10; i++) {
		if (i == 0) a[i] = x;
		else if (i == 1) a[i] = y;
		else {
			string tmp = to_string(a[i-1] + a[i-2]);
			reverse(tmp.begin(), tmp.end());
			a[i] = stoll(tmp);
		}
	}

	cout << a[9] << endl;

	return 0;
}
