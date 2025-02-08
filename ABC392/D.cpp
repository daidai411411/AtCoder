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

ll CountSameNumber(map<int, int> a, map<int, int> b) {
	ll count = 0;
	for (const auto [k, v] : a) count += v * b[k];
	return count;
}

int main() {
	int n;
	cin >> n;
	vector<ll> k(n);
	vector<map<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> k[i];
		for (int j = 0; j < k[i]; j++) {
			int ai;
			cin >> ai;
			a[i][ai]++;
		}
	}
	double max_probability = 0.0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double probability = 1.0 * CountSameNumber(a[i], a[j]) / (k[i] * k[j]);
			if (max_probability < probability) max_probability = probability;
		}
	}
	printf("%.10f\n", max_probability);
	return 0;
}
