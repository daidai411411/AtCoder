#include <stdlib.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
	}

	for (int i = 0; i < n; i++){
		int max_n = 0;
		double max_dist = 0;
		for (int j = 0; j < n; j++){
			double dist = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
			if (max_dist < dist) {
				max_n = j;
				max_dist = dist;
			}
		}
		cout << max_n + 1 << "\n";
	}
	cout << endl;
	return 0;
}
