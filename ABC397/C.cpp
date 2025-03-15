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

void ChMax(int& a, int b) {
	if (a < b) a = b;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;

	int ans = 0;
	map<int, int> left, right;
	for (int i : a) right[i]++;
	for (int i = 0; i < n - 1; i++) {
		left[a[i]]++;
		right[a[i]]--;
		if (right[a[i]] == 0) right.erase(a[i]);
		ChMax(ans, left.size() + right.size());
	}

	cout << ans << endl;

	return 0;
}
