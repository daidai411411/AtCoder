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

void Add(int n, ll& can_put_count, set<array<int, 2>>& cannot_put, int r, int c) {
	if (!(0 <= r and r < n and 0 <= c and c < n)) return;
	if (cannot_put.find({r, c}) != cannot_put.end()) return;
	cannot_put.insert({r, c});
	can_put_count--;
}

int main() {
	const vector<array<int, 2>> knight_move{
		{0, 0},
		{2, 1},
		{1, 2},
		{-1, 2},
		{-2, 1},
		{-2, -1},
		{-1, -2},
		{1, -2},
		{2, -1},
	};

	ll n, m;
	cin >> n >> m;
	ll can_put_count = n * n;
	set<array<int, 2>> cannot_put;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		for (array<int, 2> m : knight_move) {
			Add(n, can_put_count, cannot_put, a - 1 + m[0], b - 1 + m[1]);
		}
	}

	cout << can_put_count << endl;

	return 0;
}
