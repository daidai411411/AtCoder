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

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int& i : a) cin >> i;

	set<int> numbers;
	int i;
	for (i = 0; i < n; i++) {
		if (1 <= a[i] and a[i] <= m) {
			numbers.insert(a[i]);
			if (numbers.size() == m) break;
		}
	}

	cout << n - i << endl;

	return 0;
}
