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
	map<long long, long long> c_a;

	for (int i = 0; i < n; i++) {
		long long c, a;
		cin >> a >> c;

		if (c_a.find(c) == c_a.end()) {
			c_a.insert(pair<long long, long long>(c, a));
		} else if (a < c_a[c]) c_a[c] = a;
	}

	auto max_pair = max_element(c_a.begin(), c_a.end(), [](auto a, auto b){
		return a.second < b.second;
	});

	cout << max_pair->second << endl;

	return 0;
}
