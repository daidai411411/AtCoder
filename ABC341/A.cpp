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

	string s = "";

	for (int i = 0; i < n; i++) {
		s += "10";
	}
	s += "1";

	cout << s << endl;

	return 0;
}
