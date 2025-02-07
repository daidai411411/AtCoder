#include <stdlib.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

long long combination(long long n, long long r) {
	long long result = 1;

	for (int i = n; i >= n - r + 1; i--) result *= i;
	for (int i = r; i >= 2; i--) result /= i;

	return result;
}

int main() {
	string str;
	cin >> str;

	long counts[26] = {};
	for (char chara : str) {
		counts[chara - 'a']++;
	}

	long long ans = combination(str.length(), 2);

	bool have_repetition = false;
	for (long count : counts) {
		if (count >= 2) {
			ans -= combination(count, 2);
			have_repetition = true;
		}
	}
	if (have_repetition) ans += 1;

	cout << ans << endl;

	return 0;
}
