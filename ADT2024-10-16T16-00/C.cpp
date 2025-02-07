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

int main() {
	int n, m;
	cin >> n >> m;
	vector<set<int>> adjacents(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adjacents[a].insert(b);
		adjacents[b].insert(a);
	}

	for (int i = 1; i <= n; i++) {
		cout << adjacents[i].size();
		for (int j : adjacents[i]) cout << " " << j;
		cout << endl;
	}

	return 0;
}
