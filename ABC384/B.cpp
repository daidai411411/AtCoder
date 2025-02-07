#include <algorithm>
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
	int n, r;
	cin >> n >> r;

	for (int i = 0; i < n; i++) {
		int d, a;
		cin >> d >> a;

		if ((d == 1 and 1600 <= r and r <= 2799) or (d == 2 and 1200 <= r and r <= 2399)) r += a;
	}

	cout << r << endl;

	return 0;
}
