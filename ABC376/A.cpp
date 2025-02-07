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
	int n, c;
	cin >> n >> c;

	int pre_t = -2000, count = 0;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (t - pre_t < c) continue;
		count++;
		pre_t = t;
	}

	cout << count << endl;

	return 0;
}
