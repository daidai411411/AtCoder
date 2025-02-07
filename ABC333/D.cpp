#include <stdlib.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> neighbor;

int GeSize(int vertex, int parent) {
	int size = 1;

	for (int nbr : neighbor[vertex]) {
		if (nbr != parent) size += GeSize(nbr, vertex);
	}

	return size;
}

int main() {
	int n;
	cin >> n;

	neighbor.resize(n + 1, vector<int>(0));

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;

		neighbor[u].push_back(v);
		neighbor[v].push_back(u);
	}

	int num_ope;
	if (neighbor[1].size() == 1) {
		num_ope = 1;
	} else {
		vector<int> size;
		for (int nbr : neighbor[1]) {
			size.push_back(GeSize(nbr, 1));
		}
		num_ope = (accumulate(size.begin(), size.end(), 0) + 1) - *(max_element(size.begin(), size.end()));
	}

	cout << num_ope << endl;

	return 0;
}