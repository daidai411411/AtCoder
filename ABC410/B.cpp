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

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> x(q);
	for (int& xi : x) cin >> xi;

	vector<int> boxes(n + 1, 0);
	map<int, set<int>> groups;
	vector<int> places;
	for (int i = 1; i <= n; i++) groups[0].insert(i);
	for (int xi : x) {
		if (xi >= 1) {
			groups[boxes[xi]].erase(xi);
			if (groups[boxes[xi]].empty()) groups.erase(boxes[xi]);
			boxes[xi]++;
			groups[boxes[xi]].insert(xi);
			places.push_back(xi);
		} else {
			int mi = *(groups.begin()->second.begin());
			groups[boxes[mi]].erase(mi);
			if (groups[boxes[mi]].empty()) groups.erase(boxes[mi]);
			boxes[mi]++;
			groups[boxes[mi]].insert(mi);
			places.push_back(mi);
		}
	}

	for (int i : places) cout << i << ' ';
	cout << endl;
	return 0;
}
