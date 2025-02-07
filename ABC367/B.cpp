#include <algorithm>
#include <atcoder/all>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;

int main() {
	string x;
	cin >> x;

	for (int i = 0; i < 3; i++) {
		if (x[x.length() - 1] == '0') x = x.substr(0, x.length() - 1);
		else break;
		if (i == 2) x = x.substr(0, x.length() - 1);
	}

	cout << x << endl;

	return 0;
}
