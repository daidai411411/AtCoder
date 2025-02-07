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

int main() {
	ll x;
	cin >> x;

	ll f = 1;
	ll n = 2;
	while (true) {
		f *= n;
		if (x == f) break;
		n++;
	}

	cout << n << endl;

	return 0;
}
