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

	int remainder = 0, pre_t = 0;
	for (int i = 0; i < n; i++) {
		int t, v;
		cin >> t >> v;
		remainder -= t - pre_t;
		pre_t = t;
		if (remainder < 0) remainder = 0;
		remainder += v;
	}

	cout << remainder << endl;

	return 0;
}
