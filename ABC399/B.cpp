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
	int n;
	cin >> n;
	map<int, set<int>> score_to_persons;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		score_to_persons[-p].insert(i);
	}

	vector<int> ranks(n);
	int r = 1;
	for (auto [score, persons] : score_to_persons) {
		for (int person : persons) ranks[person] = r;
		r += persons.size();
	}

	for (int rank : ranks) cout << rank << endl;

	return 0;
}
