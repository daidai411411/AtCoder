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
	long long n;
	cin >> n;

	if (n % 10 == 0) {
		cout << n / 10 << endl;
	} else if (n > 0) {
		cout << n / 10 + 1 << endl;
	} else {
		cout << n / 10 << endl;
	}

	return 0;
}
