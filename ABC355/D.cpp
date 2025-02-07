#include <algorithm>
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

class Endpoint {
   public:
	ll l{0}, r{0};
};

int main() {
	int n;
	cin >> n;
	map<int, Endpoint> endpoints;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		endpoints[l].l++;
		endpoints[r].r++;
	}

	int height = 0;
	ll count = 0;
	for (const auto& ep : endpoints) {
		count += height * ep.second.l + ep.second.l * (ep.second.l - 1) / 2;
		height += ep.second.l - ep.second.r;
	}

	cout << count << endl;

	return 0;
}
