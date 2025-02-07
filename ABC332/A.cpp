#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n, s, k;
	cin >> n >> s >> k;

	long long total = 0;
	for (int i = 0; i < n; i++) {
        long long p, q;
		cin >> p >> q;
		total += p * q;
	}

	if (total < s) total += k;

	cout << total << endl;

	return 0;
}