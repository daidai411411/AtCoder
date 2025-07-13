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

int main() {
	int n, l, r;
	cin >> n >> l >> r;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] <= l and r <= y[i]) count++;
	}

	cout << count << endl;
	return 0;
}
