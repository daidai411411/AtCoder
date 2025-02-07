#include <stdlib.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;
	vector<long> c(n);
	for (long& c_i : c) cin >> c_i;

	long long max_cost = reduce(c.begin(), c.end());
	long long min_cost = max_cost;

	for (int i = 0; i < n - 1; i++){
		long long cost = s[]
	}

	return 0;
}
