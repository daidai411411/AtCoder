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

int main(void) {
	int n;
	string t;
	cin >> n >> t;

	vector<ll> one_counts;
	ll one_count = 0;
	for (int i = 0; i < n; i++) {
		if (t[i] == '0') {
			one_counts.push_back(one_count);
			one_count = 0;
		} else one_count++;
	}
	one_counts.push_back(one_count);

	if (one_counts.size() == 1) {
		cout << one_count * (one_count + 1) / 2 << endl;
		return 0;
	}

	vector<ll> sum(one_counts.size());
	sum[0] = one_counts[0] + 1;
	sum[1] = one_counts[1] + 1;
	for (int i = 2; i < one_counts.size(); i++) {
		sum[i] = sum[i - 2] + one_counts[i] + 1;
	}

	ll ans = 0;
	for (int i = 0; i < one_counts.size(); i++) {
		ans += one_counts[i] * (one_counts[i] + 1) / 2;
		if (i >= 2) ans += (one_counts[i] + 1) * sum[i - 2];
	}

	cout << ans << endl;

	return 0;
}

// '0'が偶数個となる部分文字列の個数