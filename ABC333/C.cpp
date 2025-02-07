#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	n--;

	vector<int> length(3, 1);

	int digit = 0;
	for (int i = 0; i < n; i++) {
		if (digit == 0) {
			length[0]++;
			length[1] = 1;
			length[2] = 1;
			digit = 1;
		} else if (digit == 1) {
			length[1]++;
			length[2] = 1;
			digit = 2;
		} else if (digit == 2) {
			length[2]++;
			if (length[1] == length[2]){
				if (length[0] == length[2]) digit = 0;
				else digit = 1;
			}
		}
	}

	long long sum = 0;
	for (int i = 0; i < 3; i++) {
		long long rep = 0;
		for (int j = 0; j < length[i]; j++) {
			rep = rep * 10 + 1;
		}
		sum += rep;
	}

	cout << sum << endl;

	return 0;
}