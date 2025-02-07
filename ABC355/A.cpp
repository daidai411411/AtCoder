#include <algorithm>
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
	int a, b;
	cin >> a >> b;
	if ((a == 1 && b == 2) || (a == 2 && b == 1)) {
		cout << 3 << endl;
	} else if ((a == 3 && b == 2) || (a == 2 && b == 3)) {
		cout << 1 << endl;
	} else if ((a == 1 && b == 3) || (a == 3 && b == 1)) {
		cout << 2 << endl;
	} else {
		cout << -1 << endl;
	}

	return 0;
}
