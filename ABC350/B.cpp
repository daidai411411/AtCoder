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
	int n, q;
	cin >> n >> q;
	vector<bool> tooth(n, true);
	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;
		tooth[t - 1] = !tooth[t - 1];
	}

	cout << count(tooth.begin(), tooth.end(), true) << endl;
	return 0;
}
