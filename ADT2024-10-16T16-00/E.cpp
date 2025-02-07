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
	cin >> n;
	map<int, int> min_a;
	for (int i = 0; i < n; i++) {
		int a, c;
		cin >> a >> c;
		if (min_a.find(c) == min_a.end() or a < min_a[c]) min_a[c] = a;
	}

	int max_a = 0;
	for (auto p : min_a) {
		int a = p.second;
		if (a > max_a) max_a = a;
	}

	cout << max_a << endl;

	return 0;
}
