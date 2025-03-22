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

void Move(char d, int& r, int& c, int& p, int& q) {
	if (d == 'N') {
		r++;
		p++;
	} else if (d == 'W') {
		c++;
		q++;
	} else if (d == 'S') {
		r--;
		p--;
	} else {
		c--;
		q--;
	}
}

int main() {
	int n, r, c, p = 0, q = 0;
	string s;
	cin >> n >> r >> c >> s;

	set<array<int, 2>> smoke;
	smoke.insert({p, q});
	for (char d : s) {
		Move(d, r, c, p, q);
		smoke.insert({p, q});
		if (smoke.find({r, c}) != smoke.end()) cout << 1;
		else cout << 0;
	}

	cout << endl;

	return 0;
}
