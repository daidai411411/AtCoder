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

vector<int> operator*(const vector<int>& l, const vector<int>& r) {
	vector<int> result(l.size());
	for (int i = 0; i < result.size(); i++) result[i] = r[l[i]];
	return result;
}

vector<int> power(const vector<int>& x, ll k, map<int, vector<int>>& memo) {
	if (memo.find(k) != memo.end()) return memo[k];
	if (k == 1) return x;
	vector<int> result(x.size());
	if (k == 0) iota(result.begin(), result.end(), 0);
	else if (k % 2 == 0) result = power(x, k / 2, memo) * power(x, k / 2, memo);
	else result = power(x, k / 2, memo) * power(x, k / 2, memo) * x;
	memo[k] = result;
	return result;
}

vector<int> power(const vector<int>& x, ll k) {
	map<int, vector<int>> memo;
	return power(x, k, memo);
}

int main() {
	int n;
	ll k;
	cin >> n >> k;
	vector<int> x(n), a(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		x[i]--;
	}
	for (int i = 0; i < n; i++) cin >> a[i];

	a = power(x, k) * a;

	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;

	return 0;
}
