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

int Popcount(ll n) {
	int popcount = 0;
	while (n != 0ll) {
		if ((n & 1ll) == 1) popcount++;
		n >>= 1;
	}
	return popcount;
}

int main() {
	string s;
	cin >> s;
	ll n = s.size();

	int q;
	cin >> q;
	ll k;
	for (int i = 0; i < q; i++) {
		cin >> k;
		k--;
		ll group = k / n;
		ll pos_in_group = k % n;
		char ans = s[pos_in_group];
		if (Popcount(group) % 2 == 1) {
			if (ans <= 'Z') ans += 32;
			else ans -= 32;
		}
		cout << ans << ' ';
	}
	cout << endl;

	return 0;
}

/*

0123456789
sccscssccsscsccs

0 0 s
1 1 c
2 10 c
3 11 s
4 100 c
5 101 s
6 110 s
7 111 c
8 1000 c
9 1001 s
10 1010 s
11 1011 c
12 1100 s
13 1101 c
14 1110 c
15 1111 s



*/