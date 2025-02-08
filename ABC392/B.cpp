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
	vector<bool> contained(n+1, false);
	for (int a, i = 0; i < m; i++) {
		cin >> a;
		contained[a] = true;
	}
	cout << (n - m) << endl;
	for (int i = 1; i <= n; i++) {
		if (contained[i]) continue;
		cout << i << ' ';
	}
	cout << endl;
	return 0;
}
