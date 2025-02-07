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
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a_i;
		cin >> a_i;

		if (a_i % k == 0) {
			cout << a_i / k << " ";
		}
	}

	cout << endl;
	return 0;
}
