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

void Dfs(unordered_set<ll>& xor_numbers, const int& n, const vector<ll>& a, int depth, int numof_groups, vector<ll>& total_each_group, ll& xor_number) {
	for (int group = 0; group <= numof_groups; group++) {
		xor_number ^= total_each_group[group];
		total_each_group[group] += a[depth];
		xor_number ^= total_each_group[group];
		if (depth == n - 1) xor_numbers.insert(xor_number);
		else Dfs(xor_numbers, n, a, depth + 1, max(group + 1, numof_groups), total_each_group, xor_number);
		xor_number ^= total_each_group[group];
		total_each_group[group] -= a[depth];
		xor_number ^= total_each_group[group];
	}
}

void Dfs(unordered_set<ll>& xor_numbers, const vector<ll>& a) {
	int n = a.size();
	vector<ll> total_each_group(n);
	ll xor_number = 0;
	Dfs(xor_numbers, n, a, 0, 0, total_each_group, xor_number);
}

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a) cin >> i;

	unordered_set<ll> xor_numbers;
	Dfs(xor_numbers, a);

	cout << xor_numbers.size() << endl;

	return 0;
}
