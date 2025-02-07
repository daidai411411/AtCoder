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
	string s;
	cin >> s;

	if (s[0] != '<' || s[s.length() - 1] != '>') {
		cout << "No" << endl;
		return 0;
	}

	for (int i = 1; i < s.length() - 1; i++) {
		if (s[i] != '=') {
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;
	return 0;
}
