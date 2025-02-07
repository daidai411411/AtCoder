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
	vector<int> height(n + 1), height_to_building(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> height[i];
		height_to_building[height[i]] = i;
	}

	vector<ll> d(n + 1);
	vector<int> j_to_i(n + 1);
	for (int h = 1; h <= n; h++) {
		int j = height_to_building[h];
		if (j == 1) continue;
		int i = j - 1;
		while (j_to_i[i] != 0) i = j_to_i[i];

		j_to_i[j] = i;
		d[i]++;
		d[j]--;
	}

	ll c = 0;
	for (int i = 1; i <= n; i++) {
		c += d[i];
		cout << c << " ";
	}
	cout << endl;

	return 0;
}
