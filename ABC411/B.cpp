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
	int n;
	cin >> n;
	vector<int> d(n - 1);
	for (int& di : d) cin >> di;

	vector<int> p(n, 0);
	for (int i = 1; i < n; i++) {
		p[i] = p[i - 1] + d[i - 1];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 1; j < n - i; j++) {
			cout << (p[i + j] - p[i]) << ' ';
		}
		cout << endl;
	}
	return 0;
}
