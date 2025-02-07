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
	vector<long long> a(n), s(n - 1), t(n - 1);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n - 1; i++) {
		cin >> s[i] >> t[i];
	}

	for (int i = 0; i < n - 1; i++) {
		a[i + 1] += (a[i] / s[i]) * t[i];
	}

	cout << a[n - 1] << endl;

	return 0;
}
