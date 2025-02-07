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
	for (int i = 1; i <= n; i++) {
		if (i % 3 == 0) {
			cout << "x";
		}
		else {
			cout << "o";
		}
	}

	cout << endl;
	return 0;
}
