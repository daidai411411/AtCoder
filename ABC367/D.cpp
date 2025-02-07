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
	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	ll total = 0;
	vector<int> mod(m, 0), pos(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		total += a[i];
		mod[total % m]++;
		pos[i] = total % m;
	}

	ll count = 0;
	for (int i = 0; i < n; i++) {
		count += mod[pos[i]] - 1;
		mod[pos[i]]--;
		total += a[i];
		mod[total % m]++;
	}

	cout << count << endl;

	return 0;
}
