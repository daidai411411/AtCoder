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
	string s;
	cin >> s;

	int num = stoi(s.substr(3, 3));

	if (1 <= num && num <= 349 && num != 316)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
