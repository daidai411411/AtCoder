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
	cin >> n;

	vector<int> a(n);
	for (int& a_i : a) {
		cin >> a_i;
	}

	for (int i = 0; i < n - 1; i++) {
		cout << a[i] * a[i + 1] << ' ';
	}
	cout << endl;
	return 0;
}
