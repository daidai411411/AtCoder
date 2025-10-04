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

template <typename T>
bool ChMax(T& max, T val) {
	return (val > max) ? (max = val, true) : false;
}

void Print(int n, int least, vector<int>& version_count) {
	for (int i = 1; i <= n; i++) {
		if (i < least) cout << 0 << ' ';
		else cout << version_count[i] << ' ';
	}
	cout << endl;
}

int main(void) {
	int n, q;
	cin >> n >> q;
	vector<int> x(q), y(q);
	for (int i = 0; i < q; i++) cin >> x[i] >> y[i];

	vector<int> version_count(n + 1, 1);
	int least = 1;
	for (int i = 0; i < q; i++) {
		int pc_updated = 0;
		for (int j = least; j <= x[i]; j++) pc_updated += version_count[j];
		version_count[y[i]] += pc_updated;
		ChMax(least, x[i] + 1);
		cout << pc_updated << endl;
	}

	return 0;
}
