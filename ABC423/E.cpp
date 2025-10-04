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
	ll n, q;
	cin >> n >> q;
	vector<ll> a(n), l(q), r(q);
	for (auto& i : a) cin >> i;
	for (int i = 0; i < q; i++) cin >> l[i] >> r[i];



	return 0;
}

/*

l/r

  1 . . . L . . . R . . . N
1 - - - - - - - - -
.   - - - - - - - -
.     - - - - - - -
.       - - - - - -
L         + + + + +
.           + + + +
.             + + +
.               + +
R                 +
.
.
.
N





*/