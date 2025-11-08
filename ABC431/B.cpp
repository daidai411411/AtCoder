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
	int x, n, q;
	cin >> x >> n;
	vector<int> w(n);
	for (auto& i : w) cin >> i;
	cin >> q;
	vector<int> p(q);
	for (auto& i : p) {
		cin >> i;
		i--;
	}

	vector<bool> has(n, false);
	int weight = x;
	for (auto i : p) {
		if (has[i]) {
			has[i] = false;
			weight -= w[i];
		} else {
			has[i] = true;
			weight += w[i];
		}
		cout << weight << endl;
	}
	return 0;
}
