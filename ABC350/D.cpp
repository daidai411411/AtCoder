#include <stdlib.h>

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adjacents(n, vector<int>(0));
	vector<bool> visited(n, false);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adjacents[a - 1].push_back(b - 1);
		adjacents[b - 1].push_back(a - 1);
	}

	long long numof_new_edges{0};
	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;

		long long numof_nodes{0};
		queue<int> to_be_processed;
		to_be_processed.push(i);

		while (!to_be_processed.empty()) {
			int current = to_be_processed.front();
			to_be_processed.pop();

			if (visited[current]) continue;
			visited[current] = true;
			numof_nodes++;

			for (int adjacent : adjacents[current]) {
				to_be_processed.push(adjacent);
			}
		}

		numof_new_edges += (numof_nodes * (numof_nodes - 1)) / 2;
	}

	numof_new_edges -= m;

	cout << numof_new_edges << endl;

	return 0;
}
