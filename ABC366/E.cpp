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

using Point = array<int, 2>;

int main() {
	int N, D;
	cin >> N >> D;
	map<Point, int> dist;
	for (int i = 0; i < N; i++) {
		Point p;
		cin >> p[0] >> p[1];
		for (int x = -D; x <= D; x++) {
			for (int y = -(D - abs(x)); y <= D - abs(x); y++) {
				Point near{p[0] + x, p[1] + y};
				if (i == 0) {
					dist[near] += abs(x) + abs(y);
				} else if (dist.find(near) != dist.end()) {
					dist[near] += abs(x) + abs(y);
					if (dist[near] > D) dist.erase(near);
				}
			}
		}
	}

	int count = 0;
	for (auto d : dist) {
		if (d.second <= D) count++;
	}

	cout << count << endl;

	return 0;
}
